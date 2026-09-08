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

// time : O(1)
// space: O(1)
bool	is_valid_key(mlx_key_data_t keydata)
{
	if ((keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_ESCAPE
			|| keydata.key == MLX_KEY_UP
			|| keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT
			|| keydata.key == MLX_KEY_RIGHT
			|| keydata.key == MLX_KEY_1
			|| keydata.key == MLX_KEY_2
			|| keydata.key == MLX_KEY_3
			|| keydata.key == MLX_KEY_9
			|| keydata.key == MLX_KEY_0
			|| keydata.key == MLX_KEY_Q))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_valid_pan_key(mlx_key_data_t keydata)
{
	if ((keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_UP
			|| keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT
			|| keydata.key == MLX_KEY_RIGHT))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_valid_rotate_key(mlx_key_data_t keydata)
{
	if ((keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_1
			|| keydata.key == MLX_KEY_2
			|| keydata.key == MLX_KEY_3))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_valid_zoom_key(mlx_key_data_t keydata, float zoom)
{
	if ((keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT)
		&& ((keydata.key == MLX_KEY_9 && zoom * 1.01 < 8.0)
			|| (keydata.key == MLX_KEY_0 && zoom / 1.01 > 0.2)))
		return (true);
	return (false);
}
