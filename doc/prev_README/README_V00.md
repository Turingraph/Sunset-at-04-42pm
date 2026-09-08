# Introduction

This project name as `GrASCIIfi` which is inspired by 42 Coding School, Graffiti art, ASCII art, 3D Typography, and my personal experience with Grapheme Color Synesthesia.

<!-- 
I plan to make fdf42, and I also add the feature that allow user to convert ASCII text (including Figlet output) as fdf42 input files, and display them as prism (with Z buffer) instead of isometric projection that looks like boring chocolate (as I see in original fdf42). The user can choose the origin of x and y on the tables of integers, also paint those prism with complex conformal map as rgba value on each cells, and use Gaussian convolution when they wish to do it and also save it as new fdf42 files. Also I plan to make it utilize mainly OpenGL/GLFW directly. The reason I do this is because I have grapheme color synesthesia, I never use Blender, and I want to show audience what is the color of alphabet and display it as 3D typography for pure artistic reason and as IT job portfolio. 

Moreover, I think I can use 3D typography as the symbolism of random thought when I meditate, or some random feeling that I try to be more aware. If I were to ordinate for a month in the future, I could mixing this Git repo with my personal experience with buddhism.

Another interesting idea is that I can also show the audience about my personal experience with how learning 3rd language and synesthesia experience interact with each other, if I have opportunity to learn 3rd language consistently.

Thing I already finish today which is flating every table of data as 1D array

Thing to do before Submission
1.	graphic/window/ (with only keyboard based UXUI)
2.	user tutorial and README.md
3.	fix some part of coding_examples/

easy painting feature
1.	outlier
2.	reflection (upside down)
3.	copy
4.	compression
5.	conformal
6.	line

coding_examples/
1.	editor/gauss_rgb.c
2.	editor/paint
3.	editor/mathart
4.	graphic/

Release First Stable Version
3.	graphic/rasterization/ with z buffer
4.	detvolve (determanent based image filtering) , matrix multiplication, and matrix determinant

Thing to do "after" the first stable version, to avoid scope creep.
1.	editor/mathart/derivative/
2.	editor/fractal/ (including Julia, Newton fractal etc.)
3.	mouse based UXUI and throttle
4.	Figlet in other languages and language specialized related features e.g. Thai, Japanese, Chinese, Arabic, conlang etc.
5.	synesthesia, language, meditation visualization, written conlang etc.
 -->

## What is GrASCIIfi ?

...
Unfinished.
...

## How to download GrASCIIfi

...
Unfinished.
...

## How to run GrASCIIfi

...
Unfinished.
...

# What is Fdf42 ?

This project is based on FdF42 which is 3D graphic 42 coding school assignment. The purpose of this assignment is to convert the `.fdf` files with the columns of integer to 3D isometric wireframe, and display it on 2D screen using XML42 library.

1st Example of `fdf` files: `pyramid.fdf`

```
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 5 5 5 5 5 5 5 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 6 6 6 6 6 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 7 7 7 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 9,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 7 7 7 7 7 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 6 6 6 6 6 6 6 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 5 5 5 5 5 5 5 5 5 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 4 4 4 4 4 4 4 4 4 4 4 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 2 1 0 0 0 0 0
0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 1 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```

2nd Example of `fdf` files: `elem.fdf`

```
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20 15 12 15 17 20 10  0
0 10 15 10 12 15 15 15 10  0
0  5 15 10 12 15 15 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```

Note that the i-th row, j-th column, and the integer number match with the 3D points of the 3D isometric wireframe.

FdF42 features
1.	Convert Fdf files as 3D wireframe, by using `./fdf [input file name].fdf` command. (for example `./fdf my_file.fdf`, `./fdf 10-70.fdf` etc.)
2.	User able to close 3D wireframe window frame by click `ESC` button and/or the cross on the window’s frame

## The Additional Features of GrASCIIfi.

I also add the additional features, including

