/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:33:51 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 13:44:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTER_PRIVATE_H
# define RASTER_PRIVATE_H

# include "raster_type.h"

// circle.c

t_line		init_circle_line(t_2d_int point, int ix,
				int iy, char mode);
void		raster_line_horizontal(mlx_image_t *dst, t_line line,
				int32_t color, t_line boundary);
void		raster_circle(mlx_image_t *dst,
				t_2d_int point, t_ink32 ink, t_line boundary);

// color.c

int32_t		int32_from_rgba(unsigned char r,
				unsigned char g, unsigned char b, unsigned char a);
void		raster_color_background(mlx_image_t *dst, int32_t color);
int32_t		int32_from_rgbafdf(const t_fdf_table *src, size_t index);

// line_generic.c

void		raster_line(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);

// line_x.c

void		raster_linex_minus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);
void		raster_linex_plus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);

// line_y.c

void		raster_liney_minus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);
void		raster_liney_plus(mlx_image_t *dst,
				t_line line, t_line boundary, t_ink32 ink);

// utils.c

bool		is_in_boundary(int x, int y, t_line boundary);
void		raster_rectangle(mlx_image_t *dst, t_line rectangle,
				t_line boundary, int32_t ink);

#endif
