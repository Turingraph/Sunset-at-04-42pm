#include"line.h"

// time : O(1)
// space: O(1)
t_circle	init_circle_in_boundary(t_circle point, t_boundary boundary)
{
	point.x = (int)f_interval(point.x, 0,
			boundary.sub_area.p2.x - boundary.sub_area.p1.x)
		+ boundary.sub_area.p1.x;
	point.y = (int)f_interval(point.y, 0,
			boundary.sub_area.p2.y - boundary.sub_area.p1.y)
		+ boundary.sub_area.p1.y;
	return (point);
}

// time : O(n)
// space: O(1)
void	draw_horizontal_int(int *dst, t_line line,
	int color, t_boundary boundary)
{
	int	temp;

	if (line.p1.x > line.p2.x)
	{
		temp = line.p2.x;
		line.p2.x = line.p1.x;
		line.p1.x = temp;
		temp = line.p2.y;
		line.p2.y = line.p1.y;
		line.p1.y = temp;
	}
	while (line.p1.x <= line.p2.x && dst != NULL)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary.sub_area) == true)
			dst[line.p1.y * boundary.all_area.x + line.p1.x] = color;
		line.p1.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_horizontal_uchar(unsigned char *dst,
	t_line line, unsigned char color, t_boundary boundary)
{
	int	temp;

	if (line.p1.x > line.p2.x)
	{
		temp = line.p2.x;
		line.p2.x = line.p1.x;
		line.p1.x = temp;
		temp = line.p2.y;
		line.p2.y = line.p1.y;
		line.p1.y = temp;
	}
	while (line.p1.x <= line.p2.x && dst != NULL)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary.sub_area) == true)
			dst[line.p1.y * boundary.all_area.x + line.p1.x] = color;
		line.p1.x += 1;
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
*	y = -r (because we have to calculate the 2d position
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

// time : O(r^2)
// space: O(1)
void	midpoint_circle_int(int *dst,
	int color, t_circle point, t_boundary boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = point.radius * -1;
	iy = -1 * point.radius;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = define_circle_boundary(point, ix, iy, 0);
		draw_horizontal_int(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 1);
		draw_horizontal_int(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 2);
		draw_horizontal_int(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 3);
		draw_horizontal_int(dst, line, color, boundary);
		if (pivot > 0)
			iy += 1;
		if (pivot > 0)
			pivot += 2 * iy + 2;
		ix += 1;
		pivot += 2 * ix + 1;
	}
}

// time : O(r^2)
// space: O(1)
void	midpoint_circle_uchar(unsigned char *dst,
	unsigned char color, t_circle point, t_boundary boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = point.radius * -1;
	iy = -1 * point.radius;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = define_circle_boundary(point, ix, iy, 0);
		draw_horizontal_uchar(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 1);
		draw_horizontal_uchar(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 2);
		draw_horizontal_uchar(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 3);
		draw_horizontal_uchar(dst, line, color, boundary);
		if (pivot > 0)
			iy += 1;
		if (pivot > 0)
			pivot += 2 * iy + 2;
		ix += 1;
		pivot += 2 * ix + 1;
	}
}
