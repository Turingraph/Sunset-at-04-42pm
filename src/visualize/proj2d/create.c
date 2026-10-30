/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:03:06 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 13:14:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj2d.h"

// time : O(1)
// space: O(1)
static t_fdf_proj2d	fdf_proj2d_null(void)
{
	t_fdf_proj2d	dst;

	dst.r = NULL;
	dst.g = NULL;
	dst.b = NULL;
	dst.a = NULL;
	dst.x = NULL;
	dst.y = NULL;
	dst.col = 0;
	dst.row = 0;
	dst.width = 0.0;
	return (dst);
}

/**
 * Release all resources owned by an FDF object.
 *
 * This function frees the source fdf data.
 *
 * view_fdf_proj2d() does not call destroy_fdf_proj2d(). The caller therefore remains
 * responsible for releasing an FDF object created by create_fdf_proj2d().
 *
 * Calling destroy_fdf_proj2d() with NULL is safe.
 * 
 * The return data is NULL fdf data.
 *
 * time/space: O(1) /  O(1)
 *
 * status: public api
 *
 * @param src FDF object to release
 */
t_fdf_proj2d	destroy_fdf_proj2d(t_fdf_proj2d *src)
{
	if (src == NULL)
		return (fdf_proj2d_null());
	free(src->r);
	free(src->g);
	free(src->b);
	free(src->a);
	free(src->x);
	free(src->y);
	src->x = NULL;
	src->y = NULL;
	src->r = NULL;
	src->g = NULL;
	src->b = NULL;
	src->a = NULL;
	src->col = 0;
	src->row = 0;
	src->width = 0.0;
	return (*src);
}

// time : O(n)
// space: O(n)
static t_fdf_proj2d	fdf_proj2d_malloc(t_fdf_table *src)
{
	t_fdf_proj2d	dst;

	if (src == NULL
		|| mul_overflow_size_t(src->col, src->row) == false)
		return (fdf_proj2d_null());
	dst.r = src->r;
	dst.g = src->g;
	dst.b = src->b;
	dst.a = src->a;
	src->r = NULL;
	src->g = NULL;
	src->b = NULL;
	src->a = NULL;
	dst.width = 0;
	dst.row = src->row;
	dst.col = src->col;
	dst.x = malloc_talk(src->row * src->col * sizeof(float),
			"create_fdf_proj2d\n");
	dst.y = malloc_talk(src->row * src->col * sizeof(float),
			"create_fdf_proj2d\n");
	if (dst.x == NULL || dst.y == NULL)
		return (destroy_fdf_proj2d(&dst));
	return (dst);
}

// time : O(n)
// space: O(1)
static void	fdf_proj2d_update(const t_fdf_table *src, t_fdf_proj2d *dst,
	double scale,
	t_double2d (*proj2d)(t_double2d a))
{
	size_t		i;
	t_double2d	position;
	double		z;

	if (src == NULL || mul_overflow_size_t(src->col, src->row) == false)
		return ;
	z = 0.0;
	i = 0;
	while (i < src->row * src->col)
	{
		if (src->arr != NULL)
			z = src->arr[i];
		z *= scale;
		position = fdf_table_coordinate(src, i);
		position.x *= scale;
		position.y *= scale;
		if (proj2d != NULL)
			position = proj2d(position);
		dst->x[i] = (float)position.x;
		dst->y[i] = (float)(position.y - z);
		i += 1;
	}
}

/**
 * Initialize a FDF object from a t_fdf_table table.
 *
 * The returned FDF object owns the 2D position arrays of each cells of t_fdf_table,
 * based on the 2D projection of the table (determined by 2D projection
 * argument e.g. proj2d_isometric, proj2d_military etc.
 * ). If the projection is NULL,
 * then this function return the simple orthogonal projection of t_fdf_table.
 *
 * This function use the color of t_fdf_table table,
 * instead of deep copy and/or shallow copy the color of t_fdf_table table, for
 * preventing double free issues and preventing using too many malloc than needed.
 *
 * The future version of this program will support 3D related features e.g.
 * quaternion rotation, 3D collision detection etc. but not now for the sake of development simplicity.
 * 
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param src source table containing the FDF data
 * @param proj2d the functional pointer for define the projection of
 * t_fdf_table as t_fdf. Note that the projection is always yield 3D looking results.
 * @param scale for normalizing Fdf object. This feature is useful when user apply
 * conformal map of complex analytic function.
 * @return initialized t_fdf object.
 * @see src/visualize/fdf/projection.c
 */
t_fdf_proj2d	create_conformal_fdf_proj2d(t_fdf_table *src,
	t_double2d (*complex_map)(t_double2d a), float scale)
{
	t_fdf_proj2d	dst;
	float	max_x;
	float	min_x;
	float	max_y;
	float	min_y;

	if (src == NULL || mul_overflow_size_t(src->col, src->row) == false)
		return (fdf_proj2d_null());
	dst = fdf_proj2d_malloc(src);
	if (dst.col == 0 || dst.row == 0)
		return (dst);
	fdf_proj2d_update((const t_fdf_table *)src, &dst, scale, complex_map);
	min_x = (float)minmax_from_arr_float(dst.x, dst.col * dst.row, false);
	max_x = (float)minmax_from_arr_float(dst.x, dst.col * dst.row, true);
	min_y = (float)minmax_from_arr_float(dst.y, dst.col * dst.row, false);
	max_y = (float)minmax_from_arr_float(dst.y, dst.col * dst.row, true);
	dst.width = f_max(max_x - min_x, max_y - min_y);
	dst.row = src->row;
	dst.col = src->col;
	return (dst);
}

t_fdf_proj2d	create_fdf_proj2d(t_fdf_table *src,
	t_double2d (*proj2d)(t_double2d a))
{
	return (create_conformal_fdf_proj2d(src, proj2d, 1));
}
