#include "aura.h"

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
 * @param power the specified power.
 * @return a^power + b^power - floor((a^power + b^power)^(1/power))
 */
int	aura_fermat(const t_fdf_table *dst, size_t index, size_t power)
{
	t_float2d	y;
	int			a;
	int			b;
	int			c;

	if (dst == NULL || power < 2
		|| mul_overflow_size_t(dst->col, dst->row) == false || index >= dst->col * dst->row)
		return (0);
	y = init_table_coordinate(dst, index, 1.0);
	a = (int)f_pow(f_abs(y.x), power);
	b = (int)f_pow(f_abs(y.y), power);
	c = a + b;
	c = (int)f_round(f_root_find((float)c, 3));
	c = (int)f_pow((int)c, power);
	return (f_abs_int(a + b - c) * f_min_int(dst->col, dst->row));
}


int	aura_fermat2(const t_fdf_table *dst, size_t index)
{
	return (aura_fermat(dst, index, 2));
}

int	aura_fermat3(const t_fdf_table *dst, size_t index)
{
	return (aura_fermat(dst, index, 3));
}

int	aura_fermat4(const t_fdf_table *dst, size_t index)
{
	return (aura_fermat(dst, index, 4));
}

int	aura_fermat5(const t_fdf_table *dst, size_t index)
{
	return (aura_fermat(dst, index, 5));
}

int	aura_fermat6(const t_fdf_table *dst, size_t index)
{
	return (aura_fermat(dst, index, 6));
}
