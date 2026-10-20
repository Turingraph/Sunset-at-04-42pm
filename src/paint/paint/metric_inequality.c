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
int	cell_metric_triangle_inequality(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			y_max;
	int			y_min;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	y = init_table_coordinate(dst, index, 1.0);
	y_max = f_abs(y.x) + f_abs(y.y);
	y_min = f_abs(y.x + y.y);
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
int	cell_metric_amgm_inequality(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			y_max;
	int			y_min;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	y = init_table_coordinate(dst, index, 1.0);
	y_max = (int)(f_abs(y.x + y.y) / 2.0);
	y_min = (int)f_root_find(f_abs(y.x * y.y), 2);
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
int	cell_metric_amgm_inequality_3d(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			y_max;
	int			y_min;
	int			z;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	z = 0;
	if (dst->arr != NULL)
		z = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	y_max = (int)((y.x + y.y + z) / 3.0);
	y_min = f_root_find(y.x * y.y * z, 3);
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
int	cell_metric_x_plus_y_square(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	y = init_table_coordinate(dst, index, 1.0);
	return ((int)((y.x + y.y) * (y.x + y.y)));
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
int	cell_metric_cauchy_schwarz_inequality_3d(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			z;
	int			y_max;
	int			y_min;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	z = 0;
	if (dst->arr != NULL)
		z = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	y_max = (int)(y.x * y.x + y.y * y.y + z * z);
	y_min = (int)(f_pow(y.x + y.y + z, 2));
	return (y_max - y_min);
}
