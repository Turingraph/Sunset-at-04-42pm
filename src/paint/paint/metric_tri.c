#include "paint.h"

/**
 * Calculate the maximum sine value of the real and imaginary
 * components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(row, col) * max(sin(re / a), sin(im / a))
 */
int	cell_metric_maxsin(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;
	float		s;
	float		f;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	s = f_min((float)dst->col, (float)dst->row);
	f = f_max((float)dst->col, (float)dst->row);
	if (f < 1)
		f = 1;
	y = init_table_coordinate(dst, index, 1.0);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(s * f_max(f_sin(y.x / f), f_sin(y.y / f))));
}

/**
 * Calculate the maximum component of the complex sine of a
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
 * @return max(sin(z).x, sin(z).y)
 */
int	cell_metric_maxesin(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_sin(y);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(f_max(y.x, y.y)));
}

/**
 * Calculate the maximum cosine value of the real and imaginary
 * components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(row, col) * max(cos(re / a), cos(im / a))
 */
int	cell_metric_maxcos(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;
	float		s;
	float		f;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	s = f_min((float)dst->col, (float)dst->row);
	y = init_table_coordinate(dst, index, 1.0);
	f = f_max((float)dst->col, (float)dst->row);
	if (f < 1)
		f = 1;
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(s * f_max(f_cos(y.x / f), f_cos(y.y / f))));
}

/**
 * Calculate the maximum component of the complex cosine of a
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
 * @return max(cos(z).x, cos(z).y)
 */
int	cell_metric_maxecos(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_cos(y);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(f_max(y.x, y.y)));
}

/**
 * Calculate the maximum component of the complex exponential
 * of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return max(re(exp(z)), im(exp(z)))
 */
int	cell_metric_maxexp(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_exp(y);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(f_max(y.x, y.y)));
}

