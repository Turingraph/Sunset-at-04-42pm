#include"filter.h"

// time : O(1)
// space: O(1)
bool	is_ormod_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index);
	y = complex_func(y);
	if ((int)f_round(y.im) % 2 == 1 || (int)f_round(y.re) % 2 == 1)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_ormod_square(const t_table_fdf *dst, size_t index)
{
	return (is_ormod_func(dst, index, complex_square));
}

// time : O(1)
// space: O(1)
bool	is_ormod_cube(const t_table_fdf *dst, size_t index)
{
	return (is_ormod_func(dst, index, complex_cube));
}

// time : O(1)
// space: O(1)
bool	is_ormod_sin(const t_table_fdf *dst, size_t index)
{
	return (is_ormod_func(dst, index, complex_sin));
}

// time : O(???) but might be O(log(n))
// space: O(1)
bool	ormod_collatz_coloring(const t_table_fdf *dst, size_t index)
{
	int		input_im;
	size_t	max_im;
	int		input_re;
	size_t	max_re;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	input_im = f_round(get_table_fdf_coordinate(dst, index).im);
	if (input_im < 0)
		input_im *= -1;
	max_im = collatz_max_point((size_t)input_im) / 7;
	input_re = f_round(get_table_fdf_coordinate(dst, index).re);
	if (input_re < 0)
		input_re *= -1;
	max_re = collatz_max_point((size_t)input_re) / 7;
	if (max_re % 2 == 1 || max_im % 2 == 1)
		return (false);
	return (true);
}
