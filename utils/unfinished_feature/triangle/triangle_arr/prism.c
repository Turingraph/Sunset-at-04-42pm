#include"triangle_arr.h"

// time : O(n)
// sapce: O(n)
t_triangle_arr	table_to_one_d_prism(const t_table_fdf *src,
	float width, bool is_2faces, bool is_voxel)
{
	t_triangle_arr	dst;
	t_triangle_arr	tsd;

	dst = init_triangle_arr(0, src->row, src->col);
	if (src == NULL || (src->row < 2 && src->col < 2) || src->arr == NULL)
		return (dst);
	if (src->row == 1 && src->col > 1)
		dst = all_triangle_edge_x(src, is_voxel);
	if (src->col == 1 && src->row > 1)
		dst = all_triangle_edge_y(src, is_voxel);
	if (dst.arr != NULL && dst.length > 0)
		setwidth_triangle_arr(&dst, width, 2);
	if (is_2faces == true && dst.arr != NULL && dst.length > 0)
	{
		tsd = clone_triangle_arr(&dst, dst.length);
		concat_triangle_arr(&dst, &tsd);
	}
	return (dst);
}

// time : O(1)
// space: O(1)
t_prism	init_prism(void)
{
	t_prism	dst;

	dst.faces = init_triangle_arr(0, 0, 0);
	dst.edges = init_triangle_arr(0, 0, 0);
	return (dst);
}

// time : O(n)
// sapce: O(n)
t_triangle_arr	table_to_edge(const t_table_fdf *src, float width,
    bool is_2faces)
{
	t_triangle_arr	dst;
	t_triangle_arr	items;

	if (src == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	if ((src->row < 2 && src->col < 2)
		|| (src->row == 1 && src->col > 1) || (src->col == 1 && src->row > 1))
		return (table_to_one_d_prism(src, width, is_2faces, false));
	dst = init_triangle_arr(1, src->row, src->col);
	items = all_triangle_edge_x(src, false);
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_edge_y(src, false);
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_edge_lr(src, EDGE_DIAGONAL_LEFT);
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	items = all_triangle_edge_lr(src, EDGE_DIAGONAL_RIGHT);
	push_back_to_triangle_arr(&items, width, is_2faces);
	concat_triangle_arr(&dst, &items);
	return (dst);
}

// time : O(n)
// sapce: O(n)
t_prism	table_to_prism(const t_table_fdf *src,
	float width, bool is_2faces, e_3d_shape shape)
{
	t_prism	dst;

	dst = init_prism();
	if (src == NULL || src->arr == NULL || (src->row <= 1 && src->col <= 1)
		|| src->row == 0 || src->col == 0)
		return (dst);
	if (src->row == 1 || src->col == 1)
	{
		dst.edges = table_to_one_d_prism(src, width, is_2faces, false);
		return (dst);
	}
	dst.faces = all_triangle_faces(src, shape);
	push_back_to_triangle_arr(&(dst.faces), width, is_2faces);
	if (shape == ISOMETRIC)
		return (dst);
	dst.edges = table_to_edge(src, width, is_2faces);
	push_back_to_triangle_arr(&(dst.edges), width, is_2faces);
	return (dst);
}

// time : O(1)
// space: O(1)
void	free_prism(t_prism *src)
{
	if (src != NULL)
	{
		free_triangle_arr(&(src->faces), 0);
		free_triangle_arr(&(src->edges), 0);
		*src = init_prism();
	}
}
