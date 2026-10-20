/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_x_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:23:18 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 13:39:53 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster_private.h"


/**
 * Draw a filled circle using the midpoint circle algorithm.
 * 
 * This function is used mainly for drawing the end point of straight line.
 * 
 * time/space: O(r^2) / O(1)
 * 
 * status: internal helper
 * 
 * @param dst destination MLX image
 * @param point the point of circle
 * @param style_raster contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
static void	raster_circle_half_l(mlx_image_t *dst,
	t_int2d point, t_style_raster style_raster, t_line boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = style_raster.thickness * -1;
	iy = -1 * style_raster.thickness;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = init_circle_line(point, ix, iy, 0);
		line.p2.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		line = init_circle_line(point, ix, iy, 1);
		line.p2.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		line = init_circle_line(point, ix, iy, 2);
		line.p2.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		line = init_circle_line(point, ix, iy, 3);
		line.p2.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		if (pivot > 0)
			iy += 1;
		if (pivot > 0)
			pivot += 2 * iy + 2;
		ix += 1;
		pivot += 2 * ix + 1;
	}
}

/**
 * Draw a filled circle using the midpoint circle algorithm.
 * 
 * This function is used mainly for drawing the end point of straight line.
 * 
 * time/space: O(r^2) / O(1)
 * 
 * status: internal helper
 * 
 * @param dst destination MLX image
 * @param point the point of circle
 * @param style_raster contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
static void	raster_circle_half_r(mlx_image_t *dst,
	t_int2d point, t_style_raster style_raster, t_line boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = style_raster.thickness * -1;
	iy = -1 * style_raster.thickness;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = init_circle_line(point, ix, iy, 0);
		line.p1.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		line = init_circle_line(point, ix, iy, 1);
		line.p1.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		line = init_circle_line(point, ix, iy, 2);
		line.p1.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		line = init_circle_line(point, ix, iy, 3);
		line.p1.x = point.x;
		raster_line_horizontal(dst, line, style_raster.color, boundary);
		if (pivot > 0)
			iy += 1;
		if (pivot > 0)
			pivot += 2 * iy + 2;
		ix += 1;
		pivot += 2 * ix + 1;
	}
}

// time : O(n)
// space: O(1)
static void	raster_endpoint_x(mlx_image_t *dst,
	t_line line, t_line boundary, t_style_raster style_raster)
{
	style_raster.thickness /= 2;
	style_raster.thickness -= 1;
	raster_circle_half_l(dst, line.p1, style_raster, boundary);
	raster_circle_half_r(dst, line.p2, style_raster, boundary);
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
		dst[yi * col + i] = style_raster;
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
static void	raster_linex_plus_unit(mlx_image_t *dst,
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
	while (line.p1.x <= line.p2.x)
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
void	raster_linex_plus(mlx_image_t *dst,
	t_line line, t_line boundary, t_style_raster style_raster)
{
	t_line	parallel;
	size_t	i;

	raster_linex_plus_unit(dst, line, boundary, style_raster.color);
	if (style_raster.thickness < 2)
		return ;
	raster_endpoint_x(dst, line, boundary, style_raster);
	parallel = line;
	i = 1;
	while (i < style_raster.thickness / 2)
	{
		parallel.p1.y -= 1;
		parallel.p2.y -= 1;
		raster_linex_plus_unit(dst, parallel, boundary, style_raster.color);
		line.p1.y += 1;
		line.p2.y += 1;
		raster_linex_plus_unit(dst, line, boundary, style_raster.color);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
static void	raster_linex_minus_unit(mlx_image_t *dst,
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
	while (line.p1.x <= line.p2.x)
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
void	raster_linex_minus(mlx_image_t *dst,
	t_line line, t_line boundary, t_style_raster style_raster)
{
	t_line	parallel;
	size_t	i;

	raster_linex_minus_unit(dst, line, boundary, style_raster.color);
	if (style_raster.thickness < 2)
		return ;
	raster_endpoint_x(dst, line, boundary, style_raster);
	parallel = line;
	i = 1;
	while (i < style_raster.thickness / 2)
	{
		parallel.p1.y -= 1;
		parallel.p2.y -= 1;
		raster_linex_minus_unit(dst, parallel, boundary, style_raster.color);
		line.p1.y += 1;
		line.p2.y += 1;
		raster_linex_minus_unit(dst, line, boundary, style_raster.color);
		i += 1;
	}
}
