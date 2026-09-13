/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:59:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:50:53 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../raster/raster.h"
# include "../../utils/linalg/linalg.h"
# include "../../input/table/table.h"

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

// init.c

t_fdf		init_fdf(t_table_fdf *src,
				t_complex (*projection)(float x, float y, float z),
				float scale);
t_fdf		free_fdf(t_fdf *src);

// projection.c

t_complex	projection_isometric(float x, float y, float z);
t_complex	projection_military(float x, float y, float z);
t_complex	projection_cabinet(float x, float y, float z);
t_complex	projection_orthogonal(float x, float y, float z);
t_complex	projection_wave(float x, float y, float z);

// utils.c

int32_t		get_fdf_rgba_int32(const t_fdf *src, size_t index);
bool		is_fdf_valid(const t_fdf *src);

#endif
