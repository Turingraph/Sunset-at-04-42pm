/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:14:59 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// time : O(n)
// space: O(1)
float	normal_distribution_function(float std, float means, float x)
{
	float	up;
	float	down;
	float	pi;

	pi = 3.1415;
	if (std == 0)
		return (0);
	down = std * f_root_finding(2 * pi, 2);
	up = f_exp(-1 * f_pow(x - means, 2) / (2 * std * std));
	return (up / down);
}

// https://www.khanacademy.org/math/statistics-probability/
// summarizing-quantitative-data/variance-standard-deviation-population/
// a/calculating-standard-deviation-step-by-step
// time : O(n)
// space: O(1)
float	f_std(const float *vec_v, size_t dim)
{
	size_t	i;
	float	y;
	float	mu;

	mu = f_sum(vec_v, dim);
	if (dim > 0)
		mu /= (float)dim;
	y = 0;
	i = 0;
	while (i < dim && vec_v != NULL)
	{
		y += (vec_v[i] - mu) * (vec_v[i] - mu);
		i += 1;
	}
	if (dim > 0)
		y /= (float)dim;
	return (y);
}

// time : O(n)
// space: O(1)
float	f_sum(const float *vec_v, size_t dim)
{
	float	y;
	size_t	i;

	y = 0.0;
	if (vec_v == NULL)
		return (y);
	i = 0;
	while (i < dim)
	{
		y += vec_v[i];
		i += 1;
	}
	return (y);
}
