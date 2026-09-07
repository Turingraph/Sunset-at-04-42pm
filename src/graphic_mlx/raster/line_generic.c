/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_generic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:33:09 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 17:34:42 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

// time : O(n)
// space: O(1)
void	draw_line_x_generic(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	t_2d_int	temp;

	if (line.p2.x < line.p1.x)
	{
		temp = line.p2;
		line.p2 = line.p1;
		line.p1 = temp;
	}
	if (line.p2.y - line.p1.y < 0)
		draw_line_thick_x_minus(dst, line, boundary, ink);
	else
		draw_line_thick_x_plus(dst, line, boundary, ink);
}

// time : O(n)
// space: O(1)
void	draw_line_y_generic(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	t_2d_int	temp;

	if (line.p2.y < line.p1.y)
	{
		temp = line.p2;
		line.p2 = line.p1;
		line.p1 = temp;
	}
	if (line.p2.x - line.p1.x < 0)
		draw_line_thick_y_minus(dst, line, boundary, ink);
	else
		draw_line_thick_y_plus(dst, line, boundary, ink);
}

// time : O(n)
// space: O(1)
void	draw_line_generic(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	if (f_abs_int(line.p2.x - line.p1.x) > f_abs_int(line.p2.y - line.p1.y))
		draw_line_x_generic(dst, line, boundary, ink);
	else
		draw_line_y_generic(dst, line, boundary, ink);
}
