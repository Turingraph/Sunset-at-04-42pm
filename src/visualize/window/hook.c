/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:01:50 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:31:29 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

// time : O(1)
// space: O(1)
static void	hook_pan(mlx_key_data_t keydata, t_camera2d *camera)
{
	int	delta;

	if (camera == NULL || isvalid_pan_key(keydata) == false)
		return ;
	delta = 100 * f_max(camera->zoom_x, camera->zoom_y);
	if (keydata.key == MLX_KEY_UP)
		camera->offset.y += delta;
	if (keydata.key == MLX_KEY_DOWN)
		camera->offset.y -= delta;
	if (keydata.key == MLX_KEY_LEFT)
		camera->offset.x += delta;
	if (keydata.key == MLX_KEY_RIGHT)
		camera->offset.x -= delta;
}

// time : O(n)
// space: O(1)
static void	hook_zoom(mlx_key_data_t keydata,
	t_hook2d *hook)
{
	float	scale;
	size_t	len;

	if (isvalid_hook2d(hook) == false
		|| isvalid_zoom_key(keydata, hook->camera->zoom_x, hook->camera->zoom_y) == false)
		return ;
	len = hook->fdf->col;
	len *= hook->fdf->row;
	scale = ZOOM_LEVEL;
	if (keydata.key == MLX_KEY_0 || keydata.key == MLX_KEY_O || keydata.key == MLX_KEY_L)
		scale = 1.0 / scale;
	if (isvalid_zoom_key_x(keydata, hook->camera->zoom_x) == true)
	{
		hook->camera->zoom_x *= scale;
		scale_vector(hook->fdf->x, scale, len);
	}
	if (isvalid_zoom_key_y(keydata, hook->camera->zoom_y) == true)
	{
		hook->camera->zoom_y *= scale;
		scale_vector(hook->fdf->y, scale, len);
	}
}

// time : O(n)
// space: O(1)
static void	hook_invert(mlx_key_data_t keydata,
	t_hook2d *hook)
{
	size_t	len;

	if (isvalid_hook2d(hook) == false
		|| isvalid_invert_key(keydata) == false)
		return ;
	len = hook->fdf->col;
	len *= hook->fdf->row;
	if (keydata.key == MLX_KEY_1)
	{
		hook->camera->zoom_x *= -1;
		scale_vector(hook->fdf->x, -1, len);
	}
	if (keydata.key == MLX_KEY_2)
	{
		hook->camera->zoom_y *= -1;
		scale_vector(hook->fdf->y, -1, len);
	}
}

// time : O(n)
// space: O(1)
static void	hook_reset(mlx_key_data_t keydata,
	t_hook2d *hook)
{
	size_t		len;

	if (isvalid_hook2d(hook) == false
		|| keydata.key != MLX_KEY_Q)
		return ;
	len = hook->fdf->col;
	len *= hook->fdf->row;
	hook->camera->offset.x = 0.0;
	hook->camera->offset.y = 0.0;
	if (f_abs(hook->camera->zoom_x) > ZOOM_MIN)
		scale_vector(hook->fdf->x, 1.0 / hook->camera->zoom_x, len);
	if (f_abs(hook->camera->zoom_y) > ZOOM_MIN)
		scale_vector(hook->fdf->y, 1.0 / hook->camera->zoom_y, len);
	hook->camera->zoom_x = 1.0;
	hook->camera->zoom_y = 1.0;
}

/**
 * Handle keyboard input for an interactive FDF view.
 *
 * The handler throttles redraws, then applies the requested camera or
 * object operation and redraws the FDF. Supported operations include
 * rotation, zoom, panning, and restoring the initial view.
 *
 * Available Keyboard input
 * 
 * - "ESC" = close the MLX window
 * 
 * - "Q" = reset 3D Fdf object
 * 
 * - "Left", "Right", "Up", "Down" = Panning the
 * 3D Fdf Object on 2D screen accordingly.
 * 
 * - "1" = rotaing 3D Fdf object on X Axis.
 * 
 * - "2" = rotaing 3D Fdf object on Y Axis.
 * 
 * - "3" = rotaing 3D Fdf object on Z Axis.
 * 
 * - "9" = Zoom in
 * 
 * - "0" = Zoom out
 *
 * The callback parameter must point to a valid t_hook2d containing
 * the MLX window, camera, and FDF object being displayed.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 * 
 * issue: The rotation hook is not working. Everytime user click "1",
 * "2", and/or "3", the 3D object get smaller. There isn't other known
 * issues with other hooks.
 *
 * @param keydata keyboard event received from MLX
 * @param param pointer to the active FDF view context
 */
void	hook_controller(mlx_key_data_t keydata, void *param)
{
	t_hook2d		*hook;
	static double	before = 0;
	double			after;

	hook = (t_hook2d *)param;
	if (isvalid_hook2d((const t_hook2d *)hook) == false
		|| isvalid_key(keydata) == false)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(hook->mlx);
	after = mlx_get_time();
	if (before != 0.0 && after - before < 0.366667)
		return ;
	before = after;
	before += 0.366667;
	render_fdf(hook, false);
	hook_invert(keydata, hook);
	hook_zoom(keydata, hook);
	hook_pan(keydata, hook->camera);
	hook_reset(keydata, hook);
	render_fdf(hook, true);
}
