#include "paint.h"

/**
 * Set each cell to the Euclidean distance of its standard coordinates.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void	space_coloring_pythagorus(t_table_fdf *dst)
{
	size_t		i;
	int			y;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate(dst, i, 1);
		y = (int)complex_magnitude(z, 0);
		dst->arr[i] = (int)f_round(f_root_finding(y, 2));
		i += 1;
	}
}

/**
 * Set each cell to the square root of the product of its standard
 * complex coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void	space_coloring_root_xy(t_table_fdf *dst)
{
	size_t		i;
	int			y;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate(dst, i, 1);
		y = f_abs(z.re * z.im);
		dst->arr[i] = (int)f_round(f_root_finding(y, 2));
		i += 1;
	}
}

/**
 * Set each cell to the sum of its standard
 * complex coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void	space_coloring_x_plus_y(t_table_fdf *dst)
{
	size_t		i;
	int			y;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate(dst, i, 1);
		y = f_abs(z.re) + f_abs(z.im);
		dst->arr[i] = (int)f_round(y);
		i += 1;
	}
}

/**
 * Set each cell to the maximum of its standard coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void	space_coloring_max_xy(t_table_fdf *dst)
{
	size_t		i;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate(dst, i, 1);
		dst->arr[i] = f_max_int(f_abs(z.re), f_abs(z.im));
		i += 1;
	}
}

/**
 * Set each cell to the minimum of its standard coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void	space_coloring_min_xy(t_table_fdf *dst)
{
	size_t		i;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate(dst, i, 1);
		dst->arr[i] = f_min_int(f_abs(z.re), f_abs(z.im));
		i += 1;
	}
}
