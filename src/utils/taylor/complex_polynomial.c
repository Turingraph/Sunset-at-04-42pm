#include "taylor.h"

/**
 * compute (a.x + a.y)^2
 * 
 * status: public api
 * 
 */
t_2d_float	complex_square(t_2d_float a)
{
	return (complex_multiplication(a, a));
}

/**
 * compute (a.x + a.y)^3
 * 
 * status: public api
 * 
 */
t_2d_float	complex_cube(t_2d_float a)
{
	return (complex_multiplication(a,
			complex_multiplication(a, a)));
}

/**
 * compute (a.x + a.y)^4
 * 
 * status: public api
 * 
 */
t_2d_float	complex_x4(t_2d_float a)
{
	return (complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a, a))));
}

/**
 * compute (a.x + a.y)^5
 * 
 * status: public api
 * 
 */
t_2d_float	complex_x5(t_2d_float a)
{
	return (complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a, a)))));
}

/**
 * compute (a.x + a.y)^6
 * 
 * status: public api
 * 
 */
t_2d_float	complex_x6(t_2d_float a)
{
	return (complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a, a))))));
}

