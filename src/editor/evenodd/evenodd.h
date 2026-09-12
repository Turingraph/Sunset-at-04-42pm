#ifndef EVENODD_H
# define EVENODD_H

#include "../../utils/libft/libft.h"
#include "../../utils/green_counts/green_counts.h"

// binary_search.c

bool		is_binary_search_odd(const t_table_fdf *dst, size_t index);
bool		is_binary_search_x_odd(const t_table_fdf *dst, size_t index);

// collatz.c

bool		is_collatz_odd(const t_table_fdf *dst, size_t index);
bool		is_collatz_x_odd(const t_table_fdf *dst, size_t index);

// conjugate.c

bool		is_conjugate_square(const t_table_fdf *dst, size_t index);
bool		is_conjugate_cube(const t_table_fdf *dst, size_t index);
bool		is_conjugate_sin(const t_table_fdf *dst, size_t index);
bool		is_conjugate_cos(const t_table_fdf *dst, size_t index);
bool		is_conjugate_exp(const t_table_fdf *dst, size_t index);

// generic.c

t_complex	get_table_fdf_coordinate(const t_table_fdf *dst, size_t index, float zoom);
bool		is_conjugate_func(const t_table_fdf *dst, size_t index,
				t_complex (*complex_func)(t_complex a));
bool		is_conjugate(const t_table_fdf *dst, size_t index);
bool		is_oddlength_func(const t_table_fdf *dst, size_t index,
				t_complex (*complex_func)(t_complex a));
bool		is_oddlength(const t_table_fdf *dst, size_t index);

// length.c

bool		is_oddlength_square(const t_table_fdf *dst, size_t index);
bool		is_oddlength_cube(const t_table_fdf *dst, size_t index);
bool		is_oddlength_sin(const t_table_fdf *dst, size_t index);
bool		is_oddlength_cos(const t_table_fdf *dst, size_t index);
bool		is_oddlength_exp(const t_table_fdf *dst, size_t index);

#endif
