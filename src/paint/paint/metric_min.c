#include "paint.h"

/**
 * Calculate the minimum absolute component of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return minimum of |re| and |im|
 */
int	cell_metric_min_xy(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	y = init_table_coordinate(dst, index, 1.0);
	return ((int)(f_min(f_abs(y.x), f_abs(y.y))));
}

/**
 * Calculate the minimum absolute component of a cell coordinate
 * in 3d space.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return minimum of |re|, |im|, and z
 */
int	cell_metric_min_xyz(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			min2d;
	int			z;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	z = 0;
	if (dst->arr != NULL)
		z = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	min2d = (int)(f_min(f_abs(y.x), f_abs(y.y)));
	return (f_min_int(min2d, z));
}

/**
 * Calculate the minimum cosine value of the real and imaginary
 * components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(row, col) * min(cos(re / a), cos(im / a))
 */
int	cell_metric_mincos(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	float		s;
	float		f;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	s = f_min((float)dst->col, (float)dst->row);
	y = init_table_coordinate(dst, index, 1.0);
	f = f_max((float)dst->col, (float)dst->row);
	if (f < 1)
		f = 1;
	return ((int)(s * f_min(f_cos(y.x / f), f_cos(y.y / f))));
}

/**
 * Calculate the minimum component of the complex cosine of a
 * cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * 
 * @param index index of the cell
 * 
 * @return min(cos(z).x, cos(z).y)
 */
int	cell_metric_minecos(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_cos(y);
	return ((int)(f_min(y.x, y.y)));
}

/**
 * Calculate the minimum component of the complex exponential
 * of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(re(exp(z)), im(exp(z)))
 */
int	cell_metric_minexp(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_exp(y);
	return ((int)(f_min(y.x, y.y)));
}
