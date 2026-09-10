#include"line.h"

// time : O(1)
// space: O(1)
t_line	init_float_line(t_complex point_1, t_complex point_2,
	t_line boundary)
{
	t_line	dst;

	dst.p1.x = float_to_2d_int(point_1.re, boundary, 0);
	dst.p1.y = float_to_2d_int(point_1.im, boundary, 1);
	dst.p2.x = float_to_2d_int(point_2.re, boundary, 0);
	dst.p2.y = float_to_2d_int(point_2.im, boundary, 1);
	return (dst);
}

// time : O(n)
// sapce: O(1)
void	draw_polygon(t_table_fdf *dst, t_2d_polygon *polygon, t_ink ink, t_line boundary)
{
	size_t	i;
	t_line	line;

	i = 0;
	while (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i < polygon->length - 1)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[i + 1], boundary);
		draw_straight_line(dst, line, boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL
		&& polygon->length > 0 && i == polygon->length - 1
		&& polygon->is_loop == true)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[0], boundary);
		draw_straight_line(dst, line, boundary, ink);
	}
}

// time : O(n)
// sapce: O(1)
void	draw_square_tiling(t_table_fdf *dst, t_2d_polygon *polygon, t_ink ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && polygon != NULL && tiling_area.y > 0 && i < f_floor(dst->row / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->col / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			draw_polygon(dst, polygon, ink, tiling);
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// sapce: O(1)
void	draw_kusama_circle_int(t_table_fdf *dst, t_circle circle, int ink, t_2d_int tiling_area)
{
	size_t		i;
	size_t		j;
	t_line		tiling;
	t_circle	point;
	t_boundary	boundary;

	point.radius = circle.radius;
	i = 0;
	while (dst != NULL && dst->arr != NULL && tiling_area.y > 0 && tiling_area.x > 0
		&& i < f_floor(dst->row / tiling_area.y) + 1)
	{
		j = 0;
		while (j < f_floor(dst->col / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			boundary = init_rectangle_boundary(tiling, dst->row, dst->col);
			point.x = (int)f_interval(circle.x, 0,
					boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;
			point.y = (int)f_interval(circle.y, 0,
					boundary.sub_area.p2.y - boundary.sub_area.p1.y) + boundary.sub_area.p1.y;
			midpoint_circle_int(dst->arr, ink, point, boundary);
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// sapce: O(1)
void	draw_kusama_circle_uchar(t_table_fdf *dst, t_circle circle, t_ink ink, t_2d_int tiling_area)
{
	size_t		i;
	size_t		j;
	t_line		tiling;
	t_circle	point;
	t_boundary	boundary;

	ink.color = (int)f_interval(ink.color, 0, 255);
	point.radius = circle.radius;
	i = 0;
	while (dst != NULL && tiling_area.y > 0 && tiling_area.x > 0
		&& get_rgba_of_table_fdf(dst, ink.channel) != NULL
		&& i < f_floor(dst->row / tiling_area.y) + 1)
	{
		j = 0;
		while (j < f_floor(dst->col / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			boundary = init_rectangle_boundary(tiling, dst->row, dst->col);
			point.x = (int)f_interval(circle.x, 0,
					boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;
			point.y = (int)f_interval(circle.y, 0,
					boundary.sub_area.p2.y - boundary.sub_area.p1.y) + boundary.sub_area.p1.y;
			midpoint_circle_uchar(get_rgba_of_table_fdf(dst, ink.channel),
				(unsigned char)ink.color, point, boundary);
			j += 1;
		}
		i += 1;
	}
}
