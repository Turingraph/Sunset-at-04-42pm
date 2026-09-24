#ifndef EVENODD_H
# define EVENODD_H

#include "../../utils/libft/libft.h"
#include "../../utils/green_counts/green_counts.h"

// binary_search.c

size_t		binary_search_count(size_t min_input, size_t max_input);
bool		is_binary_search_length_odd(const t_table_fdf *dst, size_t index);
bool		is_binary_search_product_odd(const t_table_fdf *dst, size_t index);
bool		is_binary_search_andmod(const t_table_fdf *dst, size_t index);

// collatz.c

size_t		collatz_max_point(size_t x);
bool		is_collatz_odd_length(const t_table_fdf *dst, size_t index);
bool		is_collatz_odd_product(const t_table_fdf *dst, size_t index);
bool		is_collatz_odd_andmod(const t_table_fdf *dst, size_t index);

// generic.c

bool		is_re2_diff_im2_odd_func(const t_table_fdf *dst, size_t index,
				t_complex (*complex_func)(t_complex a), float zoom);
bool		is_re2_diff_im2_odd(const t_table_fdf *dst, size_t index);
bool		is_oddlength_func(const t_table_fdf *dst, size_t index,
				t_complex (*complex_func)(t_complex a), float zoom);
bool		is_oddlength(const t_table_fdf *dst, size_t index);
bool		is_andmod_func(const t_table_fdf *dst, size_t index,
				t_complex (*complex_func)(t_complex a), float zoom);

// polynomial_andmod.c

bool		is_andmod_x2(const t_table_fdf *dst, size_t index);
bool		is_andmod_x3(const t_table_fdf *dst, size_t index);
bool		is_andmod_x4(const t_table_fdf *dst, size_t index);
bool		is_andmod_x5(const t_table_fdf *dst, size_t index);
bool		is_andmod_x6(const t_table_fdf *dst, size_t index);

// polynomial_length.c

bool		is_oddlength_x2(const t_table_fdf *dst, size_t index);
bool		is_oddlength_x3(const t_table_fdf *dst, size_t index);
bool		is_oddlength_x4(const t_table_fdf *dst, size_t index);
bool		is_oddlength_x5(const t_table_fdf *dst, size_t index);
bool		is_oddlength_x6(const t_table_fdf *dst, size_t index);

// polynomial_shadow.c

bool		is_oddlength_x2shadow(const t_table_fdf *dst, size_t index);
bool		is_oddlength_x3shadow(const t_table_fdf *dst, size_t index);
bool		is_andmod_x2shadow(const t_table_fdf *dst, size_t index);
bool		is_andmod_x3shadow(const t_table_fdf *dst, size_t index);

// trigonometry.c

bool		is_oddlength_sin(const t_table_fdf *dst, size_t index);
bool		is_oddlength_cos(const t_table_fdf *dst, size_t index);
bool		is_andmod_sin(const t_table_fdf *dst, size_t index);
bool		is_andmod_cos(const t_table_fdf *dst, size_t index);

#endif
