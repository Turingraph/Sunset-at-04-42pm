/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:52:58 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 13:09:32 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/**
 * Check whether the product of 2 size_t type number cause integeroverflow,
 * or output 0 or not.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param col   The 1st number.
 * @param row   The 2nd number.
 * @return true if the product are valid, greater than 0, and the index is within
 *         bounds; false otherwise.
 */
bool	mul_overflow_size_t(size_t col, size_t row)
{
	if (col == 0 || row == 0 || col > SIZE_MAX / row
		|| row > SIZE_MAX / col)
		return (false);
	return (true);
}

/**
 * Check whether the product of 2 uint32_t type number cause integeroverflow,
 * or output 0 or not.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param col   The 1st number.
 * @param row   The 2nd number.
 * @return true if the product are valid, greater than 0, and the index is within
 *         bounds; false otherwise.
 */
bool	mul_overflow_uint32_t(uint32_t col, uint32_t row)
{
	if (col == 0 || row == 0 || col > UINT32_MAX / row
		|| row > UINT32_MAX / col)
		return (false);
	return (true);
}

/**
 * Check whether the product of 2 int type number cause integeroverflow,
 * or output 0 or not.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param a   The 1st number.
 * @param row   The 2nd number.
 * @return true if the product are valid, and the index is within
 * 			bounds, the multiplication product might or might not equal to 0;
 * 			false otherwise.
 */
bool	mul_overflow_int(int a, int row)
{
	if (a > 2147483647 / row || row > 2147483647 / a
		|| a < -2147483647 / row || row > -2147483647 / a)
		return (false);
	return (true);
}

/**
 * Check whether the sum of 2 int type number cause integeroverflow,
 * or output 0 or not.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param a   The 1st number.
 * @param b   The 2nd number.
 * @return true if the sum are valid, and the index is within
 * 			bounds, false otherwise.
 */
bool	add_overflow_int(int a, int b)
{
	if (a > 2147483647 / b || b > 2147483647 / a
		|| a < -2147483647 / b || b > -2147483647 / a)
		return (false);
	return (true);
}

