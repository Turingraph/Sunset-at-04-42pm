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
 * FDF object containing source data (t_table_fdf) and its transformed positions.
 * 
 * The source table stores the original FDF data. The position arrays
 * represent the coordinates used for rendering and may be modified by
 * transformations without changing the source table.
 * 
 * @param src source FDF table
 * @param pos_x transformed x coordinates for each FDF cell
 * @param pos_y transformed y coordinates for each FDF cell
 * @param pos_z transformed z coordinates for each FDF cell
 * @param matrix 3D transformation matrix associated with the object.
 * This matrix is used for undo every linear transformation
 * when user press "Q" button.
 * @param width current width of the transformed FDF object
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
