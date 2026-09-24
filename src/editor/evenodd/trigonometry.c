#include "evenodd.h"

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
	return (is_oddlength_func(dst, index, complex_sin, 0.1));
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
	return (is_oddlength_func(dst, index, complex_cos, 0.1));
}

/**
 * Check whether the magnitude of the sin of a cell's
 * x or y is an even value.
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
bool	is_ormod_sin(const t_table_fdf *dst, size_t index)
{
	return (is_ormod_func(dst, index, complex_sin, 0.075));
}

/**
 * Check whether the magnitude of the cos of a cell's
 * x or y is an even value.
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
bool	is_ormod_cos(const t_table_fdf *dst, size_t index)
{
	return (is_ormod_func(dst, index, complex_cos, 0.075));
}
