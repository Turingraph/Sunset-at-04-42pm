#include "evenodd.h"

// time : O(???) but might be O(log(n)), this is an open problem!
// space: O(1)
size_t	collatz_max_point(size_t x)
{
	size_t	max;
	size_t	limit;

	max = 0;
	if (max < x)
		max = x;
	limit = 0;
	while (limit < 10000 && x > 1)
	{
		if (max < x)
			max = x;
		if (x % 2 == 0)
			x /= 2;
		else
			x = 3 * x + 1;
		limit += 1;
	}
	return (max);
}

// time : O(???) but might be O(log(n))
// space: O(1)
bool	is_collatz_odd(const t_table_fdf *dst, size_t index)
{
	int			input;
	size_t		max;
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate_small(dst, index);
	input = f_round(complex_magnitude(y, 0));
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (false);
	return (true);
}

// time : O(???) but might be O(log(n))
// space: O(1)
bool	is_collatz_x_odd(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			input;
	size_t		max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate_small(dst, index);
	input = f_round(y.re) * f_round(y.im);
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (false);
	return (true);
}
