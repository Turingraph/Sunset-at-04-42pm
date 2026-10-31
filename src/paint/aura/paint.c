/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:25:45 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 12:33:44 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aura.h"

t_double2d	complex_x2(t_double2d a)
{
	return (complex_power(a, 2));
}

t_double2d	complex_x3(t_double2d a)
{
	return (complex_power(a, 3));
}

/**
 * Paint a table FDF channel using the value of each cell from
 * the origin in the complex plane, as |z.x + z.im|.
 * If aura is not NULL, its output will be utilized instead
 * of the default complex-plane distance.
 * 
 * time/space: O(n) + O(aura) / O(1)
 * 
 * status: public api
 * 
 * @param dst destination FDF table to paint
 * @param channel FDF channel to paint
 * @param zoom Zoom level
 * @param aura_custom optional function to calculate the value of each cell
 * It is f(x, y, z). If it is NULL, then f(x, y, z) = |x + y + z|.
 */
void	paint_aura_fdf_table(t_fdf_table *dst,
	double zoom,
	t_fdf_channel channel,
	int (*aura_custom)(double x, double y, double z))
{
	unsigned char	*rgbarr;
	size_t			i;
	int				y;
	int				z;
	t_double2d		position;

	rgbarr = rgbarr_from_table(dst, channel);
	if (dst == NULL || (dst->arr == NULL && channel == FDF_HEIGHT)
		|| (rgbarr == NULL && channel != FDF_HEIGHT))
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		position = fdf_table_coordinate(dst, i);
		position.x *= zoom;
		position.y *= zoom;
		if (rgbarr == NULL)
			z = dst->arr[i];
		else
			z = (int)rgbarr[i];
		y = (int)f_abs(position.x + position.y + (float)z);
		if (aura_custom != NULL)
			y = aura_custom(position.x, position.y, (double)z);
		if (rgbarr == NULL)
			dst->arr[i] = y;
		else
			rgbarr[i] = (unsigned char)f_interval_int(y, 0, 255);
		i += 1;
	}
}

/**
 * Compute z' = complex_func(x).
 * Then check whether z.x is even or z.y is even
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param x complex number input
 * @param scale scaling x
 * @param complex_func optional complex function applied to the cell
 * coordinate.
 * @return true if z.x is even and z.y is even, false otherwise.
 */
int	aura_custom_andmod(t_double2d x, double z,
	t_double2d (*complex_func)(t_double2d a))
{
	if (complex_func != NULL)
		x = complex_func(x);
	if (x.x < 0)
		x.x *= -1;
	if (x.y < 0)
		x.y *= -1;
	if ((int)x.x % 2 == 1 && (int)x.y % 2 == 1 && z >= 0)
		return (1);
	return (0);
}

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating its magnitude
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
int	aura_custom_bi(t_double2d x, double z,
	int (*aura_custom)(double x, double y, double z),
	t_double2d (*complex_func)(t_double2d a))
{
	double	distance;

	if (complex_func != NULL)
		x = complex_func(x);
	distance = x.x + x.y;
	if (aura_custom != NULL)
		distance = aura_custom(x.x, x.y, z);
	if ((int)f_floor(distance) % 2 == 1)
		return (1);
	return (0);
}
