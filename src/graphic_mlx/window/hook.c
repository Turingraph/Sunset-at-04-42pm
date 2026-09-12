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
static void	hook_pan(mlx_key_data_t keydata, t_2d_camera *camera)
{
	int	delta;

	if (camera == NULL || is_valid_pan_key(keydata) == false)
		return ;
	delta = 20;
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
	t_2d_hook *hook)
{
	float		scale;
	size_t		len;

	if (is_2dhook_valid(hook) == false
		|| is_valid_zoom_key(keydata, hook->camera->zoom) == false)
		return ;
	len = hook->master_piece.fdf->col;
	len *= hook->master_piece.fdf->row;
	scale = 1.05;
	if (keydata.key == MLX_KEY_0)
		scale = 1.0 / scale;
	hook->camera->zoom *= scale;
	vector_scale(hook->master_piece.fdf->x, scale, len);
	vector_scale(hook->master_piece.fdf->y, scale, len);
}

// time : O(n)
// space: O(1)
static void	hook_home(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	size_t		len;

	if (is_2dhook_valid(hook) == false || hook->camera->zoom < 0.2
		|| keydata.key != MLX_KEY_Q)
		return ;
	len = hook->master_piece.fdf->col;
	len *= hook->master_piece.fdf->row;
	hook->camera->offset.x = 0.0;
	hook->camera->offset.y = 0.0;
	vector_scale(hook->master_piece.fdf->x, 1.0 / hook->camera->zoom, len);
	vector_scale(hook->master_piece.fdf->y, 1.0 / hook->camera->zoom, len);
	hook->camera->zoom = 1.0;
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
 * The callback parameter must point to a valid t_2d_hook containing
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
void	hook_fdf_controller(mlx_key_data_t keydata, void *param)
{
	t_2d_hook		*hook;
	static double	before = 0;
	double			after;

	hook = (t_2d_hook *)param;
	if (is_2dhook_valid((const t_2d_hook *)hook) == false
		|| is_valid_key(keydata) == false)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(hook->mlx);
	after = mlx_get_time();
	if (before != 0.0 && after - before < 0.366667)
		return ;
	before = after;
	before += 0.366667;
	draw_fdf_mlx(hook, false);
	hook_zoom(keydata, hook);
	hook_pan(keydata, hook->camera);
	hook_home(keydata, hook);
	draw_fdf_mlx(hook, true);
}
