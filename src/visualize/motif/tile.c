/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:31:22 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 17:31:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "motif_private.h"

/**
 * Calculate the side length of one tile for a given resolution.
 *
 * The tile size is obtained by dividing the supplied side length by
 * 2^resolution. Increasing the resolution therefore produces smaller
 * tiles. The result is truncated to an integer number of pixels.
 * 
 * Examples
 * - floor(1080 / 2^5) = 33
 * - floor(1920 / 2^5) = 33
 *
 * status: internal helper
 *
 * time/space: O(resolution, where resolution is limited to 10) / O(1)
 * 
 * @param side_length reference side length (width or height of the window)
 * used to calculate the tile size
 * @param resolution tile resolution; higher values produce smaller tiles
 * @return side length of one tile, or 0 when the resolution is too large
 */
static size_t	init_tile_size_unit(size_t side_length, size_t resolution)
{
	return (side_length / (size_t)f_pow(2.0, resolution));
}

/**
 * Calculate how many tiles fit along one side of the drawing area.
 *
 * The tile size is derived from fixed_length and resolution, then the
 * supplied side length is divided by that tile size. Any incomplete tile
 * at the edge is excluded.
 *
 * Examples
 * - f(1080, 5, 1080) = floor(1080 / g(1080, 5)) = 32
 * - f(1920, 5, 1080) = floor(1920 / g(1080, 5)) = 58
 * 
 * status: internal helper
 *
 * time/space: O(resolution, where resolution is limited to 10) / O(1)
 * 
 * @param side_length side length of the drawing area
 * (width or height of the window)
 * @param resolution tile resolution
 * @param fixed_length reference side length (width or height of the window)
 * used to determine tile size (the minimum width or height of the window)
 * @return number of complete tiles that fit along the supplied side
 *
 */
static size_t	init_tiles_count(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	if (init_tile_size_unit(fixed_length, resolution) == 0)
		return (0);
	return (side_length / init_tile_size_unit(fixed_length, resolution));
}

/**
 * Calculate the total side length occupied by complete tiles.
 *
 * The result is the number of complete tiles multiplied by the side
 * length of each tile. Any remaining space that cannot contain a
 * complete tile is excluded.
 *
 * Examples
 * - f(1080, 5, 1080) = init_tile_size_unit(1080, 5) *
 * init_tiles_count(1080, 5, 1080) = 1056
 * - f(1920, 5, 1080) = init_tile_size_unit(1080, 5) *
 * init_tiles_count(1920, 5, 1080) = 58 * 33 = 1914
 * 
 * status: internal helper
 *
 * time/space: O(resolution, where resolution is limited to 10) / O(1)
 * 
 * @param side_length side length of the drawing area
 * (width or height of the window)
 * @param resolution tile resolution
 * @param fixed_length reference side length (width or height of the window)
 * used to determine tile size
 * @return total side length occupied by complete tiles
 */
static size_t	init_tiles_size(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	size_t	output;

	output = init_tiles_count(side_length,
			resolution, fixed_length);
	return (output * init_tile_size_unit(fixed_length, resolution));
}

/**
 * Calculate the centered offset of the tiled area.
 *
 * The offset is the unused space remaining after placing all complete
 * tiles along the supplied side, divided equally between both sides.
 * This centers the tiled region within the drawing area.
 *
 * Examples
 * - f(1080, 5, 1080) = (1080 - 1056) / 2 = 12
 * - f(1920, 5, 1080) = (1920 - 1914) / 2 = 3
 * 
 * status: internal helper
 *
 * time/spaceO(resolution, where resolution is limited to 10) / O(1)
 * 
 * @param side_length side length of the drawing area
 * @param resolution tile resolution
 * @param fixed_length reference side length used to determine tile size
 * @return number of pixels to offset the tiled region from the edge
 */
static int	init_tiles_offset1d(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	int	output;

	output = init_tiles_size(side_length, resolution, fixed_length);
	return ((side_length - output) / 2);
}


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
static t_int2d	init_tiles_offset(size_t window_width, size_t window_height,
	size_t resolution, size_t fixed_length)
{
	t_int2d	output;

	output.x = (float)init_tiles_offset1d(window_width, resolution,
			fixed_length);
	output.y = (float)init_tiles_offset1d(window_height, resolution,
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
t_tiles	init_tiles(size_t window_width,
	size_t window_height, size_t resolution)
{
	t_tiles	dst;
	size_t			fixed_side;

	fixed_side = (size_t)f_min((float)window_width, (float)window_height);
	dst.offset = init_tiles_offset(window_width, window_height,
			resolution, fixed_side);
	dst.tiles_size = (float)init_tile_size_unit(fixed_side, resolution);
	dst.tiles_counts.x = init_tiles_count(window_width,
			resolution, fixed_side);
	dst.tiles_counts.y = init_tiles_count(window_height,
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
t_int2d	init_tile_ith(t_tiles tiles,
	int ix, int iy)
{
	t_int2d	output;

	output.x = f_min_int(tiles.window_size.x - 1,
			ix * tiles.tiles_size + tiles.offset.x);
	output.y = f_min_int(tiles.window_size.y - 1,
			iy * tiles.tiles_size + tiles.offset.y);
	return (output);
}
