/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:28:55 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/14 12:01:06 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

/** 
 * if a > b, return b, else return a.
 * 
 * status: public api
 * 
 */
float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

/** 
 * if a < b, return b, else return a.
 * 
 * status: public api
 * 
 */
float	f_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

/** 
 * it use int instead of float
 * if a > b, return b, else return a.
 * 
 * status: internal helper
 * 
 */
int	f_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * it use int instead of float 
 * if a < b, return b, else return a.
 * 
 * status: internal helper
 * 
 */
int	f_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
