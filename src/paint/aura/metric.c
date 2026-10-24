#include "aura.h"

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
int	aura_pythagoras(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			z;
	int			distance;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	z = 0;
	if (dst->arr != NULL)
		z = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	distance = (int)(y.x * y.x + y.y * y.y) + z * z;
	return ((int)(f_root_find(distance, 2)));
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
 * @return maximum of |re|, |im|, and z
 */
int	aura_max_xyz(const t_fdf_table *dst, size_t index)
{
	t_float2d	y;
	int			max2d;
	int			z;

	if (dst == NULL || mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (false);
	z = 0;
	if (dst->arr != NULL)
		z = dst->arr[index];
	y = init_table_coordinate(dst, index, 1.0);
	max2d = (int)(f_max(f_abs(y.x), f_abs(y.y)));
	return (f_max_int(max2d, z));
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
 * @return minimum of |re|, |im|, and z
 */
int	aura_min_xyz(const t_fdf_table *dst, size_t index)
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