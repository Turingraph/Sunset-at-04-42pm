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

#include "display_private.h"

// time : O(1)
// space: O(1)
static void	draw_kusama_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy, size_t thickness)
{
	t_2d_int	position;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, thickness);
	position = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0));
	draw_circle_fdf(position, ink, *hook->camera, hook->img);
}

// time : O(n)
// space: O(1)
void	draw_kusama_fdf(t_2d_hook *hook, bool is_draw, size_t thickness)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src.row && ixiy.x < (int)src.col)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row)
		{
			draw_kusama_fdf_unit(hook, is_draw, ixiy, thickness);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
