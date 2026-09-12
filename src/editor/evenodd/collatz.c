#include "evenodd.h"

/**
 * Find the maximum value reached by the Collatz sequence of an input.
 *
 * time/space: O(???) but might be O(log(n)),
 * this is an open problem! / O(1)
 *
 * status: public api
 * 
 * The sequence is limited to 10000 iterations.
 */
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

/**
 * Check whether the maximum point of a cell's magnitude's Collatz sequence,
 * divided by 7, is odd.
 *
 * time/space: O(???) but might be O(log(n)), this is an open problem! / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool	is_collatz_odd(const t_table_fdf *dst, size_t index)
{
	int			input;
	size_t		max;
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	input = f_round(complex_magnitude(y, 0));
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (false);
	return (true);
}

/**
 * Check whether the maximum point of the Collatz sequence generated
 * from the product of a cell's coordinate components, divided by 7,
 * is odd.
 *
 * time/space: O(???) but might be O(log(n)), this is an open problem! / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool	is_collatz_x_odd(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			input;
	size_t		max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	input = f_round(y.re) * f_round(y.im);
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (false);
	return (true);
}
