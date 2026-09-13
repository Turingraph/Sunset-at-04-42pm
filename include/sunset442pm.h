/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunset442pm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:31:33 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 15:03:11 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUNSET442PM_H
# define SUNSET442PM_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42.h"

/* ************************************************************************** */
/* src/utils/type/type.h */
/* ************************************************************************** */

/**
 * Identifies the data component stored in a t_table_fdf array.
 *
 * - RED selects the red color component.
 *
 * - GREEN selects the green color component.
 *
 * - BLUE selects the blue color component.
 *
 * - ALPHA selects the alpha color component.
 *
 * - HEIGHT selects the height (arr, Z) component.
 */
typedef enum t_fdf_channel
{
	RED,
	GREEN,
	BLUE,
	ALPHA,
	HEIGHT
}	t_fdf_channel;

/**
 * Stores the height and optional RGBA color components of an FDF table.
 *
 * The table contains row * col cells. arr stores the height value of
 * each cell, while r, g, b, and a store its corresponding color
 * components.
 *
 * The arrays use the same linear indexing scheme, where the cell at
 * position (x, y) is stored at index y * col_count + x.
 *
 * @param row number of rows in the FDF table
 * @param col number of columns in the FDF table
 * @param arr array containing the height values of each FDF cell
 * @param r array containing the red color component of each cell
 * @param g array containing the green color component of each cell
 * @param b array containing the blue color component of each cell
 * @param a array containing the alpha color component of each cell
 */
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

/**
 * Sometimes t_complex is used for describing 2D xy position.
 * @param re correspond to x axis position.
 * @param im correspond to y axis position.
 */
typedef struct t_complex
{
	float	re;
	float	im;
}	t_complex;

/* ************************************************************************** */
/* *** src/input/table/ *** */
/* ************************************************************************** */

/**
 * Free and reset the t_table_fdf array
 *
 * time/space: O(1) / O(1)
 * 
 * status: public api
 *
 * @param src the target t_table_fdf array
 */
void			free_table_fdf(t_table_fdf *src);

/**
 * Define t_table_fdf as array with only 0.
 *
 * time/space: O(n) / O(n)
 * 
 * status: public api
 *
 * @param row row of the target table (corresponding to y position)
 * @param col row of the target table (corresponding to x position)
 * @param is_rgba if true, allocate storage for the RGBA channels;
 * if false, only the height channel is allocated.
 * 
 * @return array with only 0 as t_table_fdf with specified rows and columns.
 */
t_table_fdf		init_table_fdf(size_t row, size_t col, bool is_rgba);

/**
 * Get either the minimum or maximum number from src.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param src the input t_table_fdf array
 * @param is_max if is_max == true, then return maximum number, 
 * else return minimum number.
 * @param channels RGBA channel to inspect
 * 
 * @return minimum or maximum integer based on the input.
 */
int				get_minmax_from_table_fdf(const t_table_fdf *src,
					bool is_max, t_fdf_channel channel);

/**
 * Adding some number, such that every number in t_table_fdf become positive.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst the input t_table_fdf array
 */
void			scale_positive_fdf(t_table_fdf *dst);

/**
 * Making all number that in an interval between minimum target number
 *  and maximum target number equal to the expected number
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst the input t_table_fdf array
 * @param min the minimum target number
 * @param max the maximum target number
 * @param expect the expected number
 */
void			scale_relu_fdf(t_table_fdf *dst, int min, int max, int expect);

/**
 * Load target file as t_table_fdf 5 rgba and height integer array data.
 *
 * time/space: O(n) / O(n)
 * 
 * @param file_name the input file
 * @param dir the directory of the input file
 * @param one_line loading style, including parse_ascii_line_standard for
 * loading file as ASCII art, parse_fdf_line_rgba as colorful Fdf file etc.
 * @param is_rgba if is_rgba == true, then the program using malloc 
 * for initializing rgba color.
 * @return return the array that contains rgba and height of the height map.
 * @see src/input/load/parse.c
 */
t_table_fdf		open_table_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*one_line)(char *line), bool is_rgba);

