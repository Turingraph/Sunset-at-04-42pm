/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:45:56 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/09 13:40:23 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_TYPE_H
# define DISPLAY_TYPE_H

# include "../fdf/fdf.h"

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
typedef struct s_2d_camera
{
	t_2d_int	offset;
	t_2d_int	window_size;
	float		zoom;
}	t_2d_camera;

/*
 * Defines the artistic rendering pattern used to display an FDF object.
 *
 * The names are inspired by artist, mathematicians, and creators whose
 * visual or conceptual style influences the corresponding renderer.
 *
 * E_PICASSO       = straight lines
 * E_TOBY_FOX      = pixel-art inspired grids
 * E_TUYOKI        = smaller pixel-art inspired grids
 * E_KUSAMA        = circles
 * E_EULER         = lines + circles
 * E_POINCARE      = circles with holes
 * E_DIJKSTRA      = lines + circles with holes
 * E_PIET_MONDRIAN = four rectangles per cell
 * E_WARHOL        = pixel-art grids + straight lines
 * E_HIROHIKO_ARAKI = pixel-art grids + network pattern
 */
typedef enum t_art_style
{
	E_PICASSO,
	E_TOBY_FOX,
	E_TUYOKI,
	E_KUSAMA,
	E_EULER,
	E_POINCARE,
	E_DIJKSTRA,
	E_PIET_MONDRIAN,
	E_WARHOL,
	E_HIROHIKO_ARAKI,
}	t_art_style;

/*
 * This struct control the drawing style of the Fdf.
 */
typedef struct s_render_style
{
	int32_t		background_color;
	size_t		line_thickness;
	t_art_style	artist;
}	t_render_style;

/**
 * Describes the object and drawing configuration presented in window.
 * 
 * A master piece combines the FDF object with the drawing style,
 * background configuration and link thickness (as artstyle configuration)
 * required to display it.
 * 
 * status: internal helper
 * 
 * @param artstyle describes how the FDF object is rasterized
 * @param fdf FDF object to display
 */
typedef struct s_master_piece
{
	t_render_style	artstyle;
	t_fdf			*fdf;
}	t_master_piece;

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
 * @param master_piece 3D FDF object and drawing
 * configuration displayed by the viewer (inside the img image).
 */
typedef struct s_2d_hook
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_camera		*camera;
	t_master_piece	master_piece;
}	t_2d_hook;

#endif
