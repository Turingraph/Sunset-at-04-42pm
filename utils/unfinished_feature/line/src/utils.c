#include"line.h"

// time : O(1)
// space: O(1)
bool	is_in_boundary(int x, int y, t_line boundary)
{
	if (x >= boundary.p1.x
		&& x < boundary.p2.x
		&& y >= boundary.p1.y
		&& y < boundary.p2.y)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
t_line	define_circle_boundary(t_circle point, int ix, int iy, char mode)
{
	t_line	dst;

	dst.p1.x = point.x - ix;
	dst.p1.y = point.y + iy;
	dst.p2.x = point.x + ix;
	dst.p2.y = point.y + iy;
	if (mode == 1)
	{
		dst.p1.y = point.y - iy;
		dst.p2.y = point.y - iy;
	}
	if (mode == 2 || mode == 3)
	{
		dst.p1.x = point.x - iy;
		dst.p1.y = point.y + ix;
		dst.p2.x = point.x + iy;
		dst.p2.y = point.y + ix;
	}
	if (mode == 3)
	{
		dst.p1.y = point.y - ix;
		dst.p2.y = point.y - ix;
	}
	return (dst);
}

// time : O(1)
// space: O(1)
t_line	reverse_line(t_line line)
{
	t_line	dst;

	dst.p1.x = line.p2.x;
	dst.p1.y = line.p2.y;
	dst.p2.x = line.p1.x;
	dst.p2.y = line.p1.y;
	return (dst);
}

// time : O(1)
// space: O(1)
t_line	get_tiling(t_2d_int tiling_area, size_t i, size_t j)
{
	t_line	tiling;

	tiling.p1.x = tiling_area.x * j;
	tiling.p1.y = tiling_area.y * i;
	tiling.p2.x = tiling_area.x * (j + 1);
	tiling.p2.y = tiling_area.y * (i + 1);
	return (tiling);
}

// time : O(1)
// space: O(1)
t_boundary	get_all_area(size_t row, size_t col)
{
	t_boundary	dst;

	dst.all_area.x = col;
	dst.all_area.y = row;
	dst.sub_area.p1.x = 0;
	dst.sub_area.p1.y = 0;
	dst.sub_area.p2.x = col;
	dst.sub_area.p2.y = row;
	return (dst);
}