/**
 * Scale an RGBA channel by duplicating its rows and columns.
 * 
 * If src == NULL or src do not contains the target color,
 *  this function will return the array with 0 as the default instead.
 *
 * time/space: O(row * s_row * col * s_col) / O(row * s_row * col * s_col)
 *
 * @param src source FDF table
 * @param s_row row scaling factor
 * @param s_col column scaling factor
 * @param rgba_type RGBA channel to scale
 * @return scaled channel array, or NULL on failure
 */
unsigned char	*scale_dimension_fdf_rgba(const t_table_fdf *src,
					size_t s_row, size_t s_col, t_fdf_channel rgba_type);

/**
 * Scale an HEIGHT channel by duplicating its rows and columns.
 *
 * time/space: O(row * s_row * col * s_col) / O(row * s_row * col * s_col)
 *
 * @param src source FDF table
 * @param s_row row scaling factor
 * @param s_col column scaling factor
 * @return scaled height integer array, or NULL on failure
 */
int				*scale_dimension_fdf_int(const t_table_fdf *src,
					size_t s_row, size_t s_col);

/**
 * Scale an FDF table by duplicating its rows and columns.
 *
 * time/space: O(row * scale_row * col * scale_col) /
 * O(row * scale_row * col * scale_col)
 *
 * @param src source FDF table
 * @param scale_row row scaling factor
 * @param scale_col column scaling factor
 * @return scaled FDF table, or an empty table on failure
 */
t_table_fdf		scale_dimension_fdf(const t_table_fdf *src,
					size_t scale_row, size_t scale_col);

/**
 * Multiply each selected FDF channel by scale.
 *
 * time/space: O(n) / O(1)
 * 
 * @param dst FDF table to modify
 * @param scale multiplication factor
 * @param channel channel to modify
 */
void			scale_multiplication_fdf(t_table_fdf *dst,
					float scale, t_fdf_channel channel);

/**
 * Add input to each value in the selected FDF channel.
 *
 * time/space: O(n) / O(1)
 * 
 * @param dst FDF table to modify
 * @param input value to add
 * @param channel channel to modify
 */
void			scale_addition_fdf(t_table_fdf *dst,
					int input, t_fdf_channel channel);

/**
 * Add the selected channel of src to dst element by element.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to add
 */
void			table_fdf_addition(t_table_fdf *dst,
					const t_table_fdf *src, t_fdf_channel channel);

/**
 * Multiply the selected channel of dst by src element by element.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to multiply
 */
void			table_fdf_hadamard(t_table_fdf *dst,
					const t_table_fdf *src, t_fdf_channel channel);

/**
 * Copy the channel from source FDF table to the dst FDF table.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to copy
 */
void			copy_table_fdf_channel(t_table_fdf *dst,
					const t_table_fdf *src, t_fdf_channel channel);

/**
 * Write an FDF channel using the Cheche01 ASCII ramp.
 *
 * time/space: O(n) / O(n)
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param channel channel to convert
 */
void			write_table_ascii_cheche01(int fd,
					const t_table_fdf *src, t_fdf_channel channel);

/**
 * Write an FDF channel using the standard ASCII ramp.
 *
 * time/space: O(n) / O(n)
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param channel channel to convert
 */
void			write_table_ascii_standard(int fd,
					const t_table_fdf *src, t_fdf_channel channel);

/**
 * Write an FDF channel using the Chungaloider ASCII ramp.
 *
 * time/space: O(n) / O(n)
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param channel channel to convert
 */
void			write_table_ascii_chungaloider(int fd,
					const t_table_fdf *src, t_fdf_channel channel);

/**
 * Write an FDF table to a file descriptor.
 *
 * time/space: O(n) / O(1)
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param digits number of digits for height values
 * @param mode output format
 */
void			write_table_fdf(int fd,
					const t_table_fdf *src, size_t digits, t_write_style mode);

/* ************************************************************************** */
/* *** src/editor/convolve/ *** */
/* ************************************************************************** */

/**
 * Apply a convolution kernel to HEIGHT channels.
 * 
 * The kernel must be a square matrix with odd dimensions (e.g. 3x3, 5x5).
 * For each pixel, the kernel is centered on that pixel. Samples outside
 * the source image are clamped to the nearest edge pixel.
 * 
 * If kernel is NULL, an average kernel will be utilized instead.
 *
 * time/space: O(n * m^2) / O(n)
 * 
 * status: public api (unchecked)
 *
 * @param src source FDF table
 * @param kernel convolution kernel.
 * @param dim the dimension (number of row and column) of the square kernel.
 * If dim is even, then dim = dim + 1. If dim is less than 3, then dim = 3.
 * The dimension should be odd number.
 * @return FDF table
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 * for more details
 */
