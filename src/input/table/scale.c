/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:46:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:27:18 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

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
void	scale_multiplication_fdf(t_fdf_table *dst, float scale,
	t_fdf_channel channel)
{
	size_t	i;

	if (dst == NULL || check_multiplication_overflow(dst->col, dst->row) == false)
		return ;
	i = 0;
	while (i < dst->col * dst->row)
	{
		if (dst->arr != NULL && channel == HEIGHT)
			dst->arr[i] = (int)f_interval_int(
					f_round(dst->arr[i] * scale),
					-2147483648.0, 2147483647.0);
		if (dst->r != NULL && channel == RED)
			dst->r[i] = (unsigned char)f_interval_int(
					dst->r[i] * scale, 0, 255);
		if (dst->g != NULL && channel == GREEN)
			dst->g[i] = (unsigned char)f_interval_int(
					dst->g[i] * scale, 0, 255);
		if (dst->b != NULL && channel == BLUE)
			dst->b[i] = (unsigned char)f_interval_int(
					dst->b[i] * scale, 0, 255);
		if (dst->a != NULL && channel == ALPHA)
			dst->a[i] = (unsigned char)f_interval_int(
					dst->a[i] * scale, 0, 255);
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
void	scale_addition_fdf(t_fdf_table *dst, int input, t_fdf_channel channel)
{
	size_t	i;

	if (dst == NULL || check_multiplication_overflow(dst->col, dst->row) == false)
		return ;
	i = 0;
	while (i < dst->col * dst->row)
	{
		if (dst->arr != NULL && channel == HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] + input), -2147483648.0, 2147483647.0);
		if (dst->r != NULL && channel == RED)
			dst->r[i] = (unsigned char)f_interval(
					(int)dst->r[i] + input, 0, 255);
		if (dst->g != NULL && channel == GREEN)
			dst->g[i] = (unsigned char)f_interval(
					(int)dst->g[i] + input, 0, 255);
		if (dst->b != NULL && channel == BLUE)
			dst->b[i] = (unsigned char)f_interval(
					(int)dst->b[i] + input, 0, 255);
		if (dst->a != NULL && channel == ALPHA)
			dst->a[i] = (unsigned char)f_interval(
					(int)dst->a[i] + input, 0, 255);
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
void	fdf_table_addition(t_fdf_table *dst,
	const t_fdf_table *src, t_fdf_channel channel)
{
	size_t	i;

	if (src == NULL || dst == NULL
		|| check_multiplication_overflow(dst->col, dst->row) == false
		|| check_multiplication_overflow(src->col, src->row) == false
		|| dst->row * dst->col != src->row * src->col)
		return ;
	i = 0;
	while (i < dst->col * dst->row)
	{
		if (src->arr != NULL && dst->arr != NULL && channel == HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] + src->arr[i]),
					-2147483648.0, 2147483647.0);
		if (src->r != NULL && dst->r != NULL && channel == RED)
			dst->r[i] = (unsigned char)f_interval(
					dst->r[i] + src->r[i], 0, 255);
		if (src->g != NULL && dst->g != NULL && channel == GREEN)
			dst->g[i] = (unsigned char)f_interval(
					dst->g[i] + src->g[i], 0, 255);
		if (src->b != NULL && dst->b != NULL && channel == BLUE)
			dst->b[i] = (unsigned char)f_interval(
					dst->b[i] + src->b[i], 0, 255);
		if (src->a != NULL && dst->a != NULL && channel == ALPHA)
			dst->a[i] = (unsigned char)f_interval(
					dst->a[i] + src->a[i], 0, 255);
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
void	fdf_table_hadamard(t_fdf_table *dst,
	const t_fdf_table *src, t_fdf_channel channel)
{
	size_t	i;

	if (src == NULL || dst == NULL
		|| check_multiplication_overflow(dst->col, dst->row) == false
		|| check_multiplication_overflow(src->col, src->row) == false
		|| dst->row * dst->col != src->row * src->col)
		return ;
	i = 0;
	while (i < dst->col * dst->row)
	{
		if (src->arr != NULL && dst->arr != NULL && channel == HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] * src->arr[i]),
					-2147483648.0, 2147483647.0);
		if (src->r != NULL && dst->r != NULL && channel == RED)
			dst->r[i] = (unsigned char)f_interval(
					dst->r[i] * src->r[i], 0, 255);
		if (src->g != NULL && dst->g != NULL && channel == GREEN)
			dst->g[i] = (unsigned char)f_interval(
					dst->g[i] * src->g[i], 0, 255);
		if (src->b != NULL && dst->b != NULL && channel == BLUE)
			dst->b[i] = (unsigned char)f_interval(
					dst->b[i] * src->b[i], 0, 255);
		if (src->a != NULL && dst->a != NULL && channel == ALPHA)
			dst->a[i] = (unsigned char)f_interval(
					dst->a[i] * src->a[i], 0, 255);
		i += 1;
	}
}

/**
 * Copy the channel from source FDF table to the dst FDF table.
 * dst and src should have the same numbers of row times column.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channel channel to copy
 */
void	copy_fdf_table_channel(t_fdf_table *dst, const t_fdf_table *src, t_fdf_channel channel)
{
	scale_multiplication_fdf(dst, 0.0, channel);
	fdf_table_addition(dst, src, channel);
}
