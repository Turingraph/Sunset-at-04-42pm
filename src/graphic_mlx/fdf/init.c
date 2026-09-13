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

#include "fdf.h"

// time : O(n)
// space: O(1)
void	init_fdf_position(const t_table_fdf *src, float *arr_x,
	float *arr_y, t_complex (*projection)(float x, float y, float z))
{
	size_t		i;
	t_complex	dst;

	if (src == NULL || arr_x == NULL || arr_y == NULL
		|| src->row == 0 || src->col == 0)
		return ;
	i = 0;
	while (i < src->row * src->col)
	{
		dst.re = (float)(i % src->col) - (float)(src->col / 2);
		dst.im = (float)(i / src->col) - (float)(src->row / 2);
		if (src->arr == NULL && projection != NULL)
			dst = projection(dst.re, dst.im, 0.0);
		else if (projection != NULL)
			dst = projection(dst.re, dst.im, src->arr[i]);
		arr_x[i] = dst.re;
		arr_y[i] = dst.im;
		i += 1;
	}
}

// time : O(1)
// space: O(1)
t_fdf	init_null_fdf(void)
{
	t_fdf	dst;

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
 * view_fdf() does not call free_fdf(). The caller therefore remains
 * responsible for releasing an FDF object created by init_fdf().
 *
 * Calling free_fdf() with NULL is safe.
 * 
 * The return data is NULL fdf data.
 *
 * time/space: O(1) /  O(1)
 *
 * status: public api
 *
 * @param src FDF object to release
 */
t_fdf	free_fdf(t_fdf *src)
{
	if (src == NULL)
		return (init_null_fdf());
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
t_fdf	init_placeholder_fdf(t_table_fdf *src)
{
	t_fdf	dst;

	if (src == NULL || src->row == 0 || src->col == 0)
		return (init_null_fdf());
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
			"graphic_mlx/fdf/public.c/init_fdf/\n");
	dst.y = malloc_talk(src->row * src->col * sizeof(float),
			"graphic_mlx/fdf/public.c/init_fdf/\n");
	if (dst.x == NULL || dst.y == NULL)
		return (free_fdf(&dst));
	return (dst);
}

/**
 * Initialize a FDF object from a t_table_fdf table.
 *
 * The returned FDF object owns the 2D position arrays of each cells of t_table_fdf,
 * based on the 2D projection of the table (determined by 2D projection
 * argument e.g. projection_isometric, projection_military etc.
 * ). If the projection is NULL,
 * then this function return the simple orthogonal projection of t_table_fdf.
 *
 * This function use the color of t_table_fdf table,
 * instead of deep copy and/or shallow copy the color of t_table_fdf table, for
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
 * @param projection the functional pointer for define the projection of
 * t_table_fdf as t_fdf.
 * @param scale for scaling Fdf object.
 * @return initialized t_fdf object.
 * @see src/graphic_mlx/fdf/projection.c
 */
t_fdf	init_fdf(t_table_fdf *src,
	t_complex (*projection)(float x, float y, float z), float scale)
{
	t_fdf	dst;
	float	max_x;
	float	min_x;

	if (src == NULL || src->row * src->col == 0)
		return (init_null_fdf());
	dst = init_placeholder_fdf(src);
	if (dst.col == 0 || dst.row == 0)
		return (dst);
	init_fdf_position(src, dst.x, dst.y, projection);
	vector_scale(dst.x, scale, src->col * src->row);
	vector_scale(dst.y, scale, src->col * src->row);
	min_x = (float)get_minmax_from_table_fdf(
			(const t_table_fdf *)src, false, HEIGHT);
	max_x = (float)get_minmax_from_table_fdf(
			(const t_table_fdf *)src, true, HEIGHT);
	dst.width = f_max(max_x - min_x, (float)f_max_int(src->row, src->col));
	dst.row = src->row;
	dst.col = src->col;
	return (dst);
}
