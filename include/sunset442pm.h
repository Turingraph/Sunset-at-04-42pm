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

/* ************************************************************************** */
/* *** src/utils/green_counts/green_counts.h *** */
/* ************************************************************************** */

// ... for projection and conformal map

/* ************************************************************************** */
/* *** src/input/table/ *** */
/* ************************************************************************** */

// init.c

void			free_table_fdf(t_table_fdf *src);
t_table_fdf		init_table_fdf(size_t row, size_t col, bool is_rgba);

// positive.c

int				get_minmax_from_table_fdf(const t_table_fdf *dst,
					bool is_max, t_enum_rgba channels);
void			scale_positive_fdf(t_table_fdf *dst);
void			scale_relu_fdf(t_table_fdf *dst, int min, int max, int expect);

// public.c

t_table_fdf		open_table_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*one_line)(char *line), bool is_rgba);

// scale_dimension.c

unsigned char	*scale_dimension_fdf_rgba(const t_table_fdf *src,
					size_t s_row, size_t s_col, t_enum_rgba rgba_type);
int				*scale_dimension_fdf_int(const t_table_fdf *src,
					size_t s_row, size_t s_col);
t_table_fdf		scale_dimension_fdf(const t_table_fdf *src,
					size_t scale_row, size_t scale_col);

// scale.c

void			scale_multiplication_fdf(t_table_fdf *dst,
					float scale, t_enum_rgba channel);
void			scale_addition_fdf(t_table_fdf *dst,
					int input, t_enum_rgba channel);
void			table_fdf_addition(t_table_fdf *dst,
					const t_table_fdf *src, t_enum_rgba channel);
void			table_fdf_hadamard(t_table_fdf *dst,
					const t_table_fdf *src, t_enum_rgba channel);

// shade.c

void			write_table_ascii_cheche01(int fd,
					const t_table_fdf *src, t_enum_rgba channel);
void			write_table_ascii_standard(int fd,
					const t_table_fdf *src, t_enum_rgba channel);
void			write_table_ascii_chungaloider(int fd,
					const t_table_fdf *src, t_enum_rgba channel);

// write.c

void			write_table_fdf(int fd,
					const t_table_fdf *src, size_t digits, t_write_style mode);

/* ************************************************************************** */
/* *** src/editor/paint/ *** */
/* ************************************************************************** */

typedef struct t_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
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

// gradient.c

void			color_cells_gradient(t_table_fdf *dst,
					t_gradient gradient_input, bool is_overwrite);


#endif