t_table_fdf	convolve_fdf(const t_table_fdf *src, float *kernel,
				size_t dim);

/**
 * Create a 2D Blur Gaussian kernel from two 1D Gaussian kernels.
 *
 * time/space: O(n^2) / O(n^2)
 *
 * @param half_dim half the kernel width. If half_dim is less than 1,
 * then the return output will have dimension equal to 3.
 * @param std_1 standard deviation for the first dimension
 * @param std_2 standard deviation for the second dimension
 * @return generated Gaussian kernel as array of float,
 * with (2 * half_dim + 1) * (2 * half_dim + 1) items.
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 *  for more details
 */
float	*gaussian_kernel(size_t half_dim, float std_1, float std_2);

/* ************************************************************************** */
/* *** src/editor/evenodd/ *** */
/* ************************************************************************** */

/**
 * Check whether the number of iterations of a binary-search procedure
 * is odd when searching for the rounded magnitude of a cell's complex
 * coordinate within the table's diagonal-length range.
 *
 * The coordinate magnitude is used as the search target, while the
 * rounded diagonal length of the table is used as the upper bound.
 *
 * time/space: O(log(n)) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the binary-search iteration count is odd,
 * false otherwise.
 */
bool	is_binary_search_length_odd(const t_table_fdf *dst, size_t index);

/**
 * Check whether the number of iterations of a binary-search procedure
 * is odd when searching for the absolute product of a cell's rounded
 * real and imaginary coordinates within the table's cell-count range.
 *
 * The search target is:
 *
 *     |round(Re(z)) * round(Im(z))|
 *
 * and the upper bound is the total number of cells in the table.
 *
 * time/space: O(log(n)) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the binary-search iteration count is odd,
 * false otherwise.
 */
bool	is_binary_search_product_odd(const t_table_fdf *dst, size_t index);

/**
 * Check whether the maximum point of a cell's magnitude's Collatz sequence,
 * divided by 7, is odd.
 *
 * time/space: O(s, where s is less than 10000) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool	is_collatz_odd_length(const t_table_fdf *dst, size_t index);

/**
 * Check whether the maximum point of the Collatz sequence generated
 * from the product of a cell's coordinate components, divided by 7,
 * is odd.
 *
 * time/space: O(s, where s is less than 10000) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool	is_collatz_odd_product(const t_table_fdf *dst, size_t index);

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether Re(z')^2 - Im(z')^2 produces an odd integer.
 *
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating the value
 *
 * @return true if the rounded calculated value is odd,
 * false otherwise.
 */
bool	is_re2_diff_im2_odd_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a));

/**
 * Compute z' = the complex coordinate of the cell.
 * Then check whether Re(z')^2 - Im(z')^2 produces an odd integer.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the rounded calculated value is odd,
 * false otherwise.
 */
bool	is_re2_diff_im2_odd(const t_table_fdf *dst, size_t index);

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time : O(1)
 * space: O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating its magnitude
 *
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
bool	is_oddlength_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a));

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time : O(1)
 * space: O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
