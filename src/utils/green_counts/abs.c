/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:14:29 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// time : O(1)
// space: O(1)
float	f_abs(float x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

// time : O(1)
// space: O(1)
int	f_abs_int(int x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

/*

*/
