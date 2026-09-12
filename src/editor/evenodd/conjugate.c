#include "evenodd.h"

// time : O(1)
// space: O(1)
bool	is_conjugate_square(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_square));
}

// time : O(1)
// space: O(1)
bool	is_conjugate_cube(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_cube));
}

// time : O(1)
// space: O(1)
bool	is_conjugate_sin(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_sin));
}

// time : O(1)
// space: O(1)
bool	is_conjugate_cos(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_cos));
}

// time : O(1)
// space: O(1)
bool	is_conjugate_exp(const t_table_fdf *dst, size_t index)
{
	return (is_conjugate_func(dst, index, complex_exp));
}
