/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discrete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 18:13:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 19:13:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taylor.h"

/**
 * Count the number of iterations required by a binary-search procedure
 * to locate min_input within the range [0, max_input].
 *
 * If min_input is greater than max_input, their values are exchanged
 * before performing the search.
 *
 * time/space: O(log(n)) / O(1)
 *
 * status: public api
 *
 * @param min_input target value to search for
 * @param max_input upper bound of the search range
 * @return number of binary-search iterations
 */
size_t	f_bisearch_count(size_t min_input, size_t max_input)
{
	size_t	min;
	size_t	mid;
	size_t	max;
	size_t	count;

	if (min_input > max_input)
	{
		min = min_input;
		min_input = max_input;
		max_input = min;
	}
	count = 0;
	min = 0;
	mid = (min + max_input) / 2;
	max = max_input;
	while (mid != min_input && min < max)
	{
		mid = (min + max) / 2;
		if (min_input < mid)
			max = mid;
		else
			min = mid + 1;
		count += 1;
	}
	return (count);
}

/**
 * Find the maximum value reached by the Collatz sequence of an input.
 * The sequence is limited to 10000 iterations.
 *
 * time/space: O(s, where s is less than 10000),
 * this is an open problem! / O(1)
 *
 * status: public api
 * 
 */
size_t	f_collatz_max(size_t x, size_t div, size_t mul)
{
	size_t	max;
	size_t	limit;

	max = 0;
	if (max < x)
		max = x;
	limit = 0;
	while (limit < 10000 && x > 1)
	{
		if (max < x)
			max = x;
		if (x % 2 == 0 && div > 0)
			x /= div;
		else if (x % 2 == 0)
			x /= 2;
		else if (mul % 2 == 1)
			x = mul * x + 1;
		else
			x = (mul + 1) * x + 1;
		limit += 1;
	}
	return (max);
}

/*

// This code might be incorrect.

static double	f_mul_dpointer(double *a, double *b)
{
	if (a == NULL && b == NULL)
		return (0);
	if (a == NULL)
		return (*b);
	if (b == NULL)
		return (*a);
	return (*a * *b);
}

void	f_fibonacci_custom(size_t x, double *a0, double *a1, double *a2)
{
	double	b0;
	double	b1;
	double	b2;

	if (x > 0)
		f_fibonacci_custom(x / 2, a0, a1, a2);
	b0 = f_mul_dpointer(a0, a0) + f_mul_dpointer(a1, a1);
	b1 = f_mul_dpointer(a1, a0) + f_mul_dpointer(a1, a2);
	b2 = f_mul_dpointer(a1, a1) + f_mul_dpointer(a2, a2);
	if (x % 2 == 1)
	{
		if (a1 != NULL)
			b0 += *a1;
		if (a0 != NULL)
			b1 = *a0;
		if (a1 != NULL)
			b2 = *a1;
	}
	if (a0 != NULL)
		*a0 = b0;
	if (a1 != NULL)
		*a1 = b1;
	if (a2 != NULL)
		*a2 = b2;
}

size_t	f_fibonacci(size_t x)
{
	double	a0;
	double	a1;
	double	a2;

	a0 = 1;
	a1 = 1;
	a2 = 0;
	f_fibonacci_custom(x, &a0, &a1, &a2);
	return ((size_t)a0);
}
*/
