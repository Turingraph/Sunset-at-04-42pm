/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:08:15 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 17:17:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "motif_private.h"

/**
 * Draw a circle at each vertex of a 2D polygon.
 *
 * Each polygon vertex is converted to a pixel coordinate within the
 * specified boundary and rendered as a filled circle. The polygon edges
 * are not drawn.
 *
 * time/space: O(n * r^2) / O(1)
 *
 * status: internal helper
 *
 * @param dst destination MLX image
 * @param polygon source 2D polygon whose vertices are rendered
 * @param ink drawing style containing the circle color and radius
 * @param boundary drawing boundary used to position and clip the circles
 */
void	draw_circle_unittile(mlx_image_t *dst,
	const t_2d_polygon *polygon, t_ink32 ink, t_line boundary)
{
	size_t		i;
	t_line		line;
	t_2d_int	point;

	i = 0;
	while (dst != NULL && polygon != NULL && i < polygon->length)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[i], boundary);
		point.x = line.p1.x;
		point.y = line.p1.y;
		draw_circle(dst, point, ink, boundary);
		i += 1;
	}
}

/**
 * Draw the edges of a 2D polygon.
 *
 * Each consecutive pair of polygon vertices is converted to a line
 * and rendered using the specified drawing style. When is_loop is
 * enabled, the final vertex is also connected back to the first vertex.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param dst destination MLX image
 * @param polygon source 2D polygon whose edges are rendered
 * @param ink drawing style containing the line color and thickness
 * @param boundary drawing boundary used to position and clip the polygon
 */
void	draw_polygon_unittile(mlx_image_t *dst, const t_2d_polygon *polygon,
	t_ink32 ink, t_line boundary)
{
	size_t	i;
	t_line	line;

	i = 0;
	while (dst != NULL && polygon != NULL && i < polygon->length - 1)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[i + 1], boundary);
		draw_line_generic(dst, line, boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL
		&& i == polygon->length - 1 && polygon->is_loop == true)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[0], boundary);
		draw_line_generic(dst, line, boundary, ink);
	}
}

/**
 * Draw polygon edges as rectangular strokes.
 *
 * Each consecutive pair of polygon vertices is converted to a line and
 * rendered as a filled rectangle. When is_loop is enabled, the final
 * vertex is also connected to the first vertex.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param dst destination MLX image
 * @param polygon source 2D polygon whose edges are rendered
 * @param ink 32-bit RGBA color used to draw the edges
 * @param boundary drawing boundary used to position and clip the edges
 */
void	draw_rectangle_unittile(mlx_image_t *dst,
	const t_2d_polygon *polygon, int32_t ink, t_line boundary)
{
	size_t	i;
	t_line	line;

	i = 0;
	while (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i < polygon->length - 1)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[i + 1], boundary);
		draw_rectangle(dst, line, boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i == polygon->length - 1
		&& polygon->is_loop == true)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[0], boundary);
		draw_rectangle(dst, line, boundary, ink);
	}
}
