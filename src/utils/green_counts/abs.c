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

#include "green_counts.h"

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
