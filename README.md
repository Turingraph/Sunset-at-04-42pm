# Description

The project is named as Sunset at 4.42pm. It is used for displaying beautiful artistic 3D Wireframe image based on user text files and user customized graphic configuration.

...(I will put some image)...

## Table of Content

1.	Installation
2.	What is Fdf?
3.	Additional features
4.	Project Status
5.	Inspiration
6.	Additional resource

## Installation

First download and build MLX42 library (https://github.com/codam-coding-college/MLX42#download-and-build---mlx42)

```
git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build # build here refers to the outputfolder.
cmake --build build -j4 # or do make -C build -j4
```

...

## What is Fdf ?

This project is based on FdF42 which is 3D graphic 42 Coding School assignment. The purpose of this assignment is to convert the `.fdf` files with the columns of integer to 3D isometric wireframe, and display it on 2D screen using MLX42 library (https://github.com/codam-coding-college/MLX42/tree/master).

```
#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 200;
	dst.rgba_start.r = 70;
	dst.rgba_start.g = 75;
	dst.rgba_start.b = 113;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 124;
	dst.rgba_end.g = 213;
	dst.rgba_end.b = 199;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_artstyle32	style;

	if (len < 2 || f_strlen(str[1]) < 5
		|| str[1][f_strlen(str[1]) - 1] != 'f'
		|| str[1][f_strlen(str[1]) - 2] != 'd'
		|| str[1][f_strlen(str[1]) - 3] != 'f'
		|| str[1][f_strlen(str[1]) - 4] != '.')
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	if (table.col * table.row == 0)
	{
		write(1, "File might be invalid and/or Malloc returns NULL.\n", 51);
		free_table_fdf(&table);
		return (0);
	}
	style.background_color = f_rgba_to_int32(255, 255, 255, 255);
	style.line_thickness = 1;
	style.artists = E_PICASSO;
	color_cells_gradient(&table, init_gradient(), true);
	output = init_fdf(&table, projection_isometric, 0.5);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

./fdf input_examples/fdf/42.fdf
```

as this picture.

```

```

Note that the i-th row, j-th column, and the integer number match with the 3D points of the 3D isometric wireframe.

FdF42 features
1.	Convert Fdf files as 3D wireframe, by using `./fdf [input file name]` command. (for example `./fdf my_file.txt`, `./fdf 10-70.fdf` etc.)
2.	User able to close 3D wireframe window frame by click `ESC` button and/or the cross on the window’s frame

## Additional features

User can also convert `txt` file (including Figlet output), for examples `input_examples/convolve/zutomayo_isometric2.txt`

using this code

```
#include"window.h"

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
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	style.background_color = f_rgba_to_int32(0, 0, 0, 255);
	style.line_thickness = 1;
	style.artists = E_PICASSO;
	color_cells_gradient(&table, init_ztmy_studyme(), true);
	color_cells_gradient(&table, init_ztmy_timeleft(), true);
	scale_multiplication_fdf(&table, 1.0 / 3.0, HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = init_fdf(&table, projection_isometric, 1.0);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

./fdf input_examples/convolve/zutomayo_isometric2.txt
```

as this picture.

```

```

Additional features including
1.	Converting fdf file as txt file (where ` ` = 0, `'` = 2, ..., `@` = 80 depending on specific ASCII to number map) and vise versa.
2.	Painting each cells of the 3D Fdf wireframe based on its height, red, green, blue, alpha, x-axis, and/or y-axis value.
3.	Double the size of the 3D Fdf wireframe.
4.	Operating convolution on 3D Fdf wireframe's cell.
5.	User have 2 input parser mode for Fdf files and Txt files.
6.	User can choose parallel projection, including orthogonal projection, isometric projection, cabinet projection etc., background color, and other rendering style.

## Project Status

...

## Inspiration

This project name as `Sunset at 4.42pm`. It is inspired by 42 Coding School, Graffiti art, ASCII art, Calligraphy art, Figlet, Linear Algebra, and my personal experience with grapheme color synesthesia.

Synesthesia is a perceptual phenomenon that make someone experience consistent experience when sense something e.g. see the color and/or taste the smell of sound, alphabet characters, personality etc. Everyone who have synesthesia experience synesthesia differently, for example Jane might feel that D is blue while Jone feel that D is red etc. Grapheme color synesthesia is the sub category of synesthesia that make a person feel that each written characters have its own color. 

In my case, I feel that
1.	A = Red (as apple)
2.	B = Blue (as the color blue)
3.	C = Yellow (as some cat)
4.	D = orange yellow (as some dog)
5.	E = orange (as egg)
6.	F = sky blue (as some fish)
7.	G = purple (as some grape)
8.	H = brown (as some horse)
9.	I = white (sometimes, people who have synesthesia, experience the association between 2 senses without any obvious reason)
10.	J = bright yellow (as happy joker)
11.	K = blue purple
12.	L = orange yellow (as lion)
13.	M = dark green (as matcha)
14.	N = dark blue green (as natural forest)
15.	O = white
16.	P = pink (as the color pink)
17.	Q = yellow/gold
18.	R = purple pink
19.	S = bright green (as some snake)
20.	T = orange yellow (as tiger)
21.	U = light blue
22.	V = dark blue
23.	W = dark blue (as whale)
24.	X = black/dark gray
25.	Y = gray mixing with light purple
26.	Z = brown
27.	0 = white (as O)
28.	1 = black
29.	2 = light yellow as sunlight from 2pm
30.	3 = brown as chocolate drink in 3pm tea party.
31.	4 = orange as sunlight in 4pm
32.	5 = yellow orange as sunlight in 5pm
33.	6 = purple as the light of the sun, when the sun slowly disappear in 6pm
34.	7 = purple as the light of the sun, when the sun slowly disappear in 7pm
35.	8 = light sky blue (similar to F) as neon light in 8pm.
36.	9 = light purple (similar to Y) as older neon light in 9pm.

I often feel that the smaller and the bigger letters have the same color, but sometimes there is some exception for example, q is pink, but Q is gold yellow.

This project is named as `Sunset at 4.42pm`, because it is inspired by 42 Coding School and the number 42 reminds me of sunset at 4.42pm.

## Additional resource

1.	see doc/user_manual/ for more details about how to use this library.
2.	see doc/contribution/ for more details about how to contribute this coding project, the directory structure of this coding project, and the future features of the next version.
3.	see doc/note/ for more details about some development logs of this coding project.

Note that some input examples of this coding project is generated by Figlet (https://textarttools.com/Figletfontstool/).
