#include "aura.h"

int	aura_hypnotize_no2(double x, double y, double z)
{
	t_double2d	a;

	a.x = x;
	a.y = y;
	return (aura_custom_bi(a, z, aura_pythagoras, complex_x2));
}

int	aura_hypnotize_no3(double x, double y, double z)
{
	t_double2d	a;

	a.x = x;
	a.y = y;
	return (aura_custom_bi(a, z, aura_pythagoras, complex_x3));
}

int	aura_fractal_no2(double x, double y, double z)
{
	t_double2d	a;

	a.x = x;
	a.y = y;
	return (aura_custom_andmod(a, z, complex_x2));
}

int	aura_fractal_no3(double x, double y, double z)
{
	t_double2d	a;

	a.x = x;
	a.y = y;
	return (aura_custom_andmod(a, z, complex_x3));
}

