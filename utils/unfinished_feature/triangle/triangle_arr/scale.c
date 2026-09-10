#include"triangle_arr.h"

// time : O(n)
// space: O(1)
void	hadamard_triangle_arr(t_triangle_arr *src, float scale, size_t axis)
{
	size_t	i;

	i = 0;
	while (i < src->length && src->arr != NULL)
	{
		src->arr[i].p1[axis] *= scale;
		src->arr[i].p2[axis] *= scale;
		src->arr[i].p3[axis] *= scale;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	shift_triangle_arr(t_triangle_arr *src, float shift, size_t axis)
{
	size_t	i;

	i = 0;
	while (i < src->length && src->arr != NULL && axis <= 2)
	{
		src->arr[i].p1[axis] += shift;
		src->arr[i].p2[axis] += shift;
		src->arr[i].p3[axis] += shift;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	setback_triangle_arr(t_triangle_arr *src, float shift, size_t axis)
{
	size_t	i;

	i = 0;
	while (i < src->length && src->arr != NULL && axis <= 2)
	{
		if (src->arr[i].p1[axis] > 0)
			src->arr[i].p1[axis] = shift;
		if (src->arr[i].p2[axis] > 0)
			src->arr[i].p2[axis] = shift;
		if (src->arr[i].p3[axis] > 0)
			src->arr[i].p3[axis] = shift;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	setwidth_triangle_arr(t_triangle_arr *src, float shift, size_t axis)
{
	size_t	i;

	i = 0;
	while (i < src->length && src->arr != NULL && axis <= 2)
	{
		if (src->arr[i].p1[axis] > 0)
			src->arr[i].p1[axis] += shift;
		if (src->arr[i].p2[axis] > 0)
			src->arr[i].p2[axis] += shift;
		if (src->arr[i].p3[axis] > 0)
			src->arr[i].p3[axis] += shift;
		i += 1;
	}
}

// time : O(n)
// sapce: O(n)
t_triangle_arr	push_back_to_triangle_arr(t_triangle_arr *src,
	float width, bool is_2faces)
{
	t_triangle_arr	compress_src;

	setwidth_triangle_arr(src, width, 2);
	if (src != NULL && src->arr != NULL && src->length > 0)
	{
		compress_src = clone_triangle_arr(src, src->length);
		if (is_2faces == true)
			hadamard_triangle_arr(&compress_src, -1.0, 2);
		else
		{
			if (width > 0)
				width *= -1;
			setback_triangle_arr(&compress_src, width, 2);
		}
		concat_triangle_arr(src, &compress_src);
	}
	return (*src);
}
