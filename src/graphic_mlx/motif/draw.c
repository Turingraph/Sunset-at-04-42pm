/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:16:19 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 13:26:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "motif_private.h"

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
static void	draw_motif_mlx_unit(mlx_image_t *img,
	t_islamic_art *src, t_line tile)
{
	size_t	i;
	t_motif	*arr;

	arr = src->motif->arr;
	i = 0;
	while (i < src->motif->length)
	{
		if (arr[i].type == E_LINE)
			draw_polygon_unittile(img, &(arr[i].polygon), arr[i].ink, tile);
		else if (arr[i].type == E_CIRCLE)
			draw_circle_unittile(img, &(arr[i].polygon), arr[i].ink, tile);
		else if (arr[i].type == E_RECTANGLE)
			draw_rectangle_unittile(img, &(arr[i].polygon),
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
void	draw_motif_mlx(mlx_image_t *img, t_islamic_art *src)
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
			tile.p1 = get_ith_tile_screen(src->tiles, ix, iy);
			tile.p2 = get_ith_tile_screen(src->tiles, ix + 1, iy + 1);
			draw_motif_mlx_unit(img, src, tile);
			ix += 1;
		}
		iy += 1;
	}
}
