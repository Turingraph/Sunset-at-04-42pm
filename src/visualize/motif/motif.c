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
static void	raster_motif_circle(mlx_image_t *dst,
	const t_2d_polygon *polygon, t_ink32 ink, t_line boundary)
{
	size_t		i;
	t_line		line;
	t_2d_int	point;

	i = 0;
	while (dst != NULL && polygon != NULL && i < polygon->length)
	{
		line = define_motif_line(polygon->arr[i], polygon->arr[i], boundary);
		point.x = line.p1.x;
		point.y = line.p1.y;
		raster_circle(dst, point, ink, boundary);
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
static void	raster_motif_line(mlx_image_t *dst, const t_2d_polygon *polygon,
	t_ink32 ink, t_line boundary)
{
	size_t	i;
	t_line	line;

	i = 0;
	while (dst != NULL && polygon != NULL && i < polygon->length - 1)
	{
		line = define_motif_line(polygon->arr[i], polygon->arr[i + 1], boundary);
		raster_line(dst, line, boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL
		&& i == polygon->length - 1 && polygon->is_loop == true)
	{
		line = define_motif_line(polygon->arr[i], polygon->arr[0], boundary);
		raster_line(dst, line, boundary, ink);
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
static void	raster_motif_rectangle(mlx_image_t *dst,
	const t_2d_polygon *polygon, int32_t ink, t_line boundary)
{
	size_t	i;
	t_line	line;

	i = 0;
	while (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i < polygon->length - 1)
	{
		line = define_motif_line(polygon->arr[i], polygon->arr[i + 1], boundary);
		raster_rectangle(dst, line, boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i == polygon->length - 1
		&& polygon->is_loop == true)
	{
		line = define_motif_line(polygon->arr[i], polygon->arr[0], boundary);
		raster_rectangle(dst, line, boundary, ink);
	}
}

/**
 * Draw one motif instance inside a single tile.
 *
 * Each polygon in the motif is rendered.
 * The coordinates of the polygon are interpreted relative to the tile boundary.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param img MLX image receiving the rendered motif
 * @param src Islamic-art motif configuration containing motif data
 * @param tile screen-space boundary of the tile to render into
 */
static void	raster_motif_unit(mlx_image_t *img,
	t_islamic_art *src, t_line tile)
{
	size_t	i;
	t_motif	*arr;

	arr = src->motif->arr;
	i = 0;
	while (i < src->motif->length)
	{
		if (arr[i].shape_2d == E_LINE)
			raster_motif_line(img, &(arr[i].polygon), arr[i].ink, tile);
		else if (arr[i].shape_2d == E_CIRCLE)
			raster_motif_circle(img, &(arr[i].polygon), arr[i].ink, tile);
		else if (arr[i].shape_2d == E_RECTANGLE)
			raster_motif_rectangle(img, &(arr[i].polygon),
				arr[i].ink.color, tile);
		i += 1;
	}
}

/**
 * Draw the configured motif across the complete tile grid.
 *
 * The motif is rendered once for every tile in the grid. The complete tile
 * range is constructed from src->tiles.tile_counts and passed to the
 * internal tile-loop helper.
 *
 * This function provides the current non-interactive motif rendering API.
 * Camera control, panning, and unified FDF/motif interaction are intentionally
 * outside its scope and may be introduced by a future rendering layer.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param img MLX image receiving the rendered motif
 * @param src motif configuration containing the motif, tile format, and
 *            background configuration
 */
void	raster_motif(mlx_image_t *img, t_islamic_art *src)
{
	t_line		tile;
	int			ix;
	int			iy;

	if (is_islamic_art_valid(src) == false)
		return ;
	iy = 0;
	while (iy < src->tiles.tile_counts.y)
	{
		ix = 0;
		while (ix < src->tiles.tile_counts.x)
		{
			tile.p1 = init_tile_ith(src->tiles, ix, iy);
			tile.p2 = init_tile_ith(src->tiles, ix + 1, iy + 1);
			raster_motif_unit(img, src, tile);
			ix += 1;
		}
		iy += 1;
	}
}
