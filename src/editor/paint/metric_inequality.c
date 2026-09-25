#include "paint.h"

/**
 * Calculate the difference between the sum of the absolute
 * components and the absolute value of their sum.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return |re| + |im| - |re + im|
 */
int	cell_metric_triangle_inequality(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			y_max;
	int			y_min;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y_max = f_abs(y.re) + f_abs(y.im);
	y_min = f_abs(y.re + y.im);
	return (y_max - y_min);
}

/**
 * Calculate the different between (x + y) / 2 - (xy)^(1/2)
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return (x + y) / 2 - (xy)^(1/2)
 */
int	cell_metric_amgm_inequality(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			y_max;
	int			y_min;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y_max = (int)(f_abs(y.re + y.im) / 2.0);
	y_min = (int)f_root_finding(f_abs(y.re * y.im), 2);
	return (y_max - y_min);
}

/**
 * Calculate the (x + y + z) / 3 - (xyz)^(1/3)
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return (x + y + z) / 3 - (xyz)^(1/3)
 */
int	cell_metric_amgm_inequality_3d(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			y_max;
	int			y_min;
	int			zd3;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = dst->arr[index];
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y_max = (int)((y.re + y.im + zd3) / 3.0);
	y_min = f_root_finding(y.re * y.im * zd3, 3);
	return (y_max - y_min);
}

/**
 * Calculate the (re + im)^2
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return (re + im)^2
 */
int	cell_metric_x_plus_y_square(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	return ((int)((y.re + y.im) * (y.re + y.im)));
}

/**
 * Calculate the x^2 + y^2 + z^2 - (x + y + z)^2
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return x^2 + y^2 + z^2 - (x + y + z)^2
 */
int	cell_metric_cauchy_schwarz_inequality_3d(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			zd3;
	int			y_max;
	int			y_min;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = dst->arr[index];
	y = get_table_fdf_coordinate(dst, index, 1.0);
	y_max = (int)(y.re * y.re + y.im * y.im + zd3 * zd3);
	y_min = (int)(f_pow(y.re + y.im + zd3, 2));
	return (y_max - y_min);
}
