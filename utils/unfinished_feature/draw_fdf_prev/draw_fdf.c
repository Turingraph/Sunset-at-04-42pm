/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:42:45 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 14:49:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_x(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook) == false
		|| hook->master_piece.artstyle.type == E_PIXEL_ART)
		return ;
	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src->col && ixiy.x < (int)src->col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src->row)
		{
			draw_fdf_mlx_x_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_y(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook) == false
		|| hook->master_piece.artstyle.type == E_PIXEL_ART)
		return ;
	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (ixiy.x < (int)src->col)
	{
		ixiy.y = 0;
		while (0 < src->row && ixiy.y < (int)src->row - 1)
		{
			draw_fdf_mlx_y_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(1)
// space: O(1)
void	proj_kusama_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_2d_int	position;
	t_ink32		ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	position = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0));
	if (hook->master_piece.projection != NULL)
	{
		position = hook->master_piece.projection(
				get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
				get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0),
				get_fdf_point(hook->master_piece.fdf, ixiy, 3, 0));
		position = world_3d_to_screen_2d(*hook->camera, position.x, position.y);
	}
	draw_fdf_mlx_unit_circle(position, ink, *hook->camera, hook->img);
}

// time : O(n)
// space: O(1)
void	proj_kusama_fdf(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook) == false
		|| hook->master_piece.artstyle.type != E_CIRCLE)
		return ;
	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src->col && ixiy.x < (int)src->col)
	{
		ixiy.y = 0;
		while (0 < src->row && ixiy.y < (int)src->row)
		{
			proj_kusama_fdf_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

/**
 * Draw or erase an FDF object on an MLX image.
 *
 * The FDF is rendered using the current 2D camera and drawing style stored
 * in the supplied hook. Normal FDF rendering draws horizontal and vertical
 * edges between adjacent points. When the drawing style is E_PIXEL_ART,
 * each FDF cell is rendered as a filled rectangle instead.
 *
 * When is_draw is true, the color stored in each FDF cell is used when
 * available. When is_draw is false, the FDF is drawn using the background
 * color, allowing the previous rendering to be erased before updating
 * the object.
 *
 * The hook must contain a valid MLX image, camera, and FDF object.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param hook FDF view context containing the image, camera, and FDF object
 * @param is_draw true to draw the FDF, false to erase it
 */
void	draw_fdf_mlx(t_2d_hook *hook, bool is_draw)
{
	if (is_2dhook_valid(hook) == false)
		return ;
	if (hook->master_piece.artstyle.type == E_LINE
		|| hook->master_piece.artstyle.type == E_RECTANGLE)
	{
		draw_fdf_mlx_y(hook, is_draw);
		draw_fdf_mlx_x(hook, is_draw);
	}
	else if (hook->master_piece.artstyle.type == E_PIXEL_ART)
		draw_fdf_mlx_pixel_art(hook, is_draw);
	else if (hook->master_piece.artstyle.type == E_CIRCLE)
		proj_kusama_fdf(hook, is_draw);
}
