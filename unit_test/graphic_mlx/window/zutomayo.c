#include"window.h"

// // time : O(1)
// // space: O(1)
// t_gradient	init_blue_period()
// {
// 	t_gradient	dst;

// 	dst.cell_channel = D7_RED;
// 	dst.input_start = 66 * 3 / 2;
// 	dst.input_end = 86 * 3 / 2;
// 	dst.rgba_start.r = 70;
// 	dst.rgba_start.g = 75;
// 	dst.rgba_start.b = 113;
// 	dst.rgba_start.a = 255;
// 	dst.rgba_end.r = 124;
// 	dst.rgba_end.g = 213;
// 	dst.rgba_end.b = 199;
// 	dst.rgba_end.a = 255;
// 	return (dst);
// }

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 0;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 0;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_timeleft()
{
	t_gradient	dst;

	dst.cell_channel = D7_RED;
	dst.input_start = 66 * 3 / 2;
	dst.input_end = 86 * 3 / 2;
	dst.rgba_start.r = 72;
	dst.rgba_start.g = 33;
	dst.rgba_start.b = 86;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 114;
	dst.rgba_end.g = 40;
	dst.rgba_end.b = 70;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_studyme()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 20;
	dst.rgba_start.r = 66;
	dst.rgba_start.g = 54;
	dst.rgba_start.b = 118;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 204;
	dst.rgba_end.g = 131;
	dst.rgba_end.b = 240;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_artstyle32	style;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	style.background_color = f_rgba_to_int32(0, 0, 0, 255);
	style.line_thickness = 1;
	style.artists = E_TUYOKI;
	color_cells_gradient(&table, init_ztmy_studyme(), true);
	color_cells_gradient(&table, init_ztmy_timeleft(), true);
	scale_multiplication_fdf(&table, 1.0 / 3.0, HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = init_fdf(&table, NULL, 1.0);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/window/zutomayo.out unit_test/editor/convolve/input_ascii/zutomayo_isometric2.txt

*/

/*
Yes. And there's an important detail in the Valgrind output:

 **What you pasted is not a leak report. It's an out-of-bounds write.**

 The smoking gun is:

```
Invalid write of size 4
...
Address 0x1744d040 is 0 bytes after a block of size 8,294,400 alloc'd
...
mlx_new_image
```

 So my first hypothesis would **not** be "you forgot a `free()` after optimizing Bresenham."

 It's:

 > **Your optimized line drawer is occasionally writing one pixel past the MLX image's allocated buffer.**

 And that could absolutely be caused by your line-drawing changes.

 ## Why this is particularly suspicious

 Valgrind says:

```
Address ... is 0 bytes after a block of size 8,294,400
```

 That means you're writing **exactly at the first byte after the allocation**.

 Since the invalid write is:

```
size 4
```

 and MLX pixels are 4 bytes (RGBA), this strongly suggests something like:

```
last valid pixel
        ↓
[ ... ][ RGBA ]
             ↑
             last valid byte

[ RGBA ]  ← you're writing here
             first byte AFTER allocation
```

 In other words, you're probably attempting something equivalent to:

```
mlx_put_pixel(image, WIDTH, y, color);
```

 when valid x coordinates are:

```
0 ... WIDTH - 1
```

 or similarly:

```
mlx_put_pixel(image, x, HEIGHT, color);
```

 when valid y coordinates are:

```
0 ... HEIGHT - 1
```

---

 ## And your optimization is a very plausible cause

 You recently changed the line drawing implementation.

 Your new loop is:

```
while (dst != NULL && line.p1.x <= line.p2.x)
{
    ...
    line.p1.x += 1;
}
```

 Notice the endpoint is **inclusive**.

 That's normally correct for Bresenham:

```
x1, x1+1, ..., x2
```

 But if `line.p2.x` can equal the image width:

```
x2 == WIDTH
```

 then you draw:

```
x = WIDTH
```

 which is one past the valid range.

 So I'd investigate the coordinates being passed to:

```
draw_horizontal_mlx()
```

 particularly the final coordinate.

---

 # There's another clue

 The stack says:

```
mlx_put_pixel
  ↓
draw_horizontal_mlx
  ↓
draw_circle
  ↓
draw_circle_fdf
  ↓
draw_line_fdf
```

 This is interesting.

 Your error isn't directly reported inside your new `bresenham_mlx_x_plus()`.

 It's occurring through:

```
draw_horizontal_mlx()
```

 inside:

```
draw_circle()
```

 So I wouldn't assume the Bresenham function itself is directly doing the bad write.

 Your optimization may have **changed the coordinates or boundary behavior upstream**, causing `draw_circle()` / `draw_horizontal_mlx()` to receive or generate a coordinate at the edge.

---

 ## I would debug it in this order

 ### 1\. Find your actual image dimensions

 If it's:

```
mlx_new_image(..., WIDTH, HEIGHT);
```

 then your valid coordinates are:

```
x: 0 <= x < WIDTH
y: 0 <= y < HEIGHT
```

 Not:

```
x <= WIDTH
y <= HEIGHT
```

 This is the classic C `0 ... len - 1` issue you were just talking about.

 ### 2\. Instrument `draw_horizontal_mlx()`

 Immediately before:

```
mlx_put_pixel(dst, x, y, color);
```

 temporarily add:

```
if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
{
    printf("BAD PIXEL: x=%d y=%d\n", x, y);
    abort();
}
```

 Use your actual image dimensions, of course.

 That will probably catch the problem immediately.

 ### 3\. Look especially at `WIDTH` / `HEIGHT`

 Given your earlier discussion about endpoint corrections, I'd pay particular attention to whether your optimized Bresenham now produces:

```
WIDTH
```

 instead of:

```
WIDTH - 1
```

 at an endpoint.

---

 # And there is a second possible issue

 You said:

 > "Now my program work faster dramatically"

 If your optimization changed the number of allocations, object lifetimes, or rendering callbacks, you could have a genuine lifetime bug too.

 But **this Valgrind output isn't showing that yet**.

 For a real leak, you'd expect something toward the end like:

```
LEAK SUMMARY:
    definitely lost: ...
    indirectly lost: ...
    possibly lost: ...
```

 What you've shown ends after the `Invalid write` reports.

 So first fix the invalid write.

 Then run:

```
valgrind --leak-check=full --show-leak-kinds=all ./...
```

 again and look specifically for:

```
LEAK SUMMARY
```

---

 ### One thing I would _not_ do

 Don't "fix" this by simply adding:

```
if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
```

 everywhere.

 You were just talking about removing unnecessary repeated checks for performance. 😄

 Instead, determine **why your geometry is producing an invalid coordinate**.

 If your architecture guarantees:

```
all rasterization coordinates ∈ [0, WIDTH) × [0, HEIGHT)
```

 then your inner pixel loop doesn't need to repeatedly defend itself.

 Your `boundary` mechanism suggests you may already have exactly that architectural layer. If so, the bug is likely that **one path (apparently the circle/horizontal drawing path) violates the boundary invariant after your optimization.**

 So my strongest hypothesis from this Valgrind trace is:

 > **Not a memory leak yet — an endpoint/bounds off-by-one bug, very possibly introduced by the optimized line/circle rasterization, causing `mlx_put_pixel()` to write exactly one pixel outside the image.**
*/