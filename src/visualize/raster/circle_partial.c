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
 * @param ink contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
void	draw_circle_half_left(mlx_image_t *dst,
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
		line.p2.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 1);
		line.p2.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 2);
		line.p2.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 3);
		line.p2.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
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
 * @param ink contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
void	draw_circle_half_right(mlx_image_t *dst,
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
		line.p1.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 1);
		line.p1.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 2);
		line.p1.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 3);
		line.p1.x = point.x;
		draw_horizontal(dst, line, ink.color, boundary);
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
 * @param ink contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
void	draw_circle_half_up(mlx_image_t *dst,
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
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 3);
		draw_horizontal(dst, line, ink.color, boundary);
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
 * @param ink contains both color and the size of the circle.
 * @param boundary drawable area used to clip the circle
 * @see https://www.youtube.com/watch?v=hpiILbMkF9w
 * for learning how Midpoint circle works.
*/
void	draw_circle_half_down(mlx_image_t *dst,
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
		line = define_circle_line(point, ix, iy, 1);
		draw_horizontal(dst, line, ink.color, boundary);
		line = define_circle_line(point, ix, iy, 2);
		draw_horizontal(dst, line, ink.color, boundary);
		if (pivot > 0)
			iy += 1;
		if (pivot > 0)
			pivot += 2 * iy + 2;
		ix += 1;
		pivot += 2 * ix + 1;
	}
}
