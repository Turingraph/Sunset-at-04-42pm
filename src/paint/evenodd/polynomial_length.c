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
bool	is_oddlength_x2(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_square, 0.2));
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
bool	is_oddlength_x3(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_cube, 0.1));
}

/**
 * Check whether constant times magnitude of the 4-th power of a cell's
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
bool	is_oddlength_x4(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_x4, 0.05));
}

/**
 * Check whether constant times magnitude of the 5-th power of a cell's
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
bool	is_oddlength_x5(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_x5, 0.05));
}


/**
 * Check whether constant times magnitude of the 6-th power of a cell's
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
bool	is_oddlength_x6(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_x6, 0.025));
}

