/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:23:56 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 12:52:22 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "motif_private.h"

/**
 * Initialize the screen-space area occupied by the complete tile grid.
 *
 * The tile grid is centered within the window. The returned line represents
 * the top-left and bottom-right corners of the area covered by all tiles.
 *
 * The tile size is derived from the fixed window dimension and the requested
 * resolution. Any unused space around the tile grid is distributed equally
 * as an offset on both sides.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param window_width width of the rendering window
 * @param window_height height of the rendering window
 * @param resolution tile subdivision resolution
 * @param fixed_length reference side length used to determine tile size
 *
 * @return line describing the centered tile-grid area in screen coordinates
 */
t_2d_int	init_offset_tile(size_t window_width, size_t window_height,
	size_t resolution, size_t fixed_length)
{
	t_2d_int	output;

	output.x = (float)init_alltiles_offset(window_width, resolution,
			fixed_length);
	output.y = (float)init_alltiles_offset(window_height, resolution,
			fixed_length);
	return (output);
}

/**
 * Initialize the tile-grid format used to repeat a motif across the window.
 *
 * The tile size is determined from the shorter window dimension and the
 * requested resolution. The number of tiles along each axis and the centered
 * offset of the complete tile area are calculated from that tile size.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param window_width width of the rendering window
 * @param window_height height of the rendering window
 * @param resolution tile subdivision resolution
 *
 * @return initialized tile-grid format
 */
t_tile_format	init_tile_format(size_t window_width,
	size_t window_height, size_t resolution)
{
	t_tile_format	dst;
	size_t			fixed_side;

	fixed_side = (size_t)f_min((float)window_width, (float)window_height);
	dst.offset = init_offset_tile(window_width, window_height,
			resolution, fixed_side);
	dst.tile_size = (float)init_tile_size(fixed_side, resolution);
	dst.tile_counts.x = init_alltiles_count(window_width,
			resolution, fixed_side);
	dst.tile_counts.y = init_alltiles_count(window_height,
			resolution, fixed_side);
	dst.window_size.x = window_width;
	dst.window_size.y = window_height;
	return (dst);
}

/**
 * Calculate the screen-space origin of a tile at the given 2D grid position
 * (ix-th column and iy-th row)
 *
 * The tile indices are translated into pixel coordinates using the tile size
 * and the offset of the complete centered tile area.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param tiles tile-grid format containing size and offset information
 * @param ix horizontal tile index
 * @param iy vertical tile index
 *
 * @return screen-space coordinates of the tile origin
 */
t_2d_int	get_ith_tile_screen(t_tile_format tiles,
	int ix, int iy)
{
	t_2d_int	output;

	output.x = f_min_int(tiles.window_size.x - 1,
			ix * tiles.tile_size + tiles.offset.x);
	output.y = f_min_int(tiles.window_size.y - 1,
			iy * tiles.tile_size + tiles.offset.y);
	return (output);
}
