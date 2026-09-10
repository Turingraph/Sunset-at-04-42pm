#include"line.h"

// time : O(n * thickness)
// space: O(1)
void	draw_uchar_straight_line(t_table_fdf *dst, t_line line,
	t_line rectangle_boundary, t_ink ink)
{
	t_boundary		boundary;
	unsigned char	*arr;
	t_circle		end_point;

	if (dst != NULL && ink.channel != HEIGHT)
	{
		boundary = init_rectangle_boundary(rectangle_boundary,
				dst->row, dst->col);
		line = init_first_line(line, boundary);
		ink.color = (int)f_interval(ink.color, 0, 255);
		arr = get_rgba_of_table_fdf(dst, ink.channel);
		if (arr != NULL
			&& f_abs(line.p2.x - line.p1.x) >= f_abs(line.p2.y - line.p1.y))
			bresenham_uchar_x_thick(arr, line, boundary, ink);
		else if (arr != NULL)
			bresenham_uchar_y_thick(arr, line, boundary, ink);
		end_point.radius = ink.thickness / 2 - 1;
		end_point.x = line.p1.x;
		end_point.y = line.p1.y;
		if (arr != NULL && ink.thickness > 1)
			midpoint_circle_uchar(arr, ink.color, end_point, boundary);
		end_point.x = line.p2.x;
		end_point.y = line.p2.y;
		if (arr != NULL && ink.thickness > 1)
			midpoint_circle_uchar(arr, ink.color, end_point, boundary);
	}
}

// time : O(n * thickness)
// space: O(1)
void	draw_int_straight_line(t_table_fdf *dst, t_line line,
	t_line rectangle_boundary, t_ink ink)
{
	t_boundary		boundary;
	t_circle		end_point;

	if (dst != NULL && ink.channel == HEIGHT)
	{
		boundary = init_rectangle_boundary(rectangle_boundary,
				dst->row, dst->col);
		line = init_first_line(line, boundary);
		if (dst->arr != NULL
			&& f_abs(line.p2.x - line.p1.x) >= f_abs(line.p2.y - line.p1.y))
			bresenham_int_x_thick(dst->arr, line, boundary, ink);
		else if (dst->arr != NULL)
			bresenham_int_y_thick(dst->arr, line, boundary, ink);
		end_point.radius = ink.thickness / 2 - 1;
		end_point.x = line.p1.x;
		end_point.y = line.p1.y;
		if (dst->arr != NULL && ink.thickness > 1)
			midpoint_circle_int(dst->arr, ink.color, end_point, boundary);
		end_point.x = line.p2.x;
		end_point.y = line.p2.y;
		if (dst->arr != NULL && ink.thickness > 1)
			midpoint_circle_int(dst->arr, ink.color, end_point, boundary);
	}
}

// time : O(n * thickness)
// space: O(1)
void	draw_straight_line(t_table_fdf *dst,
	t_line line, t_line rectangle_boundary, t_ink ink)
{
	if (dst != NULL && ink.channel == HEIGHT)
		draw_int_straight_line(dst, line, rectangle_boundary, ink);
	else if (dst != NULL)
		draw_uchar_straight_line(dst, line, rectangle_boundary, ink);
}
