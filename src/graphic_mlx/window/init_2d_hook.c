/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2d_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:02:58 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/09 13:49:46 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

/**
 * Initialize a 2D camera for an MLX window.
 *
 * The camera starts at the origin (0,0) with a zoom factor of 1.0.
 * The window size defines the initial camera viewport.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param window_width width of the camera viewport
 * @param window_height height of the camera viewport
 * @return initialized 2D camera
 */
t_2d_camera	init_2d_camera(size_t window_width, size_t window_height)
{
	t_2d_camera	camera;

	camera.offset.x = 0;
	camera.offset.y = 0;
	camera.zoom = 1.0;
	camera.window_size.x = window_width;
	camera.window_size.y = window_height;
	return (camera);
}

/**
 * Create an MLX image using the dimensions of an MLX window.
 *
 * The image uses the same width and height as the supplied MLX
 * context. If the MLX context is invalid or image creation fails,
 * NULL is returned. When image creation fails, the MLX context is
 * terminated.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param mlx MLX window context used to create the image
 * @return newly created MLX image, or NULL on failure
 */
mlx_image_t	*init_mlx_image(mlx_t *mlx)
{
	mlx_image_t	*dst;

	if (mlx == NULL || mlx->width * mlx->height == 0)
		return (NULL);
	dst = mlx_new_image(mlx, mlx->width, mlx->height);
	if (dst == NULL)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	return (dst);
}

/**
 * Initialize the rendering hook context for a 2D FDF view.
 *
 * The context stores the FDF object, drawing style, and background
 * configuration. The camera is initialized separately because
 * its lifetime is managed by the caller.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param mlx MLX window context used by the view
 * @param fdf FDF object to display
 * @param artstyle style used to render the FDF object
 * @return initialized 2D FDF rendering context
 */
t_2d_hook	init_2d_hook(mlx_t *mlx, t_fdf *fdf, t_artstyle32 artstyle)
{
	t_2d_hook	dst;

	dst.mlx = mlx;
	dst.camera = NULL;
	dst.master_piece.fdf = fdf;
	dst.master_piece.artstyle = artstyle;
	dst.img = init_mlx_image(mlx);
	return (dst);
}

/**
 * Prepare an FDF object for 3D viewing.
 *
 * The FDF object is first scaled to fit within the requested window
 * size.
 *
 * time/space: O(n) / O(n)
 *
 * status: internal helper
 *
 * @param src FDF object to transform
 * @param fixed_window_size target size used for initial scaling
 */
void	scale_fdf_as_window_object(t_fdf *src, size_t fixed_window_size)
{
	size_t		length;
	float		scale;

	if (is_fdf_valid(src) == false || fixed_window_size == 0)
		return ;
	length = src->col * src->row;
	scale = fixed_window_size / src->width;
	vector_scale(src->x, scale, length);
	vector_scale(src->y, scale, length);
}
