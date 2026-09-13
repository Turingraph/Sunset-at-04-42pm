#include "evenodd.h"

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the squared cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_re2_diff_im2_square(const t_table_fdf *dst, size_t index)
{
	return (is_re2_diff_im2_odd_func(dst, index, complex_square));
}

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the cubed cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_cube(const t_table_fdf *dst, size_t index)
{
	return (is_re2_diff_im2_odd_func(dst, index, complex_cube));
}

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the sin of the cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_sin(const t_table_fdf *dst, size_t index)
{
	return (is_re2_diff_im2_odd_func(dst, index, complex_sin));
}

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the cos of the cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_cos(const t_table_fdf *dst, size_t index)
{
	return (is_re2_diff_im2_odd_func(dst, index, complex_cos));
}

/**
 * Check whether the real-part square minus the imaginary-part square
 * of the exponent of the cell coordinate is odd.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @return true if the calculated value is odd, false otherwise.
*/
bool	is_re2_diff_im2_exp(const t_table_fdf *dst, size_t index)
{
	return (is_re2_diff_im2_odd_func(dst, index, complex_exp));
}
