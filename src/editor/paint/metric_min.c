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
int	cell_metric_min_xy(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	return ((int)(f_min(f_abs(y.re), f_abs(y.im))));
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
 * @return minimum of |re|, |im|, and zd3
 */
int	cell_metric_min_xyz(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			min_2d;
	int			zd3;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = dst->arr[index];
	y = get_table_fdf_coordinate(dst, index, 1.0);
	min_2d = (int)(f_min(f_abs(y.re), f_abs(y.im)));
	return (f_min_int(min_2d, zd3));
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
int	cell_metric_mincos(const t_table_fdf *dst, size_t index)
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
	return ((int)(s * f_min(f_cos(y.re / f), f_cos(y.im / f))));
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
 * @return min(cos(z).re, cos(z).im)
 */
int	cell_metric_minecos(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y = complex_cos(y);
	return ((int)(f_min(y.re, y.im)));
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
int	cell_metric_minexp(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (0);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y = complex_exp(y);
	return ((int)(f_min(y.re, y.im)));
}
