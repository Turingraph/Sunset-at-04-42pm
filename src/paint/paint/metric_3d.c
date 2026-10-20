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
 * @return |re| + |im| + |zd3| - |re + im + zd3|
 */
int	cell_metric_triangle_inequality_3d(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;
	int			y_max;
	int			y_min;
	int			zd3;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	y_max = f_abs(y.x) + f_abs(y.y) + f_abs(zd3);
	y_min = f_abs(y.x + y.y + zd3);
	return (y_max - y_min);
}

/**
* Calculate the Euclidean distance of a cell from the origin
* in the 3d space
* 
* time/space: O(1) / O(1)
* 
* status: public api
* 
* @param dst source FDF table
* @param index index of the cell
* @return Euclidean distance from the origin
*/
int	cell_metric_pythagoras_3d(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;
	int			zd3;
	int			distance;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	distance = (int)(y.x * y.x + y.y * y.y) + zd3 * zd3;
	return ((int)(f_root_finding(distance, 2)));
}

/**
 * Calculate the maximum absolute component of a cell coordinate
 * in 3d space.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return maximum of |re|, |im|, and zd3
 */
int	cell_metric_max_xyz(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;
	int			max_2d;
	int			zd3;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	max_2d = (int)(f_max(f_abs(y.x), f_abs(y.y)));
	return (f_max_int(max_2d, zd3));
}

/**
 * Calculate the square root of the absolute product of the
 * real and imaginary components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return sqrt(|re * im|)
 */
int	cell_metric_root_xyz(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;
	int			zd3;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	y = init_table_coordinate(dst, index, 1.0);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = f_abs_int(dst->arr[index]);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	zd3 *= (int)f_abs(y.x * y.y);
	return ((int)f_round(f_root_finding(zd3, 3)));
}

/**
 * Calculate the absolute value of the sum of x, y, and z.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return |x + y + z|
 */
int	cell_metric_addsub_3d(const t_fdf_table *dst, size_t index)
{
	t_2d_float	y;
	int			zd3;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	zd3 = 0;
	if (dst->arr != NULL)
		zd3 = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	return ((int)f_abs(y.x + y.y + zd3));
}
