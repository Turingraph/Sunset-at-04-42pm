/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:46:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 14:26:33 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

bool	isvalid_fdf_channel(const t_fdf_table *src,
	unsigned char **rgbarr, t_fdf_channel channel)
{
	if (src == NULL
		|| mul_overflow_size_t(src->col, src->row) == false
		|| rgbarr == NULL)
		return (false);
	*rgbarr = rgbarr_from_table(src, channel);
	if ((*rgbarr == NULL && channel != FDF_HEIGHT)
		|| (src->arr == NULL && channel == FDF_HEIGHT))
		return (false);
	return (true);
}

/**
 * Multiply each selected FDF channel by scale.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param scale multiplication factor
 * @param channel channel to modify
 */
void	scale_fdf_table(t_fdf_table *dst, float scale,
	t_fdf_channel channel)
{
	unsigned char	*dst_rgba;
	size_t			i;

	if (isvalid_fdf_channel(dst, &dst_rgba, channel) == false)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (channel == FDF_HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] * scale),
					-2147483648.0, 2147483647.0);
		else
			dst_rgba[i] = (unsigned char)f_interval(
					dst_rgba[i] * scale, 0, 255);
		i += 1;
	}
}

/**
 * Add input to each value in the selected FDF channel.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param input value to add
 * @param channel channel to modify
 */
void	add_fdf_table(t_fdf_table *dst, int input, t_fdf_channel channel)
{
	unsigned char	*dst_rgba;
	size_t			i;

	if (isvalid_fdf_channel(dst, &dst_rgba, channel) == false)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (channel == FDF_HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] + input),
					-2147483648.0, 2147483647.0);
		else
			dst_rgba[i] = (unsigned char)f_interval(
					dst_rgba[i] + input, 0, 255);
		i += 1;
	}
}

/**
 * Add the selected channel of src to dst element by element.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to add
 */
void	mix_add_fdf_table(t_fdf_table *dst,
	const t_fdf_table *src, t_fdf_channel channel)
{
	unsigned char	*dst_rgba;
	unsigned char	*src_rgba;
	size_t			i;

	if (isvalid_fdf_channel(dst, &dst_rgba, channel) == false
		|| isvalid_fdf_channel(src, &src_rgba, channel) == false)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (channel == FDF_HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] + src->arr[i]),
					-2147483648.0, 2147483647.0);
		else
			dst_rgba[i] = (unsigned char)f_interval(
					dst_rgba[i] + src_rgba[i], 0, 255);
		i += 1;
	}
}

/**
 * Multiply the selected channel of dst by src element by element.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to multiply
 */
void	mix_hadamard_fdf_table(t_fdf_table *dst,
	const t_fdf_table *src, t_fdf_channel channel)
{
	unsigned char	*dst_rgba;
	unsigned char	*src_rgba;
	size_t			i;

	if (isvalid_fdf_channel(dst, &dst_rgba, channel) == false
		|| isvalid_fdf_channel(src, &src_rgba, channel) == false)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (channel == FDF_HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] * src->arr[i]),
					-2147483648.0, 2147483647.0);
		else
			dst_rgba[i] = (unsigned char)f_interval(
					dst_rgba[i] * src_rgba[i], 0, 255);
		i += 1;
	}
}
