/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inequality.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:34:01 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 14:34:02 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aura.h"

/**
 * Calculate |x| + |y| + |z| - |x + y + z|
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_inequality_triangle(int x, int y, int z)
{
	int	y_max;
	int	y_min;

	y_max = f_abs(x) + f_abs(y) + f_abs(z);
	y_min = f_abs(x + y + z);
	return (y_max - y_min);
}

/**
 * Calculate (x + y + z) / 3 - (xyz)^(1/3)
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_inequality_amgm(int x, int y, int z)
{
	int	y_max;
	int	y_min;
	int	n;

	n = 3;
	if (z == 0)
		n = 2;
	y_max = (int)(f_abs_int(x + y + z) / n);
	if (z == 0)
		z = 1;
	y_min = f_root_find(f_abs_int(x * y * z), n);
	return (y_max - y_min);
}

/**
 * Calculate the x^2 + y^2 + z^2 - (x + y + z)^2
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_inequality_cauchy(int x, int y, int z)
{
	int	y_max;
	int	y_min;

	y_max = (x * x + y * y + z * z) * (x * x + y * y + z * z);
	y_min = (x + y + z) * (x + y + z);
	return (y_max - y_min);
}

int	aura_inequality_addmul(int x, int y, int z)
{
	int	y_max;
	int	y_min;

	y_max = f_abs_int(x + 1) * f_abs_int(y + 1) * f_abs_int(z + 1);
	y_min = f_abs_int(x + 1) + f_abs_int(y + 1) + f_abs_int(z + 1);
	return (y_max - y_min);
}
