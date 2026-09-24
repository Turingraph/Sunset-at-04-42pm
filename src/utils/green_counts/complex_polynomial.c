#include "green_counts.h"

/**
 * compute (a.re + a.im)^2
 * 
 * status: public api
 * 
 */
t_complex	complex_square(t_complex a)
{
	return (complex_multiplication(a, a));
}

/**
 * compute (a.re + a.im)^3
 * 
 * status: public api
 * 
 */
t_complex	complex_cube(t_complex a)
{
	return (complex_multiplication(a,
			complex_multiplication(a, a)));
}

/**
 * compute (a.re + a.im)^4
 * 
 * status: public api
 * 
 */
t_complex	complex_x4(t_complex a)
{
	return (complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a, a))));
}

/**
 * compute (a.re + a.im)^5
 * 
 * status: public api
 * 
 */
t_complex	complex_x5(t_complex a)
{
	return (complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a, a)))));
}

/**
 * compute (a.re + a.im)^6
 * 
 * status: public api
 * 
 */
t_complex	complex_x6(t_complex a)
{
	return (complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a,
			complex_multiplication(a, a))))));
}