1.	Input Handle (`src/input/`, this folder is responsible for both handle, copy, and editing both fdf and txt input file)
	1.	Support arbitrary `txt` files, in order to convert Figlet and/or other ASCII art file into FdF File using `input/`
	2.	Handle with `synesthesia.txt` using `synesthesia/`
2.	Input Editor (`src/editor/`, this folder is only responsible for editing and copy input fdf file)
	1.	Can color FdF files based on `paint/paint.c/paint_gradient_fdf(t_table_fdf *table, t_gradient *gradient, char direction);` function where `gradient` including 1st color, 2nd color, 1st x position, 2nd x position, and `direction` choose one out of 3 Axises.
	2.	Can blur FdF files using convolution from `convolution/`
3.	Graphic Command
	1.	`--z_buffer` command allow user to do Z Buffer calculation, so the only surface of the object that are in front of another surface will be shown accordingly, and the color is based on the angle between cross project vector of 2D triangles, and the light vector.
	2.	`--prism` so the 3D model will looks like prism instead of chocolate as seen in most FdF project.
	3.	`--double_faces` sp the 3D model will have 2 faces.
	4.	`--triangle` to display isometric 3D model with triangle meshes line and without Z buffer calculation.
	5.	`--z_buffer --triangle` display 3D object as Z buffer object and draw the triangle line (without Z buffer) line on top of the Z buffer object.
	6.	`--triangle --z_buffer` display 3D object as Z buffer object with the surface triangle line.
	7.	`--z_buffer --isometric` display 3D object as Z buffer object and draw the isometric line (without Z buffer) line on top of the Z buffer object.
	8.	`--isometric --z_buffer` display 3D object as Z buffer object with the surface isometric line.
4.	Quaternion Rotation
	1.	quaternion rotation of 3D object and light source. (I have to design how user specify the rotation of the 3D object and light source later)
5.	Color
	1.	User can define the color of the 3D Object as follow
	*	`--rgb_object` = color of 3B object (default is `#FFFFFF`)
	*	`--rgb_shadow` = color of the shadow of 3D object (default is `#000000`)
	*	`--rgb_background` = color of the background (default is `#000000`)
	*	`--rgb_triangle` = color of the triangle mesh line (default is `#FFFFFF`)
	*	`--rgb_isometric` = color of the triangle mesh line (default is `#FFFFFF`)
	2.	If the color of FdF input file is defined but the alpha channel isn't specified, then the color in that region overwrite the global color.
	3.	If the color of FdF input file and the alpha channel (`a`) are defined, then the color of that region is defined as `f_round((1 - (a/255)) * global_rgb + (a/255) * local_rgb)`.
6.	Grapheme Color Synesthesia Inspired Feature
	1.	Display 3D input text when use `./fdf "Hello World"` base on FIGlet style ASCII files input (`text/a.txt`, `text/b.txt`, etc.). If there is no target files, then return the error.
	2.	`--Adir` option to specify which folder that have `dir/synesthesia.txt`, `dir/a.fdf`, `dir/b.fdf` etc. to include for `./fdf "Goodbye Mars"` input. The default input of `--Adir` is `text/`
	3.	`dir/synesthesia.txt` as 2 to 5 column text, where 2nd, 3rd, 4th, and 5th must be 8 digits Hexadecimal strings.
	*	1st column (optional) = character e.g. `a`, `A`, `1`, `;` etc.
	*	2nd column (not optional if 1st column exists) = color of that characters.
	*	3rd column (optional, default is `000000FF`) = color of the shadow of that characters
	*	4th column (optional, default is `FFFFFFFF`) = color of the triangle line of that characters.
	*	5th column (optional, default is `FFFFFFFF`) = color of the isometric line of that characters.
	4.	When display `./fdf "string"`, the "global" color of each characters are `a * first_char + (1 - a) * current_char` where `a=` last 2 digits of the color of the first character as specified in `dir/synesthesia.txt`
	5.	All string in `dir/synesthesia.txt` after `#` and before `\n` is treated as comment.
	6.	If `dir/synesthesia.txt` do not specify the color of the specific characters e.g. a, $ etc. then that character will have `FFFFFFFF` as default color.
	7.	Both `.fdf` and `dir/synesthesia.txt` are case insensitive.

