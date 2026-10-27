/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:13 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 18:24:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taylor.h"

/**
 * compute (a.x + a.y) * (b.x + b.y)
 * 
 * status: public api
 * 
 */
t_float2d	complex_multiplication(t_float2d a, t_float2d b)
{
	t_float2d	dst;

	dst.x = a.x * b.x - a.y * b.y;
	dst.y = a.x * b.y + a.y * b.x;
	return (dst);
}

// https://math.stackexchange.com/questions/3872891/
// multiplicative-inverse-of-complex-numbers-proof

/**
 * if a.x + a.y equal to 0, return 0
 * compute 1 / (a.x + a.y)
 * 
 * status: public api
 * 
 */
t_float2d	complex_reciprocal(t_float2d a)
{
	t_float2d	dst;

	dst.x = 0;
	dst.y = 0;
	if ((a.x < 0.01 && a.x > -0.01) && (a.y < 0.01 && a.y > -0.01))
		return (dst);
	dst.x = a.x / (a.x * a.x + a.y * a.y);
	dst.y = -1 * a.y / (a.x * a.x + a.y * a.y);
	return (dst);
}

/**
 * compute |a.x + a.im|
 * 
 * status: public api
 * 
 */
float	complex_magnitude(t_float2d a, char is_square)
{
	float	y;

	y = a.x * a.x + a.y * a.y;
	if (is_square > 0)
		return (y);
	return (f_root_find(y, 2));
}

/**
 * compute (a.x + a.y)^2
 * 
 * status: public api
 * 
 */
t_float2d	complex_square(t_float2d a)
{
	return (complex_multiplication(a, a));
}

/**
 * compute (a.x + a.y)^3
 * 
 * status: public api
 */
t_float2d	complex_polynomial(t_float2d a, size_t power, size_t reciprocal)
{
	size_t	i;

	if (power == 0)
	{
		a.x = 1;
		a.y = 0;
		return (a);
	}
	i = 1;
	while (i < power)
	{
		a = complex_square(a);
		i += 1;
	}
	i = 1;
	while (i < reciprocal)
	{
		a = complex_reciprocal(a);
		i += 1;
	}
	return (a);
}
