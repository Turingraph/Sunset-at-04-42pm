#include "paint.h"

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
bool	is_boundary_fdf(const t_table_fdf *dst, size_t index, int threshold)
{
	if (dst == NULL || dst->arr == NULL
		|| check_multiplication_overflow(dst->col, dst->row) == false
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
int	count_neighbor_fdf(const t_table_fdf *dst, size_t index, int threshold)
{
	int	y;

	y = 0;
	if (dst == NULL || dst->arr == NULL
		|| check_multiplication_overflow(dst->col, dst->row) == false
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
