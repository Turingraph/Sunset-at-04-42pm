/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_y_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:26:24 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:26:44 by phsottat         ###   ########.fr       */
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
 * @param raster_style contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
static void	raster_circle_half_u(mlx_image_t *dst,
	t_2d_int point, t_raster_style raster_style, t_line boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = raster_style.thickness * -1;
	iy = -1 * raster_style.thickness;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = init_circle_line(point, ix, iy, 0);
		raster_line_horizontal(dst, line, raster_style.color, boundary);
		line = init_circle_line(point, ix, iy, 3);
		raster_line_horizontal(dst, line, raster_style.color, boundary);
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
 * @param raster_style contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
static void	raster_circle_half_d(mlx_image_t *dst,
	t_2d_int point, t_raster_style raster_style, t_line boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = raster_style.thickness * -1;
	iy = -1 * raster_style.thickness;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = init_circle_line(point, ix, iy, 1);
		raster_line_horizontal(dst, line, raster_style.color, boundary);
		line = init_circle_line(point, ix, iy, 2);
		raster_line_horizontal(dst, line, raster_style.color, boundary);
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
static void	raster_endpoint_y(mlx_image_t *dst,
	t_line line, t_line boundary, t_raster_style raster_style)
{
	raster_style.thickness /= 2;
	raster_style.thickness -= 1;
	raster_circle_half_u(dst, line.p1, raster_style, boundary);
	raster_circle_half_d(dst, line.p2, raster_style, boundary);
}

// time : O(n)
// space: O(1)
static void	raster_liney_plus_unit(mlx_image_t *dst,
	t_line line, t_line boundary, int32_t color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = 1;
	delta_x = line.p2.y - line.p1.y;
	delta_y = sign * (line.p2.x - line.p1.x);
	pivot = 2 * delta_y - delta_x;
	while (line.p1.y <= line.p2.y)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary) == true)
			mlx_put_pixel(dst, line.p1.x, line.p1.y, color);
		if (0 < pivot)
		{
			pivot -= 2 * delta_x;
			line.p1.x += sign;
		}
		pivot += 2 * delta_y;
		line.p1.y += 1;
	}
}

// time : O(n)
// space: O(1)
void	raster_liney_plus(mlx_image_t *dst,
	t_line line, t_line boundary, t_raster_style raster_style)
{
	t_line	parallel;
	size_t	i;

	raster_liney_plus_unit(dst, line, boundary, raster_style.color);
	if (raster_style.thickness < 2)
		return ;
	raster_endpoint_y(dst, line, boundary, raster_style);
	parallel = line;
	i = 1;
	while (i < raster_style.thickness / 2)
	{
		parallel.p1.x -= 1;
		parallel.p2.x -= 1;
		raster_liney_plus_unit(dst, parallel, boundary, raster_style.color);
		line.p1.x += 1;
		line.p2.x += 1;
		raster_liney_plus_unit(dst, line, boundary, raster_style.color);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
static void	raster_liney_minus_unit(mlx_image_t *dst,
	t_line line, t_line boundary, int32_t color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = -1;
	delta_x = line.p2.y - line.p1.y;
	delta_y = sign * (line.p2.x - line.p1.x);
	pivot = 2 * delta_y - delta_x;
	while (line.p1.y <= line.p2.y)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary) == true)
			mlx_put_pixel(dst, line.p1.x, line.p1.y, color);
		if (0 < pivot)
		{
			pivot -= 2 * delta_x;
			line.p1.x += sign;
		}
		pivot += 2 * delta_y;
		line.p1.y += 1;
	}
}

// time : O(n)
// space: O(1)
void	raster_liney_minus(mlx_image_t *dst,
	t_line line, t_line boundary, t_raster_style raster_style)
{
	t_line	parallel;
	size_t	i;

	raster_liney_minus_unit(dst, line, boundary, raster_style.color);
	if (raster_style.thickness < 2)
		return ;
	raster_endpoint_y(dst, line, boundary, raster_style);
	parallel = line;
	i = 1;
	while (i < raster_style.thickness / 2)
	{
		parallel.p1.x -= 1;
		parallel.p2.x -= 1;
		raster_liney_minus_unit(dst, parallel, boundary, raster_style.color);
		line.p1.x += 1;
		line.p2.x += 1;
		raster_liney_minus_unit(dst, line, boundary, raster_style.color);
		i += 1;
	}
}
