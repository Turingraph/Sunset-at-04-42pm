/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:01:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 17:33:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * Combine the RGBA channels of a table element into a 32-bit color.
 *
 * Missing channels are treated as zero. The channels are packed in
 * RGBA order, with red as the most significant byte and alpha as the
 * least significant byte.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param src source FDF object
 * @param index element index whose RGBA channels are combined
 * @return packed 32-bit RGBA color, or 0 if src is NULL or index is invalid
 */
int32_t	get_fdf_rgba_int32(const t_fdf *src, size_t index)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	if (src == NULL || index >= src->row * src->col)
		return (0);
	r = 0;
	g = 0;
	b = 0;
	a = 0;
	if (src->r != NULL)
		r = (int32_t)src->r[index];
	if (src->g != NULL)
		g = (int32_t)src->g[index];
	if (src->b != NULL)
		b = (int32_t)src->b[index];
	if (src->a != NULL)
		a = (int32_t)src->a[index];
	return (r << 24 | g << 16 | b << 8 | a);
}

// time : O(1)
// space: O(1)
bool	is_fdf_valid(const t_fdf *src)
{
	if (src == NULL)
		return (false);
	if (src->width == 0
		|| src->row * src->col == 0
		|| src->x == NULL
		|| src->y == NULL)
		return (false);
	return (true);
}
