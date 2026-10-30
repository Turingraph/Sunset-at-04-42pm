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

/*
To Do Now (proj2d)
1.	t_double2d proj2d_(x, y, z) => t_double2d proj2d(x, y)
2.	create_fdf_proj2d(src, proj2d, scale) => create_fdf_proj2d(src, proj2d, is_normalize)
3.	scale_fdf_proj2d(src, scale_x, scale_y)
4.	rotate_fdf_proj2d(src, delta)

To Do Now (other)
1.	check fibonacci
*/

// create.c

t_fdf_proj2d	create_conformal_fdf_proj2d(t_fdf_table *src,
					t_double2d (*proj2d)(t_double2d a), float scale);
t_fdf_proj2d	create_fdf_proj2d(t_fdf_table *src,
					t_double2d (*proj2d)(t_double2d vec2d));
t_fdf_proj2d		destroy_fdf_proj2d(t_fdf_proj2d *src);

// proj2d.c

t_double2d	proj2d_isometric(t_double2d vec2d);
t_double2d	proj2d_military(t_double2d vec2d);
t_double2d	proj2d_cabinet(t_double2d vec2d);
t_double2d	proj2d_orthogonal(t_double2d vec2d);

// utils.c

int32_t		rgba32_from_proj2d(const t_fdf_proj2d *src, size_t index);
bool		isvalid_fdf_proj2d(const t_fdf_proj2d *src);
void		scale_vector(float *update_v, float s, size_t dim);
void		scale_fdf_proj2d(t_fdf_proj2d *dst, float scale_x, float scale_y);

#endif
