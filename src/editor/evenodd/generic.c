#include "evenodd.h"

/**
 * Get the standard coordinate of a cell in the FDF table.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table containing the cell
 * @param index index of the cell
 * @param zoom coordinate scaling factor
 *
 * @return complex coordinate of the selected cell.
 */
t_complex	get_table_fdf_coordinate(const t_table_fdf *dst, size_t index, float zoom)
{
	t_complex	y;

	y.re = 0;
	y.im = 0;
	if (dst == NULL || dst->row == 0 || dst->col == 0)
		return (y);
	y.re = (float)dst->col / 2.0 - (float)index / (float)dst->col;
	y.im = (float)(index % dst->col) - (float)dst->row / 2.0;
	y.re *= zoom;
	y.im *= zoom;
	return (y);
}

/**
 * Check whether the conjugate function of a cell's coordinate
 * produces an odd value after applying an optional complex function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating the conjugate value
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_conjugate_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a))
{
	t_complex	y;
	int			conjugate;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 0.1);
	if (complex_func != NULL)
		y = complex_func(y);
	conjugate = (int)f_round(y.re * y.re - y.im * y.im);
	if (conjugate % 2 == 0)
		return (false);
	return (true);
}

/**
 * Check whether the conjugate function of a cell's coordinate
 * produces an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_conjugate(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, NULL));
}

/**
 * Check whether the magnitude of a cell's coordinate is odd after
 * applying an optional complex function.
 *
 * time : O(1)
 * space: O(1)
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
 * Check whether the magnitude of a cell's coordinate is odd.
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
