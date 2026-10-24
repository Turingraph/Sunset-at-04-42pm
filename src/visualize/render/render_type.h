/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:45:56 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 18:58:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_TYPE_H
# define DISPLAY_TYPE_H

# include "../proj2d/proj2d.h"
# include "../raster/raster.h"

/**
 * 2D camera describing the visible portion of a rendered object.
 * 
 * The camera controls the position and scale used to map object
 * coordinates into the 2D rendering area.
 * 
 * @param offset position of the camera relative to the rendered object
 * @param window_size size of the visible 2D rendering area
 * @param zoom scale applied by the camera
 */
typedef struct t_camera2d
{
	t_int2d	offset;
	t_int2d	window_size;
	float		zoom;
}	t_camera2d;

/**
 * Describes the rendering properties of a 2D motif or FDF drawing.
 * 
 * color stores the 32-bit drawing color. shape2d determines how the associated
 * geometry or FDF data is rendered. thickness controls the size of the
 * rendered primitive where applicable.
 * 
 * status: public api
 * 
 * @param shape2d the given shape including SHAPE2D_CIRCLE, SHAPE2D_LINE, and SHAPE2D_RECTANGLE.
 * @param thickness size parameter used by the selected rendering shape2d
 */
typedef struct t_style_render
{
	size_t		thickness;
	t_shape2d	shape2d;
}	t_style_render;

/**
 * Runtime state required by the 2D MLX viewer.
 * 
 * The hook owns the MLX image and keeps references to the camera and
 * master piece used while the rendering loop is running.
 * 
 * status: internal helper
 * 
 * @param mlx MLX window context
 * @param img image used as the rendering target
 * @param camera camera used to transform the displayed object
 * @param style_render describes how the FDF object is rasterized
 * @param fdf FDF object to display
 */
typedef struct t_hook2d
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_camera2d		*camera;
	t_style_render	style_render;
	t_fdf_proj2d	*fdf;
	int32_t			background_color;
}	t_hook2d;

/*
Rendering is a broad term that generally means transforming computer-readable
information, for example objects in a 3d scene, to one or more images.

Rasterization is a more specific term that typically means the process of
transforming a vector (curve based) image to a rasterized (pixel based) image.

Reference
*	https://stackoverflow.com/questions/15796436/
	what-s-the-difference-between-rasterization-and-rendering
*/

#endif
