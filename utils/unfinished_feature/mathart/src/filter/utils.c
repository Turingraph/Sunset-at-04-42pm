#include"filter.h"

// time : O(1)
// space: O(1)
bool	is_conjugate_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;
	int			conjugate;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index);
	y = complex_func(y);
	conjugate = (int)f_round(y.re * y.re - y.im * y.im);
	if (conjugate % 2 == 0)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_conjugate(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, NULL));
}

// time : O(1)
// space: O(1)
bool	is_complex_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index);
	y = complex_func(y);
	if ((int)f_round(complex_magnitude(y, 0)) % 2 == 1)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_complex(const t_table_fdf *dst, size_t index)
{
	return (is_complex_func(dst, index, NULL));
}

// time : O(1)
// space: O(1)
bool	is_positive_cell(const t_table_fdf *dst, size_t index)
{
	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	if (dst->arr != NULL && dst->arr[index] > 0)
		return (true);
	return (false);
}
