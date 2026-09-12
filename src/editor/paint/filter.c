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
bool	is_space_fdf(const t_table_fdf *dst, size_t index)
{
	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0
		|| index > dst->row * dst->col)
		return (false);
	if (dst->arr[index] <= 0)
		return (true);
	return (false);
}

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
 *
 * @return true if the cell is a positive value located on the table
 * boundary or adjacent to an empty cell, false otherwise.
 */
bool	is_boundary_fdf(const t_table_fdf *dst, size_t index)
{
	if (dst == NULL || dst->row == 0 || dst->arr == NULL
		|| dst->col == 0 || index > dst->row * dst->col)
		return (false);
	if (dst->arr[index] > 0 && (index % dst->col == 0
			|| index % dst->col == dst->col - 1
			|| index / dst->col == 0 || index / dst->col == dst->row - 1))
		return (true);
	if (dst->arr[index] > 0 && index + dst->col + 1 < dst->row * dst->col
		&& (int)index - (int)dst->col - 1 >= 0 && (
			dst->arr[index + 1] <= 0
			|| dst->arr[(int)index - 1] <= 0
			|| dst->arr[(int)index + (int)dst->col + 1] <= 0
			|| dst->arr[(int)index + (int)dst->col - 1] <= 0
			|| dst->arr[(int)index - (int)dst->col + 1] <= 0
			|| dst->arr[(int)index - (int)dst->col - 1] <= 0
			|| dst->arr[(int)index + (int)dst->col] <= 0
			|| dst->arr[(int)index - (int)dst->col] <= 0
		))
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
bool	is_chess_fdf(const t_table_fdf *dst, size_t index)
{
	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return (false);
	if ((index % dst->col + index / dst->col) % 2 == 1)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
static void	set_cells_color_unit(t_table_fdf *dst, int color,
	t_enum_rgba channel, size_t i)
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
void	set_cells_color(t_table_fdf *dst, int color,
	t_enum_rgba channel, bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index))
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (is_filtered_cell == NULL
			|| is_filtered_cell((const t_table_fdf *)dst, i) == true)
			set_cells_color_unit(dst, color, channel, i);
		i += 1;
	}
}
