/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:34:22 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:25:43 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

// time : O(1)
// space: O(1)
t_line	define_circle_line(t_2d_int point, int ix, int iy, char mode)
{
	t_line	dst;

	dst.p1.x = point.x - ix;
	dst.p2.x = point.x + ix;
	dst.p1.y = point.y + iy;
	dst.p2.y = point.y + iy;
	if (mode == 1)
	{
		dst.p1.y = point.y - iy;
		dst.p2.y = point.y - iy;
	}
	if (mode == 2 || mode == 3)
	{
		dst.p1.x = point.x + iy;
		dst.p2.x = point.x - iy;
		dst.p1.y = point.y + ix;
		dst.p2.y = point.y + ix;
	}
	if (mode == 3)
	{
		dst.p1.y = point.y - ix;
		dst.p2.y = point.y - ix;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
static void	draw_horizontal_mlx(mlx_image_t *dst, t_line line,
	int32_t color, t_line boundary)
{
	int	start;
	int	stop;

	if (line.p1.y < boundary.p1.y || line.p1.y >= boundary.p2.y)
		return ;
	start = f_max_int(line.p1.x, boundary.p1.x);
	stop = f_min_int(line.p2.x, boundary.p2.x - 1);
	while (start <= stop && dst != NULL)
	{
		mlx_put_pixel(dst, start, line.p1.y, color);
		start += 1;
	}
}

/*
In order to draw the circle,
this equation must be satisfy x^2 + (y + 0.5)^2 = r^2, where
*	r = radius
*	y + 0.5 because there are 50% chance
		that we color the pixel on the y + 1 th row.

We can check if the point outside the circle
or not by using Pythagorian theorem, such that
*	if x^2 + y^2 > r^2 means the point is outside the circle.

if (x^2 + (y + 0.5)^2 > r^2)
{
	y += 1;
}

In other words

if (x^2 + (y + 0.5)^2 - r^2 > 0)
{
	y += 1;
}

During first iteration
*	x = 0
*	y = -r (because we have to calculate the 2d point
		of the top point of the circle)

Calculating this inequality when y = -r and x = 0.
*	x^2 + (y + 0.5)^2 - r^2 > 0
*	(y + 0.5)^2 - r^2 > 0
*	y^2 + y + 0.25 - r^2 > 0
*	r^2 - r + 0.25 - r^2 > 0
*	- r + 0.25 > 0
*	- r > 0 (we can ignore the constent term to gain more efficiency)

So we can define 
*	pivot = -r

However, we have to update the pivot after each iteration.

One way to do this is the update team such that
*	new term = (new term - current term) + current term

define: g(x, y) = x^2 + (y + 0.5)^2 - r^2, then
*	g(i + 1, j) = i^2 + 2i + 1 + (j + 0.5)^2 - r^2 = g(i, j) + 2i + 1
*	g(i, j + 1) = i^2 + j^2 + 3j + 1.5^2 - r^2 = g(i, j) + 2j + 2

ChatGPT said that we have to loop 

while (dst != NULL && ix <= -1 * iy)
{
	...
}

inspired of 

while (dst != NULL && ix <= point.radius)
{
	...
}

Even through point.radius equal to the initial value of -1 * iy,
because you have to loop the circle for 45 degree, and
unlike point.radius, iy is updated.

Reference
*	https://www.youtube.com/watch?v=hpiILbMkF9w
*/

/**
 * Draw a filled circle using the midpoint circle algorithm.
 * 
 * The circle is rasterized using integer arithmetic and four horizontal
 * spans are drawn for each calculated point. Pixels outside the boundary
 * are clipped by draw_horizontal_mlx().
 * 
 * This function also used for drawing the end point of straight line.
 * 
 * time/space: O(r^2) / O(1)
 * 
 * status: internal helper
 * 
 * @param dst destination MLX image
 * @param point the point of circle
 * @param ink contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
void	draw_circle(mlx_image_t *dst,
	t_2d_int point, t_ink32 ink, t_line boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = ink.thickness * -1;
	iy = -1 * ink.thickness;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = define_circle_line(point, ix, iy, 0);
		draw_horizontal_mlx(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 1);
		draw_horizontal_mlx(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 2);
		draw_horizontal_mlx(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 3);
		draw_horizontal_mlx(dst, line, ink.color, boundary);
		if (pivot > 0)
			iy += 1;
		if (pivot > 0)
			pivot += 2 * iy + 2;
		ix += 1;
		pivot += 2 * ix + 1;
	}
}

/**
 * Define the rectangle/point within the given area.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param src the rectangle area (which is defined by 2 pairs of integers
 * as x_min, y_min --> x_max, y_max)
 * @param boundary the area that contains src rectangle.
 */
t_line	init_rectangle(t_line src, t_line boundary)
{
	t_line	dst;

	dst.p1.x = f_interval_int(f_min_int(src.p1.x, src.p2.x),
			boundary.p1.x, boundary.p2.x - 1);
	dst.p2.x = f_interval_int(f_max_int(src.p1.x, src.p2.x),
			boundary.p1.x, boundary.p2.x - 1);
	dst.p1.y = f_interval_int(f_min_int(src.p1.y, src.p2.y),
			boundary.p1.y, boundary.p2.y - 1);
	dst.p2.y = f_interval_int(f_max_int(src.p1.y, src.p2.y),
			boundary.p1.y, boundary.p2.y - 1);
	return (dst);
}

/**
 * Fill a rectangular area with a color.
 *
 * The rectangle is restricted to the specified drawing boundary before
 * each pixel within the resulting area is filled with the given color.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param dst destination MLX image
 * @param rectangle rectangular area to fill
 * @param boundary drawing boundary used to restrict the rectangle
 * @param ink 32-bit RGBA color used to fill the rectangle
 */
void	draw_rectangle(mlx_image_t *dst, t_line rectangle,
	t_line boundary, int32_t ink)
{
	int	i;
	int	j;

	rectangle = init_rectangle(rectangle, boundary);
	i = rectangle.p1.x;
	while (i <= rectangle.p2.x)
	{
		j = rectangle.p1.y;
		while (j <= rectangle.p2.y)
		{
			mlx_put_pixel(dst, i, j, ink);
			j += 1;
		}
		i += 1;
	}
}
