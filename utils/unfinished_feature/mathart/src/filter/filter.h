#ifndef FILTER_H
# define FILTER_H

#include"../../../utils/libft/libft.h"
#include"../../../utils/green_counts/green_counts.h"
/*
I will finish this folder after submit fdf42 project.

I calculate manually and use Wolfarm Alpha to calculate the derivative of z^3.
Here is the result.
*	note that z = x+yi, where i = root of -1.
*	d/dz[z^3] = 3z^2 = 3 * (x^2-y^2+2xyi) = 3x^2 - 3y^2 + 6xyi
*	d/dx[(x+yi)^3] = 3x^2 - 3y^2 + 6xyi = d/dz[z^3]
*	d/dy[(x+yi)^3] = 3x^2i - 3y^2i - 6xy = d/dz[z^3i]

It "feel" that there might be a conjecture/theorem
that d/dx[f(z)] = d/dz[f(z)] and d/dy[f(z)] = d/dy[f(z)i].

ChatGPT said that this is the result of Cauchy–Riemann equations.

Also ChatGPT recommend me to use ln(1 - |J|) if |J| produce too saturated color.
where J = jacobian matrix of the complex value function.

According to Wolfarm Website ( https://mathworld.wolfram.com/Cauchy-RiemannEquations.html )
*	0 = d/dx f(x + yi) + i * d/dy f(x + yi)
*	d/dx f(x + yi) = - i * d/dy f(x + yi)

This implies that generating the curl, gradient, partial derivative,
and determanent of Jacobian Matrix of basic functions
e.g. polynomial, trigonometry, log, exponential etc.
might not yield interesting artistic result (according to my subjective taste).

One interesting idea that ChatGPT recommend me is to apply those operation, use f_round,
and then mod by 2, in FILTER (because f_round() % 2 isn't linear operator).
*/

/*
List of unfinished function that I will implement after submit fdf42.
1.	is_conjugate_log
2.	is_complex_log
*/

// border.c
bool	is_in_prism_border(const t_table_fdf *dst, size_t index);
bool	is_in_prism_terrain(const t_table_fdf *dst, size_t index);

// conjugate.c
bool	is_conjugate_square(const t_table_fdf *dst, size_t index);
bool	is_conjugate_cube(const t_table_fdf *dst, size_t index);
bool	is_conjugate_sin(const t_table_fdf *dst, size_t index);
bool	is_conjugate_reciprocal(const t_table_fdf *dst, size_t index);
bool	is_conjugate_log(const t_table_fdf *dst, size_t index);

// complex.c
bool	is_complex_square(const t_table_fdf *dst, size_t index);
bool	is_complex_cube(const t_table_fdf *dst, size_t index);
bool	is_complex_sin(const t_table_fdf *dst, size_t index);
bool	is_complex_log(const t_table_fdf *dst, size_t index);
bool	is_complex_reciprocal(const t_table_fdf *dst, size_t index);

// discrete_math.c
bool	is_collatz_coloring(const t_table_fdf *dst, size_t index);
bool	is_collatz_x_coloring(const t_table_fdf *dst, size_t index);
bool	is_binary_search_coloring(const t_table_fdf *dst, size_t index);
bool	is_binary_search_x_coloring(const t_table_fdf *dst, size_t index);
bool	is_chess_cell(const t_table_fdf *dst, size_t index);

// ormod.c
bool	is_ormod_square(const t_table_fdf *dst, size_t index);
bool	is_ormod_cube(const t_table_fdf *dst, size_t index);
bool	is_ormod_sin(const t_table_fdf *dst, size_t index);
bool	ormod_collatz_coloring(const t_table_fdf *dst, size_t index);

// utils.c
bool	is_positive_cell(const t_table_fdf *dst, size_t index);
bool	is_conjugate_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a));
bool	is_conjugate(const t_table_fdf *dst, size_t index);
bool	is_complex_func(const t_table_fdf *dst, size_t index,
	t_complex (*complex_func)(t_complex a));
bool	is_complex(const t_table_fdf *dst, size_t index);

#endif
