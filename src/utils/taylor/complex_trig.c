/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_trig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/31 12:43:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taylor.h"

// https://en-wikipedia-org.translate.goog/wiki/
// Euler%27s_formula?_x_tr_sl=en&_x_tr_tl=th&_x_tr_hl=th&_x_tr_pto=tc

/**
 * compute e^(a.x + a.y)
 * 
 * status: public api
 * 
 */
t_double2d	complex_exp(t_double2d a)
{
	t_double2d	dst;

	dst.x = f_cos(a.y) * f_exp(a.x);
	dst.y = f_sin(a.y) * f_exp(a.x);
	return (dst);
}

/*
According to Euler formula
*	e^{a + bi} = e^a * (cos(b) + i * sin(b))

According to Trigonometry
*	cos(-x) = cos(x)
*	sin(-x) = -sin(x)

Calculate e^{a - bi}
*	e^{a - bi} = e^a * (cos(-b) + i * sin(-b))
*	e^{a - bi} = e^a * (cos(b) - i * sin(b))

Calculate cos(b)
*	e^{a + bi} + e^{a - bi} = e^a*cos(b) + e^a*sin(b)i + e^a*cos(b) - e^a*sin(b)i
*	e^{a + bi} + e^{a - bi} = e^a*cos(b) + e^a*cos(b)
*	e^{bi} + e^{- bi} = 2 * cos(b)
*	cos(b) = (e^{bi} + e^{- bi}) / 2

Reference
*	https://youtu.be/CjQTWtW_x9o?si=ZnGRHjQ-SNRfhmjt
*	https://www.wolframalpha.com/input?i=cos%28a%2Bbi%29
*/

/**
 * compute cos(a.x + a.y)
 * 
 * status: public api
 * 
 */
t_double2d	complex_cos(t_double2d a)
{
	t_double2d	y;
	t_double2d	x1;
	t_double2d	x2;
	t_double2d	e1;
	t_double2d	e2;

	x1.x = -1 * a.x;
	x1.y = a.y;
	e1 = complex_exp(x1);
	x2.x = a.x;
	x2.y = -1 * a.y;
	e2 = complex_exp(x2);
	y.x = (e1.x + e2.x) / 2;
	y.y = (e1.y + e2.y) / 2;
	return (y);
}

/**
 * compute sin(a.x + a.y)
 * 
 * status: public api
 * 
 */
t_double2d	complex_sin(t_double2d a)
{
	t_double2d	y;
	t_double2d	x1;
	t_double2d	x2;
	t_double2d	e1;
	t_double2d	e2;

	x1.x = a.x;
	x1.y = -1 * a.y;
	e1 = complex_exp(x1);
	x2.x = -1 * a.x;
	x2.y = a.y;
	e2 = complex_exp(x2);
	y.x = (e1.x - e2.x) / 2;
	y.y = (e1.y - e2.y) / 2;
	return (y);
}

t_double2d	complex_rotate(double angle)
{
	t_double2d	y;

	y.x = f_cos(angle);
	y.y = f_sin(angle);
	return (y);
}