Example of `dir/synesthesia.txt`

```
a ff000055
b 0000ff55
c ffff0055
...
z 4e4736FF
# This is comment. You can also use `dir/synesthesia.txt` without writing comment.
```

Limitation of GrASCIIfi in the current version.
1.	Support only English Language Alphabets, empty space (a.k.a. ` `), decimal number `0-9`, and another 14 printable ASCII characters.
2.	No `\n` (a.k.a. new line) and `\t` (a.k.a. taps).
3.	Not compatible with Blender and no every other features from future features list.
4.	Focus mainly about 3D typography and Grapheme color synesthesia related feature.
5.	Not support small characters. Every user's English alphabet input will be treated as it is capital letters.
<!-- 6.	Cannot rotate multiple alphabets in different direction -->

Beside 0-9 and a-z, this project support only 14 special characters.

```
ampersand.txt      &
at_sign.txt        @
dollar.txt         $
percent.txt        %
plus.txt           +
minus.txt          -
equal.txt          =
dot.txt            .
comma.txt          ,
exclamation.txt    !
question.txt       ?
left_paren.txt     (
right_paren.txt    )
slash.txt          /
```

The other characters are treated as empty space (a.k.a. ` `).

Future Features
1.	Shell
	*	Allow the user to manipulating `fdf` and `txt` files and running `./fdf` more smoothly with MiniShell42 inspired interactive Shell via `src/shell/` instead of editing fdf files via C scripts and/or manually.
2.	Language Specific Feature and color alphabet base on its phoneme.
	*	Support other some languages based 3D typography e.g. Thai, Japanese, Arabic, famous conlang, user defined conlang etc.
	*	Might helps some language learner study languages as subplement learning resource, by color each alphabets based on the pronunciation of the word.
3.	Convert 3D model to Blender compatible file
4.	Add Gen AI model for generating background
5.	React Typescript based User Friendly Frontend
6.	More ways to paint FdF file e.g. draw pixel art style circle, apply 2D FFT for more convolution, apply Flood fill Algorithm to color FdF file etc.
7.	Allow user to make 3D Typography DaVinci Resolve user friendly animations e.g. rotating text, moving text, zoom text, etc.

## Folder Structure

1.	`build/`
*	object files
2.	`examples/`
*	demonstrate how to use this Git repo
3.	`lib/`
*	library
4.	`src/`
*	C files
5.	`test/`
*	testing files

# How am I use LLM ?

I use LLM to brainstorm the synesthesia related features, guide me on writing Makefile, and other tasks. For examples, ChatGPT recommend me to use `wildcard`. However, every C programming and Makefile files is 100% written by me.

## How am I use LLM for designing choice ?

