#include "spots.h"

static bool	is_available_left(size_t col, size_t index)
{
	if (index % col == 0)
		return (false);
	return (true);
}

static bool	is_available_right(size_t col, size_t index)
{
	if (index % col == col - 1)
		return (false);
	return (true);
}

static bool	is_available_up(size_t col, size_t index)
{
	if (index / col == 0)
		return (false);
	return (true);
}

static bool	is_available_down(size_t col, size_t row, size_t index)
{
	if (index / col == row - 1)
		return (false);
	return (true);
}

static bool	is_edge_frame(size_t col, size_t row, size_t index)
{
	if (is_available_up(col, index) == false
		|| is_available_down(col, row, index) == false
		|| is_available_left(col, index) == false
		|| is_available_right(col, index) == false)
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
bool	spots_boundary(const t_fdf_table *dst, size_t index)
{
	int	threshold;

	threshold = 0;
	if (dst == NULL || dst->arr == NULL
		|| mul_overflow_size_t(dst->col, dst->row) == false
		|| index >= dst->col * dst->row)
		return (false);
	if (dst->arr[index] > threshold
			&& is_edge_frame(dst->col, dst->row, index) == true)
		return (true);
	if (dst->arr[index] > threshold
		&& (dst->arr[index + 1] <= threshold
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
