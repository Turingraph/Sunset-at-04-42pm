#include "generator.h"

// time : O(1)
// space: O(1)
int	gen_conjugate_square(const t_table_fdf *dst, size_t index)
{
	return (gen_conjugate_func(dst, index, complex_square));
}

// time : O(1)
// space: O(1)
int	gen_conjugate_cube(const t_table_fdf *dst, size_t index)
{
	return (gen_conjugate_func(dst, index, complex_cube));
}

// time : O(1)
// space: O(1)
int	gen_conjugate_sin(const t_table_fdf *dst, size_t index)
{
	return (gen_conjugate_func(dst, index, complex_sin));
}

// time : O(1)
// space: O(1)
int	gen_conjugate_reciprocal(const t_table_fdf *dst, size_t index)
{
	return (gen_conjugate_func(dst, index, complex_reciprocal));
}

// I will implement this function after submit fdf42 coding project.
// time : O(1)
// space: O(1)
int	gen_conjugate_log(const t_table_fdf *dst, size_t index)
{
	return (gen_conjugate_func(dst, index, complex_square));
}

