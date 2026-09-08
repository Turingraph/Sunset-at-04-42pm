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
t_line	get_rectangle_from_hook(t_2d_hook *hook, bool mode, t_2d_int ixiy)
{
	t_line	rec;
	int		l;
	int		r;

	l = 0;
	r = 3;
	if (mode == false)
	{
		l = 1;
		r = 2;
	}
	rec.p1 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, l),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, l));
	rec.p2 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, r),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, r));
	return (rec);
}

// time : O(1)
// space: O(1)
t_line	get_bigger_rectangle_from_hook(t_2d_hook *hook,
	bool is_larger, t_2d_int ixiy)
{
	t_line	rec;
	t_line	big;
	t_line	small;
	int		area_big;
	int		area_small;

	rec = get_rectangle_from_hook(hook, true, ixiy);
	big.p1.x = f_min_int(rec.p1.x, rec.p2.x);
	big.p1.y = f_min_int(rec.p1.y, rec.p2.y);
	big.p2.x = f_max_int(rec.p1.x, rec.p2.x);
	big.p2.y = f_max_int(rec.p1.y, rec.p2.y);
	area_big = (big.p2.x - big.p1.x) * (big.p2.y - big.p1.y);
	rec = get_rectangle_from_hook(hook, false, ixiy);
	small.p1.x = f_min_int(rec.p1.x, rec.p2.x);
	small.p1.y = f_min_int(rec.p1.y, rec.p2.y);
	small.p2.x = f_max_int(rec.p1.x, rec.p2.x);
	small.p2.y = f_max_int(rec.p1.y, rec.p2.y);
	area_small = (small.p2.x - small.p1.x) * (small.p2.y - small.p1.y);
	if (area_big > area_small && is_larger == true)
		return (big);
	if (area_big <= area_small && is_larger == true)
		return (small);
	if (area_big > area_small && is_larger == false)
		return (small);
	return (big);
}

// time : O(n)
// space: O(1)
void	draw_toby_fox_fdf(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;
	t_ink32		ink;
	t_line		line;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src.row - 1 && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			ink = get_hook_ink32(hook, is_draw, ixiy, 0);
			line = get_bigger_rectangle_from_hook(hook, true, ixiy);
			draw_rectangle_fdf(line, ink.color, *hook->camera, hook->img);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_tuyoki_fdf(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;
	t_ink32		ink;
	t_line		line;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src.row - 1 && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			ink = get_hook_ink32(hook, is_draw, ixiy, 0);
			line = get_bigger_rectangle_from_hook(hook, false, ixiy);
			draw_rectangle_fdf(line, ink.color, *hook->camera, hook->img);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
