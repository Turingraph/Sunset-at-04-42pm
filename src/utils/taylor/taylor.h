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

// stats.c

double		normal_distribution(double std, double means, double x);
float		f_std(const float *vec_v, size_t dim);
float		f_sum(const float *vec_v, size_t dim);

// taylor.c

double		f_pow(double x, size_t a);
double		f_root_finding(double x, size_t a);
double		f_sin(double x);
double		f_cos(double x);
double		f_exp(double x);

#endif
