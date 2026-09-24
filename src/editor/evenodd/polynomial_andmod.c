#include "evenodd.h"

/**
 * Check whether the ax^2 and ay^2 of the cell is an odd value.
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
bool	is_andmod_x2(const t_table_fdf *dst, size_t index)
{
	return (is_andmod_func(dst, index, complex_square, 0.075));
}

/**
 * Check whether the ax^3 and ay^3 of the cell is an odd value.
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
bool	is_andmod_x3(const t_table_fdf *dst, size_t index)
{
	return (is_andmod_func(dst, index, complex_cube, 0.05));
}

/**
 * Check whether the ax^4 and ay^4 of the cell is an odd value.
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
bool	is_andmod_x4(const t_table_fdf *dst, size_t index)
{
	return (is_andmod_func(dst, index, complex_x4, 0.5));
}

/**
 * Check whether the ax^5 and ay^5 of the cell is an odd value.
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
bool	is_andmod_x5(const t_table_fdf *dst, size_t index)
{
	return (is_andmod_func(dst, index, complex_x5, 0.05));
}

/**
 * Check whether the ax^6 and ay^6 of the cell is an odd value.
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
bool	is_andmod_x6(const t_table_fdf *dst, size_t index)
{
	return (is_andmod_func(dst, index, complex_x6, 0.03));
}
