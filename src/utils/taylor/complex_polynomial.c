#include "taylor.h"

/**
 * compute (a.x + a.y)^2
 * 
 * status: public api
 * 
 */
t_float2d	complex_square(t_float2d a)
{
	return (complex_multiplication(a, a));
}

/**
 * compute (a.x + a.y)^3
 * 
 * status: public api
 * 
 */
t_float2d	complex_cube(t_float2d a)
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
t_float2d	complex_x4(t_float2d a)
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
t_float2d	complex_x5(t_float2d a)
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
t_float2d	complex_x6(t_float2d a)
{
	return (complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a, a))))));
}

