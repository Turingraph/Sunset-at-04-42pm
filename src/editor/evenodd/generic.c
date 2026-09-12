#include "evenodd.h"

// time : O(1)
// space: O(1)
t_complex	get_table_fdf_coordinate_small(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	y.re = 0;
	y.im = 0;
	if (dst == NULL || dst->row == 0 || dst->col == 0)
		return (y);
	y.re = (float)dst->col / 2.0 - (float)index / (float)dst->col;
	y.im = (float)(index % dst->col) - (float)dst->row / 2.0;
	y.re *= 0.1;
	y.im *= 0.1;
	return (y);
}

// time : O(1)
// space: O(1)
bool	is_conjugate_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;
	int			conjugate;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate_small(dst, index);
	if (complex_func != NULL)
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
bool	is_oddlength_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate_small(dst, index);
	if (complex_func != NULL)
		y = complex_func(y);
	if ((int)f_round(complex_magnitude(y, 0)) % 2 == 1)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_oddlength(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, NULL));
}
