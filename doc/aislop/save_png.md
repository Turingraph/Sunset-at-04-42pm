## 1\. The basic idea: pixels → encoder → bytes → file

Suppose you have a rendered FDF image with a resolution of `800 × 600` pixels.

If each pixel uses RGB, your raw pixel buffer requires:

$$
800 \times 600 \times 3 = 1{,}440{,}000 \text{ bytes}
$$

You might represent it in C as:

```
typedef struct s_pixel
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_pixel;

typedef struct s_image
{
	size_t	width;
	size_t	height;
	t_pixel	*pixels;
}	t_image;
```

You could access the pixel at coordinates `(x, y)` with:

```
pixel = image->pixels[y * image->width + x];
```

However, **this buffer is not a PNG or JPEG file**. It is just raw pixel data.

You need an encoder to transform those pixels into the appropriate image format.

The general pipeline is:

```
FDF geometry
     |
     v
Render image
     |
     v
Raw pixel buffer
     |
     +------------------+
     |                  |
     v                  v
  PNG encoder       JPEG encoder
     |                  |
     v                  v
 PNG byte stream    JPEG byte stream
     |                  |
     +--------+---------+
              |
              v
         write(fd, ...)
              |
              v
           Image file
```

The encoder handles the format-specific details. Your file-writing function handles the resulting bytes.

## 2\. How would PNG encoding work?

PNG is a lossless image format. It preserves the pixel values without introducing the lossy compression used by JPEG.

A PNG file contains several components:

- A file signature identifying the format.
- An `IHDR` chunk describing the image dimensions, color type, and other properties.
- One or more `IDAT` chunks containing compressed image data.
- An `IEND` chunk marking the end of the image.

The encoder also handles filtering, compression, checksums, and the required file structure.

You don't need to implement these operations yourself if you use a library such as **libpng**.

Conceptually, your code would look like this:

```
bool	write_png(int fd, const t_image *image)
{
	/*
	 * 1. Initialize the PNG encoder.
	 * 2. Configure the image dimensions and color format.
	 * 3. Supply the pixel rows to the encoder.
	 * 4. Write the encoded PNG bytes to fd.
	 * 5. Release encoder resources.
	 */
}
```

The actual implementation requires calls to the PNG library.

### Can the PNG encoder write directly to your file descriptor?

Yes\!

With libpng, you can configure a custom write callback that receives encoded data and forwards it to your file descriptor.

For example, the callback could conceptually look like this:

```
static void	png_write_to_fd(png_structp png,
		png_bytep data, png_size_t length)
{
	int		fd;
	size_t	offset;
	ssize_t	n;

	fd = *(int *)png_get_io_ptr(png);
	offset = 0;
	while (offset < length)
	{
		n = write(fd, data + offset, length - offset);
		if (n <= 0)
			png_error(png, "write failed");
		offset += (size_t)n;
	}
}
```

This is an illustrative implementation; production code should also handle interrupted system calls appropriately and ensure the callback's error handling integrates correctly with libpng.

You would register the callback using `png_set_write_fn()`.

The important detail is that **the callback receives already-encoded PNG bytes**, not individual pixels.

Your encoder might process thousands of pixels and produce a compressed byte stream. Your callback simply writes each supplied portion of that stream.

This fits nicely with your existing low-level C utilities.

## 3\. How would JPEG encoding work?

JPEG is similar in principle, but its encoding process is different.

A typical JPEG encoder performs operations such as:

1. Convert the input color representation into a suitable color space.
2. Divide the image into blocks.
3. Apply a discrete cosine transform (DCT).
4. Quantize the resulting coefficients, discarding some information.
5. Entropy-encode the coefficients.
6. Generate the JPEG file structure.

The quantization step makes JPEG lossy: decoding the image generally won't reproduce the exact original pixels.

In C, you could use **libjpeg** or **libjpeg-turbo**.

Your function might have this interface:

```
bool	write_jpg(int fd, const t_image *image, int quality);
```

The `quality` parameter would control the encoder's quality setting, within the range supported by the library.

For JPEG, you would configure a destination manager that supplies encoded output to your file descriptor. Alternatively, you could encode to a memory buffer or a `FILE *` stream and write the resulting data.

Again, you don't need to implement the compression algorithm yourself.

### What about alpha transparency?

JPEG doesn't support an alpha channel.

If your FDF renderer produces RGBA pixels, you must decide how to handle transparency before encoding JPEG—for example, by compositing the pixels against a background color.

PNG supports alpha transparency, so it is a more natural choice when you want to preserve it.

---

## 4\. How would I design this in your library?

Given your existing naming conventions, I would separate the rendering operation from the encoding operation.

For example:

```
t_image	*fdf_render_image(const t_fdf_table *table,
				size_t width, size_t height);

bool	write_png(int fd, const t_image *image);

bool	write_jpg(int fd, const t_image *image, int quality);
```

The precise signatures would depend on your existing image and rendering types.

This separation has several advantages:

- Your FDF renderer doesn't need to know how PNG compression works.
- Your PNG encoder doesn't need to understand FDF geometry.
- The same rendered image can be saved as PNG or JPEG.
- You can add other output formats without rewriting the rendering code.

Your existing enum could then select an output format:

```
typedef enum t_fdf_format
{
	FDF_FORMAT_DECIMAL_BW,
	FDF_FORMAT_DECIMAL_RGBA,
	FDF_FORMAT_DECIMAL_RGBA,
	WRITE_ASCII,
	WRITE_PNG,
	WRITE_JPG
}	t_fdf_format;
```

One architectural detail is worth considering: the first four modes serialize FDF data, while the last two export rendered images.

Those are different operations, even if you expose them through one interface.

For a small project, a single enum is perfectly workable. If the library grows, you might eventually separate textual FDF serialization from image export.

---

## 5\. An even simpler alternative: use an existing image-writing library

If you just want to export rendered images without learning the details of PNG and JPEG encoding, you have several options.

| Library | Advantages | Considerations |
| --- | --- | --- |
| [libpng](<https://www.libpng.org/pub/png/libpng.html>) | Mature PNG implementation with detailed control | More involved API |
| [libjpeg-turbo](<https://libjpeg-turbo.org/>) | Fast JPEG encoding and decoding | More involved API |
| [stb\_image\_write](<https://github.com/nothings/stb/blob/master/stb_image_write.h>) | Simple interface for writing common image formats, including PNG and JPEG | Single-header design; fewer configuration options than dedicated libraries |

For a solo C project approaching its first stable release, I'd consider `stb_image_write` if adding an external dependency is acceptable.

Its API can be much simpler than configuring libpng or libjpeg.

For example, its PNG-writing interface accepts the filename, dimensions, number of color components, pixel buffer, and row stride.

However, the standard interface writes using a filename rather than accepting an existing file descriptor directly. You would need to use an appropriate alternative interface or adapt your output architecture if an existing `fd` is a strict requirement.

**My recommendation:** Keep your existing `write(fd, buffer, length)` utility for writing bytes, but let an established image encoder generate those bytes. Don't try to turn raw pixel data directly into PNG or JPEG by writing each pixel to the file.

That way, you retain control over your library's I/O conventions without taking on the substantial complexity of implementing image formats yourself.