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
void	setcells_pythagorus_length(const t_table_fdf *dst)
{
	size_t		i;
	int			y;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate_standard(dst, i);
		y = (int)complex_magnitude(z, 0);
		dst->arr[i] = (int)f_round(f_root_finding(y, 2));
		i += 1;
	}
}

/**
 * Set each cell to the square root of the product of its standard
 * coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void	setcells_times_length(const t_table_fdf *dst)
{
	size_t		i;
	int			y;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate_standard(dst, i);
		y = z.re * z.im;
		dst->arr[i] = (int)f_round(f_root_finding(y, 2));
		i += 1;
	}
}

/**
 * Set each cell to the sum of its standard
 * coordinate components.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to modify
 */
void	setcells_addition_length(const t_table_fdf *dst)
{
	size_t		i;
	int			y;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate_standard(dst, i);
		y = z.re + z.im;
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
void	setcells_maximum_length(const t_table_fdf *dst)
{
	size_t		i;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate_standard(dst, i);
		dst->arr[i] = f_max_int(z.re, z.im);
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
void	setcells_minimum_length(const t_table_fdf *dst)
{
	size_t		i;
	t_complex	z;

	if (dst == NULL || dst->arr == NULL || dst->row == 0 || dst->col == 0)
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		z = get_table_fdf_coordinate_standard(dst, i);
		dst->arr[i] = f_min_int(z.re, z.im);
		i += 1;
	}
}
