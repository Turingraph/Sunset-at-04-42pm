#include"line.h"

// time : O(1)
// space: O(1)
int	init_swap_bresenham_y(t_line *line,
	int *delta_x, int *delta_y)
{
	int	y;

	y = 1;
	if (line != NULL && delta_x != NULL && delta_y != NULL
		&& f_abs(line->p2.x - line->p1.x) < f_abs(line->p2.y - line->p1.y))
	{
		*delta_y = line->p2.x - line->p1.x;
		*delta_x = line->p2.y - line->p1.y;
		if (*delta_x < 0)
		{
			*delta_y = line->p1.x - line->p2.x;
			*delta_x = line->p1.y - line->p2.y;
			y = 2;
		}
		if (*delta_y < 0)
		{
			*delta_y += 1;
			return (y * -1);
		}
		return (y);
	}
	return (0);
}

// time : O(1)
// space: O(1)
int	init_swap_bresenham_x(t_line *line,
	int *delta_x, int *delta_y)
{
	int	y;

	y = 1;
	if (line != NULL && delta_x != NULL && delta_y != NULL
		&& f_abs(line->p2.x - line->p1.x) >= f_abs(line->p2.y - line->p1.y))
	{
		*delta_x = line->p2.x - line->p1.x;
		*delta_y = line->p2.y - line->p1.y;
		if (*delta_x < 0)
		{
			*delta_x = line->p1.x - line->p2.x;
			*delta_y = line->p1.y - line->p2.y;
			y = 2;
		}
		if (*delta_y < 0)
		{
			*delta_y += 1;
			return (y * -1);
		}
		return (y);
	}
	return (0);
}

// time : O(1)
// space: O(1)
t_boundary	init_rectangle_boundary(t_line sub_area, size_t row, size_t col)
{
	int			temp;
	t_boundary	dst;

	dst.all_area.x = (int)col;
	dst.all_area.y = (int)row;
	dst.sub_area.p1.x = (int)f_interval(sub_area.p1.x, 0, col);
	dst.sub_area.p1.y = (int)f_interval(sub_area.p1.y, 0, row);
	dst.sub_area.p2.x = (int)f_interval(sub_area.p2.x, 0, col);
	dst.sub_area.p2.y = (int)f_interval(sub_area.p2.y, 0, row);
	if (dst.sub_area.p1.x > dst.sub_area.p2.x)
	{
		temp = dst.sub_area.p1.x;
		dst.sub_area.p1.x = dst.sub_area.p2.x;
		dst.sub_area.p2.x = temp;
	}
	if (dst.sub_area.p1.y > dst.sub_area.p2.y)
	{
		temp = dst.sub_area.p1.y;
		dst.sub_area.p1.y = dst.sub_area.p2.y;
		dst.sub_area.p2.y = temp;
	}
	return (dst);
}

/*
I compute 
dst.p1.x = (int)f_interval(src.p1.x, 0,
	boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;

instead of compute
dst.p1.x = (int)f_interval(src.p1.x, 0,
	boundary.sub_area.p2.x - boundary.sub_area.p1.x);

because I want to "move" the entire line within the sub area of
the entire canvas (a.k.a. table_fdf).
*/

// time : O(1)
// space: O(1)
t_line	init_first_line(t_line src, t_boundary boundary)
{
	t_line	dst;

	dst.p1.x = (int)f_interval(src.p1.x, 0,
			boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;
	dst.p2.x = (int)f_interval(src.p2.x, 0,
			boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;
	dst.p1.y = (int)f_interval(src.p1.y, 0,
			boundary.sub_area.p2.y - boundary.sub_area.p1.y) + boundary.sub_area.p1.y;
	dst.p2.y = (int)f_interval(src.p2.y, 0,
			boundary.sub_area.p2.y - boundary.sub_area.p1.y) + boundary.sub_area.p1.y;
	return (dst);
}

/*
Note that I compute

return (int)f_floor(dst * (boundary.p2.y - boundary.p1.y));

instead of compute

return (int)f_floor(dst * (boundary.p2.y - boundary.p1.y)) + boundary.p1.y;

because I want to avoid adding the boundary.p1.y twice,
given that init_first_line already compute this term.
*/

// time : O(1)
// space: O(1)


int	float_to_2d_int(float src, t_line boundary, char mode)
{
	float	dst;

	dst = f_interval(src, 0, 1);
	if (mode == 1)
		return (int)f_floor(dst * (boundary.p2.y - 1 - boundary.p1.y));
	return (int)f_floor(dst * (boundary.p2.x - 1 - boundary.p1.x));
}
