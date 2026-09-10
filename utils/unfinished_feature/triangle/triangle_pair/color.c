#include"triangle_pair.h"

// time : O(1)
// space: O(1)
int	average_square_coloring(const unsigned char *src, size_t index, size_t col)
{
	int	y;

	y = 0;
	if (src == NULL)
		return (0);
	y += (int)src[index];
	y += (int)src[index + 1];
	y += (int)src[index + col + 1];
	y += (int)src[index + col];
	return (y);
}

// time : O(1)
// space: O(1)
void	average_tri_coloring(const t_table_fdf *src,
	size_t index, t_triangle *dst)
{
	int	y;

	if (dst != NULL && src != NULL && index < src->col * src->row)
	{
		y = 0;
		y = average_square_coloring(src->r, index, src->col);
		dst->r = (unsigned char)f_interval(((float)y) / 4, 0, 255);
		y = average_square_coloring(src->g, index, src->col);
		dst->g = (unsigned char)f_interval(((float)y) / 4, 0, 255);
		y = average_square_coloring(src->b, index, src->col);
		dst->b = (unsigned char)f_interval(((float)y) / 4, 0, 255);
		y = average_square_coloring(src->a, index, src->col);
		dst->a = (unsigned char)f_interval(((float)y) / 4, 0, 255);
	}
}

// time : O(1)
// space: O(1)
void	topleft_tri_coloring(const t_table_fdf *src,
	size_t index, t_triangle *dst)
{
	if (dst != NULL && src != NULL && index < src->col * src->row)
	{
		dst->r = 0;
		dst->g = 0;
		dst->b = 0;
		dst->a = 0;
		if (src->r != NULL)
			dst->r = src->r[index];
		if (src->g != NULL)
			dst->g = src->g[index];
		if (src->b != NULL)
			dst->b = src->b[index];
		if (src->a != NULL)
			dst->a = src->a[index];
	}
}

// time : O(1)
// space: O(1)
unsigned char	get_edge_average_tri_color(
	const unsigned char *src, t_triangle_arr *dst, size_t col)
{
	int	y;

	if (src == NULL || dst == NULL || dst->capacity < 2 || dst->arr == NULL)
		return (0);
	y = src[(int)f_floor(dst->arr[0].p1[1] * col + dst->arr[0].p1[0])];
	y += src[(int)f_floor(dst->arr[1].p2[1] * col + dst->arr[1].p2[0])];
	return ((unsigned char)f_interval(((float)y) / 2, 0, 255));
}

// time : O(1)
// space: O(1)
void	edge_average_tri_coloring(const t_table_fdf *src, t_triangle_arr *dst)
{
	if (dst != NULL && dst->arr != NULL && dst->capacity > 1 && src != NULL)
	{
		dst->arr[0].r = get_edge_average_tri_color(src->r, dst, src->col);
		dst->arr[1].r = get_edge_average_tri_color(src->r, dst, src->col);
		dst->arr[0].g = get_edge_average_tri_color(src->g, dst, src->col);
		dst->arr[1].g = get_edge_average_tri_color(src->g, dst, src->col);
		dst->arr[0].b = get_edge_average_tri_color(src->b, dst, src->col);
		dst->arr[1].b = get_edge_average_tri_color(src->b, dst, src->col);
		dst->arr[0].a = get_edge_average_tri_color(src->a, dst, src->col);
		dst->arr[1].a = get_edge_average_tri_color(src->a, dst, src->col);
	}
}
