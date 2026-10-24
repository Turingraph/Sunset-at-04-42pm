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

#ifndef PROJ2D_H
# define PROJ2D_H

# include "../../utils/taylor/taylor.h"
# include "../../input/table/table.h"

/**
 * FDF object containing the 2D projected representation data of the 
 * t_fdf_table data.
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
typedef struct t_fdf_proj2d
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
}	t_fdf_proj2d;

// create.c

t_fdf_proj2d		create_fdf_proj2d(t_fdf_table *src,
				t_float2d (*proj2d)(float x, float y, float z),
				float scale);
t_fdf_proj2d		destroy_fdf_proj2d(t_fdf_proj2d *src);

// proj2d.c

t_float2d	proj2d_isometric(float x, float y, float z);
t_float2d	proj2d_military(float x, float y, float z);
t_float2d	proj2d_cabinet(float x, float y, float z);
t_float2d	proj2d_orthogonal(float x, float y, float z);
t_float2d	proj2d_wave(float x, float y, float z);

// utils.c

int32_t		rgba32_from_proj2d(const t_fdf_proj2d *src, size_t index);
bool		isvalid_fdf_proj2d(const t_fdf_proj2d *src);
void		scale_vector(float *update_v, float s, size_t dim);

#endif
