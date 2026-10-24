#include "aura.h"

/**
 * Calculate the minimum sine value of the real and imaginary
 * components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(row, col) * min(sin(re / a), sin(im / a))
 */
int	aura_minsin(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	float		s;
	float		f;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	s = f_min((float)dst->col, (float)dst->row);
	f = f_min((float)dst->col, (float)dst->row);
	if (f < 1)
		f = 1;
	y = init_table_coordinate(dst, index, 1.0);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(s * f_min(f_sin(y.x / f), f_sin(y.y / f))));
}

/**
 * Calculate the minimum component of the complex sine of a
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
 * @return min(sin(z).x, sin(z).y)
 */
int	aura_minesin(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_sin(y);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(f_min(y.x, y.y)));
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
int	aura_mincos(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	float		s;
	float		f;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	s = f_min((float)dst->col, (float)dst->row);
	y = init_table_coordinate(dst, index, 1.0);
	f = f_min((float)dst->col, (float)dst->row);
	if (f < 1)
		f = 1;
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
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
int	aura_minecos(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_cos(y);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
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
int	aura_minexp(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	y = complex_exp(y);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	return ((int)(f_min(y.x, y.y)));
}

