#include "paint.h"

// time : O(1)
// space: O(1)
t_complex	get_table_fdf_coordinate_standard(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	y.re = 0;
	y.im = 0;
	if (dst == NULL || dst->row == 0 || dst->col == 0)
		return (y);
	y.re = (float)dst->col / 2.0 - (float)index / (float)dst->col;
	y.im = (float)(index % dst->col) - (float)dst->row / 2.0;
	return (y);
}

// time : O(1)
// space: O(1)
int	get_rgba_input(t_enum_rgba rgba_type, t_rgba src)
{
	if (rgba_type == RED)
		return (src.r);
	if (rgba_type == GREEN)
		return (src.g);
	if (rgba_type == BLUE)
		return (src.b);
	if (rgba_type == ALPHA)
		return (src.a);
	return (0);
}
