*This project has been created as part of the 42 curriculm by phsottat.*

# Description

This project is based on FdF42 which is 3D graphic 42 coding school assignment. The purpose of this assignment is to convert the `.fdf` files with the columns of integer to 3D isometric wireframe (let's call it as "Fdf object"), and display it on 2D screen using XML42 library.

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
3.  The program won't works if the fdf input is invalid.

## Additional Feature

1.  User can pan, zoom, and reset interactive hook.
2.  User can change the renderer style of Fdf object by setting the line thickness, drawing style, and background color via `t_artstyle32` struct arguments.
3.  User can change the projection style e.g. Isometric projection, Cabinet projection etc.
4.  User can color each cell of Fdf object based on its height, rgba channels, and row and/or column position.
5.  There are other features that will mentioned in this Git repo. (https://github.com/Turingraph/Sunset-at-04-42pm). Note that the rotation hook isn't supported yet.

# Instructions

In order to run the program, you can
1.  `make`
2.  `./fdf maps/[some user input file].fdf`

Note that
*   The Fdf object won't displayed if the file have invalid number, file isn't accessible, and/or file isn't exists.
*   You can close delete the binary file by `make clean`
*   You can close delete the binary file and the program file by `make fclean`
*   You can rebuild all of the binary file by `make re`

# How am I use LLM ?

LLM helps me write document and I check and edit its output accordingly.

The LLM recommend me some common good software engineering practice.

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

## Consult with ChatGPT No.3: 1D Array is Faster.

ChatGPT warn me to use 1D array over 2D array when deal with large input. Several Stackoverflow from this post ( https://stackoverflow.com/questions/17259877/1d-or-2d-array-whats-faster ) also recommend everyone to use 1D over 2D array because 1D array is faster (because calculating `arr[col * i + j]` is faster than calculate `arr[i][j]` when `arr` is dynamic array).

So I change this

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

to this.

```
typedef struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
}	t_table_fdf;
```

# Resources

1.  Fdf Guide
*   https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc
2.  How to use MLX42?
*   https://github.com/codam-coding-college/MLX42
3.  What is .SECONDEXPANSION in Makefile
*   https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile
*   https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
4.  Type of parallel projection
*   https://en.wikipedia.org/wiki/Parallel_projection#/media/File:Comparison_of_graphical_projections.svg
5.  Line Drawing algorithm
*   https://youtu.be/CceepU1vIKo?si=lJwQ-ujIfeobgLU2
6.  Circle drawing algorithm
*   https://youtu.be/hpiILbMkF9w?si=L_WBY0tV6aWe99qc
7.  Get Next Line Tester
*   https://github.com/Tripouille/gnlTester
8.  Makefile string manipulation manual
*   https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_node/make_79.html
