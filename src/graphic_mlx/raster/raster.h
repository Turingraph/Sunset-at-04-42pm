/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:33:51 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 17:35:09 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTER_H
# define RASTER_H

# include "../../utils/green_counts/green_counts.h"
# include "../../utils/libft/libft.h"
# include "MLX42.h"

/**
 * a pair of integer (x, y) for representing a 2D point, 2D coordinate,
 * and/or the size of row and column of t_table_fdf.
 */
typedef struct s_2d_int
{
	int	x;
	int	y;
}	t_2d_int;

/**
 * Line segment between two 2D integer coordinates.
 *
 * p1 and p2 represent the two endpoints of the 2D line segment.
 */
typedef struct s_line
{
	t_2d_int	p1;
	t_2d_int	p2;
}	t_line;

/**
 * Describes the rendering properties of a 2D motif or FDF drawing.
 * 
 * color stores the 32-bit drawing color. type determines how the associated
 * geometry or FDF data is rendered. thickness controls the size of the
 * rendered primitive where applicable.
 * 
 * @param color 32-bit drawing color
 * @param thickness size parameter used by the selected rendering type
 */
typedef struct s_ink32
{
	int32_t		color;
	size_t		thickness;
}	t_ink32;

// color.c

int32_t		f_rgba_to_int32(unsigned char r,
				unsigned char g, unsigned char b, unsigned char a);
void		color_background_mlx(mlx_image_t *dst, int32_t color);
int32_t		get_table_rgba_int32(const t_table_fdf *src, size_t index);

// line_generic.c

void		draw_line_generic(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);

// line_x.c

void		draw_endpoint(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);
void		draw_line_thick_x_plus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);
void		draw_line_thick_x_minus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);

// line_y.c

void		draw_line_thick_y_plus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);
void		draw_line_thick_y_minus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);

// shape.c

t_line		init_rectangle(t_line src, t_line boundary);
void		draw_rectangle(mlx_image_t *dst, t_line rectangle,
				t_line boundary, int32_t ink);
void		draw_circle(mlx_image_t *dst,
				t_2d_int point, t_ink32 ink, t_line boundary);

// utils.c

bool		is_in_boundary(int x, int y, t_line boundary);

#endif
