# Description

This project name as `Sunset at 4.42pm`. It is inspired by 42 Coding School, Graffiti art, ASCII art, Calligraphy art, Figlet, Linear Algebra, and my personal experience with grapheme color synesthesia.

Synesthesia is the neutral traits that make someone experience consistent experience when sense something e.g. see the color and/or taste the smell of sound, alphabet characters, personality etc. Everyone who have synesthesia experience synesthesia differently, for example Jane might feel that D is blue while Jone feel that D is red etc. Grapheme color synesthesia is the sub category of synesthesia that make a person feel that each written characters have its own color. 

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

Note that people with grapheme color synesthesia often feel that the smaller and the bigger letters have the same color, but sometimes there is some exception. In my case, I feel that q is pink, but Q is gold yellow.

This project is named as `Sunset at 4.42pm`, because it is inspired by 42 Coding School, and 42 reminds me of sunset at 4.42pm.

## What is Fdf42 ?

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

