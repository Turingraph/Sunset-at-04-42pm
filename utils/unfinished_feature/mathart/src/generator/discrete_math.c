#include"generator.h"

// time : O(???) but might be O(log(n))
// space: O(1)
int	gen_collatz_coloring(const t_table_fdf *dst, size_t index)
{
	int			input;
	size_t		max;
	t_complex	position;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	position = get_table_fdf_coordinate(dst, index);
	input = (int)f_round(complex_magnitude(position, index));
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input);
	return ((int)max);
}

// time : O(???) but might be O(log(n))
// space: O(1)
int	gen_collatz_x_coloring(const t_table_fdf *dst, size_t index)
{
	t_complex	cinput;
	int			input;
	size_t		max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	cinput = get_table_fdf_coordinate(dst, index);
	input = (int)f_round(cinput.re * cinput.re - cinput.im * cinput.im);
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input);
	return ((int)max);
}

// time : O(log(n))
// space: O(1)
int	gen_binary_search_coloring(const t_table_fdf *dst, size_t index)
{
	int		input;
	size_t	max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	input = f_round(complex_magnitude(
		get_table_fdf_coordinate(dst, index), 0));
	if (input < 0)
		input *= -1;
	max = binary_search_count((size_t)input,
		(size_t)f_round(f_root_finding(dst->row * dst->row + dst->col * dst->col, 2)));
	return ((int)max);
}

// time : O(log(n))
// space: O(1)
int	gen_binary_search_x_coloring(const t_table_fdf *dst, size_t index)
{
	t_complex	cinput;
	int			input;
	size_t		max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	cinput = get_table_fdf_coordinate(dst, index);
	input = (int)f_round(cinput.re) * (int)f_round(cinput.im);
	if (input < 0)
		input *= -1;
	max = binary_search_count((size_t)input, dst->row * dst->col);
	return ((int)max);
}
