#include "spots.h"

/**
 * Check whether a cell is located on the boundary of the table
 * or is adjacent to an empty cell.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param threshold cell that have value greater than the threshold is considered as non-empty space.
 * Cell that have value equal to or less than the threshold is considered as empty space.
 * 
 * @return true if the cell is a positive value located on the table
 * boundary or adjacent to an empty cell, false otherwise.
 */
bool	spots_boundary(const t_fdf_table *dst, size_t index, int threshold)
{
	if (dst == NULL || dst->arr == NULL
		|| mul_overflow_size_t(dst->col, dst->row) == false
		|| index >= dst->col * dst->row)
		return (false);
	if (dst->arr[index] > threshold
			&& (index % dst->col == 0 || index % dst->col == dst->col - 1
			|| index / dst->col == 0 || index / dst->col == dst->row - 1))
		return (true);
	if (dst->arr[index] > threshold && index + dst->col + 1 < dst->row * dst->col
		&& (int)index - (int)dst->col - 1 >= threshold && (
			dst->arr[index + 1] <= threshold
			|| dst->arr[(int)index - 1] <= threshold
			|| dst->arr[(int)index + (int)dst->col + 1] <= threshold
			|| dst->arr[(int)index + (int)dst->col - 1] <= threshold
			|| dst->arr[(int)index - (int)dst->col + 1] <= threshold
			|| dst->arr[(int)index - (int)dst->col - 1] <= threshold
			|| dst->arr[(int)index + (int)dst->col] <= threshold
			|| dst->arr[(int)index - (int)dst->col] <= threshold
		))
		return (true);
	return (false);
}

/**
 * Check whether a cell is considered empty
 * (the integer height of the cell less than or equal to 0).
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the cell contains a value less than or equal to 0,
 * false otherwise.
 */
bool	spots_space(const t_fdf_table *dst, size_t index)
{
	if (dst == NULL || dst->arr == NULL
		|| mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	if (dst->arr[index] <= 0)
		return (true);
	return (false);
}

/**
 * Check whether a cell belongs to the chess pattern.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the cell position belongs to the chess pattern,
 * false otherwise.
 */
bool	spots_chess(const t_fdf_table *dst, size_t index)
{
	if (dst == NULL || dst->arr == NULL
		|| mul_overflow_size_t(dst->col, dst->row) == false)
		return (false);
	if ((index % dst->col + index / dst->col) % 2 == 1)
		return (true);
	return (false);
}

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

	if (mul_overflow_size_t(dst->col, dst->row) == false)
		return ;
	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (spots == NULL
			|| spots((const t_fdf_table *)dst, i) == true)
			paint_spots_fdf_table_unit(dst, color, channel, i);
		i += 1;
	}
}
