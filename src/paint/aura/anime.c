#include "aura.h"

int	aura_chainsawman_no2(double x, double y, double z)
{
	t_double2d	a;

	a.x = x;
	if (a.x < 0)
		a.x *= -1;
	a.y = y;
	if (a.y < 0)
		a.y *= -1;
	return (aura_custom_bi(a, z, aura_inequality_amgm, complex_x2));
}

int	aura_chainsawman_no3(double x, double y, double z)
{
	t_double2d	a;

	a.x = x;
	if (a.x < 0)
		a.x *= -1;
	a.y = y;
	if (a.y < 0)
		a.y *= -1;
	return (aura_custom_bi(a, z, aura_inequality_amgm, complex_x3));
}

