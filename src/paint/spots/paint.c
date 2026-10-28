#include "spots.h"

// time : O(1)
// space: O(1)
static void	paint_spots_fdf_table_unit(t_fdf_table *dst, int color,
	t_fdf_channel channel, size_t i)
{
	unsigned char	cccc;

	cccc = f_interval_int(color, 0, 255);
	if (dst->arr != NULL && channel == FDF_HEIGHT)
		dst->arr[i] = color;
	if (dst->r != NULL && channel == FDF_RED)
		dst->r[i] = cccc;
	if (dst->g != NULL && channel == FDF_GREEN)
		dst->g[i] = cccc;
	if (dst->b != NULL && channel == FDF_BLUE)
		dst->b[i] = cccc;
	if (dst->a != NULL && channel == FDF_ALPHA)
		dst->a[i] = cccc;
}

/**
 * Apply a color or height value to the selected channel of every cell.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 * @param color color or height value to apply. The color value is
 * clamped to the range [0, 255].
 * @param channel selected color or height channel
 * @param spots optional callback used to select which cells
 * are modified. If NULL, every cell is modified.
 */
void	paint_spots_fdf_table(t_fdf_table *dst, int color,
	t_fdf_channel channel, bool (*spots)(const t_fdf_table *dst, size_t index))
{
	size_t	i;

	if (dst != NULL && mul_overflow_size_t(dst->col, dst->row) == false)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (spots == NULL
			|| spots((const t_fdf_table *)dst, i) == true)
			paint_spots_fdf_table_unit(dst, color, channel, i);
		i += 1;
	}
}
