/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:03:34 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 11:40:04 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

// This function is only used for view_fdf.
static bool	handle_fdf0(mlx_t *mlx, mlx_image_t *img)
{
	if (img == NULL)
	{
		if (mlx != NULL)
			mlx_terminate(mlx);
		return (false);
	}
	return (true);
}

// This function is only used for view_fdf.
static int32_t	handle_fdf1(mlx_t *mlx, mlx_image_t *img)
{
	return (mlx_image_to_window(mlx, img,
			((int)mlx->width - (int)img->width) / 2,
			((int)mlx->height - (int)img->height) / 2));
}

// This function is only used for view_fdf.
static void	handle_fdf2(mlx_t *mlx, mlx_image_t *img)
{
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}

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
 * status: public api
 *
 * @param fdf FDF object to display.
 * The default color of the FDF object is black.
 * @param fdf_render style used to render the FDF object.
 * @param background_color the background color of the window scene.
 */
void	view_fdf_proj2d(t_fdf_proj2d *fdf, t_style_render fdf_render,
	int32_t background_color)
{
	mlx_t			*mlx;
	t_hook2d		hook;
	t_camera2d		camera;

	if (isvalid_fdf_proj2d(fdf) == false)
		return ;
	mlx = mlx_init(SUNSET_WINDOW_WIDTH,
			SUNSET_WINDOW_HEIGHT, "Sunset at 4:42 pm", true);
	hook = init_hook2d(mlx, fdf, fdf_render, background_color);
	if (handle_fdf0(mlx, hook.img) == false)
		return ;
	camera = init_camera2d(SUNSET_WINDOW_WIDTH, SUNSET_WINDOW_HEIGHT);
	hook.camera = &camera;
	normalize_fdf_proj2d(fdf, f_max(SUNSET_WINDOW_WIDTH,
			SUNSET_WINDOW_HEIGHT));
	raster_color_background(hook.img, background_color);
	render_fdf(&hook, true);
	if (-1 == handle_fdf1(mlx, hook.img))
	{
		mlx_terminate(mlx);
		return ;
	}
	mlx_key_hook(mlx, &hook_controller, &hook);
	handle_fdf2(mlx, hook.img);
}

void	view_fdf_pixel_art(t_fdf_table *src, int32_t background_color)
{
	t_style_render	style;
	t_fdf_proj2d	dst;

	if (src == NULL || mul_overflow_size_t(src->col, src->row) == false)
		return ;
	style.shape2d = SHAPE2D_RECTANGLE;
	style.thickness = 0;
	scale_fdf_table(src, 0, FDF_HEIGHT);
	dst = create_fdf_proj2d(src, NULL);
	view_fdf_proj2d(&dst, style, background_color);
	destroy_fdf_proj2d(&dst);
}

void	view_fdf_pixel_art_conformal(t_fdf_table *src, int32_t background_color, double scale, t_double2d (*complex_map)(t_double2d a))
{
	t_style_render	style;
	t_fdf_proj2d	dst;

	if (src == NULL || mul_overflow_size_t(src->col, src->row) == false)
		return ;
	style.shape2d = SHAPE2D_CIRCLE;
	style.thickness = 5;
	scale_fdf_table(src, 0, FDF_HEIGHT);
	dst = create_conformal_fdf_proj2d(src, complex_map, scale);
	view_fdf_proj2d(&dst, style, background_color);
	destroy_fdf_proj2d(&dst);
}
