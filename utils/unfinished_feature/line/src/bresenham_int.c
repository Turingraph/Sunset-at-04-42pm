#include"line.h"

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
		dst[yi][i] = ink;
		if (high - mid < mid - low)
			yi += 1;
		i += 1;
	}
}

0 < 2mid - low - high
0 < 2 d (i + 1) - 2 yi - 1
0 < 2 dy (i + 1) - 2 dx yi - dx

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
void	bresenham_int_x(int *dst, t_line line, t_boundary boundary, int color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = init_swap_bresenham_x(&line, &delta_x, &delta_y);
	if (sign == 2 || sign == -2)
	{
		line = reverse_line(line);
		sign /= 2;
	}
	pivot = 2 * delta_y - delta_x;
	while (dst != NULL && line.p1.x <= line.p2.x)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary.sub_area) == true)
			dst[line.p1.y * boundary.all_area.x + line.p1.x] = color;
		if (0 < sign * pivot)
		{
			pivot -= 2 * delta_x * sign;
			line.p1.y += sign;
		}
		pivot += 2 * delta_y;
		line.p1.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	bresenham_int_y(int *dst, t_line line, t_boundary boundary, int color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = init_swap_bresenham_y(&line, &delta_x, &delta_y);
	if (sign == 2 || sign == -2)
	{
		line = reverse_line(line);
		sign /= 2;
	}
	pivot = 2 * delta_y - delta_x;
	while (dst != NULL && line.p1.y <= line.p2.y)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary.sub_area) == true)
			dst[line.p1.y * boundary.all_area.x + line.p1.x] = color;
		if (0 < sign * pivot)
		{
			pivot -= 2 * delta_x * sign;
			line.p1.x += sign;
		}
		pivot += 2 * delta_y;
		line.p1.y += 1;
	}
}

// time : O(n * thickness)
// space: O(1)
void	bresenham_int_x_thick(int *dst, t_line line, t_boundary boundary, t_ink ink)
{
	size_t	i;
	t_line	parallel;

	if (dst != NULL && ink.channel == HEIGHT
		&& f_abs_int(line.p2.x - line.p1.x) >= f_abs_int(line.p2.y - line.p1.y))
	{
		bresenham_int_x(dst, line, boundary, ink.color);
		parallel = line;
		i = 0;
		while (i < ink.thickness / 2)
		{
			line.p1.y += 1;
			line.p2.y += 1;
			bresenham_int_x(dst, line, boundary, ink.color);
			parallel.p1.y -= 1;
			parallel.p2.y -= 1;
			bresenham_int_x(dst, parallel, boundary, ink.color);
			i += 1;
		}
	}
}

// time : O(n * thickness)
// space: O(1)
void	bresenham_int_y_thick(int *dst, t_line line, t_boundary boundary, t_ink ink)
{
	size_t	i;
	t_line	parallel;

	if (dst != NULL && ink.channel == HEIGHT
		&& f_abs_int(line.p2.x - line.p1.x) < f_abs_int(line.p2.y - line.p1.y))
	{
		bresenham_int_y(dst, line, boundary, ink.color);
		parallel = line;
		i = 0;
		while (i < ink.thickness / 2)
		{
			line.p1.x += 1;
			line.p2.x += 1;
			bresenham_int_y(dst, line, boundary, ink.color);
			parallel.p1.x -= 1;
			parallel.p2.x -= 1;
			bresenham_int_y(dst, parallel, boundary, ink.color);
			i += 1;
		}
	}
}

