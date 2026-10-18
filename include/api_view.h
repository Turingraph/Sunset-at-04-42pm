/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_view.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:08:59 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/16 15:23:36 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_VIEW_H
# define API_VIEW_H


/* ************************************************************************** */
/* *** src/visualize/raster/ *** */
/* ************************************************************************** */

/**
 * Describes the rendering properties of a 2D motif or FDF drawing.
 * 
 * color stores the 32-bit drawing color. shape_2d determines how the associated
 * geometry or FDF data is rendered. thickness controls the size of the
 * rendered primitive where applicable.
 * 
 * @param color 32-bit drawing color
 * @param thickness size parameter used by the selected rendering shape_2d
 */
typedef struct s_ink32
{
	int32_t		color;
	size_t		thickness;
}	t_raster_style;

/**
 * Supported 2D motif and rendering types.
 * 
 * The type determines how the motif geometry or FDF data is interpreted
 * by the raster layer.
 * 
 * ENUM TYPE
 * 
 * - E_RECTANGLE draws rectangular geometry.
 * 
 * - E_CIRCLE draws circular geometry.
 * 
 * - E_LINE draws polygon edges as lines.
 */
typedef enum t_2d_shape
{
	E_RECTANGLE,
	E_CIRCLE,
	E_LINE,
}	t_2d_shape;

/**
 * Pack individual RGBA channels into a 32-bit color value.
 *
 * The channels are packed in RGBA order, with red as the most
 * significant byte and alpha as the least significant byte.
 *
 * time/space: O(1) / O(1)
 *
 * @param r red channel value
 * @param g green channel value
 * @param b blue channel value
 * @param a alpha channel value
 * @return packed 32-bit RGBA color
 * @see https://github.com/codam-coding-college/MLX42/blob/master/docs/Colors.md
 * to understand how to use color with MLX42 graphic library.
 */
int32_t	rgba32_from_char(unsigned char r,
	unsigned char g, unsigned char b, unsigned char a);

/* ************************************************************************** */
/* *** src/visualize/fdf/ *** */
/* ************************************************************************** */

/**
 * FDF object containing the 2D projected representation data of the 
 * t_fdf_table data.
 * 
 * @param r the red channel of each FdF cell.
 * @param g the green channel of each FdF cell.
 * @param b the blue channel of each FdF cell.
 * @param a the alpha channel of each FdF cell.
 * @param row the numbers of all row of the FdF object which correlated to the y axis.
 * @param col the numbers of all column of the FdF object which correlated to the x axis.
 * @param x x coordinates for each FDF cell according to the 2D projected representation.
 * @param y y coordinates for each FDF cell according to the 2D projected representation.
 * @param width current width of the transformed FDF object, for scaling the Fdf object
 * with the suitable scaling factor relative to the window height and width.
 */
typedef struct t_fdf_projection
{
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
	size_t			row;
	size_t			col;
	float			*x;
	float			*y;
	float			width;
}	t_fdf_proj2d;

/**
 * Release all resources owned by an FDF object.
 *
 * This function frees the source fdf data.
 *
 * view_fdf() does not call destroy_fdf_proj2d(). The caller therefore remains
 * responsible for releasing an FDF object created by create_fdf_proj2d().
 *
 * Calling destroy_fdf_proj2d() with NULL is safe.
 * 
 * The return data is NULL fdf data.
 *
 * time/space: O(1) /  O(1)
 *
 * @param src FDF object to release
 */
t_fdf_proj2d	destroy_fdf_proj2d(t_fdf_proj2d *src);

/**
 * Initialize a FDF object from a t_fdf_table table.
 *
 * The returned FDF object owns the 2D position arrays of each cells of t_fdf_table,
 * based on the 2D projection of the table (determined by 2D projection
 * argument e.g. projection_isometric, projection_military etc.
 * ). If the projection is NULL,
 * then this function return the simple orthogonal projection of t_fdf_table.
 *
 * This function use the color of t_fdf_table table,
 * instead of deep copy and/or shallow copy the color of t_fdf_table table, for
 * preventing double free issues and preventing using too many malloc than needed.
 *
 * The future version of this program will support 3D related features e.g.
 * quaternion rotation, 3D collision detection etc. but not now for the sake of development simplicity.
 * 
 * time/space: O(n) / O(n)
 *
 * @param src source table containing the FDF data
 * @param projection the functional pointer for define the projection of
 * t_fdf_table as t_fdf_proj2d.
 * @param scale for scaling Fdf object.
 * @return initialized t_fdf_proj2d object.
 * @see src/visualize/fdf/projection.c
 */
