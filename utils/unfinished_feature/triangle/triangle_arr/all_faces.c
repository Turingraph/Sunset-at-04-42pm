#include"triangle_arr.h"

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_faces(const t_table_fdf *src, e_3d_shape shape)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	if (src == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(
			2 * (src->row - 1) * (src->col - 1), src->row, src->col);
	if (dst.arr == NULL || src->arr == NULL)
		return (dst);
	i = 0;
	while (i < src->row - 1)
	{
		j = 0;
		while (j < src->col - 1)
		{
			item = f_fdf_face(src, i * src->col + j, shape);
			j += concat_triangle_arr(&dst, &item);
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_edge_x(
	const t_table_fdf *src, bool is_voxel)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	if (src == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(2 * src->row * (src->col - 1),
			src->row, src->col - 1);
	if (dst.arr == NULL)
		return (dst);
	i = 0;
	while (i < src->row)
	{
		j = 0;
		while (j < src->col - 1)
		{
			item = f_fdf_edge(src, i * src->col + j, EDGE_X, is_voxel);
			j += concat_triangle_arr(&dst, &item);
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_edge_y(
	const t_table_fdf *src, bool is_voxel)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	if (src == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(2 * src->col * (src->row - 1),
			src->row - 1, src->col);
	if (dst.arr == NULL)
		return (dst);
	i = 0;
	while (i < src->row - 1)
	{
		j = 0;
		while (j < src->col)
		{
			item = f_fdf_edge(src, i * src->col + j, EDGE_Y, is_voxel);
			j += concat_triangle_arr(&dst, &item);
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_edge_lr(const t_table_fdf *src, e_edge mode)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;
	bool			is_voxel;

	is_voxel = false;
	if (src == NULL || src->row <= 1 || src->col <= 1 || src->arr == NULL
		|| (mode != EDGE_DIAGONAL_LEFT && mode != EDGE_DIAGONAL_RIGHT))
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(2 * (src->row - 1) * (src->col - 1),
			src->row - 1, src->col - 1);
	i = 0;
	while (i < src->row - 1 && dst.arr != NULL)
	{
		j = 0;
		while (j < src->col - 1)
		{
			item = f_fdf_edge(src, i * src->col + j, mode, is_voxel);
			j += concat_triangle_arr(&dst, &item);
		}
		i += 1;
	}
	return (dst);
}

// time : O(1)
// space: O(1)
bool	is_triangle_arr_valid(t_triangle_arr *src)
{
	if (src == NULL || src->arr == NULL || src->length == 0
		|| src->table_col * src->table_row == 0
		|| src->width_x < 0 || src->width_y < 0 || src->width_z < 0)
		return (false);
	return (true);
}
