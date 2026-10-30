/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taylor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:28 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/14 11:59:35 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taylor.h"

/*
# ifndef MAXIMUM_ERROR
#  define MAXIMUM_ERROR 1e-8
# endif

# ifndef MAXIMUM_TERM
#  define MAXIMUM_TERM 20
# endif
*/

/*
This function approximate e^x

e constant = 2.718
*	e = 1/1! + 1/2! + ... + 1/n!
*	d/dx[e^x] = e^x
*	a^0 = 1

Taylor Series
*	taylor(f) = f(a) + (x-a)f'(a) + (x-a)^2f''(a)/2! + ... + (x-a)^nf^n(a)/n!
*	maclaurin(f) = f(0) + xf'(0) + x^2f''(0)/2! + ... + x^nf^n(0)/n!

Then
*	maclaurin(e^x) = 1 + x/1 + x^2/2! + ... + x^n/n!

Therefore, we can approximate e^x as 1 + x/1 + x^2/2! + ... + x^n/n!

Note that ChatGPT recommended me to remove accuracy argument
and truncate the Taylor series based on acceptable error rate.
You can also use Taylor inequality to approximate the error more accurately
but this approach is more difficult to implement and debug.

Reference
1.	https://youtu.be/eX1hvWxmJVE?si=9jQUq-r2TJ8hPvIb
2.	https://mathworld.wolfram.com/TaylorSeries.html
3.	https://youtu.be/Cqi-b3nQdKM?si=qxGl29v81BEl0xbz

Note that you can also approximate the analytic function using Pade approximation where
*	Taylor_Series = (a_0 + a_1x + a_2x^2 + ... a_nx^n) / (1 + b_1x + b_2x^2 + ... b_mx^m)
*	Taylor_Series = A_series / B_series

The cons of Taylor approximation is that
*	t_0 + t_1x + t_2x^2 + ... t_nx^n can approach positive or negative
	infinity when the value of x is large and n is finite.

The pros of Pade Approximation is that
*	when x is large, the finite term approximation approach 0 instead.

The downside of Pade Approximation is that
*	solving for the right value for every a_i and b_j can
	be much more inefficient and much more difficult than typical Taylor loop.

Read this for more details.
*	https://youtu.be/szMaPkJEMrw?si=f6c9YjOdM2ri2j6m
*/

/**
 * compute e^x with 8 iterations Taylor series
 * 
 * status: public api
 * 
 */
double	f_exp(double x)
{
	double	y;
	double	term;
	double	div;
	size_t	i;

	div = 1;
	term = x;
	y = 1;
	i = 1;
	while (div != 0 && f_abs(term / div) > MAXIMUM_ERROR && i < MAXIMUM_TERM)
	{
		y += term / div;
		term *= x;
		i += 1;
		div *= (double)i;
	}
	return (y);
}


/**
 * compute x^a with a iterations.
 * 
 * status: public api
 * 
 */
double	f_pow(double x, size_t a)
{
	size_t	i;
	double	y;

	y = 1;
	i = 0;
	while (i < a)
	{
		y *= x;
		i += 1;
	}
	return (y);
}

// https://youtu.be/-RdOwhmqP5s?si=HZMppRY9tGm3OjL-

// Newton method approximates x ^ (1 / a) where a >= 1
// x_(n+1) = x_n - f(x_n) / f'(x_n)
// where f(x) = x^a - c, such that x^a = f(x) + c, x^a = c

/**
 * if a == 0, then y = 0, else y = x^(1 / a) using 8 iterations newton method.
 * 
 * status: public api
 * 
 */
double	f_root_find(double x, size_t a)
{
	double	y;
	double	err;
	size_t	i;

	if (a == 0 || x == 0)
		return (0);
	y = x;
	i = 0;
	err = (f_pow(y, a) - x) / ((double)a * f_pow(y, a - 1));
	while (f_abs(err) > MAXIMUM_ERROR && i < MAXIMUM_TERM)
	{
		y -= err;
		err = (f_pow(y, a) - x) / ((double)a * f_pow(y, a - 1));
		i += 1;
	}
	return (y);
}

/*
// time : O(1)
// space: O(1)
double	f_sin(double x)
{
	return (sin(x));
}

// time : O(1)
// space: O(1)
double	f_cos(double x)
{
	return (cos(x));
}
*/

/*
You can use Laylor series to approximate Trigonometry function.
https://blog.devgenius.io/
the-magic-behind-trigonometric-functions-using-
taylor-series-in-programming-f4cae34d3729
*/

/**
 * if -1.0 < x < 1.0, then return x
 * else return sin(x) with 8 iterations Taylor series
 * 
 * status: public api
 * 
 */
double	f_sin(double x)
{
	double	y;
	double	div;
	double	term;
	double	pi2;
	size_t	i;

	i = 0;
	pi2 = 2 * PI31415;
	x = x - f_floor(x / pi2) * pi2;
	if (x < 0.01 && x > -0.01)
		return (x);
	term = x;
	div = 1;
	y = 0;
	while (div != 0 && f_abs(term / div) > MAXIMUM_ERROR && i < MAXIMUM_TERM)
	{
		if (i % 2 == 0)
			y += term / div;
		else
			y -= term / div;
		i += 1;
		div *= ((double)i * 2) * ((double)i * 2 + 1);
		term *= x * x;
	}
	return (y);
}

/**
 * compute cos(x) = sin(x + 3.1415 / 2.0)
 * 
 * status: public api
 * 
 */
double	f_cos(double x)
{
	return (f_sin(x + PI31415 / 2.0));
}
