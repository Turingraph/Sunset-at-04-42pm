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
bool	is_oddlength_square(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_square));
}

// time : O(1)
// space: O(1)
bool	is_oddlength_cube(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_cube));
}

// time : O(1)
// space: O(1)
bool	is_oddlength_sin(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_sin));
}

// time : O(1)
// space: O(1)
bool	is_oddlength_cos(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_cos));
}

// time : O(1)
// space: O(1)
bool	is_oddlength_exp(const t_table_fdf *dst, size_t index)
{
	return (is_oddlength_func(dst, index, complex_exp));
}
