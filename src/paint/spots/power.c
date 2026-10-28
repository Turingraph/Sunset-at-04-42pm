#include "spots.h"

static t_double2d	complex_x2(t_double2d a)
{
	return (complex_power(a, 2));
}

static t_double2d	complex_x3(t_double2d a)
{
	return (complex_power(a, 3));
}

static t_double2d	complex_x4(t_double2d a)
{
	return (complex_power(a, 4));
}

static bool	spots_oddlength(const t_fdf_table *dst, size_t index, double zoom,
	t_double2d (*complex_pow)(t_double2d x))
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= zoom;
	x.y *= zoom;
	x = complex_pow(x);
	if ((int)f_round(complex_magnitude(x, 0)) % 2 == 1)
		return (true);
	return (false);
}

bool	spots_oddlength_x2(const t_fdf_table *dst, size_t index)
{
	return (spots_oddlength(dst, index, 0.1, complex_x2));
}

bool	spots_oddlength_22(const t_fdf_table *dst, size_t index)
{
	return (spots_oddlength(dst, index, 0.2, complex_x2));
}


bool	spots_oddlength_x3(const t_fdf_table *dst, size_t index)
{
	return (spots_oddlength(dst, index, 0.05, complex_x3));
}

bool	spots_oddlength_x4(const t_fdf_table *dst, size_t index)
{
	return (spots_oddlength(dst, index, 0.05, complex_x4));
}

bool	spots_bugs_x2(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.2;
	x.y *= 0.2;
	return (spots_aura_custom(x, aura_pythagoras, complex_x2));
}

bool	spots_bugs_x3(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.05;
	x.y *= 0.05;
	return (spots_aura_custom(x, aura_pythagoras, complex_x3));
}

bool	spots_andmod_x2(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.075;
	x.y *= 0.075;
	return (spots_andmod_custom(x, complex_x2));
}

bool	spots_andmod_x3(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.05;
	x.y *= 0.05;
	return (spots_andmod_custom(x, complex_x3));
}

bool	spots_andmod_x4(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.025;
	x.y *= 0.025;
	return (spots_andmod_custom(x, complex_x4));
}

bool	spots_max_x2(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.2;
	x.y *= 0.2;
	return (spots_aura_custom(x, aura_max, complex_x2));
}

bool	spots_max_x3(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.05;
	x.y *= 0.05;
	return (spots_aura_custom(x, aura_max, complex_x3));
}

bool	spots_fermat_x2(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.2;
	x.y *= 0.2;
	return (spots_aura_custom(x, aura_fermat, complex_x2));
}

bool	spots_fermat_x3(const t_fdf_table *dst, size_t index)
{
	t_double2d	x;

	x = fdf_table_coordinate(dst, index);
	x.x *= 0.05;
	x.y *= 0.05;
	return (spots_aura_custom(x, aura_fermat, complex_x3));
}
