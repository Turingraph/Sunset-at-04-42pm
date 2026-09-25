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
int	cell_metric_maxsin(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	float		s;
	float		f;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	s = f_min((float)dst->col, (float)dst->row);
	f = f_max((float)dst->col, (float)dst->row);
	if (f < 1)
		f = 1;
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y.re = f_abs(y.re);
	y.im = f_abs(y.im);
	return ((int)(s * f_max(f_sin(y.re / f), f_sin(y.im / f))));
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
 * @return max(sin(z).re, sin(z).im)
 */
int	cell_metric_maxesin(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y = complex_sin(y);
	y.re = f_abs(y.re);
	y.im = f_abs(y.im);
	return ((int)(f_max(y.re, y.im)));
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
int	cell_metric_maxcos(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	float		s;
	float		f;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	s = f_min((float)dst->col, (float)dst->row);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	f = f_max((float)dst->col, (float)dst->row);
	if (f < 1)
		f = 1;
	y.re = f_abs(y.re);
	y.im = f_abs(y.im);
	return ((int)(s * f_max(f_cos(y.re / f), f_cos(y.im / f))));
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
 * @return max(cos(z).re, cos(z).im)
 */
int	cell_metric_maxecos(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y = complex_cos(y);
	y.re = f_abs(y.re);
	y.im = f_abs(y.im);
	return ((int)(f_max(y.re, y.im)));
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
int	cell_metric_maxexp(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y = complex_exp(y);
	y.re = f_abs(y.re);
	y.im = f_abs(y.im);
	return ((int)(f_max(y.re, y.im)));
}