t_fdf_proj2d	create_fdf_proj2d(t_fdf_table *src,
	t_2d_float (*projection)(float x, float y, float z), float scale);

/**
 * Apply an isometric projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using an isometric projection. The x and y coordinates contribute to both
 * the horizontal and vertical components, while z affects the vertical
 * component.
 *
 * formula:
 * - x' = 0.866 * x - 0.866 * y
 * - y' = 0.5 * x + 0.5 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_2d_float	projection_isometric(float x, float y, float z);

/**
 * Apply a military projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using a military projection. The x and y coordinates contribute equally
 * to the horizontal and vertical components, while z affects the vertical
 * component.
 *
 * formula:
 * - x' = 0.707 * x - 0.707 * y
 * - y' = 0.707 * x + 0.707 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_2d_float	projection_military(float x, float y, float z);

/**
 * Apply a cabinet projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using a cabinet projection. The x coordinate is preserved horizontally,
 * while the y coordinate contributes to both horizontal and vertical
 * components. The z coordinate affects the vertical component.
 *
 * formula:
 * - x' = x - 0.353 * y
 * - y' = 0.707 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_2d_float	projection_cabinet(float x, float y, float z);

/**
 * Apply an orthogonal projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * by preserving the x coordinate as the horizontal component and combining
 * the y and z coordinates into the vertical component.
 *
 * formula:
 * - x' = x
 * - y' = y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_2d_float	projection_orthogonal(float x, float y, float z);

/**
 * Apply a wave projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * by applying a cosine wave based on the x coordinate to the z coordinate.
 * The resulting value is combined with the y coordinate to produce the
 * vertical component.
 *
 * formula:
 * - x' = x - 0.353 * y
 * - y' = z * f_cos(x) + y - z
 * 
 * time/space: O(1) / O(1)
 *
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_2d_float	projection_wave(float x, float y, float z);

/* ************************************************************************** */
/* *** src/visualize/render/ *** */
/* ************************************************************************** */

/*
 * This struct control the drawing style of the Fdf.
 */
typedef struct s_render_style
{
	size_t		thickness;
	t_2d_shape	shape_2d;
}	t_fdf_render;

/* ************************************************************************** */
/* *** src/visualize/window/ *** */
/* ************************************************************************** */

/**
 * Display an FDF object in an interactive a 1920x1080 MLX window.
 *
 * The FDF object is scaled to fit the viewing area.
 * The drawing style controls how the FDF object is
 * rendered (setting line thickness, background color,
 * and rendering style inspired by famous creators).
 *
 * The view supports interactive manipulation through the registered
 * FDF keyboard controller.
 *
 * Available keyboard input is handled by hook_controller(), including
 * 
 * - "ESC" = close the MLX window
 * 
 * - "Q" = reset 3D Fdf object
 * 
 * - "Left", "Right", "Up", "Down" = Panning the
 * 3D Fdf Object on 2D screen accordingly.
 * 
 * - "9" = Zoom in
 * 
 * - "0" = Zoom out
 *
 * time/space: O(n) / O(n)
 *
 * @param fdf FDF object to display.
 * The default color of the FDF object is black.
 * @param fdf_render style used to render the FDF object.
 * @param background_color the background color of the window scene.
 */
void	view_fdf(t_fdf_proj2d *fdf, t_fdf_render fdf_render,
			int32_t background_color);

/* ************************************************************************** */
/* *** src/visualize/motif/ *** */
/* ************************************************************************** */

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
	t_2d_float	*arr;
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
	t_raster_style			ink;
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

/**
 * Display a motif as a tiled 2D composition in an MLX window.
 *
 * Creates a 1920x1080 static MLX window, initializes the rendering image and tile
 * format, fills the image with the requested motif, and keeps the window
 * open until the MLX loop terminates.
 *
 * The motif coordinates are interpreted by the motif rendering system and
 * repeated according to the requested tile resolution.
 *
 * The caller retains ownership of the supplied motif array.
 *
 * time/space: O(n) / O(n)
 *
 * @param src motif array to render (as Islamic Art,
 * Kusama art, Piet Mondrian inspired art etc.)
 * @param background_color background colour of the rendered composition
 * @param resolution tile subdivision resolution (equal to or less than 10).
 * If the resolution more than 10, then resolution equal to 10, given that 1920 < 2^n when 10 < n
 * If the resolution is equal to 0, then there will be only 1 tile, given that 1 = 2^0.
 */
void	view_motif(t_motif_arr *src,
	int32_t background_color, size_t resolution);

#endif
