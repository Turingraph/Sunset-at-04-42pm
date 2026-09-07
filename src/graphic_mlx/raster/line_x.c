/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:23:18 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 18:44:29 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

// time : O(n)
// space: O(1)
void	draw_endpoint(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	ink.thickness /= 2;
	ink.thickness -= 1;
	draw_circle(dst, line.p1, ink, boundary);
	draw_circle(dst, line.p2, ink, boundary);
}

/*
dx = x2 - x1
dy = y2 - y1
d = dy / dx
yi + y1 <= d (i + 1) + y1 <= yi + y1 + 1
yi <= d (i + 1) <= yi + 1
low <= mid <= high
high - mid < mid - low

void	draw_line()
{
	while (i <= x2 - x1)
	{
		dst[yi * col + i] = ink;
		if (high - mid < mid - low)
			yi += 1;
		i += 1;
	}
}

0 < 2mid - low - high
0 < 2 d (i + 1) - 2 yi - 1
0 < 2 dy (i + 1) - 2 dx yi - dx
0 < 2 dy i + 2 dy - 2 dx yi - dx

define: g(i, yi) = 2 dy (i + 1) - 2 dx yi - dx
*	g(i, 0) = 2 dy i + 2 dy - dx
*	g(0, 0) = 2 dy - dx
*	g(i + 1, j) = g(i, j) + 2 dy
*	g(i, j + 1) = g(i, j) - 2 dx

Reference
*	https://youtu.be/CceepU1vIKo?si=h9zAxMM_4gDwWVDU
*/

// time : O(n)
// space: O(1)
static void	draw_line_x_plus(mlx_image_t *dst,
	t_line line, t_line boundary, int32_t color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = 1;
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
void	draw_line_thick_x_plus(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	t_line	parallel;
	size_t	i;

	draw_line_x_plus(dst, line, boundary, ink.color);
	if (ink.thickness < 2)
		return ;
	draw_endpoint(dst, line, boundary, ink);
	parallel = line;
	i = 1;
	while (i < ink.thickness / 2)
	{
		parallel.p1.y -= 1;
		parallel.p2.y -= 1;
		draw_line_x_plus(dst, parallel, boundary, ink.color);
		line.p1.y += 1;
		line.p2.y += 1;
		draw_line_x_plus(dst, line, boundary, ink.color);
		i += 1;
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
