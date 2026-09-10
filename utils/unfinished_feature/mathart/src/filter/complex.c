#include "filter.h"

// time : O(1)
// space: O(1)
bool	is_complex_square(const t_table_fdf *dst, size_t index)
{
	return (is_complex_func(dst, index, complex_square));
}

// time : O(1)
// space: O(1)
bool	is_complex_cube(const t_table_fdf *dst, size_t index)
{
	return (is_complex_func(dst, index, complex_cube));
}

// time : O(1)
// space: O(1)
bool	is_complex_sin(const t_table_fdf *dst, size_t index)
{
	return (is_complex_func(dst, index, complex_sin));
}

// time : O(1)
// space: O(1)
bool	is_complex_reciprocal(const t_table_fdf *dst, size_t index)
{
	return (is_complex_func(dst, index, complex_reciprocal));
}

// I will implement this function after submit fdf42 coding project.
// time : O(1)
// space: O(1)
bool	is_complex_log(const t_table_fdf *dst, size_t index)
{
	return (is_complex_func(dst, index, complex_square));
}
