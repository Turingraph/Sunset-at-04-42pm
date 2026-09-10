#ifndef GENERATOR_H
# define GENERATOR_H

#include"../../../utils/libft/libft.h"
#include"../../../utils/green_counts/green_counts.h"

/*
I will finish this folder after submit fdf42 project.
*/

/*
List of unfinished function that I will implement after submit fdf42.
1.	gen_conjugate_log
2.	gen_complex_log
*/

// complex.c
int	gen_complex_square(const t_table_fdf *dst, size_t index);
int	gen_complex_cube(const t_table_fdf *dst, size_t index);
int	gen_complex_sin(const t_table_fdf *dst, size_t index);
int	gen_complex_log(const t_table_fdf *dst, size_t index);
int	gen_complex_reciprocal(const t_table_fdf *dst, size_t index);

// conjugate.c
int	gen_conjugate_square(const t_table_fdf *dst, size_t index);
int	gen_conjugate_cube(const t_table_fdf *dst, size_t index);
int	gen_conjugate_sin(const t_table_fdf *dst, size_t index);
int	gen_conjugate_log(const t_table_fdf *dst, size_t index);
int	gen_conjugate_reciprocal(const t_table_fdf *dst, size_t index);

// discrete_math.c
int	gen_collatz_coloring(const t_table_fdf *dst, size_t index);
int	gen_collatz_x_coloring(const t_table_fdf *dst, size_t index);
int	gen_binary_search_coloring(const t_table_fdf *dst, size_t index);
int	gen_binary_search_x_coloring(const t_table_fdf *dst, size_t index);

// utils.c
int	gen_conjugate_func(const t_table_fdf *dst, size_t index, t_complex (*complex_func)(t_complex a));
int	gen_conjugate(const t_table_fdf *dst, size_t index);
int	gen_complex_func(const t_table_fdf *dst, size_t index, t_complex (*complex_func)(t_complex a));
int	gen_complex(const t_table_fdf *dst, size_t index);
int	gen_gaussian_bell_curve(const t_table_fdf *dst, size_t index);

#endif
