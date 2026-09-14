/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:13 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/14 12:07:54 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

/**
 * compute (a.re + a.im) * (b.re + b.im)
 * 
 * status: public api
 * 
 */
t_complex	complex_multiplication(t_complex a, t_complex b)
{
	t_complex	dst;

	dst.re = a.re * b.re - a.im * b.im;
	dst.im = a.re * b.im + a.im * b.re;
	return (dst);
}

/**
 * compute (a.re + a.im)^2
 * 
 * status: public api
 * 
 */
t_complex	complex_square(t_complex a)
{
	return (complex_multiplication(a, a));
}

/**
 * compute (a.re + a.im)^3
 * 
 * status: public api
 * 
 */
t_complex	complex_cube(t_complex a)
{
	return (complex_multiplication(a,
			complex_multiplication(a, a)));
}

// https://math.stackexchange.com/questions/3872891/
// multiplicative-inverse-of-complex-numbers-proof

/**
 * if a.re + a.im equal to 0, return 0
 * compute 1 / (a.re + a.im)
 * 
 * status: public api
 * 
 */
t_complex	complex_reciprocal(t_complex a)
{
	t_complex	dst;

	dst.re = 0;
	dst.im = 0;
	if ((a.re < 0.01 && a.re > -0.01) && (a.im < 0.01 && a.im > -0.01))
		return (dst);
	dst.re = a.re / (a.re * a.re + a.im * a.im);
	dst.im = -1 * a.im / (a.re * a.re + a.im * a.im);
	return (dst);
}

/**
 * compute |a.re + a.im|
 * 
 * status: public api
 * 
 */
float	complex_magnitude(t_complex a, char is_square)
{
	float	y;

	y = a.re * a.re + a.im * a.im;
	if (is_square > 0)
		return (y);
	return (f_root_finding(y, 2));
}
