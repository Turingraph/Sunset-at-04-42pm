/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/14 12:10:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * compute |x|
 * 
 * status: public api
 * 
 */
float	f_abs(float x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

/**
 * it use int instead of float
 * compute |x|
 * 
 * status: internal helper
 * 
 */
int	f_abs_int(int x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

unsigned char	minmax_from_arr_uchar(unsigned char *arr, size_t length, bool is_max)
{
	int		sign;
	size_t	i;
	int		y;

	if (arr == NULL || length == 0)
		return (0);
	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (i < length)
	{
		if (y * sign < (int)arr[i] * sign)
			y = (int)arr[i];
		i += 1;
	}
	return ((unsigned char)y);
}

int	minmax_from_arr_int(int *arr, size_t length, bool is_max)
{
	int		sign;
	size_t	i;
	int		y;

	if (arr == NULL || length == 0)
		return (0);
	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (i < length)
	{
		if (y * sign < arr[i] * sign)
			y = arr[i];
		i += 1;
	}
	return (y);
}

float	minmax_from_arr_float(float *arr, size_t length, bool is_max)
{
	float		sign;
	size_t	i;
	float		y;

	if (arr == NULL || length == 0)
		return (0);
	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (i < length)
	{
		if (y * sign < arr[i] * sign)
			y = arr[i];
		i += 1;
	}
	return (y);
}
