/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_art.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 13:31:49 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 13:36:43 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_pixel_art_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	ink.type = E_RECTANGLE;
	line.p1 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0));
	line.p2 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 3),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 3));
	draw_fdf_mlx_unit(line, ink, *(hook->camera), hook->img);
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_pixel_art(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook) == false
		|| hook->master_piece.artstyle.type != E_PIXEL_ART)
		return ;
	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src->col && ixiy.x < (int)src->col - 1)
	{
		ixiy.y = 0;
		while (0 < src->row && ixiy.y < (int)src->row - 1)
		{
			draw_fdf_mlx_pixel_art_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
