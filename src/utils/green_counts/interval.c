/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:10:57 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:12:37 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// https://stackoverflow.com/questions/41856771/
// write-your-own-implementation-of-maths-floor-function-c

// time : O(1)
// space: O(1)
float	f_floor(float num)
{
	long long	n;
	float		d;

	if (num > 2147483647.0)
		return (2147483647.0);
	if (num < -2147483648.0)
		return (-2147483648.0);
	n = (long long)num;
	d = (float)n;
	return (d);
}

// time : O(1)
// space: O(1)
float	f_round(float num)
{
	float	floor;

	floor = f_floor(num);
	if (num > 2147483647.0)
		return (2147483647.0);
	if (num < -2147483648.0)
		return (-2147483648.0);
	if (num - floor < floor + 1 - num)
		return (floor);
	return (floor + 1);
}

// time : O(1)
// space: O(1)
float	f_interval(float num, float min, float max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}

// time : O(1)
// space: O(1)
int	f_interval_int(int num, int min, int max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}
