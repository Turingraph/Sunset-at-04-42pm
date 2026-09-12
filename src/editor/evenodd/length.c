#include "evenodd.h"


// time : O(1)
// space: O(1)
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
