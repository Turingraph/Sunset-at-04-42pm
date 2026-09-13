#include "evenodd.h"

/**
 * Check whether the magnitude of the square of a cell's
 * complex coordinate is an odd value.
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
bool	is_oddlength_square(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_square));
}

/**
 * Check whether the magnitude of the cube of a cell's
 * complex coordinate is an odd value.
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
bool	is_oddlength_cube(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_cube));
}

/**
 * Check whether the magnitude of the sin of a cell's
 * complex coordinate is an odd value.
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
bool	is_oddlength_sin(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_sin));
}

/**
 * Check whether the magnitude of the cos of a cell's
 * complex coordinate is an odd value.
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
bool	is_oddlength_cos(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_cos));
}

/**
 * Check whether the magnitude of exponential of a cell's
 * complex coordinate is an odd value.
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
bool	is_oddlength_exp(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_exp));
}
