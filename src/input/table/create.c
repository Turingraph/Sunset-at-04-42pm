/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:44:49 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 14:03:40 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

/**
 * Free and reset the t_fdf_table array
 *
 * time/space: O(1) / O(1)
 * 
 * status: public api
 *
 * @param src the target t_fdf_table array
 */
void	destroy_fdf_table(t_fdf_table *src)
{
	if (src == NULL)
		return ;
	free(src->arr);
	free(src->r);
	free(src->g);
	free(src->b);
	free(src->a);
	src->arr = NULL;
	src->r = NULL;
	src->g = NULL;
	src->b = NULL;
	src->a = NULL;
	src->row = 0;
	src->col = 0;
}

/**
 * Define t_fdf_table as array with only 0.
 *
 * time/space: O(n) / O(n)
 * 
 * status: public api
 *
 * @param row row of the target table (corresponding to y position)
 * @param col row of the target table (corresponding to x position)
 * @param is_rgba if is_rgba is true, then using malloc saving more
 *  extra color (the initialized color is black).
 * 
 * @return array with only 0 as t_fdf_table with specified rows and columns.
 */
t_fdf_table	create_fdf_table(size_t row, size_t col, bool is_rgba)
{
	t_fdf_table	dst;

	dst.arr = NULL;
	if (mul_overflow_size_t(col, row) == true)
		dst.arr = malloc_talk(sizeof(int) * row * col, "create_fdf_table\n");
	dst.row = row;
	dst.col = col;
	dst.r = NULL;
	dst.g = NULL;
	dst.b = NULL;
	dst.a = NULL;
	if (is_rgba == true && mul_overflow_size_t(col, row) == true)
	{
		dst.r = malloc_talk(sizeof(unsigned char) * row * col,
				"create_fdf_table\n");
		dst.g = malloc_talk(sizeof(unsigned char) * row * col,
				"create_fdf_table\n");
		dst.b = malloc_talk(sizeof(unsigned char) * row * col,
				"create_fdf_table\n");
		dst.a = malloc_talk(sizeof(unsigned char) * row * col,
				"create_fdf_table\n");
	}
	if (dst.arr == NULL)
		destroy_fdf_table(&dst);
	return (dst);
}

// time : O(n)
// space: O(1)
static size_t	fdf_load_col(const t_fdf_load_arr *src)
{
	size_t	i;
	size_t	col;

	col = 0;
	i = 0;
	while (i < src->length && src->arr != NULL)
	{
		if (col < src->arr[i].length)
			col = src->arr[i].length;
		i += 1;
	}
	return (col);
}

// time : O(1)
// space: O(1)
static void	transfer_fdf_load_rgba(const t_fdf_load *src,
	t_fdf_table *dst, size_t row, size_t col)
{
	if (src != NULL && dst != NULL
		&& mul_overflow_size_t(dst->col, dst->row) == true
		&& col < dst->col * dst->row
		&& row < dst->row && col < dst->col && col < src->length)
	{
		if (src->r != NULL && dst->r != NULL)
			dst->r[dst->col * row + col] = src->r[col];
		if (src->g != NULL && dst->g != NULL)
			dst->g[dst->col * row + col] = src->g[col];
		if (src->b != NULL && dst->b != NULL)
			dst->b[dst->col * row + col] = src->b[col];
		if (src->a != NULL && dst->a != NULL)
			dst->a[dst->col * row + col] = src->a[col];
	}
}

// time : O(n)
// space: O(n)
t_fdf_table	fdfload_to_fdftable(const t_fdf_load_arr *src, bool is_rgba)
{
	t_fdf_table	dst;
	size_t		i;
	size_t		j;

	if (src == NULL || src->arr == NULL
		|| src->length == 0 || src->capacity == 0)
		return (create_fdf_table(0, 0, false));
	dst = create_fdf_table(src->length, fdf_load_col(src), is_rgba);
	if (dst.arr == NULL)
		return (dst);
	i = 0;
	while (i < src->length)
	{
		j = 0;
		while (j < src->arr[i].length && src->arr[i].arr != NULL)
		{
			dst.arr[dst.col * i + j] = src->arr[i].arr[j];
			if (is_rgba == true)
				transfer_fdf_load_rgba(&(src->arr[i]), &dst, i, j);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}
