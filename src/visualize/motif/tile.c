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
size_t	init_tile_size(size_t side_length, size_t resolution)
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
size_t	init_alltiles_count(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	if (init_tile_size(fixed_length, resolution) == 0)
		return (0);
	return (side_length / init_tile_size(fixed_length, resolution));
}

/**
 * Calculate the total side length occupied by complete tiles.
 *
 * The result is the number of complete tiles multiplied by the side
 * length of each tile. Any remaining space that cannot contain a
 * complete tile is excluded.
 *
 * Examples
 * - f(1080, 5, 1080) = init_tile_size(1080, 5) *
 * init_alltiles_count(1080, 5, 1080) = 1056
 * - f(1920, 5, 1080) = init_tile_size(1080, 5) *
 * init_alltiles_count(1920, 5, 1080) = 58 * 33 = 1914
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
size_t	init_alltiles_size(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	size_t	output;

	output = init_alltiles_count(side_length,
			resolution, fixed_length);
	return (output * init_tile_size(fixed_length, resolution));
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
int	init_alltiles_offset(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	int	output;

	output = init_alltiles_size(side_length, resolution, fixed_length);
	return ((side_length - output) / 2);
}
