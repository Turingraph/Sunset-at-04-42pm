/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 13:40:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 14:28:54 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

/**
 * This function is used for checking if x and y position is in the boundary.
 * Note that user can use t_line for defining the boundary.
 * However, the boundary.p2 should be considered as a pair of point that
 * outside the boundary.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param window_width width of the camera viewport
 * @param window_height height of the camera viewport
 * @return initialized 2D camera
 */
bool	is_in_boundary(int x, int y, t_line boundary)
{
	if (x >= boundary.p1.x
		&& x < boundary.p2.x
		&& y >= boundary.p1.y
		&& y < boundary.p2.y)
		return (true);
	return (false);
}
