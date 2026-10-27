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

static void	paint_aura_fdf_table_loop(t_fdf_table *dst,
	unsigned char *dst_rgba,
	unsigned char *src_rgba,
	int (*aura_custom)(int x, int y, int z))
{
	size_t			i;
	int				y;
	int				z;
	t_float2d		position;

	i = 0;
	while (i < dst->row * dst->col)
	{
		position = init_table_coordinate(dst, i, 1.0);
		if (src_rgba == NULL)
			z = dst->arr[i];
		else
			z = (int)src_rgba[i];
		y = (int)f_abs(position.x + position.y + (float)z);
		if (aura_custom != NULL)
			y = aura_custom((int)position.x, (int)position.y, z);
		if (dst_rgba == NULL)
			dst->arr[i] = y;
		else
			dst_rgba[i] = (unsigned char)f_interval_int(y, 0, 255);
		i += 1;
	}
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
 * @param src_channel FDF channel to paint
 * @param dst_channel FDF channel to paint
 * @param aura_custom optional function to calculate the value of each cell
 * It is f(x, y, z). If it is NULL, then f(x, y, z) = |x + y + z|.
 */
void	paint_aura_fdf_table(t_fdf_table *dst,
	t_fdf_channel src_channel,
	t_fdf_channel dst_channel,
	int (*aura_custom)(int x, int y, int z))
{
	unsigned char	*src_rgba;
	unsigned char	*dst_rgba;

	if (dst == NULL || dst->arr == NULL
		|| mul_overflow_size_t(dst->col, dst->row) == false)
		return ;
	src_rgba = rgbarr_from_table(dst, src_channel);
	dst_rgba = rgbarr_from_table(dst, dst_channel);
	if ((dst->arr == NULL
			&& (src_channel == FDF_HEIGHT || dst_channel == FDF_HEIGHT))
		|| (dst_rgba == NULL && dst_channel != FDF_HEIGHT)
		|| (src_rgba == NULL && src_channel != FDF_HEIGHT))
		return ;
	paint_aura_fdf_table_loop(dst, dst_rgba, src_rgba, aura_custom);
}
