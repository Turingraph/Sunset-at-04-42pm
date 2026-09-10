#include"triangle_arr.h"

// time : O(n)
// space: O(1)
float	update_width_of_triangle_arr(t_triangle_arr *src, size_t axis)
{
	size_t	i;
	float	min;
	float	max;

	min = 0;
	max = 0;
	if (src->arr != NULL && 0 < src->length && axis <= 2)
		min = height_of_triangle((const t_triangle *)&(src->arr[0]), axis, 0);
	i = 0;
	while (src->arr != NULL && i < src->length && axis <= 2)
	{
		if (max < height_of_triangle(&(src->arr[i]), axis, true))
			max = height_of_triangle(&(src->arr[i]), axis, true);
		if (min > height_of_triangle(&(src->arr[i]), axis, false))
			min = height_of_triangle(&(src->arr[i]), axis, false);
		i += 1;
	}
	if (axis == 0)
		src->width_x = max - min;
	if (axis == 1)
		src->width_y = max - min;
	if (axis == 2)
		src->width_z = max - min;
	return (min);
}

// time : O(n)
// space: O(1)
float	center_triangle_arr(t_triangle_arr *src, size_t axis)
{
	float	min;
	float	max;

	min = update_width_of_triangle_arr(src, axis);
	max = min;
	if (axis == 0)
		max += src->width_x;
	if (axis == 1)
		max += src->width_y;
	if (axis == 2)
		max += src->width_z;
	shift_triangle_arr(src, -1 * (max + min) / 2, axis);
	return ((max + min) / 2);
}

// time : O(n)
// space: O(1)
float	average_triangle_arr(t_triangle_arr *src, size_t axis, bool is_update)
{
	size_t	i;
	float	y;

	y = 0;
	i = 0;
	while (i < src->length && src->arr != NULL && axis <= 2)
	{
		if (src->arr[i].p1 != NULL)
			y += src->arr[i].p1[axis];
		if (src->arr[i].p2 != NULL)
			y += src->arr[i].p2[axis];
		if (src->arr[i].p3 != NULL)
			y += src->arr[i].p3[axis];
		i += 1;
	}
	if (src->length > 0)
		y /= 3 * src->length;
	if (is_update == false)
		return (y);
	shift_triangle_arr(src, -1 * y, axis);
	return (y);
}

// time : O(n)
// space: O(1)
void	center_prism(t_prism *src)
{
	float	min_x;
	float	min_y;
	float	min_z;

	if (src == NULL || is_triangle_arr_valid(&src->faces) == false)
		return ;
	min_x = update_width_of_triangle_arr(&src->faces, 0);
	min_y = update_width_of_triangle_arr(&src->faces, 1);
	min_z = update_width_of_triangle_arr(&src->faces, 2);
	shift_triangle_arr(&src->faces, -1 * (src->faces.width_x) / 2 - min_x, 0);
	shift_triangle_arr(&src->faces, -1 * (src->faces.width_y) / 2 - min_y, 1);
	shift_triangle_arr(&src->faces, -1 * (src->faces.width_z) / 2 - min_z, 2);
	shift_triangle_arr(&src->edges, -1 * (src->faces.width_x) / 2 - min_x, 0);
	shift_triangle_arr(&src->edges, -1 * (src->faces.width_y) / 2 - min_y, 1);
	shift_triangle_arr(&src->edges, -1 * (src->faces.width_z) / 2 - min_z, 2);
}
