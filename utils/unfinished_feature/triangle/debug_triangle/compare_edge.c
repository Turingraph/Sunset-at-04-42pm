#include "debug_triangle.h"

// time : O(1)
// space: O(1)
bool	compare_3dpoint_edge(const t_triangle *src,
	t_3d_point point_0, t_3d_point point_1, char triangle_index)
{
	if (src == NULL)
		return (false);
	if (src->p1 == NULL || src->p2 == NULL || src->p3 == NULL)
		return (false);
	if (are_2_3dpoint_same(src->p1, point_0.x, point_0.y, point_0.z) == true
		&& ((are_2_3dpoint_same(src->p2, point_0.x, point_0.y, 0.0) == true
				&& triangle_index == 0)
			|| (are_2_3dpoint_same(src->p2,
					point_1.x, point_1.y, point_1.z) == true
				&& triangle_index == 1))
		&& are_2_3dpoint_same(src->p3, point_1.x, point_1.y, 0.0) == true)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	compare_3dpoint_edge_tester(const t_triangle_arr *src,
	const t_triangle_tester *tester)
{
	if (tester == NULL && src == NULL)
		return (true);
	if (tester == NULL || src == NULL)
		return (false);
	if (src->length == tester->length && tester->length == 0)
		return (true);
	if (tester->length == 2 && tester->length == 2
		&& compare_3dpoint_edge(&(src->arr[0]),
			tester->points[0], tester->points[1], 0) == true
		&& compare_3dpoint_edge(&(src->arr[1]),
			tester->points[0], tester->points[1], 1) == true)
		return (true);
	return (false);
}

// This 2 testing functions are only reliable if and only if the "edge" exists.
// time : O(1)
// space: O(1)
bool	compare_table_edge_3dxy(const t_table_fdf *table,
	const t_triangle *src, size_t index, char triangle_index)
{
	float	row;
	float	col;

	if (table == NULL && src == NULL)
		return (true);
	if (table == NULL || table->arr == NULL || index >= table->col * table->row || src == NULL)
		return (false);
	if (src->p1 == NULL || src->p2 == NULL || src->p3 == NULL)
		return (false);
	row = index / table->col;
	col = index % table->col;
	if (are_2_3dpoint_same(src->p1, col, row, (float)table->arr[index]) == true
		&& ((are_2_3dpoint_same(src->p2, col, row, 0.0) == true && triangle_index == 0)
			|| (are_2_3dpoint_same(src->p2, col + 1.0, row,
				(float)table->arr[index + 1]) == true && triangle_index == 1))
		&& are_2_3dpoint_same(src->p3, col + 1.0, row, 0.0) == true)
		return (true);
	if (are_2_3dpoint_same(src->p1, col, row, (float)table->arr[index]) == true
		&& ((are_2_3dpoint_same(src->p2, col, row, 0.0) == true && triangle_index == 2)
			|| (are_2_3dpoint_same(src->p2, col + 1, row,
				(float)table->arr[index + table->col]) == true && triangle_index == 3))
		&& are_2_3dpoint_same(src->p3, col + 1, row, 0.0) == true)
		return (true);
	return (false);
}

// This 2 testing functions are only reliable if and only if the "edge" exists.
// time : O(1)
// space: O(1)
bool	compare_table_edge_3d_arr(const t_table_fdf *table,
	const t_triangle_arr *src, size_t index, e_edge mode)
{
	if (table == NULL && src == NULL)
		return (true);
	if (src->length != 2)
	{
		write(1, "compare_table_edge_3d_arr is incompatible with "
			"`t_triangle_arr *arr` argument because it does not check if the "
			"surrounding cells exists or not (a.k.a. if it >= 0).\n", 165);
		return (false);
	}
	if (table == NULL || src->arr == NULL || table->arr == NULL
		|| index >= table->col * table->row || src == NULL)
		return (false);
	if (mode == EDGE_X && compare_table_edge_3dxy(table, &(src->arr[0]), index, 0) == true
		&& compare_table_edge_3dxy(table, &(src->arr[1]), index, 1) == true)
		return (true);
	if (mode == EDGE_Y && compare_table_edge_3dxy(table, &(src->arr[0]), index, 2) == true
		&& compare_table_edge_3dxy(table, &(src->arr[1]), index, 3) == true)
		return (true);
	return (false);
}
