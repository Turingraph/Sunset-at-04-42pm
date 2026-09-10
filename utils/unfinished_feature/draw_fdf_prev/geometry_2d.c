/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:01:37 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 17:04:58 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// time : O(1)
// space: O(1)
bool	is_line_in_screen(t_2d_camera camera,
	t_line src)
{
	if ((0 > src.p1.x && 0 > src.p2.x)
		|| (camera.window_size.x < src.p1.x && camera.window_size.x < src.p2.x)
		|| (0 > src.p1.y && 0 > src.p2.y)
		|| (camera.window_size.y < src.p1.y && camera.window_size.y < src.p2.y))
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_circle_in_screen(t_2d_camera camera,
	t_2d_int src, int radius)
{
	if (-1 * radius <= src.x
		&& src.x <= camera.window_size.x + 0 + radius
		&& -1 * radius <= src.y
		&& src.y <= camera.window_size.y + radius)
		return (true);
	return (false);
}

/**
 * Retrieve a transformed coordinate from an FDF point.
 *
 * The point is selected from the FDF position arrays according to
 * the requested dimension. The optional next selector retrieves the
 * coordinate of the next point on the X or Y axis.
 *
 * NEXT VALUE of next
 *
 * - 0 uses the current FDF point.
 *
 * - 1 moves to the next point on the X axis.
 *
 * - 2 moves to the next point on the Y axis.
 * 
 * - 3 move to the next point on both X and Y axises.
 *
 * DIMENSION VALUE of dim
 *
 * - 1 returns the X coordinate.
 *
 * - 2 returns the Y coordinate.
 *
 * - Any other value returns the Z coordinate.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api (unchecked)
 *
 * @param fdf FDF object containing transformed point coordinates
 * @param ixiy X/Y index of the FDF point
 * @param dim coordinate dimension to retrieve
 * @param next selects the current point or the next point on an axis
 * @return transformed coordinate of the selected FDF point
 */
float	get_fdf_point(t_fdf *fdf, t_2d_int ixiy, size_t dim, char next)
{
	if (is_fdf_valid(fdf) == false)
		return (0.0);
	if (next == 1 || next == 3)
		ixiy.x += 1;
	if (next == 2 || next == 3)
		ixiy.y += 1;
	if (dim == 1)
		return (fdf->x[ixiy.y * fdf->src->col + ixiy.x]);
	if (dim == 2)
		return (fdf->y[ixiy.y * fdf->src->col + ixiy.x]);
	return (fdf->pos_z[ixiy.y * fdf->src->col + ixiy.x]);
}
