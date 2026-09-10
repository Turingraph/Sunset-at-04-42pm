#include"filter.h"

// time : O(???) but might be O(log(n))
// space: O(1)
bool	is_collatz_coloring(const t_table_fdf *dst, size_t index)
{
	int		input;
	size_t	max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	input = f_round(complex_magnitude(
		get_table_fdf_coordinate(dst, index), 0));
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (false);
	return (true);
}

// time : O(???) but might be O(log(n))
// space: O(1)
bool	is_collatz_x_coloring(const t_table_fdf *dst, size_t index)
{
	t_complex	cinput;
	int			input;
	size_t		max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	cinput = get_table_fdf_coordinate(dst, index);
	input = f_round(cinput.re) * f_round(cinput.im);
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (false);
	return (true);
}

// time : O(log(n))
// space: O(1)
bool	is_binary_search_coloring(const t_table_fdf *dst, size_t index)
{
	int		input;
	size_t	max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	input = f_round(complex_magnitude(
		get_table_fdf_coordinate(dst, index), 0));
	if (input < 0)
		input *= -1;
	max = binary_search_count((size_t)input,
		(size_t)f_round(f_root_finding(dst->row * dst->row + dst->col * dst->col, 2)));
	if (max % 2 == 0)
		return (false);
	return (true);
}

// time : O(log(n))
// space: O(1)
bool	is_binary_search_x_coloring(const t_table_fdf *dst, size_t index)
{
	t_complex	cinput;
	int			input;
	size_t		max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	cinput = get_table_fdf_coordinate(dst, index);
	input = (int)f_round(cinput.re) * (int)f_round(cinput.im);
	if (input < 0)
		input *= -1;
	max = binary_search_count((size_t)input, dst->row * dst->col);
	if (max % 2 == 0)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_chess_cell(const t_table_fdf *dst, size_t index)
{
	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	if ((index / dst->col + index % dst->col) % 2 == 1)
		return (true);
	return (false);
}
