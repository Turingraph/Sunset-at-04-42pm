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
typedef enum t_enum_rgba
{
	RED,
	GREEN,
	BLUE,
	ALPHA,
	HEIGHT
}	t_enum_rgba;

/**
 * Stores the height and optional RGBA color components of an FDF table.
 *
 * The table contains row * col cells. arr stores the height value of
 * each cell, while r, g, b, and a store its corresponding color
 * components.
 *
 * The arrays use the same linear indexing scheme, where the cell at
 * position (row, col) is stored at index row * col_count + col.
 *
 * status: public api
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
 * @param is_rgba if is_rgba is true, then using malloc saving more
 *  extra color (the initialized color is black).
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
int				get_minmax_from_table_fdf(const t_table_fdf *dst,
					bool is_max, t_enum_rgba channel);

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
 * status: public api
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
 * time/space: O(n^2) / O(n^2)
 *
 * status: public api
 *
 * @param src source FDF table
 * @param s_row row scaling factor
 * @param s_col column scaling factor
 * @param rgba_type RGBA channel to scale
 * @return scaled channel array, or NULL on failure
 */
unsigned char	*scale_dimension_fdf_rgba(const t_table_fdf *src,
					size_t s_row, size_t s_col, t_enum_rgba rgba_type);

/**
 * Scale an HEIGHT channel by duplicating its rows and columns.
 *
 * time/space: O(n^2) / O(n^2)
 *
 * status: public api
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
 * time/space: O(n^4)
 *
 * status: public api
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
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param scale multiplication factor
 * @param channel channel to modify
 */
void			scale_multiplication_fdf(t_table_fdf *dst,
					float scale, t_enum_rgba channel);

/**
 * Add input to each value in the selected FDF channel.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param input value to add
 * @param channel channel to modify
 */
void			scale_addition_fdf(t_table_fdf *dst,
					int input, t_enum_rgba channel);

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
					const t_table_fdf *src, t_enum_rgba channel);

/**
 * Multiply the selected channel of dst by src element by element.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to multiply
 */
void			table_fdf_hadamard(t_table_fdf *dst,
					const t_table_fdf *src, t_enum_rgba channel);

/**
 * Copy the channel from source FDF table to the dst FDF table.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to copy
 */
void			copy_table_fdf_channel(t_table_fdf *dst,
					const t_table_fdf *src, t_enum_rgba channel);

/**
 * Write an FDF channel using the Cheche01 ASCII ramp.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param channel channel to convert
 */
void			write_table_ascii_cheche01(int fd,
					const t_table_fdf *src, t_enum_rgba channel);

/**
 * Write an FDF channel using the standard ASCII ramp.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param channel channel to convert
 */
void			write_table_ascii_standard(int fd,
					const t_table_fdf *src, t_enum_rgba channel);

/**
 * Write an FDF channel using the Chungaloider ASCII ramp.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param channel channel to convert
 */
void			write_table_ascii_chungaloider(int fd,
					const t_table_fdf *src, t_enum_rgba channel);

/**
 * Write an FDF table to a file descriptor.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
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
 * If dim is odd, then dim = dim + 1. If dim is less than 3, then dim = 3.
 * The dimension should be odd number.
 * @return FDF table with the selected channels convolved
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
 * status: public api
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

...

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

typedef enum t_7cell_channels
{
	D7_RED,
	D7_GREEN,
	D7_BLUE,
	D7_ALPHA,
	D7_ROW,
	D7_COL,
	D7_HEIGHT
}	t_7cell_channels;

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
	t_7cell_channels	cell_channel;
	int					input_start;
	int					input_end;
}	t_gradient;

/**
 * Check whether a cell is considered empty
 * (the integer height of the cell less than or equal to 0).
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
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
 * status: public api
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
 * status: public api
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
 * status: public api
 *
 * @param dst FDF table to modify
 * @param color color or height value to apply. The color value is
 * clamped to the range [0, 255].
 * @param channel selected color or height channel
 * @param is_filtered_cell optional callback used to select which cells
 * are modified. If NULL, every cell is modified.
 */
void		set_cells_color(t_table_fdf *dst, int color, t_enum_rgba channel,
				bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index));

/**
 * Apply a color gradient to cells within an input range.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
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
 * status: public api
 *
 * @param dst FDF table to modify
 */
void		setcells_pythagorus_length(const t_table_fdf *dst);

/**
 * Set each cell to the square root of the product of its standard
 * coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void		setcells_times_length(const t_table_fdf *dst);

/**
 * Set each cell to the sum of its standard
 * coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void		setcells_addition_length(const t_table_fdf *dst);

/**
 * Set each cell to the maximum of its standard coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void		setcells_maximum_length(const t_table_fdf *dst);

/**
 * Set each cell to the minimum of its standard coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void		setcells_minimum_length(const t_table_fdf *dst);

#endif
