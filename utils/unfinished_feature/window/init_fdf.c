#include"window.h"

// time : O(1)
// space: O(1)
float	init_fdf_position_unit(const t_table_fdf *src, char axis, size_t i)
{
	if (src == NULL || src->arr == NULL || axis < 0 || axis > 2
		|| src->row * src->col == 0)
		return (0.0);
	if (axis == 0)
		return ((float)(i % src->col) - (float)(src->col / 2));
	if (axis == 1)
		return ((float)(i / src->col) - (float)(src->row / 2));
	return ((float)src->arr[i]);
}

// time : O(n)
// space: O(n)
float	*init_fdf_position(const t_table_fdf *src, char axis)
{
	float	*dst;
	size_t	i;

	if (src == NULL || src->arr == NULL || axis < 0 || axis > 2
		|| src->row * src->col == 0)
		return (NULL);
	dst = (float *)malloc(sizeof(float) * src->row * src->col);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row * src->col)
	{
		dst[i] = init_fdf_position_unit(src, axis, i);
		i += 1;
	}
	return (dst);
}


t_fdf	init_fdf(t_table_fdf *src)
{
	t_fdf	dst;
	float	max_x;
	float	min_x;

	dst.src = src;
	dst.pos_x = init_fdf_position(src, 0);
	dst.pos_y = init_fdf_position(src, 1);
	dst.pos_z = init_fdf_position(src, 2);
	dst.matrix = init_3d_zoom_matrix(1.0);
	min_x = (float)get_minmax_from_table_fdf(
		(const t_table_fdf *)src, false, HEIGHT);
	max_x = (float)get_minmax_from_table_fdf(
		(const t_table_fdf *)src, true, HEIGHT);
	dst.width = f_max3(max_x - min_x, src->row, src->col);
	return (dst);
}

// time : O(1)
// space: O(1)
bool	is_fdf_valid(const t_fdf *src)
{
	t_table_fdf	*table;

	if (src == NULL)
		return (false);
	table = src->src;
	if (table == NULL || table->arr == NULL
		|| src->width == 0
		|| table->row * table->col == 0
		|| src->matrix.col != 3
		|| src->matrix.row != 3
		|| src->matrix.arr == NULL
		|| src->pos_x == NULL
		|| src->pos_y == NULL
		|| src->pos_z == NULL)
		return (false);
	return (true);
}



void	free_fdf(t_fdf *src)
{
	if (src == NULL)
		return ;
	free_table_fdf(src->src);
	free(src->pos_x);
	free(src->pos_y);
	free(src->pos_z);
	free(src->matrix.arr);
	src->pos_x = NULL;
	src->pos_y = NULL;
	src->pos_z = NULL;
	src->src = NULL;
	src->matrix.arr = NULL;
	src->matrix.col = 0;
	src->matrix.row = 0;
}
