/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:07:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:18:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "motif_private.h"

// time : O(1)
// space: O(1)
bool	is_islamic_art_valid(const t_islamic_art *src)
{
	if (src == NULL || src->motif == NULL
		|| src->motif->arr == NULL || src->motif->length == 0
		|| src->tiles.tile_counts.x * src->tiles.tile_counts.y == 0
		|| src->tiles.tile_size == 0)
		return (false);
	return (true);
}

/**
 * Convert a 2D normalized floating-point coordinate to a 2D integer coordinate.
 * 
 * The source value is clamped to [0, 1] for both real and imaginary part,
 * and scaled to the size of the
 * selected boundary dimension.
 * 
 * The returned coordinate is relative to the boundary origin. This allows
 * the caller to apply the boundary offset separately and prevents the
 * boundary origin from being added more than once.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: internal helper
 * 
 * @param src normalized coordinate to convert
 * @param boundary target rectangular boundary
 * @return converted integer coordinate relative to the boundary origin
 */
t_2d_int	normal_complex_to_2d_int(t_complex src, t_line boundary)
{
	t_complex	normal;
	t_2d_int	dst;

	normal.re = f_interval(src.re, 0, 1);
	normal.im = f_interval(src.im, 0, 1);
	dst.x = (int)f_floor(normal.re * (boundary.p2.x - boundary.p1.x));
	dst.x += boundary.p1.x;
	dst.y = (int)f_floor(normal.im * (boundary.p2.y - boundary.p1.y));
	dst.y += boundary.p1.y;
	return (dst);
}

/**
 * Convert two normalized complex-plane points into a 2D integer line
 * within the specified boundary. The real component is mapped to the
 * x dimension and the imaginary component to the y dimension. The
 * resulting coordinates are translated by the boundary origin.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param point_1 first normalized complex point
 * @param point_2 second normalized complex point
 * @param boundary target rectangular boundary
 * @return integer line mapped to the boundary
 */
t_line	init_float_line(t_complex point_1, t_complex point_2,
	t_line boundary)
{
	t_line	dst;

	dst.p1 = normal_complex_to_2d_int(point_1, boundary);
	dst.p2 = normal_complex_to_2d_int(point_2, boundary);
	return (dst);
}
