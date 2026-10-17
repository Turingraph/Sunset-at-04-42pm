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

#include "display_private.h"

// time : O(1)
// space: O(1)
static t_line	draw_toby_fox_fdf_unit(t_2d_hook *hook, t_2d_int ixiy)
{
	t_line	rec;
	int		l;
	int		r;

	l = 0;
	r = 3;
	rec.p1 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->fdf, ixiy, 1, l),
			get_fdf_point(hook->fdf, ixiy, 2, l));
	rec.p2 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->fdf, ixiy, 1, r),
			get_fdf_point(hook->fdf, ixiy, 2, r));
	return (rec);
}

// time : O(n)
// space: O(1)
void	draw_toby_fox_fdf(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;
	t_ink32		ink;
	t_line		line;

	src = *hook->fdf;
	ixiy.x = 0;
	while (0 < src.row - 1 && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			ink = get_hook_ink32(hook, is_draw, ixiy);
			line = draw_toby_fox_fdf_unit(hook, ixiy);
			draw_rectangle_fdf(line, ink.color, *hook->camera, hook->img);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
