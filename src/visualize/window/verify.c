/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:03:47 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:32:12 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

static bool	key_right_action(mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	isvalid_key(mlx_key_data_t keydata)
{
	if (key_right_action(keydata)
		&& (keydata.key == MLX_KEY_ESCAPE
			|| keydata.key == MLX_KEY_UP
			|| keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT
			|| keydata.key == MLX_KEY_RIGHT
			|| keydata.key == MLX_KEY_1
			|| keydata.key == MLX_KEY_2
			|| keydata.key == MLX_KEY_9
			|| keydata.key == MLX_KEY_0
			|| keydata.key == MLX_KEY_I
			|| keydata.key == MLX_KEY_O
			|| keydata.key == MLX_KEY_K
			|| keydata.key == MLX_KEY_L
			|| keydata.key == MLX_KEY_Q))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	isvalid_pan_key(mlx_key_data_t keydata)
{
	if (key_right_action(keydata)
		&& (keydata.key == MLX_KEY_UP
			|| keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT
			|| keydata.key == MLX_KEY_RIGHT))
		return (true);
	return (false);
}

bool	isvalid_zoom_key_x(mlx_key_data_t keydata, float zoom)
{
	bool	key_large;
	bool	key_small;

	key_large = false;
	if (keydata.key == MLX_KEY_9 || keydata.key == MLX_KEY_I)
		key_large = true;
	key_small = false;
	if (keydata.key == MLX_KEY_0 || keydata.key == MLX_KEY_O)
		key_small = true;
	if (key_right_action(keydata)
		&& ((key_large == true && f_abs(zoom * ZOOM_LEVEL) < ZOOM_MAX)
			|| (key_small == true && f_abs(zoom / ZOOM_LEVEL) > ZOOM_MIN)))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	isvalid_zoom_key_y(mlx_key_data_t keydata, float zoom)
{
	bool	key_large;
	bool	key_small;

	key_large = false;
	if (keydata.key == MLX_KEY_9 || keydata.key == MLX_KEY_K)
		key_large = true;
	key_small = false;
	if (keydata.key == MLX_KEY_0 || keydata.key == MLX_KEY_L)
		key_small = true;
	if (key_right_action(keydata)
		&& ((key_large == true && f_abs(zoom * ZOOM_LEVEL) < ZOOM_MAX)
			|| (key_small == true && f_abs(zoom / ZOOM_LEVEL) > ZOOM_MIN)))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	isvalid_zoom_key(mlx_key_data_t keydata, float zoom_x, float zoom_y)
{
	bool	is_zoom_x;
	bool	is_zoom_y;

	is_zoom_x = isvalid_zoom_key_x(keydata, zoom_x);
	is_zoom_y = isvalid_zoom_key_y(keydata, zoom_y);
	if (is_zoom_x == false && is_zoom_y == false)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	isvalid_invert_key(mlx_key_data_t keydata)
{
	if (key_right_action(keydata)
		&& (keydata.key == MLX_KEY_1
		|| keydata.key == MLX_KEY_2))
		return (true);
	return (false);
}
