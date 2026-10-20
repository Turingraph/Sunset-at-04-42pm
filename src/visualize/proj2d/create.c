/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:03:06 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:10:19 by phsottat         ###   ########.fr       */
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
 * view_fdf() does not call destroy_fdf_proj2d(). The caller therefore remains
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
	dst.row = src->row;
	dst.col = src->col;
	dst.x = malloc_talk(src->row * src->col * sizeof(float),
			"visualize/fdf/public.c/create_fdf/\n");
	dst.y = malloc_talk(src->row * src->col * sizeof(float),
			"visualize/fdf/public.c/create_fdf/\n");
	if (dst.x == NULL || dst.y == NULL)
		return (destroy_fdf_proj2d(&dst));
	return (dst);
}

// time : O(n)
// space: O(1)
static void	fdf_proj2d_update(const t_fdf_table *src, float *arr_x,
	float *arr_y, t_float2d (*proj2d)(float x, float y, float z))
{
	size_t		i;
	t_float2d	dst;

	if (src == NULL || arr_x == NULL || arr_y == NULL
		|| mul_overflow_size_t(src->col, src->row) == false)
		return ;
	i = 0;
	while (i < src->row * src->col)
	{
		dst.x = (float)(i % src->col) - (float)(src->col / 2);
		dst.y = (float)(i / src->col) - (float)(src->row / 2);
		if (src->arr == NULL && proj2d != NULL)
			dst = proj2d(dst.x, dst.y, 0.0);
		else if (proj2d != NULL)
			dst = proj2d(dst.x, dst.y, src->arr[i]);
		arr_x[i] = dst.x;
		arr_y[i] = dst.y;
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
 * t_fdf_table as t_fdf.
 * @param scale for scaling Fdf object.
 * @return initialized t_fdf object.
 * @see src/visualize/fdf/projection.c
 */
t_fdf_proj2d	create_fdf_proj2d(t_fdf_table *src,
	t_float2d (*proj2d)(float x, float y, float z), float scale)
{
	t_fdf_proj2d	dst;
	float	max_x;
	float	min_x;

	if (src == NULL || mul_overflow_size_t(src->col, src->row) == false)
		return (fdf_proj2d_null());
	dst = fdf_proj2d_malloc(src);
	if (dst.col == 0 || dst.row == 0)
		return (dst);
	fdf_proj2d_update(src, dst.x, dst.y, proj2d);
	scale_vector(dst.x, scale, src->col * src->row);
	scale_vector(dst.y, scale, src->col * src->row);
	min_x = (float)fdf_table_minmax(
			(const t_fdf_table *)src, false, HEIGHT);
	max_x = (float)fdf_table_minmax(
			(const t_fdf_table *)src, true, HEIGHT);
	dst.width = f_max(max_x - min_x, (float)f_max_int(src->row, src->col));
	dst.row = src->row;
	dst.col = src->col;
	return (dst);
}
