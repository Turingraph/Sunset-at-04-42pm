/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:25:45 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 14:41:40 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aura.h"

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
 * @param src_channel FDF channel to paint
 * @param dst_channel FDF channel to paint
 * @param aura_custom optional function to calculate the value of each cell
 * It is f(x, y, z). If it is NULL, then f(x, y, z) = |x + y + z|.
 */
void	paint_aura_fdf_table(t_fdf_table *dst,
	t_fdf_channel channel,
	int (*aura_custom)(int x, int y, int z))
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
		if (rgbarr == NULL)
			z = dst->arr[i];
		else
			z = (int)rgbarr[i];
		y = (int)f_abs(position.x + position.y + (float)z);
		if (aura_custom != NULL)
			y = aura_custom((int)position.x, (int)position.y, z);
		if (rgbarr == NULL)
			dst->arr[i] = y;
		else
			rgbarr[i] = (unsigned char)f_interval_int(y, 0, 255);
		i += 1;
	}
}
