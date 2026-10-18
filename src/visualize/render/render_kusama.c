/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_kusama.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:17:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:17:06 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

// time : O(1)
// space: O(1)
static void	render_kusama_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_2d_int	position;
	t_raster_style		raster_style;

	raster_style = hook_to_raster(hook, is_draw, ixiy);
	position = world_to_screen2d(*hook->camera,
			get_fdf_point(hook->fdf, ixiy, 1, 0),
			get_fdf_point(hook->fdf, ixiy, 2, 0));
	render_circle(position, raster_style, *hook->camera, hook->img);
}

// time : O(n)
// space: O(1)
void	render_kusama(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf_proj2d		src;

	src = *hook->fdf;
	ixiy.x = 0;
	while (0 < src.row && ixiy.x < (int)src.col)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row)
		{
			render_kusama_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
