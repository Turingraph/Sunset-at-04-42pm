#include "evenodd.h"

/**
 * Count the number of iterations required by a binary-search procedure
 * to locate min_input within the range [0, max_input].
 *
 * If min_input is greater than max_input, their values are exchanged
 * before performing the search.
 *
 * time/space: O(log(n)) / O(1)
 *
 * @param min_input target value to search for
 * @param max_input upper bound of the search range
 * @return number of binary-search iterations
 */
size_t	binary_search_count(size_t min_input, size_t max_input)
{
	size_t	min;
	size_t	mid;
	size_t	max;
	size_t	count;

	if (min_input > max_input)
	{
		min = min_input;
		min_input = max_input;
		max_input = min;
	}
	count = 0;
	min = 0;
	mid = (min + max_input) / 2;
	max = max_input;
	while (mid != min_input && min < max)
	{
		mid = (min + max) / 2;
		if (min_input < mid)
			max = mid;
		else
			min = mid + 1;
		count += 1;
	}
	return (count);
}

/**
 * Check whether the number of iterations of a binary-search procedure
 * is odd when searching for the rounded magnitude of a cell's complex
 * coordinate within the table's diagonal-length range.
 *
 * The coordinate magnitude is used as the search target, while the
 * rounded diagonal length of the table is used as the upper bound.
 *
 * time/space: O(log(n)) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the binary-search iteration count is odd,
 * false otherwise.
 */
bool	is_binary_search_length_odd(const t_table_fdf *dst, size_t index)
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
	max = binary_search_count((size_t)input,
		(size_t)f_round(f_root_finding(dst->row * dst->row + dst->col * dst->col, 2)));
	if (max % 2 == 0)
		return (false);
	return (true);
}

/**
 * Check whether the number of iterations of a binary-search procedure
 * is odd when searching for the absolute product of a cell's rounded
 * real and imaginary coordinates within the table's cell-count range.
 *
 * The search target is:
 *
 *     |round(Re(z)) * round(Im(z))|
 *
 * and the upper bound is the total number of cells in the table.
 *
 * time/space: O(log(n)) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the binary-search iteration count is odd,
 * false otherwise.
 */
bool	is_binary_search_product_odd(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			input;
	size_t		max;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	input = (int)f_round(y.re) * (int)f_round(y.im);
	if (input < 0)
		input *= -1;
	max = binary_search_count((size_t)input, dst->row * dst->col);
	if (max % 2 == 0)
		return (false);
	return (true);
}