1.	LLM recommended me to use Figlet for ASCII typography art font.
2.	LLM said that my project also related to MiniRT42.
3.	LLM recommended me to use another 14 special characters for the first stable version of GrASCIIfi.
4.	LLM recommended me to study Japanese, Chinese, and/or Arabic as third language (that isn't Indo European e.g. English, German, Franch etc. and/or Kra–Dai languages e.g. Thai, Lao etc. and have rich interesting writing system, also my mother tongue is Thai language).
5.	LLM recommended me to create `THIRD_PARTY_LICENSES.md` and `LICENSE` (`GrASCIIfi` use Apeche license) in root directory for crediting Figlet properly and ethically.

## Consult with ChatGPT No.1: Dynamic Array vs Linked List for loading input.

LLM said that I should use dynamic array for fdf input file instead of linked list for saving more space.

## Consult with ChatGPT No.2: Array of Struct vs Array of Pointer

Also LLM warn me to use array of struct over array of pointer of struct for performance reason.

According to StackOverflow ( https://stackoverflow.com/questions/42328735/array-of-structs-vs-array-of-pointers-to-structs ).

Pros of Array of Pointer
1.	You can use the last `NULL` to specify the length of array.
2.	ith `NULL` means the ith item is missing
3.	chaning the order of elements by moving pointers.
4.	You can define multiple elements as the pointer of the same element.

Cons of Array of Pointer
1.	allocating and freeing this indirect array is more cumbersome. 
2.	waste more memory than Array of struct.
3.	access i-th item slower than Array of struct.

It is note that triangles mesh in typical computer graphic does not utilize the pros of array of Pointer at all. So I have to refactor it as Array of struct instead.

## Consult with ChatGPT No.3: The Sum of Convolution should be 1

I asked LLM to check if my convolution output is correct or not, it warned me that the sum of convolution kernel should equal to 1 or else the brightness of the color will change unexpectedly.

## Consult with ChatGPT No.4: ASCII art shading

I want to convert Figlet text data as 3D geometric model, so I have to convert each printable characters as an integer.

I research about the standard shading of ASCII art from this Stackoverflow post ( https://stackoverflow.com/questions/30097953/ascii-art-sorting-an-array-of-ascii-characters-by-brightness-levels-c-c ), and it turn out that there are 70 ASCII characters ```$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'.``` for ASCII shading, which cannot deal with some printable characters from `NHRD96KAPgeESGVF54y32T7=s` string. In addition, the approach from Stackoverflow does not consider the case where characters have same brightness and are the mirror of each other e.g. `p` and `q`, `b`, and `d`, `/` and `\`, `[` and `]` etc.

LLM said that there is no standard way to rank the brightness of all 95 characters that also catagorizing the pair of mirror characters.

So I create `ascii_shading/version_01/` which contains my personal subjective ranking. Which contains 4 following files
1.	`ascii_shading/version_01/mirror.txt` (list of the mirror characters)
2.	`ascii_shading/version_01/cheche_design.txt` (my subjective 95 ASCII characters brightness ranking)
3.	`ascii_shading/version_01/standard.txt` (my subjective 95 ASCII characters brightness ranking that align with 70 standard ASCII shading characters)
4.	`ascii_shading/version_01/chungaloider_design.txt` (Chungaloider's 95 ASCII characters brightness ranking on Stackoverflow question 30097953)

`ascii_shading/version_01` also contains other following 2 folders
1.	`ascii_shading/version_01/examples/` (my own simple ASCII art examples txt files)
2.	`ascii_shading/version_01/cheche_design/` (my own thinking process of how I rank the brightness of all 95 printable ASCII characters for `ascii_shading/version_01/cheche_design.txt`)

I might ranks the brightness of the characters e.g. `a`, `B`, `ห`, `พ`, `ไ`, `\`, etc. based on other metrics e.g. counting dark Pixel, counting the standard deviation of dark pixel of each characters from different fonts, FFT/ML related technique etc. in the future. and/or I might treat each string individual characters as a chunk of multiple small triangles meshes.

## Consult with ChatGPT No.5: 1D Array is Faster.

ChatGPT warn me to use 1D array over 2D array when deal with large input. Several Stackoverflow from this post ( https://stackoverflow.com/questions/17259877/1d-or-2d-array-whats-faster ) also recommend everyone to use 1D over 2D array because 1D array is faster (because calculating `arr[col * i + j]` is faster than calculate `arr[i][j]` when `arr` is dynamic array) and use less memory (because there computer do not have to use extra space for pointer of the pointer). However, both 1D static array and 2d static array use equal amount of time and space to operate for the same task. The only reason to use 2D array over 1D array is when deal with static array, small size input data, and for making debugging easier.

However, my `t_table_fdf` use 2D array for reducing debugging difficulty.

```
typedef struct t_table_fdf t_table_fdf;

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				**arr;
	unsigned char	**r;
	unsigned char	**g;
	unsigned char	**b;
	unsigned char	**a;
};
```

In addition, it might be possible that many if not most future users would likely convert small Figlet input data ( https://www.figlet.org/ ), like this

```
                          .   oooo         o8o           
                        .o8   `888         `"'           
 .ooooo.  oooo d8b    .o888oo  888 .oo.   oooo   .oooo.o 
d88' `88b `888""8P      888    888P"Y88b  `888  d88(  "8 
888   888  888          888    888   888   888  `"Y88b.  
888   888  888          888 .  888   888   888  o.  )88b 
`Y8bod8P' d888b         "888" o888o o888o o888o 8""888P' 
```

as 16 times larger and apply 5x5 Gaussian convolution, or do something similar to this without deal with lots of input data.

## Consult with ChatGPT No.6: `src/input/load/` likely too slow.

...

# Resource

1.	Computer Graphic pipeline
	1.	How Real Time Computer Graphics and Rasterization work
	*	https://youtu.be/brDJVEPOeY8?si=Tt-vaGcUnZng1LDp
	2.	Array of Struct vs Array of Pointer
	*	https://stackoverflow.com/questions/42328735/array-of-structs-vs-array-of-pointers-to-structs
	3.	Visualizing the 4d numbers Quaternions
	*	https://youtu.be/d4EgbgTm0Bg?si=wdYcMB8PoKzabdQJ
	4.	Interesting New Algorithm
	*	https://youtu.be/B9bztU1sTFA?si=WPThJWzQgdAkDBSi
2.	import MXL42 library
	1.  MLX42
	*   https://github.com/codam-coding-college/MLX42#download-and-build---mlx42
	2.  `-I`, `-L`, and `-l` option for `cc` command
	*   https://stackoverflow.com/questions/519342/what-is-the-difference-between-i-and-l-in-makefile
	3.  Pthread
	*   https://www.reddit.com/r/explainlikeimfive/comments/1jwix0w/eli5_what_are_threads_in_operating_system/
	*   https://stackoverflow.com/questions/15127279/whats-a-pthread
	4.  Static linking vs dynamic linking
	*	https://stackoverflow.com/questions/1993390/static-linking-vs-dynamic-linking
	5.	Install OpenGL on Ubuntu
	*	https://stackoverflow.com/questions/7842622/setting-up-opengl-on-ubuntu
	6.	Install X11 on Ubuntu.
	*	https://askubuntu.com/questions/1167278/how-to-install-x11-development-libraries-on-ubuntu-19-04
	7.	RandR headers not found; install libxrandr development package error
	*	https://github.com/openMVG/openMVG/issues/85
	8.	Install GLFW
	*	https://stackoverflow.com/questions/17768008/how-to-build-install-glfw-3-and-use-it-in-a-linux-project
	*	https://www.glfw.org/docs/latest/compile.html#compile_deps_wayland
3.	Makefile
	1.	Makefile Tutorial
	*	https://makefiletutorial.com/
	2.	Wildcard in Makefile
	*	https://stackoverflow.com/questions/11184389/what-does-wildcard-mean-in-makefile
	3.	ar on an existing .a file?
	*	https://stackoverflow.com/questions/4318906/ar-on-an-existing-a-file
	4.	Recursive wildcard.
	*	https://stackoverflow.com/questions/2483182/recursive-wildcards-in-gnu-make
	5.	Mkdir nested folder
	*	https://stackoverflow.com/questions/66781722/make-nested-directories-and-files-with-linux
	6.	Makefile Mkdir
	*	https://stackoverflow.com/questions/1950926/create-directories-using-make-file
	7.	Rm directory and everything in it.
	*	https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
4.	Typography
	1.	Figlet
	*	https://textarttools.com/Figletfontstool/
	2.	Figlet License
	*	https://github.com/cmatsuoka/figlet/blob/master/LICENSE
	3.	Figlet Font Database
	*	https://www.figlet.org/cgi-bin/fontdb.cgi
	4.	Including third party license
	*	https://www.reddit.com/r/reactjs/comments/1mri80d/best_practice_for_including_thirdparty_licenses/
	5.	ASCII Art gradient
	*	https://paulbourke.net/dataformats/asciiart/
	6.	Render 3D model as ASCII Art (I might read this later for the future version of GrASCIIfi)
	*	https://alexharri.com/blog/ascii-rendering
	*	https://www.reddit.com/r/PlotterArt/comments/1qfzhzt/ascii_characters_are_not_pixels_a_deep_dive_into/
	7.	The concept of Ambigram seem very interesting for designing new Figlet font for my future project!
	*	https://en.wikipedia.org/wiki/Ambigram
5.	Convolution
	1.	But what is a convolution?
	*	https://youtu.be/KuXjwB4LzSA?si=5538Gr5xpS-cfLwV
	2.	Gaussian Blur implementation
	*	https://stackoverflow.com/questions/1696113/how-do-i-gaussian-blur-an-image-without-using-any-in-built-gaussian-functions
	3.	Convolution demonstration on Wikipedia
	*	https://en.wikipedia.org/wiki/Kernel_(image_processing)#/media/File:2D_Convolution_Animation.gif
	4.	Implementing floor function
	*	https://stackoverflow.com/questions/41856771/write-your-own-implementation-of-maths-floor-function-c
	5.	Newton Method for approximating root
	*	https://youtu.be/-RdOwhmqP5s?si=HZMppRY9tGm3OjL-
	6.	Taylor Series for approximating e^x
	*	https://youtu.be/eX1hvWxmJVE?si=9jQUq-r2TJ8hPvIb
	*	https://mathworld.wolfram.com/TaylorSeries.html
6.	Software testing tool
	1.	Valgrind
	*	https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks
	2.	Get Next Line Tester
	*	https://github.com/Tripouille/gnlTester
	3.	Random Hex Generator
	*	https://www.browserling.com/tools/random-hex
7.	Synesthesia
	1.	I spent a day with SYNESTHETES (Neurological condition aka SYNESTHESIA) 
	*	https://youtu.be/lP58G70QmpA?si=L086y0idPJ9W9uyV
	2.	A simple yet impossible test
	*	https://youtu.be/-hc29pbzM1A?si=P2j8dik4Lz00w28V
	3.	Born On A Blue Day: Inside the Extraordinary Mind of an Autistic Savant
	*	https://www.amazon.com/Born-Blue-Day-Extraordinary-Autistic/dp/1416549013
8.	Git (`git reset HEAD~`)
	1.	Undo Last Git commit.
	*	https://stackoverflow.com/questions/927358/how-do-i-undo-the-most-recent-local-commits-in-git
	2.	Solve "Updates were rejected because the tip of your current branch is behind"
	*	https://stackoverflow.com/questions/39399804/updates-were-rejected-because-the-tip-of-your-current-branch-is-behind-its-remot

<!-- 
I plan to make fdf42, and I also add the feature that allow user to convert ASCII text (including Figlet output) as fdf42 input files, and display them as prism (with Z buffer) instead of isometric projection that looks like boring chocolate (as I see in original fdf42). The user can choose the origin of x and y on the tables of integers, also paint those prism with complex conformal map as rgba value on each cells, and use Gaussian convolution when they wish to do it and also save it as new fdf42 files. Also I plan to make it utilize mainly OpenGL/GLFW directly. The reason I do this is because I have grapheme color synesthesia, I never use Blender, and I want to show audience what is the color of alphabet and display it as 3D typography for pure artistic reason and as IT job portfolio. 
Moreover, I think I can use 3D typography as the symbolism of random thought when I meditate, or some random feeling that I try to be more aware. If I were to ordinate for a month in the future, I could mixing this Git repo with my personal experience with buddhism.
Another interesting idea is that I can also show the audience about my personal experience with how learning 3rd language and synesthesia experience interact with each other, if I have opportunity to learn 3rd language consistently.
What is the genre of this type of content ?
-->
