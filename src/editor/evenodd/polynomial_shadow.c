#include "evenodd.h"

/**
 * Check whether constant times magnitude of the square of a cell's
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
bool	is_oddlength_x2shadow(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_square, 0.1));
}

/**
 * Check whether constant times magnitude of the cube of a cell's
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
bool	is_oddlength_x3shadow(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_cube, 0.05));
}
