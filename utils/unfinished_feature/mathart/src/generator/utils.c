#include"generator.h"

// time : O(1)
// space: O(1)
int	gen_conjugate_func(const t_table_fdf *dst, size_t index, t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index);
	if (complex_func != NULL)
		y = complex_func(y);
	return ((int)f_round(y.re * y.re - y.im * y.im));
}

// time : O(1)
// space: O(1)
int	gen_conjugate(const t_table_fdf *dst, size_t index)
{
	return gen_conjugate_func(dst, index, NULL);
}

// time : O(1)
// space: O(1)
int	gen_complex_func(const t_table_fdf *dst, size_t index, t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index);
	if (complex_func != NULL)
		y = complex_func(y);
	return ((int)f_round(complex_magnitude(y, 0)));
}

// time : O(1)
// space: O(1)
int	gen_complex(const t_table_fdf *dst, size_t index)
{
	return gen_complex_func(dst, index, NULL);
}

// time : O(1)
// space: O(1)
int	gen_gaussian_bell_curve(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index);
	return ((int)f_round(f_exp(-1 * (y.re * y.re + y.im * y.im))));
}
