#include "evenodd.h"

/**
 * Check whether the conjugate function of the square of a cell's
 * coordinate produces an odd value.
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
bool	is_conjugate_square(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_square));
}

/**
 * Check whether the conjugate function of the cube of a cell's
 * coordinate produces an odd value.
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
bool	is_conjugate_cube(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_cube));
}

/**
 * Check whether the conjugate function of the sin of a cell's
 * coordinate produces an odd value.
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
bool	is_conjugate_sin(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_sin));
}

/**
 * Check whether the conjugate function of the cos of a cell's
 * coordinate produces an odd value.
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
bool	is_conjugate_cos(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_cos));
}

/**
 * Check whether the conjugate function of the exponential of a cell's
 * coordinate produces an odd value.
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
bool	is_conjugate_exp(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_exp));
}
