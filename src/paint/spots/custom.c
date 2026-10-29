#include "spots.h"

/**
 * Compute z' = complex_func(x).
 * Then check whether z.x is even or z.y is even
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param x complex number input
 * @param scale scaling x
 * @param complex_func optional complex function applied to the cell
 * coordinate.
 * @return true if z.x is even and z.y is even, false otherwise.
 */
bool	spots_andmod_custom(t_double2d x,
	t_double2d (*complex_func)(t_double2d a))
{
	if (complex_func != NULL)
		x = complex_func(x);
	if (x.x < 0)
		x.x *= -1;
	if (x.y < 0)
		x.y *= -1;
	if ((int)x.x % 2 == 1 && (int)x.y % 2 == 1)
		return (true);
	return (false);
}

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating its magnitude
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
bool	spots_aura_custom(t_double2d x,
	int (*aura_custom)(int x, int y, int z),
	t_double2d (*complex_func)(t_double2d a))
{
	double	distance;

	if (complex_func != NULL)
		x = complex_func(x);
	if (x.x < 0)
		x.x *= -1;
	if (x.y < 0)
		x.y *= -1;
	distance = x.x + x.y;
	if (aura_custom != NULL)
		distance = aura_custom(x.x, x.y, 0);
	if ((int)f_floor(distance) % 2 == 1)
		return (true);
	return (false);
}
