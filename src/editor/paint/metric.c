#include "paint.h"

/**
* Calculate the Euclidean distance of a cell from the origin
* in the complex plane.
* 
* time/space: O(1) / O(1)
* 
* status: public api
* 
* @param dst source FDF table
* @param index index of the cell
* @return Euclidean distance from the origin
*/
int	cell_metric_pythagoras(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	return ((int)complex_magnitude(y, 0));
}

/**
 * Calculate the maximum absolute component of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return maximum of |re| and |im|
 */
int	cell_metric_max_xy(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	return ((int)(f_max(f_abs(y.re), f_abs(y.im))));
}

/**
 * Calculate the absolute value of the sum of the real and
 * imaginary components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return |re + im|
 */
int	cell_metric_addsub(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	return ((int)f_abs(y.re + y.im));
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
int	cell_metric_root_xy(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	return ((int)f_round(f_root_finding(f_abs(y.re * y.im), 2)));
}

/**
 * Calculate the a^3 + b^3 - c^3 where a,b,c are integer and c is the
 * floor 3rd root of a^3 + b^3
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return a^3 + b^3 - floor((a^3 + b^3)^(1/3))
 */
int	cell_metric_fermat_theorem(const t_table_fdf *dst, size_t index)
{
	t_complex	y;
	int			a;
	int			b;
	int			c;

	if (dst == NULL || index >= dst->row * dst->col)
		return (false);
	y = get_table_fdf_coordinate(dst, index, 1.0);
	a = (int)f_pow(f_abs(y.re), 3);
	b = (int)f_pow(f_abs(y.im), 3);
	c = (int)f_floor(f_root_finding((float)(a + b), 3));
	c = (int)f_pow((int)c, 3);
	return (a + b - c);
}
