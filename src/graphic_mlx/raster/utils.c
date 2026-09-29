/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 13:40:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 14:28:54 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster_private.h"

/**
 * This function is used for checking if x and y position is in the boundary.
 * Note that user can use t_line for defining the boundary.
 * However, the boundary.p2 should be considered as a pair of point that
 * outside the boundary.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param window_width width of the camera viewport
 * @param window_height height of the camera viewport
 * @return initialized 2D camera
 */
bool	is_in_boundary(int x, int y, t_line boundary)
{
	if (x >= boundary.p1.x
		&& x < boundary.p2.x
		&& y >= boundary.p1.y
		&& y < boundary.p2.y)
		return (true);
	return (false);
}

/**
 * Define the rectangle/point within the given area.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param src the rectangle area (which is defined by 2 pairs of integers
 * as x_min, y_min --> x_max, y_max)
 * @param boundary the area that contains src rectangle.
 */
t_line	init_rectangle(t_line src, t_line boundary)
{
	t_line	dst;

	dst.p1.x = f_interval_int(f_min_int(src.p1.x, src.p2.x),
			boundary.p1.x, boundary.p2.x - 1);
	dst.p2.x = f_interval_int(f_max_int(src.p1.x, src.p2.x),
			boundary.p1.x, boundary.p2.x - 1);
	dst.p1.y = f_interval_int(f_min_int(src.p1.y, src.p2.y),
			boundary.p1.y, boundary.p2.y - 1);
	dst.p2.y = f_interval_int(f_max_int(src.p1.y, src.p2.y),
			boundary.p1.y, boundary.p2.y - 1);
	return (dst);
}

/**
 * Fill a rectangular area with a color.
 *
 * The rectangle is restricted to the specified drawing boundary before
 * each pixel within the resulting area is filled with the given color.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param dst destination MLX image
 * @param rectangle rectangular area to fill
 * @param boundary drawing boundary used to restrict the rectangle
 * @param ink 32-bit RGBA color used to fill the rectangle
 */
void	draw_rectangle(mlx_image_t *dst, t_line rectangle,
	t_line boundary, int32_t ink)
{
	int	i;
	int	j;

	rectangle = init_rectangle(rectangle, boundary);
	i = rectangle.p1.x;
	while (i <= rectangle.p2.x)
	{
		j = rectangle.p1.y;
		while (j <= rectangle.p2.y)
		{
			mlx_put_pixel(dst, i, j, ink);
			j += 1;
		}
		i += 1;
	}
}
