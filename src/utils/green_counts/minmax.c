/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:28:55 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:12:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// time : O(1)
// space: O(1)
float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

// time : O(1)
// space: O(1)
float	f_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

// time : O(1)
// space: O(1)
int	f_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// time : O(1)
// space: O(1)
int	f_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
