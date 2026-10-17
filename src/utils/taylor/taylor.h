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
# include "../libft/type.h"

# ifndef MAXIMUM_ERROR
#  define MAXIMUM_ERROR 1e-4
# endif

# ifndef MAXIMUM_TERM
#  define MAXIMUM_TERM 8
# endif

// abs.c

float		f_abs(float x);
int			f_abs_int(int x);

// complex_polynomial.c

t_2d_float	complex_square(t_2d_float a);
t_2d_float	complex_cube(t_2d_float a);
t_2d_float	complex_x4(t_2d_float a);
t_2d_float	complex_x5(t_2d_float a);
t_2d_float	complex_x6(t_2d_float a);

// complex_trig.c

t_2d_float	complex_exp(t_2d_float a);
t_2d_float	complex_sin(t_2d_float a);
t_2d_float	complex_cos(t_2d_float a);

// complex.c

t_2d_float	complex_multiplication(t_2d_float a, t_2d_float b);
t_2d_float	complex_reciprocal(t_2d_float a);
float		complex_magnitude(t_2d_float a, char is_square);

// interval.c

float		f_floor(float num);
float		f_round(float num);
float		f_interval(float num, float min, float max);
int			f_interval_int(int num, int min, int max);

// minmax.c

float		f_max(float a, float b);
float		f_min(float a, float b);
int			f_max_int(int a, int b);
int			f_min_int(int a, int b);

// stats.c

float		normal_distribution_function(float std, float means, float x);
float		f_std(const float *vec_v, size_t dim);
float		f_sum(const float *vec_v, size_t dim);

// taylor.c

float		f_pow(float x, size_t a);
float		f_root_finding(float x, size_t a);
float		f_sin(float x);
float		f_cos(float x);
float		f_exp(float x);

#endif
