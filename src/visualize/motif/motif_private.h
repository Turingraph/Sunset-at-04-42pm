/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motif_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:14:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 12:51:24 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTIF_PRIVATE_H
# define MOTIF_PRIVATE_H

# include "../raster/raster.h"
# include "motif_type.h"

/**
 * Describes how a motif is repeated across a 2D drawing area.
 *
 * The drawing area is divided into a rectangular grid of tiles. Motif
 * coordinates are interpreted relative to an individual tile and are
 * scaled according to tile_size before being placed on the drawing area.
 *
 * The offset allows the tile grid to begin at a position other than
 * the origin. This makes it possible to position a repeated motif
 * pattern without changing the motif itself.
 *
 * This shape2d belongs to the motif renderer and is independent of FDF
 * data. It can therefore be used to build repeated geometric patterns
 * such as lines, circles, rectangles, Islamic geometric art, or other
 * tile-based drawings.
 *
 * status: internal helper
 *
 * @param tile_size size of each tile in the drawing area
 * @param tile_counts number of tiles along the X and Y axes
 * @param offset normalized coordinates describing the tile-grid offset
 */
typedef struct t_tile
{
	float	tile_size;
	t_int2d	tile_counts;
	t_int2d	offset;
	t_int2d	window_size;
}	t_tile;

/**
* Describes a tiled motif composition and its background.
*
* The motif array contains the geometric elements that are repeated
* across the tile format. The same composition can therefore be used
* to create Islamic geometric art, ornamental patterns, or other
* repeated line-based artwork.
*
* The tile format determines how the motif is positioned and repeated
* across the drawing area. The background color is used to fill the
* area behind the rendered motif.
*
* This shape2d belongs to the motif renderer and does not depend on FDF
* data.
*
* status: internal helper
*
* @param motif collection of motifs used to build the composition
* @param tiles tiling configuration for repeating the motif
* @param background_color color rendered behind the motif
*/
typedef struct t_motif_art
{
	t_motif_arr	*motif;
	t_tile		tiles;
}	t_motif_art;

// motif.c

void			raster_motif(mlx_image_t *img, t_motif_art *src);

// public.c

void			view_motif(t_motif_arr *src,
					int32_t background_color, size_t resolution);

// tile.c

t_tile	init_tile_format(size_t width,
					size_t height, size_t resolution);
t_int2d		init_tile_ith(t_tile tiles,
					int ix, int iy);

// utils.c

bool			isvalid_motif_art(const t_motif_art *src);
t_line			init_motif_line(t_float2d point_1, t_float2d point_2,
					t_line boundary);

#endif
