#include"line.h"

// time : O(1)
// space: O(1)
t_line	init_rectangle(t_line src, t_boundary boundary)
{
	t_line	dst;

	dst.p1.x = (int)f_interval(f_min(src.p1.x, src.p2.x), 0,
		boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;
	dst.p1.y = (int)f_interval(f_min(src.p1.y, src.p2.y), 0,
		boundary.sub_area.p2.y - boundary.sub_area.p1.y) + boundary.sub_area.p1.y;
	dst.p2.x = (int)f_interval(f_max(src.p1.x, src.p2.x), 0,
		boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;
	dst.p2.y = (int)f_interval(f_max(src.p1.y, src.p2.y), 0,
		boundary.sub_area.p2.y - boundary.sub_area.p1.y) + boundary.sub_area.p1.y;
	return (dst);
}

// time : O(n)
// space: O(1)
void	draw_rectangle_int(t_table_fdf *dst, t_line rectangle,
	t_line boundary, int ink)
{
	t_boundary		sub_area;
	int				i;
	int				j;

	if (dst != NULL && dst->arr != NULL)
	{
		sub_area = init_rectangle_boundary(boundary,
				dst->row, dst->col);
		rectangle = init_rectangle(rectangle, sub_area);
		i = rectangle.p1.x;
		while (i <= rectangle.p2.x)
		{
			j = rectangle.p1.y;
			while (j <= rectangle.p2.y)
			{
				if (is_in_boundary(i, j, sub_area.sub_area) == true)
					dst->arr[j * sub_area.all_area.x + i] = ink;
				j += 1;
			}
			i += 1;
		}
	}
}

// time : O(n)
// space: O(1)
void	draw_rectangle_uchar(t_table_fdf *dst, t_line rectangle,
	t_line boundary, t_ink ink)
{
	t_boundary		sub_area;
	int				i;
	int				j;
	unsigned char	*arr;

	ink.color = (int)f_interval(ink.color, 0, 255);
	arr = get_rgba_of_table_fdf(dst, ink.channel);
	if (dst != NULL && arr != NULL)
	{
		sub_area = init_rectangle_boundary(boundary,
				dst->row, dst->col);
		rectangle = init_rectangle(rectangle, sub_area);
		i = rectangle.p1.x;
		while (i <= rectangle.p2.x)
		{
			j = rectangle.p1.y;
			while (j <= rectangle.p2.y)
			{
				if (is_in_boundary(i, j, sub_area.sub_area) == true)
					arr[j * sub_area.all_area.x + i] = (unsigned char)ink.color;
				j += 1;
			}
			i += 1;
		}
	}
}

// time : O(n)
// sapce: O(1)
void	draw_mondrian_tiling_int(t_table_fdf *dst, t_line rectangle, int ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && tiling_area.y > 0 && i < f_floor(dst->row / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->col / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			draw_rectangle_int(dst, rectangle, tiling, ink);
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// sapce: O(1)
void	draw_mondrian_tiling_uchar(t_table_fdf *dst, t_line rectangle, t_ink ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && tiling_area.y > 0 && i < f_floor(dst->row / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->col / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			draw_rectangle_uchar(dst, rectangle, tiling, ink);
			j += 1;
		}
		i += 1;
	}
}
