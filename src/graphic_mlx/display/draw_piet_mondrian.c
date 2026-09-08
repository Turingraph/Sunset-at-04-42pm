/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_piet_mondrian.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:22:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:22:27 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_private.h"

// time : O(1)
// space: O(1)
static void	draw_piet_mondriany_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, 0);
	line = init_draw_line_y(*hook->camera, hook->master_piece.fdf, ixiy);
	draw_rectangle_fdf(line, ink.color, *(hook->camera), hook->img);
}

// time : O(1)
// space: O(1)
static void	draw_piet_mondrianx_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, 0);
	line = init_draw_line_x(*hook->camera, hook->master_piece.fdf, ixiy);
	draw_rectangle_fdf(line, ink.color, *(hook->camera), hook->img);
}

// time : O(n)
// space: O(1)
static void	draw_piet_mondrianx_fdf(t_2d_hook *hook,
	bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src.row && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row)
		{
			draw_piet_mondrianx_fdf_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
static void	draw_piet_mondriany_fdf(t_2d_hook *hook,
	bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (1 < src.row && ixiy.x < (int)src.col)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			draw_piet_mondriany_fdf_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_piet_mondrian_fdf(t_2d_hook *hook, bool is_draw)
{
	draw_piet_mondrianx_fdf(hook, is_draw);
	draw_piet_mondriany_fdf(hook, is_draw);
}