bool	is_oddlength(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the square of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_oddlength_square(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the cube of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_oddlength_cube(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the sin of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_oddlength_sin(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the cos of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_oddlength_cos(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of exponential of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_oddlength_exp(const t_table_fdf *dst, size_t index);

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the squared cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_re2_diff_im2_square(const t_table_fdf *dst, size_t index);

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the cubed cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_cube(const t_table_fdf *dst, size_t index);

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the sin of the cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_sin(const t_table_fdf *dst, size_t index);

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the cos of the cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_cos(const t_table_fdf *dst, size_t index);

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the exponent of the cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_exp(const t_table_fdf *dst, size_t index);

/* ************************************************************************** */
/* *** src/editor/paint/ *** */
/* ************************************************************************** */

/**
 * Defines a color input for t_gradient argument of the function `color_cells_gradient`
 * 
 * If the color channel is less than 0, then the color isn't render.
 */
typedef struct t_rgba
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_rgba;

typedef enum t_gradient_channel
{
	D7_RED,
	D7_GREEN,
	D7_BLUE,
	D7_ALPHA,
	D7_ROW,
	D7_COL,
	D7_HEIGHT
}	t_gradient_channel;

/**
 * Defines a color gradient over a selected cell property.
 *
 * cell_channel selects the property used to determine the gradient position.
 * input_start and input_end define the affected range.
 * rgba_start and rgba_end define the colors at the range boundaries.
 */
typedef struct t_gradient
{
	t_rgba				rgba_start;
	t_rgba				rgba_end;
	t_gradient_channel	cell_channel;
	int					input_start;
	int					input_end;
}	t_gradient;

/**
 * Check whether a cell is considered empty
 * (the integer height of the cell less than or equal to 0).
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the cell contains a value less than or equal to 0,
 * false otherwise.
 */
bool		is_space_fdf(const t_table_fdf *dst, size_t index);

/**
 * Check whether a cell is located on the boundary of the table
 * or is adjacent to an empty cell.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the cell is a positive value located on the table
 * boundary or adjacent to an empty cell, false otherwise.
 */
bool		is_boundary_fdf(const t_table_fdf *dst, size_t index);

/**
 * Check whether a cell belongs to the chess pattern.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the cell position belongs to the chess pattern,
 * false otherwise.
 */
bool		is_chess_fdf(const t_table_fdf *dst, size_t index);

/**
 * Apply a color or height value to the selected channel of every cell.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 * @param color color or height value to apply. The color value is
 * clamped to the range [0, 255].
 * @param channel selected color or height channel
 * @param is_filtered_cell optional callback used to select which cells
 * are modified. If NULL, every cell is modified.
 */
void		set_cells_color(t_table_fdf *dst, int color, t_fdf_channel channel,
				bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index));

/**
 * Apply a color gradient to cells within an input range.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 * @param gradient_input gradient definition
 * @param is_overwrite replace existing colors instead of blending
 */
void		color_cells_gradient(t_table_fdf *dst,
				t_gradient gradient_input, bool is_overwrite);

/**
 * Set each cell to the Euclidean distance of its standard coordinates.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 */
void		setcells_pythagorus_length(t_table_fdf *dst);

/**
 * Set each cell to the square root of the product of its standard
 * complex coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 */
void		setcells_times_length(t_table_fdf *dst);

/**
 * Set each cell to the sum of its standard
 * complex coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 */
void		setcells_addition_length(t_table_fdf *dst);

/**
 * Set each cell to the maximum of its standard coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 */
void		setcells_maximum_length(t_table_fdf *dst);

/**
 * Set each cell to the minimum of its standard coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * @param dst FDF table to modify
 */
void		setcells_minimum_length(t_table_fdf *dst);

/* ************************************************************************** */
/* *** src/graphic_mlx/fdf/ *** */
/* ************************************************************************** */

/**
 * FDF object containing the 2D projected representation data of the 
 * t_table_fdf data.
 * 
 * @param r the red channel of each FdF cell.
 * @param g the green channel of each FdF cell.
 * @param b the blue channel of each FdF cell.
 * @param a the alpha channel of each FdF cell.
 * @param row the numbers of all row of the FdF object which correlated to the y axis.
 * @param col the numbers of all column of the FdF object which correlated to the x axis.
 * @param x x coordinates for each FDF cell according to the 2D projected representation.
 * @param y y coordinates for each FDF cell according to the 2D projected representation.
 * @param width current width of the transformed FDF object, for scaling the Fdf object
 * with the suitable scaling factor relative to the window height and width.
 */
typedef struct s_fdf
{
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
	size_t			row;
	size_t			col;
	float			*x;
	float			*y;
	float			width;
}	t_fdf;

/**
 * Release all resources owned by an FDF object.
 *
 * This function frees the source fdf data.
 *
 * view_fdf() does not call free_fdf(). The caller therefore remains
 * responsible for releasing an FDF object created by init_fdf().
 *
 * Calling free_fdf() with NULL is safe.
 * 
 * The return data is NULL fdf data.
 *
 * time/space: O(1) /  O(1)
 *
 * @param src FDF object to release
 */
t_fdf	free_fdf(t_fdf *src);

/**
 * Initialize a FDF object from a t_table_fdf table.
 *
 * The returned FDF object owns the 2D position arrays of each cells of t_table_fdf,
 * based on the 2D projection of the table (determined by 2D projection
 * argument e.g. projection_isometric, projection_military etc.
 * ). If the projection is NULL,
 * then this function return the simple orthogonal projection of t_table_fdf.
 *
 * This function use the color of t_table_fdf table,
 * instead of deep copy and/or shallow copy the color of t_table_fdf table, for
 * preventing double free issues and preventing using too many malloc than needed.
 *
 * The future version of this program will support 3D related features e.g.
 * quaternion rotation, 3D collision detection etc. but not now for the sake of development simplicity.
 * 
 * time/space: O(n) / O(n)
 *
 * @param src source table containing the FDF data
 * @param projection the functional pointer for define the projection of
 * t_table_fdf as t_fdf.
 * @param scale for scaling Fdf object.
 * @return initialized t_fdf object.
 * @see src/graphic_mlx/fdf/projection.c
 */
t_fdf	init_fdf(t_table_fdf *src,
	t_complex (*projection)(float x, float y, float z), float scale);

/**
 * Apply an isometric projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using an isometric projection. The x and y coordinates contribute to both
 * the horizontal and vertical components, while z affects the vertical
 * component.
 *
 * formula:
 * - x' = 0.866 * x - 0.866 * y
 * - y' = 0.5 * x + 0.5 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_isometric(float x, float y, float z);

/**
 * Apply a military projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using a military projection. The x and y coordinates contribute equally
 * to the horizontal and vertical components, while z affects the vertical
 * component.
 *
 * formula:
 * - x' = 0.707 * x - 0.707 * y
 * - y' = 0.707 * x + 0.707 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_military(float x, float y, float z);

/**
 * Apply a cabinet projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using a cabinet projection. The x coordinate is preserved horizontally,
 * while the y coordinate contributes to both horizontal and vertical
 * components. The z coordinate affects the vertical component.
 *
 * formula:
 * - x' = x - 0.353 * y
 * - y' = 0.707 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_cabinet(float x, float y, float z);

/**
 * Apply an orthogonal projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * by preserving the x coordinate as the horizontal component and combining
 * the y and z coordinates into the vertical component.
 *
 * formula:
 * - x' = x
 * - y' = y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_orthogonal(float x, float y, float z);

/**
 * Apply a wave projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * by applying a cosine wave based on the x coordinate to the z coordinate.
 * The resulting value is combined with the y coordinate to produce the
 * vertical component.
 *
 * formula:
 * - x' = x - 0.353 * y
 * - y' = z * f_cos(x) + y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_wave(float x, float y, float z);

/* ************************************************************************** */
/* *** src/graphic_mlx/display/ *** */
/* ************************************************************************** */

/*
 * This control how to display Fdf object.
 * It is based on the name of my favorite creators.
 * 
 * E_PICASSO = straight line
 * E_TOBY_FOX = Pixel art inspired grids
 * E_TUYOKI = Pixel art inspired grids (sometimes smaller than Toby Fox's grid)
 * E_KUSAMA = circle
 * E_EULER = E_PICASSO + E_KUSAMA = graph (without hole)
 * E_POINCARE = donut (circle with hole)
 * E_DIJKSTRA = E_POINCARE + E_EULER = network (same as Euler but have hole)
 * E_PIET_MONDRIAN = 4 rectangles on each cells
 * E_WARHOL = E_TOBY_FOX + E_PICASSO
 * E_HIROHIKO_ARAKI = E_TOBY_FOX + E_DIJKSTRA (inspired by Jojo's Stand)
 */
typedef enum t_art_style
{
	E_PICASSO,
	E_TOBY_FOX,
	E_TUYOKI,
	E_KUSAMA,
	E_EULER,
	E_POINCARE,
	E_DIJKSTRA,
	E_PIET_MONDRIAN,
	E_WARHOL,
	E_HIROHIKO_ARAKI,
}	t_art_style;

/*
 * This struct control the drawing style of the Fdf.
 */
typedef struct s_render_style
{
	int32_t		background_color;
	size_t		line_thickness;
	t_art_style	artist;
}	t_render_style;

/* ************************************************************************** */
/* *** src/graphic_mlx/window/ *** */
/* ************************************************************************** */

/**
 * Display an FDF object in an interactive 1920x1080 MLX window.
 *
 * The FDF object is scaled to fit the viewing area.
 * The drawing style controls how the FDF object is
 * rendered (setting line thickness, background color,
 * and rendering style inspired by famous creators).
 *
 * The view supports interactive manipulation through the registered
 * FDF keyboard controller.
 *
 * Available keyboard input is handled by hook_fdf_controller(), including
 * 
 * - "ESC" = close the MLX window
 * 
 * - "Q" = reset FDF object
 * 
 * - "Left", "Right", "Up", "Down" = Panning the
 * FDF Object on 2D screen accordingly.
 * 
 * - "9" = Zoom in
 * 
 * - "0" = Zoom out
 *
 * time/space: O(n) / O(n)
 *
 * @param fdf FDF object to display.
 * The default color of the FDF object is black.
 * @param artstyle style used to render the FDF object.
 */
void	view_fdf(t_fdf *fdf, t_render_style artstyle);

/* ************************************************************************** */
/* *** src/graphic_mlx/window/ *** */
/* ************************************************************************** */

/**
 * 2D polygon represented by normalized coordinates.
 *
 * Each coordinate in arr must be within the range [0, 1]. The polygon
 * is scaled to the supplied drawing boundary when rendered, allowing
 * the same polygon to be reused across different areas and tile sizes.
 *
 * @param arr polygon vertices using normalized x and y coordinates
 * @param length number of vertices
 * @param is_loop connect the final vertex back to the first vertex
 */
typedef struct s_2d_polygon
{
	t_complex	*arr;
	size_t		length;
	bool		is_loop;
}	t_2d_polygon;

/**
 * Supported 2D motif and rendering types.
 * 
 * The type determines how the motif geometry or FDF data is interpreted
 * by the raster layer.
 * 
 * ENUM TYPE
 * 
 * - E_RECTANGLE draws rectangular geometry.
 * 
 * - E_CIRCLE draws circular geometry.
 * 
 * - E_LINE draws polygon edges as lines.
 * 
 */
typedef enum t_2d_shape
{
	E_RECTANGLE,
	E_CIRCLE,
	E_LINE,
}	t_2d_shape;

/**
 * Reusable 2D drawing motif composed of geometry and drawing properties.
 *
 * polygon provides the geometric data while ink describes how that geometry
 * should be rendered. A motif can therefore be reused with different
 * positions, transformations, or drawing operations.
 */
typedef struct s_motif
{
	t_2d_polygon	polygon;
	t_ink32			ink;
	t_2d_shape		type;
}	t_motif;

/**
 * Array of reusable 2D drawing motifs.
 *
 * A motif array represents a collection of independent drawing elements
 * that can be rendered together. It can be used to construct geometric or
 * line-based artwork such as Islamic patterns, Piet Mondrian-style
 * compositions, Kusama-inspired patterns, and other procedural drawings.
 */
typedef struct s_motif_arr
{
	t_motif	*arr;
	size_t	length;
}	t_motif_arr;

/**
 * Display a motif as a tiled 2D composition in an MLX window.
 *
 * Creates a 1920x1080 static MLX window, initializes the rendering image and tile
 * format, fills the image with the requested motif, and keeps the window
 * open until the MLX loop terminates.
 *
 * The motif coordinates are interpreted by the motif rendering system and
 * repeated according to the requested tile resolution.
 *
 * The caller retains ownership of the supplied motif array.
 *
 * time/space: O(n) / O(n)
 *
 * @param src motif array to render (as Islamic Art,
 * Kusama art, Piet Mondrian inspired art etc.)
 * @param background_color background colour of the rendered composition
 * @param resolution tile subdivision resolution (equal to or less than 10).
 * If the resolution more than 10, then resolution equal to 10, given that 1920 < 2^n when 10 < n
 * If the resolution is equal to 0, then there will be only 1 tile, given that 1 = 2^0.
 */
void	view_motif(t_motif_arr *src,
	int32_t background_color, size_t resolution);

#endif
