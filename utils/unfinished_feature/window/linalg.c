#include"window.h"



float	linear_map_fdf(const t_fdf *src, t_matrix matrix, size_t i, char axis)
{
	float	output;
	float	*m;
	float	*x;
	float	*y;
	float	*z;

	if (is_fdf_valid(src) == false
		|| matrix.col * matrix.row != 9
		|| matrix.arr == NULL)
		return (0.0);
	m = matrix.arr;
	x = src->pos_x;
	y = src->pos_y;
	z = src->pos_z;
	output = x[i] * m[0] + y[i] * m[1] + z[i] * m[2];
	if (axis == 0)
		return (output);
	output = x[i] * m[3] + y[i] * m[4] + z[i] * m[5];
	if (axis == 1)
		return (output);
	output = x[i] * m[6] + y[i] * m[7] + z[i] * m[8];
	return (output);
}



void	linear_map_fdf_all(t_fdf *src, t_matrix matrix)
{
	size_t	i;

	if (is_fdf_valid(src) == false
		|| matrix.col * matrix.row != 9
		|| matrix.arr == NULL)
		return ;
	i = 0;
	while (i < src->src->row * src->src->col)
	{
		src->pos_x[i] = linear_map_fdf((const t_fdf *)src, matrix, i, 0);
		src->pos_y[i] = linear_map_fdf((const t_fdf *)src, matrix, i, 1);
		src->pos_z[i] = linear_map_fdf((const t_fdf *)src, matrix, i, 2);
		i += 1;
	}
}
