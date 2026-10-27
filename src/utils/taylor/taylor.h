/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taylor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:28:15 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:21:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAYLOR_H
# define TAYLOR_H

# include <stdlib.h>
# include "../libft/libft.h"

# ifndef MAXIMUM_ERROR
#  define MAXIMUM_ERROR 1e-8
# endif

# ifndef MAXIMUM_TERM
#  define MAXIMUM_TERM 24
# endif

# ifndef PI
#  define PI 3.141592653589
# endif

// complex_trig.c

t_float2d	complex_exp(t_float2d a);
t_float2d	complex_sin(t_float2d a);
t_float2d	complex_cos(t_float2d a);

// complex.c

t_float2d	complex_multiplication(t_float2d a, t_float2d b);
t_float2d	complex_reciprocal(t_float2d a);
float		complex_magnitude(t_float2d a, char is_square);
t_float2d	complex_square(t_float2d a);
t_float2d	complex_polynomial(t_float2d a, size_t power, size_t reciprocal);

// discrete.c

size_t		f_bisearch_count(size_t min_input, size_t max_input);
size_t		f_collatz_max(size_t x, size_t div, size_t mul);
void		f_fibonacci_custom(size_t x, size_t *a0, size_t *a1, size_t *a2);
size_t		f_fibonacci(size_t x);

// stats.c

double		f_normal(double std, double means, double x);
float		f_std(const float *vec_v, size_t dim);
float		f_sum(const float *vec_v, size_t dim);

// taylor.c

double		f_pow(double x, size_t a);
double		f_root_find(double x, size_t a);
double		f_sin(double x);
double		f_cos(double x);
double		f_exp(double x);

#endif
