#include "evenodd.h"

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether Re(z')^2 - Im(z')^2 produces an odd integer.
 *
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating the value
 *
 * @return true if the rounded calculated value is odd,
 * false otherwise.
 */
bool	is_re2_diff_im2_odd_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;
	int			product;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 0.5);
	if (complex_func != NULL)
		y = complex_func(y);
	product = (int)f_round(y.re * y.re - y.im * y.im);
	if (product % 2 == 0)
		return (false);
	return (true);
}

/**
 * Compute z' = the complex coordinate of the cell.
 * Then check whether Re(z')^2 - Im(z')^2 produces an odd integer.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the rounded calculated value is odd,
 * false otherwise.
 */
bool	is_re2_diff_im2_odd(const t_table_fdf *dst, size_t index)
{
	return (is_re2_diff_im2_odd_func(dst, index, NULL));
}

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating its magnitude
 *
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
bool	is_oddlength_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 0.1);
	if (complex_func != NULL)
		y = complex_func(y);
	if ((int)f_round(complex_magnitude(y, 0)) % 2 == 1)
		return (true);
	return (false);
}

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
bool	is_oddlength(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, NULL));
}
