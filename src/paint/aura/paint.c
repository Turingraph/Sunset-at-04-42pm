#include "aura.h"

/**
 * Counts the neighboring cells whose values exceed a given threshold.
 *
 * Examines the eight possible neighbors (horizontal, vertical, and diagonal)
 * of the cell at the specified index in a 2D grid stored as a 1D array.
 * A neighbor is counted if its value is strictly greater than the threshold.
 * Neighbors outside the grid boundaries are ignored.
 *
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table
 * @param index Index of the cell (within the FDF table) whose neighbors will be examined.
 * The index must be within the grid's valid range.
 * @param threshold Minimum value a neighboring cell must exceed to be counted.
 * 
 * @return The number of valid neighboring cells whose values exceed the
 * threshold, ranging from 0 to 8. Returns 0 if the FDF table is invalid.
 */
int	aura_conway(const t_fdf_table *dst, size_t index, int threshold)
{
	int	y;

	y = 0;
	if (dst == NULL || dst->arr == NULL
		|| mul_overflow_size_t(dst->col, dst->row) == false
		|| index >= dst->col * dst->row)
		return (y);
	if (index % dst->col < dst->col - 1 && dst->arr[index + 1] > threshold)
		y += 1;
	if (index % dst->col > 0 && dst->arr[index - 1] > threshold)
		y += 1;
	if (index / dst->col < dst->row - 1 && dst->arr[index + dst->col] > threshold)
		y += 1;
	if (index / dst->col > 0 && dst->arr[index - dst->col] > threshold)
		y += 1;
	if (index / dst->col < dst->row - 1
		&& index % dst->col < dst->col - 1
		&& dst->arr[index + dst->col + 1] > threshold)
		y += 1;
	if (index / dst->col < dst->row - 1
		&& index % dst->col > 0
		&& dst->arr[index + dst->col - 1] > threshold)
		y += 1;
	if (index / dst->col > 0
		&& index % dst->col < dst->col - 1
		&& dst->arr[index - dst->col + 1] > threshold)
		y += 1;
	if (index / dst->col > 0
		&& index % dst->col > 0
		&& dst->arr[index - dst->col - 1] > threshold)
		y += 1;
	return (y);
}

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
