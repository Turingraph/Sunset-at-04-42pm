#include "paint.h"

// time : O(1)
// space: O(1)
int	get_input_rgba(t_fdf_channel rgba_type, t_input_rgba src)
{
	if (rgba_type == FDF_RED)
		return (src.r);
	if (rgba_type == FDF_GREEN)
		return (src.g);
	if (rgba_type == FDF_BLUE)
		return (src.b);
	if (rgba_type == FDF_ALPHA)
		return (src.a);
	return (0);
}

/**
 * Paint a table FDF channel using the value of each cell from
 * the origin in the complex plane, as |z.x + z.im|.
 * If cell_metric is not NULL, its output will be utilized instead
 * of the default complex-plane distance.
 * 
 * time/space: O(n) + O(cell_metric) / O(1)
 * 
 * status: public api
 * 
 * @param dst destination FDF table to paint
 * @param channel FDF channel to paint
 * @param cell_metric optional function to calculate the value of each cell
 */
void	paint_space(t_fdf_table *dst, t_fdf_channel channel,
	int (*cell_metric)(const t_fdf_table *dst, size_t index))
{
	size_t			i;
	int				y;
	t_float2d		z;
	unsigned char	*rgba;

	if (dst == NULL || dst->arr == NULL
		|| mul_overflow_size_t(dst->col, dst->row) == false)
		return ;
	rgba = rgbarr_from_table(dst, channel);
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = init_table_coordinate(dst, i, 1);
		y = (int)(f_abs(z.x) + f_abs(z.y));
		y = (int)f_round(f_root_find(y, 2));
		if (cell_metric != NULL)
			y = cell_metric(dst, i);
		if (channel == FDF_HEIGHT)
			dst->arr[i] = y;
		else if (rgba != NULL)
			rgba[i] = (unsigned char)f_interval_int(y, 0, 255);
		i += 1;
	}
}
