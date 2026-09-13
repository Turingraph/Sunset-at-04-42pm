/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 11:13:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 18:15:33 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Reference
*	https://www.desmos.com/calculator/ohf8ypwncs
*	https://en.wikipedia.org/wiki/Parallel_projection#/
	media/File:Comparison_of_graphical_projections.svg
*	https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc
*/

/**
 * Apply an isometric projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using an isometric projection. The x and y coordinates contribute to both
 * the horizontal and vertical components, while z affects the vertical
 * component.
 *
 * formula:
 * - x' = 0.866 * x - 0.866 * y
 * - y' = 0.5 * x + 0.5 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_isometric(float x, float y, float z)
{
	t_complex	dst;

	dst.re = 0.866 * x - 0.866 * y;
	dst.im = 0.5 * x + 0.5 * y - z;
	return (dst);
}

/**
 * Apply a military projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using a military projection. The x and y coordinates contribute equally
 * to the horizontal and vertical components, while z affects the vertical
 * component.
 *
 * formula:
 * - x' = 0.707 * x - 0.707 * y
 * - y' = 0.707 * x + 0.707 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_military(float x, float y, float z)
{
	t_complex	dst;

	dst.re = 0.707 * x - 0.707 * y;
	dst.im = 0.707 * x + 0.707 * y - z;
	return (dst);
}

/**
 * Apply a cabinet projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * using a cabinet projection. The x coordinate is preserved horizontally,
 * while the y coordinate contributes to both horizontal and vertical
 * components. The z coordinate affects the vertical component.
 *
 * formula:
 * - x' = x - 0.353 * y
 * - y' = 0.707 * y - z
 * 
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_cabinet(float x, float y, float z)
{
	t_complex	dst;

	dst.re = x - 0.353 * y;
	dst.im = 0.707 * y - z;
	return (dst);
}

/**
 * Apply an orthogonal projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * by preserving the x coordinate as the horizontal component and combining
 * the y and z coordinates into the vertical component.
 *
 * formula:
 * - x' = x
 * - y' = y - z
 * 
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_orthogonal(float x, float y, float z)
{
	t_complex	dst;

	dst.re = x;
	dst.im = y - z;
	return (dst);
}

/**
 * Apply a wave projection to a 3D point.
 *
 * This projection transforms the x, y, and z coordinates into a 2D point
 * by applying a cosine wave based on the x coordinate to the z coordinate.
 * The resulting value is combined with the y coordinate to produce the
 * vertical component.
 *
 * formula:
 * - x' = x - 0.353 * y
 * - y' = z * f_cos(x) + y - z
 * 
 * time/space: O(1) / O(1)
 *
 * status: public api
 * 
 * @param x x-coordinate of the 3D point
 * @param y y-coordinate of the 3D point
 * @param z z-coordinate of the 3D point
 * @return 2D complex point containing the projected coordinates
 */
t_complex	projection_wave(float x, float y, float z)
{
	t_complex	dst;

	dst.re = x;
	dst.im = z * f_cos(x) + y - z;
	return (dst);
}
