/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:01:01 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 13:53:54 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

// time : O(1)
// space: O(1)
t_raster_style	hook_to_raster(t_2d_hook *hook, bool is_draw, t_2d_int ixiy)
{
	t_raster_style		raster_style;
	t_fdf_proj2d		*fdf;

	fdf = hook->fdf;
	raster_style.thickness = hook->artstyle.thickness;
	raster_style.color = hook->background_color;
	if (is_draw == true)
		raster_style.color = rgba32_from_proj2d((const t_fdf_proj2d *)fdf,
				ixiy.y * fdf->col + ixiy.x);
	else
		raster_style.color = hook->background_color;
	return (raster_style);
}

// time : O(1)
// space: O(1)
void	render_circle(t_2d_int point,
	t_raster_style raster_style, t_2d_camera camera, mlx_image_t *dst)
{
	t_line	boundary;

	if (is_circle_in_screen(camera, point, raster_style.thickness) == false)
		return ;
	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	raster_circle(dst, point, raster_style, boundary);
}

// time : O(1)
// space: O(1)
void	render_rectangle(t_line line, int32_t raster_style,
	t_2d_camera camera, mlx_image_t *dst)
{
	t_line	boundary;

	if (is_line_in_screen(camera, line) == false)
		return ;
	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	raster_rectangle(dst, line, boundary, raster_style);
}

// time : O(1)
// space: O(1)
void	render_line(t_line line, t_raster_style raster_style,
	t_2d_camera camera, mlx_image_t *dst)
{
	t_line	boundary;

	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	if (is_line_in_screen(camera, line) == true)
		raster_line(dst, line, boundary, raster_style);
	else
	{
		render_circle(line.p1, raster_style, camera, dst);
		render_circle(line.p2, raster_style, camera, dst);
	}
}
