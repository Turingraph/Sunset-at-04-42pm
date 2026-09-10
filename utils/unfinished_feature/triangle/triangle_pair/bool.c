#include"triangle_pair.h"

// time : O(1)
// space: O(1)
bool	is_exist_xy(int *src, size_t index, bool is_and, size_t next)
{
	if (src == NULL)
		return (false);
	if (src[index] > 0 && src[index + next] > 0 && is_and == true)
		return (true);
	if ((src[index] > 0 || src[index + next] > 0) && is_and == false)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_edge_x(const t_table_fdf *src, size_t index, bool is_voxel)
{
	size_t	row;

	if (src == NULL || src->arr == NULL
		|| index >= src->row * src->col || src->col == 1)
		return (false);
	if (src->row == 1 && is_exist_xy(src->arr, index, true, 1) == true
		&& index < src->col)
		return (true);
	if (src->row == 1)
		return (false);
	row = index / src->col;
	if (row == src->row - 1 && is_exist_xy(src->arr, index, true, 1) == true)
		return (true);
	if (row == 0 && is_exist_xy(src->arr, index, true, 1) == true)
		return (true);
	if (row != 0 && is_exist_xy(src->arr, index, true, 1) == true
		&& (is_exist_xy(src->arr, index + src->col, is_voxel, 1) == false
			|| is_exist_xy(src->arr, index - src->col, is_voxel, 1) == false))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_edge_y(const t_table_fdf *src, size_t index, bool is_voxel)
{
	size_t	col;

	if (src == NULL || src->arr == NULL
		|| index >= src->row * src->col || src->row == 1)
		return (false);
	if (src->col == 1 && is_exist_xy(src->arr, index, true, src->col) == true
		&& index < src->row)
		return (true);
	if (src->col == 1)
		return (false);
	col = index % src->col;
	if (col == src->col - 1
		&& is_exist_xy(src->arr, index, true, src->col) == true)
		return (true);
	if (col == 0 && is_exist_xy(src->arr, index, true, 1) == true)
		return (true);
	if (col != 0 && is_exist_xy(src->arr, index, true, src->col) == true
		&& (is_exist_xy(src->arr, index + 1, is_voxel, src->col) == false
			|| is_exist_xy(src->arr, index - 1, is_voxel, src->col) == false))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_edge_diagonal_lr(const t_table_fdf *src, size_t index, bool is_left)
{
	if (src == NULL || src->arr == NULL || index >= src->row * src->col
		|| src->row < 2 || src->col < 2)
		return (false);
	if (src->arr[index] > 0 && src->arr[index + src->col + 1] > 0
		&& (src->arr[index + 1] <= 0 || src->arr[index + src->col] <= 0)
		&& is_left == true)
		return (true);
	if (src->arr[index + 1] > 0 && src->arr[index + src->col] > 0
		&& (src->arr[index] <= 0 || src->arr[index + src->col + 1] <= 0)
		&& is_left == false)
		return (true);
	return (false);
}

