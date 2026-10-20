/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:01:01 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 11:42:01 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

// time : O(1)
// space: O(1)
t_style_raster	hook_to_raster(t_hook2d *hook, bool is_draw, t_int2d ixiy)
{
	t_style_raster		style_raster;
	t_fdf_proj2d		*fdf;

	fdf = hook->fdf;
	style_raster.thickness = hook->style_render.thickness;
	style_raster.color = hook->background_color;
	if (is_draw == true)
		style_raster.color = rgba32_from_proj2d((const t_fdf_proj2d *)fdf,
				ixiy.y * fdf->col + ixiy.x);
	else
		style_raster.color = hook->background_color;
	return (style_raster);
}

// time : O(1)
// space: O(1)
void	render_circle(t_int2d point,
	t_style_raster style_raster, t_camera2d camera, mlx_image_t *dst)
{
	t_line	boundary;

	if (is_circle_in_screen(camera, point, style_raster.thickness) == false)
		return ;
	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	raster_circle(dst, point, style_raster, boundary);
}

// time : O(1)
// space: O(1)
void	render_rectangle(t_line line, int32_t style_raster,
	t_camera2d camera, mlx_image_t *dst)
{
	t_line	boundary;

	if (is_line_in_screen(camera, line) == false)
		return ;
	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	raster_rectangle(dst, line, boundary, style_raster);
}

// time : O(1)
// space: O(1)
void	render_line(t_line line, t_style_raster style_raster,
	t_camera2d camera, mlx_image_t *dst)
{
	t_line	boundary;

	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2 = camera.window_size;
	if (is_line_in_screen(camera, line) == true)
		raster_line(dst, line, boundary, style_raster);
	else
	{
		render_circle(line.p1, style_raster, camera, dst);
		render_circle(line.p2, style_raster, camera, dst);
	}
}
