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

#ifndef RASTER_H
# define RASTER_H

# include "raster_type.h"

// circle.c

void		raster_circle(mlx_image_t *dst,
				t_2d_int point, t_raster_style raster_style, t_line boundary);

// color.c

int32_t		rgba32_from_char(unsigned char r,
				unsigned char g, unsigned char b, unsigned char a);
void		raster_color_background(mlx_image_t *dst, int32_t color);
int32_t		rgba32_from_table(const t_fdf_table *src, size_t index);

// line_generic.c

void		raster_line(mlx_image_t *dst,
				t_line line, t_line boundary, t_raster_style raster_style);

// utils.c

void		raster_rectangle(mlx_image_t *dst, t_line rectangle,
				t_line boundary, int32_t color);

#endif
