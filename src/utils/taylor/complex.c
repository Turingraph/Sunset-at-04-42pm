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

#include "taylor.h"

/**
 * compute (a.x + a.y) * (b.x + b.y)
 * 
 * status: public api
 * 
 */
t_2d_float	complex_multiplication(t_2d_float a, t_2d_float b)
{
	t_2d_float	dst;

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
t_2d_float	complex_reciprocal(t_2d_float a)
{
	t_2d_float	dst;

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
float	complex_magnitude(t_2d_float a, char is_square)
{
	float	y;

	y = a.x * a.x + a.y * a.y;
	if (is_square > 0)
		return (y);
	return (f_root_finding(y, 2));
}
