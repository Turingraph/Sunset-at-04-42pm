/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:13:49 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 12:42:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

/**
 * Apply a 3D linear transformation to one FDF point.
 *
 * The transformation matrix must contain 9 elements representing a 3x3
 * matrix. The selected axis is calculated from the corresponding matrix
 * row.
 * 
 * The point at index i is read from the FDF object's current position
 * arrays. This helper does not modify the source object.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param src FDF object containing the point coordinates
 * @param matrix 3x3 linear transformation matrix
 * @param i index of the point to transform
 * @param axis transformed coordinate to return: 0 for X,
 * 1 for Y, 2 or other input for Z
 * @return transformed coordinate, or 0.0 when the input is invalid
 */
float	linear_map_fdf(const t_fdf *src, t_matrix matrix, size_t i, char axis)
{
	float	output;
	float	*m;
	float	*x;
	float	*y;
	float	*z;

	if (is_fdf_valid(src) == false
		|| matrix.col * matrix.row != 9
		|| matrix.arr == NULL)
		return (0.0);
	m = matrix.arr;
	x = src->pos_x;
	y = src->pos_y;
	z = src->pos_z;
	output = x[i] * m[0] + y[i] * m[1] + z[i] * m[2];
	if (axis == 0)
		return (output);
	output = x[i] * m[3] + y[i] * m[4] + z[i] * m[5];
	if (axis == 1)
		return (output);
	output = x[i] * m[6] + y[i] * m[7] + z[i] * m[8];
	return (output);
}

/**
 * Apply a 3D linear transformation to every point in an FDF object.
 *
 * The transformation matrix must contain 9 elements representing a 3x3
 * matrix. The X, Y, and Z position arrays of the FDF object are replaced
 * by their transformed coordinates.
 *
 * This function modifies the FDF object in place. It is therefore suitable
 * for applying rotations, scaling, reflections, shearing, or other 3D
 * linear transformations before rendering.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param src FDF object whose point coordinates are transformed
 * @param matrix 3x3 linear transformation matrix
 */
void	linear_map_fdf_all(t_fdf *src, t_matrix matrix)
{
	size_t	i;

	if (is_fdf_valid(src) == false
		|| matrix.col * matrix.row != 9
		|| matrix.arr == NULL)
		return ;
	i = 0;
	while (i < src->src->row * src->src->col)
	{
		src->pos_x[i] = linear_map_fdf((const t_fdf *)src, matrix, i, 0);
		src->pos_y[i] = linear_map_fdf((const t_fdf *)src, matrix, i, 1);
		src->pos_z[i] = linear_map_fdf((const t_fdf *)src, matrix, i, 2);
		i += 1;
	}
}

// time : O(1)
// space: O(1)
t_2d_int	world_3d_to_screen_2d(t_2d_camera camera,
	float x, float y)
{
	t_2d_int	dst;

	dst.x = x + (camera.offset.x + camera.window_size.x) / 2;
	dst.y = y + (camera.offset.y + camera.window_size.y) / 2;
	return (dst);
}
