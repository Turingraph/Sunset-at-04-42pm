/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taylor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:28 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:15:20 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// time : O(1)
// space: O(1)
float	f_pow(float x, size_t a)
{
	size_t	i;
	float	y;

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
// time : O(1)
// space: O(1)
float	f_root_finding(float x, size_t a)
{
	float	y;
	float	err;
	size_t	i;

	if (a == 0 || x == 0)
		return (0);
	y = x;
	i = 0;
	err = (f_pow(y, a) - x) / ((float)a * f_pow(y, a - 1));
	while (f_abs(err) > 1e-4 && i < 8)
	{
		y -= err;
		err = (f_pow(y, a) - x) / ((float)a * f_pow(y, a - 1));
		i += 1;
	}
	return (y);
}

/*
You can use Laylor series to approximate Trigonometry function.
https://blog.devgenius.io/
the-magic-behind-trigonometric-functions-using-
taylor-series-in-programming-f4cae34d3729
*/

/*
// time : O(1)
// space: O(1)
float	f_sin(float x)
{
	return (sin(x));
}

// time : O(1)
// space: O(1)
float	f_cos(float x)
{
	return (cos(x));
}
*/

float	f_sin(float x)
{
	float	y;
	float	div;
	float	term;
	float	pi2;
	size_t	i;

	i = 0;
	pi2 = 6.283;
	x = x - f_floor(x / pi2) * pi2;
	if (x < 1.0 && x > -1.0)
		return (x);
	term = x;
	div = 1;
	y = 0;
	while (div != 0 && f_abs(term / div) > 1e-4 && i < 8)
	{
		if (i % 2 == 0)
			y += term / div;
		else
			y -= term / div;
		i += 1;
		div *= ((float)i * 2) * ((float)i * 2 + 1);
		term *= x * x;
	}
	return (y);
}

// time : O(n)
// space: O(1)
float	f_cos(float x)
{
	return (f_sin(x + 3.1415 / 2.0));
}

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
*/

// time : O(1)
// space: O(1)
float	f_exp(float x)
{
	float	y;
	float	term;
	float	div;
	size_t	i;

	div = 1;
	term = x;
	y = 1;
	i = 1;
	while (div != 0 && f_abs(term / div) > 1e-4 && i < 8)
	{
		y += term / div;
		term *= x;
		i += 1;
		div *= (float)i;
	}
	return (y);
}
