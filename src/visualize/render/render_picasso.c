/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picasso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:22:19 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:22:20 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

// time : O(1)
// space: O(1)
static t_line	init_liney(t_2d_camera camera, t_fdf_proj2d *fdf, t_2d_int ixiy)
{
	t_line		line;

	line.p1 = world_to_screen2d(camera,
			init_fdf_point1d(fdf, ixiy, 1, 0),
			init_fdf_point1d(fdf, ixiy, 2, 0));
	line.p2 = world_to_screen2d(camera,
			init_fdf_point1d(fdf, ixiy, 1, 2),
			init_fdf_point1d(fdf, ixiy, 2, 2));
	return (line);
}

// time : O(1)
// space: O(1)
static t_line	init_linex(t_2d_camera camera, t_fdf_proj2d *fdf, t_2d_int ixiy)
{
	t_line		line;

	line.p1 = world_to_screen2d(camera,
			init_fdf_point1d(fdf, ixiy, 1, 0),
			init_fdf_point1d(fdf, ixiy, 2, 0));
	line.p2 = world_to_screen2d(camera,
			init_fdf_point1d(fdf, ixiy, 1, 1),
			init_fdf_point1d(fdf, ixiy, 2, 1));
	return (line);
}

// time : O(1)
// space: O(1)
static void	render_picassoy_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line			line;
	t_raster_style	raster_style;

	raster_style = hook_to_raster(hook, is_draw, ixiy);
	line = init_liney(*hook->camera, hook->fdf, ixiy);
	render_line(line, raster_style, *(hook->camera), hook->img);
}

// time : O(1)
// space: O(1)
static void	render_picassox_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line			line;
	t_raster_style	raster_style;

	raster_style = hook_to_raster(hook, is_draw, ixiy);
	line = init_linex(*hook->camera, hook->fdf, ixiy);
	render_line(line, raster_style, *(hook->camera), hook->img);
}

// time : O(n)
// space: O(1)
static void	render_picassox(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf_proj2d		src;

	src = *hook->fdf;
	ixiy.x = 0;
	while (0 < src.row && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row)
		{
			render_picassox_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
static void	render_picassoy(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf_proj2d		src;

	src = *hook->fdf;
	ixiy.x = 0;
	while (1 < src.row && ixiy.x < (int)src.col)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			render_picassoy_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	render_picasso(t_2d_hook *hook, bool is_draw)
{
	render_picassox(hook, is_draw);
	render_picassoy(hook, is_draw);
}
