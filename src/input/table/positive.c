/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:44:59 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/31 13:49:22 by phsottat         ###   ########.fr       */
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
 * @param src the input t_table_fdf array
 * @param is_max if is_max == true, then return maximum number, 
 * else return minimum number.
 * @param channels RGBA channel to inspect
 * 
 * @return minimum or maximum integer based on the input.
 */
int	get_minmax_from_table_fdf(const t_table_fdf *src,
	bool is_max, t_fdf_channel channel)
{
	int		sign;
	size_t	i;
	int		y;

	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (src != NULL && i < src->row * src->col)
	{
		if (channel == HEIGHT && src->arr != NULL
			&& sign * y < sign * src->arr[i])
			y = src->arr[i];
		if (channel == ALPHA && src->a != NULL && sign * y < sign * src->a[i])
			y = src->a[i];
		if (channel == RED && src->r != NULL && sign * y < sign * src->r[i])
			y = src->r[i];
		if (channel == GREEN && src->g != NULL && sign * y < sign * src->g[i])
			y = src->g[i];
		if (channel == BLUE && src->b != NULL && sign * y < sign * src->b[i])
			y = src->b[i];
		i += 1;
	}
	return (y);
}

/**
 * Adding some number, such that every number in t_table_fdf become positive.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst the input t_table_fdf array
 */
void	scale_positive_fdf(t_table_fdf *dst)
{
	int	y;

	y = get_minmax_from_table_fdf((const t_table_fdf *)dst, false, HEIGHT);
	if (y < 0 && y > -2147483648)
		y *= -1;
	else if (y == -2147483648)
		y = 0;
	scale_addition_fdf(dst, y, HEIGHT);
}

/**
 * Making all number that in an interval between minimum target number
 *  and maximum target number equal to the expected number
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst the input t_table_fdf array
 * @param min the minimum target number
 * @param max the maximum target number
 * @param expect the expected number
 */
void	scale_relu_fdf(t_table_fdf *dst, int min, int max, int expect)
{
	size_t	i;
	int		temp;

	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	i = 0;
	while (dst != NULL && dst->arr != NULL && i < dst->row * dst->col)
	{
		if (min <= dst->arr[i] && dst->arr[i] <= max)
			dst->arr[i] = expect;
		i += 1;
	}
}
