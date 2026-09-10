#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	*free_triangle(t_triangle *src)
{
	if (src == NULL)
		return (NULL);
	if (src->p1 != NULL)
		free(src->p1);
	if (src->p2 != NULL)
		free(src->p2);
	if (src->p3 != NULL)
		free(src->p3);
	src->r = 0;
	src->g = 0;
	src->b = 0;
	src->a = 0;
	src->p1 = NULL;
	src->p2 = NULL;
	src->p3 = NULL;
	return (NULL);
}

// delete_1st_triangle = 0 means to delete all triangles.
// delete_1st_triangle > 0 means to delete only some triangles
// delete_1st_triangle is used for concat_triangle_arr
// and copy_triangle_arr.
// time : O(1)
// space: O(1)
void	*free_triangle_arr(t_triangle_arr *src, size_t delete_1st_triangle)
{
	if (src == NULL)
		return (NULL);
	if (src != NULL && src->arr != NULL)
	{
		while (delete_1st_triangle < src->length)
		{
			free_triangle(&(src->arr[delete_1st_triangle]));
			delete_1st_triangle += 1;
		}
		free(src->arr);
	}
	src->arr = NULL;
	src->capacity = 0;
	src->length = 0;
	src->width_x = 0.0;
	src->width_y = 0.0;
	src->width_z = 0.0;
	return (NULL);
}

// time : O(1)
// space: O(1)
t_triangle	init_triangle(void)
{
	t_triangle	dst;

	dst.r = (unsigned char)255;
	dst.g = (unsigned char)255;
	dst.b = (unsigned char)255;
	dst.a = (unsigned char)0;
	dst.p1 = init_3d_vector(0, 0, 0);
	dst.p2 = init_3d_vector(0, 0, 0);
	dst.p3 = init_3d_vector(0, 0, 0);
	return (dst);
}

// time : O(1)
// space: O(1)
t_triangle_arr	init_triangle_arr(size_t length, size_t row, size_t col)
{
	t_triangle_arr	dst;

	dst.length = 0;
	dst.capacity = length;
	dst.width_x = 0.0;
	dst.width_y = 0.0;
	dst.width_z = 0.0;
	dst.table_row = row;
	dst.table_col = col;
	dst.arr = NULL;
	if (length > 0)
		dst.arr = malloc_talk(sizeof(t_triangle) * length,
				"graphic/triangle_pair/init.c/init_triangle_arr\n");
	if (length > 0 && dst.arr == NULL)
	{
		dst.capacity = 0;
		dst.table_row = 0;
		dst.table_col = 0;
	}
	return (dst);
}

// time : O(1)
// space: O(1)
float	height_of_triangle(const t_triangle *src, size_t axis, bool is_greater)
{
	float	dst;
	float	sign;

	if (src == NULL || axis > 2 || src->p1 == NULL
		|| src->p2 == NULL || src->p3 == NULL)
		return (0.0);
	dst = src->p1[axis];
	sign = 1;
	if (is_greater == false)
		sign *= -1;
	if (dst * sign < sign * src->p2[axis])
		dst = src->p2[axis];
	if (dst * sign < sign * src->p3[axis])
		dst = src->p3[axis];
	return (dst);
}
