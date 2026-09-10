#include"triangle_pair.h"

// time : O(1)
// space: O(1)
t_triangle	f_fdf_triangle(const t_table_fdf *src, size_t index, char topology)
{
	t_triangle	dst;
	size_t		axis_x;
	size_t		axis_y;

	dst = init_triangle();
	if (src == NULL || src->arr == NULL || dst.p1 == NULL || dst.p2 == NULL || dst.p3 == NULL
		|| index >= (src->row - 1) * (src->col - 1))
		return (dst);
	axis_y = index / src->col;
	axis_x = index % src->col;
	if (src->color_sampling == SAMPLE_TOP_LEFT || src->color_sampling == SAMPLE_EDGE_AVERAGE)
		topleft_tri_coloring(src, index, &dst);
	if (src->color_sampling == SAMPLE_AVERAGE)
		average_tri_coloring(src, index, &dst);
	if (topology == 1 || topology == 2)
	{
		update_3d_vector(dst.p1, axis_x, axis_y, src->arr[index]);
		update_3d_vector(dst.p2, axis_x, axis_y + 1, src->arr[index + src->col]);
		if (topology == 2)
			update_3d_vector(dst.p2, axis_x + 1, axis_y, src->arr[index + 1]);
		update_3d_vector(dst.p3, axis_x + 1, axis_y + 1, src->arr[index + src->col + 1]);
		return (dst);
	}
	update_3d_vector(dst.p1, axis_x, axis_y + 1, src->arr[index + src->col]);
	update_3d_vector(dst.p2, axis_x, axis_y, src->arr[index]);
	if (topology == 4)
		update_3d_vector(dst.p2, axis_x + 1, axis_y + 1, src->arr[index + src->col + 1]);
	update_3d_vector(dst.p3, axis_x + 1, axis_y, src->arr[index + 1]);
	return (dst);
}

// time : O(1)
// space: O(1)
size_t	count_2_triangle_faces(const t_table_fdf *src, size_t index, char *path)
{
	size_t	y;

	if (path != NULL)
		*path = 0;
	y = 0;
	if (src == NULL || src->arr == NULL || index >= src->row * src->col)
		return (0);
	if (src->arr[index] > 0)
		y += 1;
	if (src->arr[index + 1] > 0)
		y += 1;
	if (src->arr[index + src->col] > 0)
		y += 1;
	if (src->arr[index + src->col + 1] > 0)
		y += 1;
	if (src->arr[index] <= 0 && y == 3 && path != NULL)
		*path = 1;
	if (src->arr[index + 1] <= 0 && y == 3 && path != NULL)
		*path = 2;
	if (src->arr[index + src->col] <= 0 && y == 3 && path != NULL)
		*path = 3;
	if (src->arr[index + src->col + 1] <= 0 && y == 3 && path != NULL)
		*path = 4;
	if (y < 3)
		return (0);
	if (y == 3)
		return (1);
	if (path != NULL)
		*path = 5;
	return (2);
}

// time : O(1)
// space: O(1)
float	test_2_fdf_triangles(const t_table_fdf *src, size_t index)
{
	float		y;
	float		*target;
	t_triangle	triangle;

	if (src == NULL || src->arr == NULL || index >= (src->row - 1) * (src->col - 1))
		return (0);
	target = init_3d_vector(index % src->col + 1, index / src->col, src->arr[index + 1]);
	if (target == NULL)
		return (0);
	triangle = f_fdf_triangle(src, index, 1);
	if (triangle.p1 == NULL || triangle.p2 == NULL || triangle.p3 == NULL)
	{
		free(target);
		free_triangle(&triangle);
		return (0);
	}
	vector_scale(triangle.p2, -1.0, 3);
	vector_add(triangle.p1, triangle.p2, 3);
	vector_add(triangle.p3, triangle.p2, 3);
	cross_product_3d(triangle.p1, triangle.p3);
	y = scale_projection(triangle.p1, target, 3);
	free(target);
	free_triangle(&triangle);
	return (y);
}

// time : O(1)
// space: O(1)
t_triangle_arr	f_fdf_face(const t_table_fdf *src, size_t index, e_3d_shape shape)
{
	t_triangle_arr	dst;
	char			topology;
	int				test;

	topology = 0;
	dst = init_triangle_arr(2, 2, 2);
	if (src == NULL || src->arr == NULL || index >= (src->row - 1) * (src->col - 1))
		return (dst);
	dst.length = 2;
	if (shape != ISOMETRIC)
		dst.length = count_2_triangle_faces(src, index, &topology);
	if (dst.length == 2)
	{
		test = (index / src->col + index % src->col) % 2;
		if (shape == PRISM_CROSS)
			test = test_2_fdf_triangles(src, index);
		if (test > 0)
		{
			dst.arr[0] = f_fdf_triangle(src, index, 3);
			dst.arr[1] = f_fdf_triangle(src, index, 4);
			return (dst);
		}
		dst.arr[0] = f_fdf_triangle(src, index, 1);
		dst.arr[1] = f_fdf_triangle(src, index, 2);
		return (dst);
	}
	if (dst.length == 1)
	{
		dst.arr[0] = f_fdf_triangle(src, index, topology);
		free_triangle(&(dst.arr[1]));
	}
	if (dst.length == 0)
		free_triangle_arr(&dst, 0);
	return (dst);
}
