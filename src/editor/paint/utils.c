#include "paint.h"

// time : O(1)
// space: O(1)
int	get_rgba_input(t_fdf_channel rgba_type, t_rgba src)
{
	if (rgba_type == RED)
		return (src.r);
	if (rgba_type == GREEN)
		return (src.g);
	if (rgba_type == BLUE)
		return (src.b);
	if (rgba_type == ALPHA)
		return (src.a);
	return (0);
}

/**
 * Paint a table FDF channel using the value of each cell from
 * the origin in the complex plane, as |z.re + z.im|.
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
void	paint_space(t_table_fdf *dst, t_fdf_channel channel,
	int (*cell_metric)(const t_table_fdf *dst, size_t index))
{
	size_t			i;
	int				y;
	t_complex		z;
	unsigned char	*rgba;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	rgba = get_rgba_of_table_fdf(dst, channel);
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate(dst, i, 1);
		y = (int)(f_abs(z.re) + f_abs(z.im));
		y = (int)f_round(f_root_finding(y, 2));
		if (cell_metric != NULL)
			y = cell_metric(dst, i);
		if (channel == HEIGHT)
			dst->arr[i] = y;
		else if (rgba != NULL)
			rgba[i] = (unsigned char)f_interval_int(y, 0, 255);
		i += 1;
	}
}
