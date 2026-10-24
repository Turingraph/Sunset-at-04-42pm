#include "aura.h"

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
 * @param aura optional function to calculate the value of each cell
 */
void	paint_aura_fdf_table(t_fdf_table *dst, t_fdf_channel channel,
	int (*aura)(const t_fdf_table *dst, size_t index))
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
		if (aura != NULL)
			y = aura(dst, i);
		if (channel == FDF_HEIGHT)
			dst->arr[i] = y;
		else if (rgba != NULL)
			rgba[i] = (unsigned char)f_interval_int(y, 0, 255);
		i += 1;
	}
}
