#include "table_private.h"

void	mod_fdf_table(t_fdf_table *dst, int mod,
	t_fdf_channel channel)
{
	unsigned char	*dst_rgba;
	size_t			i;

	if (isvalid_fdf_channel(dst, &dst_rgba, channel) == false
		|| (mod < 2 && mod > -2))
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (channel == FDF_HEIGHT)
			dst->arr[i] = dst->arr[i] % mod;
		else
			dst_rgba[i] = (unsigned char)f_interval(
					dst_rgba[i] % mod, 0, 255);
		i += 1;
	}
}

void	interval_fdf_table(t_fdf_table *dst, int input_min, int input_max,
	t_fdf_channel channel)
{
	int				temp;
	unsigned char	*dst_rgba;
	size_t			i;

	if (channel != FDF_HEIGHT)
	{
		input_max = f_interval(input_max, 0, 255);
		input_min = f_interval(input_min, 0, 255);
	}
	if (input_min > input_max)
	{
		temp = input_min;
		input_min = input_max;
		input_max = temp;
	}
	if (isvalid_fdf_channel(dst, &dst_rgba, channel) == false)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (channel == FDF_HEIGHT)
			dst->arr[i] = f_interval(dst->arr[i], input_min, input_max);
		else
			dst_rgba[i] = f_interval(dst_rgba[i], input_min, input_max);
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
 * @param src source FDF table (It isn't const, because the dst and src can be the same fdf table).
 * @param dst_channel channel to copy
 * @param src_channel channel to copy
 */
void	copy_fdf_table_channel(t_fdf_table *dst, t_fdf_table *src,
	t_fdf_channel dst_channel, t_fdf_channel src_channel)
{
	unsigned char	*dst_rgba;
	unsigned char	*src_rgba;
	size_t			i;

	if (isvalid_fdf_channel(dst, &dst_rgba, dst_channel) == false
		|| isvalid_fdf_channel(src, &src_rgba, src_channel) == false)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (dst_channel == FDF_HEIGHT && src_channel == FDF_HEIGHT)
			dst->arr[i] = src->arr[i];
		else if (dst_channel == FDF_HEIGHT && src_channel != FDF_HEIGHT)
			dst->arr[i] = (int)src_rgba[i];
		else if (dst_channel != FDF_HEIGHT && src_channel == FDF_HEIGHT)
			dst_rgba[i] = (int)f_interval_int(src->arr[i], 0, 255);
		else
			dst_rgba[i] = (int)src_rgba[i];
		i += 1;
	}
}
