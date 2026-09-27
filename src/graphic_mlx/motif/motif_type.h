/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motif_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:12:33 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 16:11:40 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTIF_TYPE_H
# define MOTIF_TYPE_H

# include <stdlib.h>
# include <stdbool.h>

/**
 * 2D polygon represented by normalized coordinates.
 *
 * Each coordinate in arr must be within the range [0, 1]. The polygon
 * is scaled to the supplied drawing boundary when rendered, allowing
 * the same polygon to be reused across different areas and tile sizes.
 *
 * @param arr polygon vertices using normalized x and y coordinates
 * @param length number of vertices
 * @param is_loop connect the final vertex back to the first vertex
 */
typedef struct s_2d_polygon
{
	t_complex	*arr;
	size_t		length;
	bool		is_loop;
}	t_2d_polygon;

/**
 * Reusable 2D drawing motif composed of geometry and drawing properties.
 *
 * polygon provides the geometric data while ink describes how that geometry
 * should be rendered. A motif can therefore be reused with different
 * positions, transformations, or drawing operations.
 */
typedef struct s_motif
{
	t_2d_polygon	polygon;
	t_ink32			ink;
	t_2d_shape		shape_2d;
}	t_motif;

/**
 * Array of reusable 2D drawing motifs.
 *
 * A motif array represents a collection of independent drawing elements
 * that can be rendered together. It can be used to construct geometric or
 * line-based artwork such as Islamic patterns, Piet Mondrian-style
 * compositions, Kusama-inspired patterns, and other procedural drawings.
 */
typedef struct s_motif_arr
{
	t_motif	*arr;
	size_t	length;
}	t_motif_arr;

#endif
