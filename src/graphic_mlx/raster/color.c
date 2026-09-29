/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:28:58 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 16:27:01 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster_private.h"

/**
 * Pack individual RGBA channels into a 32-bit color value.
 *
 * The channels are packed in RGBA order, with red as the most
 * significant byte and alpha as the least significant byte.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param r red channel value
 * @param g green channel value
 * @param b blue channel value
 * @param a alpha channel value
 * @return packed 32-bit RGBA color
 * @see https://github.com/codam-coding-college/MLX42/blob/master/docs/Colors.md
 * to understand how to use color with MLX42 graphic library.
 */
int32_t	f_rgba_to_int32(unsigned char r,
	unsigned char g, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * Fill an MLX image with a single color.
 *
 * Every pixel in the destination image is replaced with the specified
 * 32-bit RGBA color.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param dst destination MLX image
 * @param color 32-bit RGBA color used to fill the image
 */
void	color_background_mlx(mlx_image_t *dst, int32_t color)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (dst != NULL && i < (int32_t)dst->height)
	{
		j = 0;
		while (j < (int32_t)dst->width)
		{
			mlx_put_pixel(dst, j, i, color);
			j += 1;
		}
		i += 1;
	}
}

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
 * @param src source FDF table
 * @param index element index whose RGBA channels are combined
 * @return packed 32-bit RGBA color, or 0 if src is NULL or index is invalid
 */
int32_t	get_table_rgba_int32(const t_table_fdf *src, size_t index)
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
