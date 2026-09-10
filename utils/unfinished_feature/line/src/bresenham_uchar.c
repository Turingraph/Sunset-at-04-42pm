#include"line.h"

// time : O(n)
// space: O(1)
void	bresenham_uchar_x(unsigned char *dst, t_line line, t_boundary boundary, unsigned char color)
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
void	bresenham_uchar_y(unsigned char *dst, t_line line, t_boundary boundary, unsigned char color)
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
void	bresenham_uchar_x_thick(unsigned char *dst, t_line line, t_boundary boundary, t_ink ink)
{
	size_t			i;
	t_line			parallel;
	unsigned char	ink_color;

	ink_color = (unsigned char)f_interval(ink.color, 0, 255);
	if (dst != NULL && ink.channel != HEIGHT
		&& f_abs(line.p2.x - line.p1.x) >= f_abs(line.p2.y - line.p1.y))
	{
		bresenham_uchar_x(dst, line, boundary, ink_color);
		parallel = line;
		i = 0;
		while (i < ink.thickness / 2)
		{
			line.p1.y += 1;
			line.p2.y += 1;
			bresenham_uchar_x(dst, line, boundary, ink_color);
			parallel.p1.y -= 1;
			parallel.p2.y -= 1;
			bresenham_uchar_x(dst, parallel, boundary, ink_color);
			i += 1;
		}
	}
}

// time : O(n * thickness)
// space: O(1)
void	bresenham_uchar_y_thick(unsigned char *dst, t_line line, t_boundary boundary, t_ink ink)
{
	size_t			i;
	t_line			parallel;
	unsigned char	ink_color;

	ink_color = (unsigned char)f_interval(ink.color, 0, 255);
	if (dst != NULL && ink.channel != HEIGHT
		&& f_abs(line.p2.x - line.p1.x) < f_abs(line.p2.y - line.p1.y))
	{
		bresenham_uchar_y(dst, line, boundary, ink_color);
		parallel = line;
		i = 0;
		while (i < ink.thickness / 2)
		{
			line.p1.x += 1;
			line.p2.x += 1;
			bresenham_uchar_y(dst, line, boundary, ink_color);
			parallel.p1.x -= 1;
			parallel.p2.x -= 1;
			bresenham_uchar_y(dst, parallel, boundary, ink_color);
			i += 1;
		}
	}
}
