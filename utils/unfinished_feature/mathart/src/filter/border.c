#include "filter.h"

// time : O(1)
// space: O(1)
int	count_2_fdf_triangles_bool(const t_table_fdf *dst, size_t index)
{
	int		y;

	y = 0;
	if (index >= (dst->row - 1) * (dst->col - 1))
		return (-1);
	if (dst->arr[index] > 0)
		y += 1;
	if (dst->arr[index + dst->col] > 0)
		y += 1;
	if (dst->arr[index + dst->col + 1] > 0)
		y += 1;
	if (dst->arr[index + 1] > 0)
		y += 1;
	if (y >= 3)
		return (y / 2);
	return (0);
}

// time : O(1)
// space: O(1)
bool	is_in_prism_border(const t_table_fdf *dst, size_t index)
{
	int	y;

	if (dst == NULL || index >= (dst->row - 1) * (dst->col - 1))
		return (false);
	y = count_2_fdf_triangles_bool(dst, index);
	if (y == 1)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_in_prism_terrain(const t_table_fdf *dst, size_t index)
{
	int	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = count_2_fdf_triangles_bool(dst, index);
	if (y == 2)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_greater_than_magnitude(const t_table_fdf *dst, size_t index)
{
	int			y;
	t_complex	coordinate;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	coordinate = get_table_fdf_coordinate(dst, index);
	y = complex_magnitude(coordinate, false);
	if (dst->arr[index] > y)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_greater_than_conjugate(const t_table_fdf *dst, size_t index)
{
	int			y;
	t_complex	coordinate;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	coordinate = get_table_fdf_coordinate(dst, index);
	y = coordinate.re * coordinate.re - coordinate.im * coordinate.im;
	if (dst->arr[index] > y)
		return (true);
	return (false);
}
