/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:33:56 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 14:54:52 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aura.h"

/**
 * Calculate |x * y * z|^(1/2)
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_root2(int x, int y, int z)
{
	return ((int)f_round(f_root_find(x * y * z, 2)));
}

/**
 * Calculate |x * y * z|^(1/3)
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_root3(int x, int y, int z)
{
	return ((int)f_round(f_root_find(x * y * z, 3)));
}

/**
 * Calculate |x + y + z|
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_addsub(int x, int y, int z)
{
	return (f_abs_int(x + y + z));
}

/**
 * Calculate x^z + y^z - floor((x^z + y^z)^(1/z))
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 */
int	aura_fermat(int x, int y, int z)
{
	int			a;
	int			b;
	int			c;

	a = (int)f_pow(x, z);
	b = (int)f_pow(y, z);
	c = a + b;
	c = (int)f_floor(f_root_find((float)c, 3));
	c = (int)f_pow((int)c, z);
	return (f_abs_int(a + b - c));
}
