#include "paint.h"

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
bool	is_space_fdf(const t_fdf_table *dst, size_t index)
{
	if (dst == NULL || dst->arr == NULL
		|| check_multiplication_overflow(dst->col, dst->row) == false || index >= dst->col * dst->row)
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
bool	is_chess_fdf(const t_fdf_table *dst, size_t index)
{
	if (dst == NULL || dst->arr == NULL
		|| check_multiplication_overflow(dst->col, dst->row) == false)
		return (false);
	if ((index % dst->col + index / dst->col) % 2 == 1)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
static void	set_cells_color_unit(t_fdf_table *dst, int color,
	t_fdf_channel channel, size_t i)
{
	unsigned char	cccc;

	cccc = f_interval_int(color, 0, 255);
	if (dst->arr != NULL && channel == HEIGHT)
		dst->arr[i] = color;
	if (dst->r != NULL && channel == RED)
		dst->r[i] = cccc;
	if (dst->g != NULL && channel == GREEN)
		dst->g[i] = cccc;
	if (dst->b != NULL && channel == BLUE)
		dst->b[i] = cccc;
	if (dst->a != NULL && channel == ALPHA)
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
 * @param is_filtered_cell optional callback used to select which cells
 * are modified. If NULL, every cell is modified.
 */
void	set_cells_color(t_fdf_table *dst, int color,
	t_fdf_channel channel, bool (*is_filtered_cell)(const t_fdf_table *dst, size_t index))
{
	size_t	i;

	if (check_multiplication_overflow(dst->col, dst->row) == false)
		return ;
	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (is_filtered_cell == NULL
			|| is_filtered_cell((const t_fdf_table *)dst, i) == true)
			set_cells_color_unit(dst, color, channel, i);
		i += 1;
	}
}
