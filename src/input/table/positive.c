/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:44:59 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 14:11:57 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

/**
 * Get either the minimum or maximum number from src.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param src the input t_fdf_table array
 * @param is_max if is_max == true, then return maximum number, 
 * else return minimum number.
 * @param channels RGBA channel to inspect
 * 
 * @return minimum or maximum integer based on the input.
 */
int	fdf_table_minmax(const t_fdf_table *src,
	bool is_max, t_fdf_channel channel)
{
	int		sign;
	size_t	i;
	int		y;

	if (mul_overflow_size_t(src->col, src->row) == false)
		return (0);
	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (src != NULL && i < src->col * src->row)
	{
		if (channel == FDF_HEIGHT && src->arr != NULL
			&& sign * y < sign * src->arr[i])
			y = src->arr[i];
		if (channel == FDF_ALPHA && src->a != NULL && sign * y < sign * src->a[i])
			y = src->a[i];
		if (channel == FDF_RED && src->r != NULL && sign * y < sign * src->r[i])
			y = src->r[i];
		if (channel == FDF_GREEN && src->g != NULL && sign * y < sign * src->g[i])
			y = src->g[i];
		if (channel == FDF_BLUE && src->b != NULL && sign * y < sign * src->b[i])
			y = src->b[i];
		i += 1;
	}
	return (y);
}

/**
 * Adding some number, such that every number in t_fdf_table become positive.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst the input t_fdf_table array
 */
void	positive_fdf_table(t_fdf_table *dst)
{
	int	y;

	y = fdf_table_minmax((const t_fdf_table *)dst, false, FDF_HEIGHT);
	if (y < 0 && y > -2147483648)
		y *= -1;
	else if (y == -2147483648)
		y = 0;
	add_fdf_table(dst, y, FDF_HEIGHT);
}

/**
 * Making all number that in an interval between minimum target number
 *  and maximum target number equal to the expected number
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst the input t_fdf_table array
 * @param min the minimum target number
 * @param max the maximum target number
 * @param expect the expected number
 */
void	relu_fdf_table(t_fdf_table *dst, int min, int max, int expect)
{
	size_t	i;
	int		temp;

	if (dst != NULL && dst->arr != NULL
		&& mul_overflow_size_t(dst->col, dst->row) == false)
		return ;
	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	i = 0;
	while (i < dst->col * dst->row)
	{
		if (min <= dst->arr[i] && dst->arr[i] <= max)
			dst->arr[i] = expect;
		i += 1;
	}
}
