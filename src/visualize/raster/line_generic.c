/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_generic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:33:09 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 17:34:42 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster_private.h"

// time : O(n)
// space: O(1)
static void	raster_linex(mlx_image_t *dst,
	t_line line, t_line boundary, t_style_raster style_raster)
{
	t_int2d	temp;

	if (line.p2.x < line.p1.x)
	{
		temp = line.p2;
		line.p2 = line.p1;
		line.p1 = temp;
	}
	if (line.p2.y - line.p1.y < 0)
		raster_linex_minus(dst, line, boundary, style_raster);
	else
		raster_linex_plus(dst, line, boundary, style_raster);
}

// time : O(n)
// space: O(1)
static void	raster_liney(mlx_image_t *dst,
	t_line line, t_line boundary, t_style_raster style_raster)
{
	t_int2d	temp;

	if (line.p2.y < line.p1.y)
	{
		temp = line.p2;
		line.p2 = line.p1;
		line.p1 = temp;
	}
	if (line.p2.x - line.p1.x < 0)
		raster_liney_minus(dst, line, boundary, style_raster);
	else
		raster_liney_plus(dst, line, boundary, style_raster);
}

// time : O(n)
// space: O(1)
void	raster_line(mlx_image_t *dst,
	t_line line, t_line boundary, t_style_raster style_raster)
{
	if (dst == NULL || mul_overflow_uint32_t(dst->width, dst->height) == false)
		return ;
	if (f_abs_int(line.p2.x - line.p1.x) > f_abs_int(line.p2.y - line.p1.y))
		raster_linex(dst, line, boundary, style_raster);
	else
		raster_liney(dst, line, boundary, style_raster);
}
