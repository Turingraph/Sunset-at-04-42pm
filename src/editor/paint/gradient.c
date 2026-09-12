/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:16:49 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:28:38 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint.h"

// time : O(1)
// space: O(1)
int	gradient_smooth(t_enum_rgba rgba_type,
	t_gradient gradient_input, int input_threshold)
{
	float	y;
	float	dx;
	float	dy;
	float	y1;
	float	y2;

	if (gradient_input.input_start == gradient_input.input_end)
		return (get_rgba_input(rgba_type, gradient_input.rgba_start));
	y1 = (float)(get_rgba_input(rgba_type, gradient_input.rgba_start));
	y2 = (float)(get_rgba_input(rgba_type, gradient_input.rgba_end));
	dx = (float)(gradient_input.input_end - gradient_input.input_start);
	if (dx == 0)
		dx = 1;
	dy = (float)(y2 - y1);
	y = (((float)(input_threshold - gradient_input.input_start)) / dx);
	y *= dy;
	y += y1;
	return (f_interval_int((int)f_round(y), -255, 255));
}

// time : O(1)
// space: O(1)
int	get_gradient_input(const t_table_fdf *src,
	t_7cell_channels mode, size_t index)
{
	if (src == NULL)
		return (-255);
	if (index >= src->row * src->col)
		return (-255);
	if (mode == D7_RED && src->r != NULL)
		return ((int)src->r[index]);
	if (mode == D7_GREEN && src->g != NULL)
		return ((int)src->g[index]);
	if (mode == D7_BLUE && src->b != NULL)
		return ((int)src->b[index]);
	if (mode == D7_ALPHA && src->a != NULL)
		return ((int)src->a[index]);
	if (mode == D7_ROW)
		return ((int)(index / src->col));
	if (mode == D7_COL)
		return ((int)(index % src->col));
	if (mode == D7_HEIGHT && src->arr != NULL)
		return ((int)src->arr[index]);
	return (-255);
}

// time : O(1)
// space: O(1)
int	update_cell_color(int alpha, bool is_overwrite,
	int dst, int new_color)
{
	float	dc;

	if (is_overwrite == true)
		return (new_color);
	dc = (float)dst - (float)new_color;
	if (dc < 0)
		dc *= -1;
	return (f_interval_int(
			f_round(((dc * alpha) + (new_color * (255 - alpha))) / 255.0),
			0, 255));
}

// time : O(1)
// space: O(1)
void	color_cells_gradient_unit(t_table_fdf *dst,
	t_gradient gradient_input, bool is_overwrite, size_t i)
{
	int				threshold;
	unsigned char	alpha;

	threshold = get_gradient_input((const t_table_fdf *)dst,
			gradient_input.cell_channel, i);
	alpha = 0;
	if (dst->a != NULL && is_overwrite == false)
		alpha = dst->a[i];
	if (gradient_input.input_start <= threshold
		&& threshold <= gradient_input.input_end)
	{
		if (is_overwrite == true && dst->a != NULL
			&& gradient_smooth(ALPHA, gradient_input, threshold) >= 0)
			dst->a[i] = gradient_smooth(ALPHA, gradient_input, threshold);
		if (dst->r != NULL && gradient_smooth(RED, gradient_input, threshold) >= 0)
			dst->r[i] = update_cell_color(alpha, is_overwrite, dst->r[i],
					gradient_smooth(RED, gradient_input, threshold));
		if (dst->g != NULL && gradient_smooth(GREEN, gradient_input, threshold) >= 0)
			dst->g[i] = update_cell_color(alpha, is_overwrite, dst->g[i],
					gradient_smooth(GREEN, gradient_input, threshold));
		if (dst->b != NULL && gradient_smooth(BLUE, gradient_input, threshold) >= 0)
			dst->b[i] = update_cell_color(alpha, is_overwrite, dst->b[i],
					gradient_smooth(BLUE, gradient_input, threshold));
	}
}

/**
 * Apply a color gradient to cells within an input range.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 * @param gradient_input gradient definition
 * @param is_overwrite replace existing colors instead of blending
 */
void	color_cells_gradient(t_table_fdf *dst,
	t_gradient gradient_input, bool is_overwrite)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col && dst->arr != NULL)
	{
		color_cells_gradient_unit(dst, gradient_input,
			is_overwrite, i);
		i += 1;
	}
}
