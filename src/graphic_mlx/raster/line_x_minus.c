/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_x_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:38:03 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:26:04 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

// time : O(n)
// space: O(1)
static void	draw_line_x_minus(mlx_image_t *dst,
	t_line line, t_line boundary, int32_t color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = -1;
	delta_x = line.p2.x - line.p1.x;
	delta_y = sign * (line.p2.y - line.p1.y);
	pivot = 2 * delta_y - delta_x;
	while (dst != NULL && line.p1.x <= line.p2.x)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary) == true)
			mlx_put_pixel(dst, line.p1.x, line.p1.y, color);
		if (0 < pivot)
		{
			pivot -= 2 * delta_x;
			line.p1.y += sign;
		}
		pivot += 2 * delta_y;
		line.p1.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_line_thick_x_minus(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	t_line	parallel;
	size_t	i;

	draw_line_x_minus(dst, line, boundary, ink.color);
	if (ink.thickness < 2)
		return ;
	draw_endpoint(dst, line, boundary, ink);
	parallel = line;
	i = 1;
	while (i < ink.thickness / 2)
	{
		parallel.p1.y -= 1;
		parallel.p2.y -= 1;
		draw_line_x_minus(dst, parallel, boundary, ink.color);
		line.p1.y += 1;
		line.p2.y += 1;
		draw_line_x_minus(dst, line, boundary, ink.color);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_line_thick_x_minus_noend(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	t_line	parallel;
	size_t	i;

	draw_line_x_minus(dst, line, boundary, ink.color);
	if (ink.thickness < 2)
		return ;
	parallel = line;
	i = 1;
	while (i < ink.thickness / 2)
	{
		parallel.p1.y -= 1;
		parallel.p2.y -= 1;
		draw_line_x_minus(dst, parallel, boundary, ink.color);
		line.p1.y += 1;
		line.p2.y += 1;
		draw_line_x_minus(dst, line, boundary, ink.color);
		i += 1;
	}
}
