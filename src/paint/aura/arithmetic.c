#include "aura.h"

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
int	aura_root_xyz(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			z;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	y = init_table_coordinate(dst, index, 1.0);
	z = 0;
	if (dst->arr != NULL)
		z = f_abs_int(dst->arr[index]);
	y.x = f_abs(y.x);
	y.y = f_abs(y.y);
	z *= (int)f_abs(y.x * y.y);
	return ((int)f_round(f_root_find(z, 3)));
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
int	aura_addsub(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			z;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	z = 0;
	if (dst->arr != NULL)
		z = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	return ((int)f_abs(y.x + y.y + z));
}

