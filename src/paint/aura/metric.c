/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metric.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:34:03 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 14:54:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aura.h"

/**
* Calculate (x^2 + y^2 + z^2)^(1/2)
* 
* time/space: O(1) / O(1)
* 
* status: public api
*/
int	aura_pythagoras(int x, int y, int z)
{
	int	distance;

	distance = x * x + y * y + z * z;
	return ((int)(f_root_find(distance, 2)));
}

/**
 * Return max(x, y, z)
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_max(int x, int y, int z)
{
	int			max3d;

	max3d = f_max_int(f_abs(x), f_abs(y));
	return (f_max_int(max3d, z));
}

/**
 * Calculate min(x, y, z)
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_min(int x, int y, int z)
{
	int			min3d;

	min3d = f_min_int(f_abs_int(x), f_abs_int(y));
	return (f_min_int(min3d, z));
}
