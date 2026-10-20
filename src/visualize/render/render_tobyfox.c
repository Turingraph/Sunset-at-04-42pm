/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_toby_fox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:22:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:22:33 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

// time : O(1)
// space: O(1)
static t_line	render_tobyfox_unit(t_2d_hook *hook, t_2d_int ixiy)
{
	t_line	rec;
	int		l;
	int		r;

	l = 0;
	r = 3;
	rec.p1 = world_to_screen2d(*hook->camera,
			init_fdf_point1d(hook->fdf, ixiy, 1, l),
			init_fdf_point1d(hook->fdf, ixiy, 2, l));
	rec.p2 = world_to_screen2d(*hook->camera,
			init_fdf_point1d(hook->fdf, ixiy, 1, r),
			init_fdf_point1d(hook->fdf, ixiy, 2, r));
	return (rec);
}

// time : O(n)
// space: O(1)
void	render_tobyfox(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf_proj2d		src;
	t_raster_style		raster_style;
	t_line		line;

	src = *hook->fdf;
	ixiy.x = 0;
	while (0 < src.row - 1 && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			raster_style = hook_to_raster(hook, is_draw, ixiy);
			line = render_tobyfox_unit(hook, ixiy);
			render_rectangle(line, raster_style.color, *hook->camera, hook->img);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
