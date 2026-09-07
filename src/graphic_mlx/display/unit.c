/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:01:01 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 17:37:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_private.h"

// time : O(1)
// space: O(1)
t_ink32	get_hook_ink32(t_2d_hook *hook, bool is_draw, t_2d_int ixiy,
	size_t thickness)
{
	t_ink32		ink;
	t_fdf		*fdf;

	fdf = hook->master_piece.fdf;
	ink.thickness = thickness;
	ink.color = hook->master_piece.artstyle.background_color;
	if (is_draw == true)
		ink.color = get_fdf_rgba_int32((const t_fdf *)fdf,
				ixiy.y * fdf->col + ixiy.x);
	else
		ink.color = hook->master_piece.artstyle.background_color;
	return (ink);
}

// time : O(1)
// space: O(1)
void	draw_circle_fdf(t_2d_int point,
	t_ink32 ink, t_2d_camera camera, mlx_image_t *dst)
{
	t_line	boundary;

	if (is_circle_in_screen(camera, point, ink.thickness) == false)
		return ;
	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	draw_circle(dst, point, ink, boundary);
}

// time : O(1)
// space: O(1)
void	draw_rectangle_fdf(t_line line, int32_t ink,
	t_2d_camera camera, mlx_image_t *dst)
{
	t_line	boundary;

	if (is_line_in_screen(camera, line) == false)
		return ;
	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	draw_rectangle(dst, line, boundary, ink);
}

// time : O(1)
// space: O(1)
void	draw_line_fdf(t_line line, t_ink32 ink,
	t_2d_camera camera, mlx_image_t *dst)
{
	t_line	boundary;

	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	if (is_line_in_screen(camera, line) == true)
		draw_line_generic(dst, line, boundary, ink);
	else
	{
		draw_circle_fdf(line.p1, ink, camera, dst);
		draw_circle_fdf(line.p2, ink, camera, dst);
	}
}
