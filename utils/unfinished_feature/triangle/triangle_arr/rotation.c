#include"triangle_arr.h"

// https://en.wikipedia.org/wiki/Rotation_matrix

// time : O(1)
// space: O(1)
void	rotate_triangle_x(float *input, float delta)
{
	float	*output;

	if (input == NULL)
		return ;
	output = (float *)malloc(sizeof(float) * 3);
	if (output == NULL)
		return ;
	output[0] = input[0];
	output[1] = input[1] * f_cos(delta) - input[2] * f_sin(delta);
	output[2] = input[1] * f_sin(delta) + input[2] * f_cos(delta);
	input[0] = output[0];
	input[1] = output[1];
	input[2] = output[2];
	free(output);
}

// time : O(1)
// space: O(1)
void	rotate_triangle_y(float *input, float delta)
{
	float	*output;

	if (input == NULL)
		return ;
	output = (float *)malloc(sizeof(float) * 3);
	if (output == NULL)
		return ;
	output[0] = input[0] * f_cos(delta) + input[2] * f_sin(delta);
	output[1] = input[1];
	output[2] = -1 * input[0] * f_sin(delta) + input[2] * f_cos(delta);
	input[0] = output[0];
	input[1] = output[1];
	input[2] = output[2];
	free(output);
}

// time : O(1)
// space: O(1)
void	rotate_triangle_z(float *input, float delta)
{
	float	*output;

	if (input == NULL)
		return ;
	output = (float *)malloc(sizeof(float) * 3);
	if (output == NULL)
		return ;
	output[0] = input[0] * f_cos(delta) - input[1] * f_sin(delta);
	output[1] = input[0] * f_sin(delta) + input[1] * f_cos(delta);
	output[2] = input[2];
	input[0] = output[0];
	input[1] = output[1];
	input[2] = output[2];
	free(output);
}

// time : O(1)
// space: O(1)
void	rotate_triangle(t_triangle *src, float delta, char axis)
{
	if (src == NULL
		|| src->p1 == NULL || src->p2 == NULL || src->p3 == NULL
		|| axis < 0 || axis > 2)
		return ;
	if (axis == 0)
	{
		rotate_triangle_x(src->p1, delta);
		rotate_triangle_x(src->p2, delta);
		rotate_triangle_x(src->p3, delta);
	}
	if (axis == 1)
	{
		rotate_triangle_y(src->p1, delta);
		rotate_triangle_y(src->p2, delta);
		rotate_triangle_y(src->p3, delta);
	}
	if (axis == 2)
	{
		rotate_triangle_z(src->p1, delta);
		rotate_triangle_z(src->p2, delta);
		rotate_triangle_z(src->p3, delta);
	}
}

// time : O(n)
// space: O(1)
void	rotate_triangle_arr(t_triangle_arr *src,
	float delta, char axis)
{
	size_t	i;

	i = 0;
	if (src != NULL && src->arr != NULL && i < src->length)
	{
		rotate_triangle(&src->arr[i], delta, axis);
		i += 1;
	}
}
