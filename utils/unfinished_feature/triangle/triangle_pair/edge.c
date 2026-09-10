#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	get_edge_indexing(size_t *row, size_t *col, e_edge topology)
{
	if (topology == EDGE_X || topology == EDGE_DIAGONAL_RIGHT)
		*col += 1;
	if (topology == EDGE_Y)
		*row += 1;
	if (topology == EDGE_DIAGONAL_LEFT)
	{
		*row += 1;
		*col += 1;
	}
}

// time : O(1)
// space: O(1)
void	init_edge_positions(t_triangle_arr *dst,
	size_t index, e_edge topology, size_t src_col)
{
	size_t	row;
	size_t	col;
	size_t	row_2;
	size_t	col_2;

	if (dst != NULL && dst->capacity > 1 && dst->arr != NULL)
	{
		row = index / src_col;
		col = index % src_col;
		row_2 = row;
		col_2 = col;
		get_edge_indexing(&row_2, &col_2, topology);
		if (topology == EDGE_DIAGONAL_RIGHT)
			row += 1;
		update_3d_vector(dst->arr[0].p1, (float)col, (float)row, 1.0);
		update_3d_vector(dst->arr[0].p2, (float)col, (float)row, 0);
		update_3d_vector(dst->arr[0].p3, (float)col_2, (float)row_2, 0);
		update_3d_vector(dst->arr[1].p1, (float)col, (float)row, 1.0);
		update_3d_vector(dst->arr[1].p2, (float)col_2, (float)row_2, 1.0);
		update_3d_vector(dst->arr[1].p3, (float)col_2, (float)row_2, 0);
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
bool	fdf_edge_detection(const t_table_fdf *src,
	size_t index, e_edge topology, bool is_voxel)
{
	if (src == NULL || src->arr == NULL || index >= src->col * src->row)
		return (false);
	if (topology == EDGE_X && is_edge_x(src, index, is_voxel) == true)
		return (true);
	if (topology == EDGE_Y && is_edge_y(src, index, is_voxel) == true)
		return (true);
	if (topology == EDGE_DIAGONAL_LEFT
		&& is_edge_diagonal_lr(src, index, true) == true)
		return (true);
	if (topology == EDGE_DIAGONAL_RIGHT
		&& is_edge_diagonal_lr(src, index, false) == true)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
void	f_fdf_edge_coloring(const t_table_fdf *src,
	size_t index, t_triangle_arr *dst)
{
	if (src != NULL && index < src->row * src->col && dst != NULL
		&& dst->arr != NULL && dst->length >= 2)
	{
		if (src->color_sampling == SAMPLE_AVERAGE
			|| src->color_sampling == SAMPLE_EDGE_AVERAGE)
			edge_average_tri_coloring(src, dst);
		else
		{
			topleft_tri_coloring(src, index, &(dst->arr[0]));
			topleft_tri_coloring(src, index, &(dst->arr[1]));
		}
	}
}

// time : O(1)
// space: O(1)
t_triangle_arr	f_fdf_edge(const t_table_fdf *src,
	size_t index, e_edge topology, bool is_voxel)
{
	t_triangle_arr	dst;

	dst = init_triangle_arr(2, 0, 0);
	if (dst.arr == NULL || src == NULL || src->arr == NULL
		|| fdf_edge_detection(src, index, topology, is_voxel) == false)
		return (dst);
	dst.arr[0] = init_triangle();
	dst.arr[1] = init_triangle();
	init_edge_positions(&dst, index, topology, src->col);
	index = (size_t)f_floor(dst.arr[0].p1[1] * src->col + dst.arr[0].p1[0]);
	dst.arr[0].p1[2] = src->arr[index];
	dst.arr[1].p1[2] = dst.arr[0].p1[2];
	index = (size_t)f_floor(dst.arr[1].p2[1] * src->col + dst.arr[1].p2[0]);
	dst.arr[1].p2[2] = src->arr[index];
	f_fdf_edge_coloring(src, index, &dst);
	return (dst);
}
