/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_dim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:46:33 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/31 16:04:53 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

// nearest-neighbor scaling by pixel duplication

// time : O(n^2)
// space: O(1)
static void	copy_duplicated_row_rgba(const unsigned char *src, unsigned char *dst,
	size_t max_col, size_t scale_col)
{
	size_t	i;
	size_t	ii;

	i = 0;
	while (src != NULL && dst != NULL && i < max_col)
	{
		ii = 0;
		while (ii < scale_col)
		{
			*(dst + scale_col * i + ii) = *(src + i);
			ii += 1;
		}
		i += 1;
	}
}

// time : O(n^2)
// space: O(1)
static void	copy_duplicated_row(const int *src, int *dst,
	size_t max_col, size_t scale_col)
{
	size_t	i;
	size_t	ii;

	i = 0;
	while (src != NULL && dst != NULL && i < max_col)
	{
		ii = 0;
		while (ii < scale_col)
		{
			*(dst + scale_col * i + ii) = *(src + i);
			ii += 1;
		}
		i += 1;
	}
}

/**
 * Scale an RGBA channel by duplicating its rows and columns.
 * 
 * If src == NULL or src do not contains the target color,
 *  this function will return the array with 0 as the default instead.
 *
 * time/space: O(n^2) / O(n^2)
 *
 * status: public api
 *
 * @param src source FDF table
 * @param scale_row row scaling factor
 * @param scale_col column scaling factor
 * @param rgba_type RGBA channel to scale
 * @return scaled channel array, or NULL on failure
 */
unsigned char	*scale_dim_fdf_table_rgba(const t_fdf_table *src,
	size_t scale_row, size_t scale_col, t_fdf_channel rgba_type)
{
	size_t			i;
	size_t			ii;
	unsigned char	*dst;
	unsigned char	*arr;

	arr = rgbarr_from_table(src, rgba_type);
	if (arr == NULL || src == NULL || src->arr == NULL
		|| mul_overflow_size_t(scale_col, scale_row) == false
		|| mul_overflow_size_t(src->row, src->col) == false
		|| mul_overflow_size_t(scale_row * scale_col, src->row * src->col) == false)
		return (NULL);
	dst = malloc(sizeof(unsigned char) * src->row * src->col * scale_row * scale_col);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row)
	{
		ii = 0;
		while (ii < scale_row)
		{
			copy_duplicated_row_rgba(arr + i * src->col,
				dst + (i * scale_row + ii) * src->col * scale_col, src->col, scale_col);
			ii += 1;
		}
		i += 1;
	}
	return (dst);
}

/**
 * Scale an FDF_HEIGHT channel by duplicating its rows and columns.
 *
 * time/space: O(n^2) / O(n^2)
 *
 * status: public api
 *
 * @param src source FDF table
 * @param scale_row row scaling factor
 * @param scale_col column scaling factor
 * @return scaled height integer array, or NULL on failure
 */
int	*scale_dim_fdf_table_int(const t_fdf_table *src,
	size_t scale_row, size_t scale_col)
{
	size_t		i;
	size_t		ii;
	int			*dst;

	if (src == NULL || src->arr == NULL
		|| mul_overflow_size_t(scale_col, scale_row) == false
		|| mul_overflow_size_t(src->row, src->col) == false
		|| mul_overflow_size_t(scale_row * scale_col, src->row * src->col) == false)
		return (NULL);
	dst = malloc(sizeof(int) * src->row * src->col * scale_row * scale_col);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row)
	{
		ii = 0;
		while (ii < scale_row)
		{
			copy_duplicated_row(src->arr + i * src->col,
				dst + (i * scale_row + ii) * src->col * scale_col, src->col, scale_col);
			ii += 1;
		}
		i += 1;
	}
	return (dst);
}

/**
 * Scale an FDF table by duplicating its rows and columns.
 *
 * time/space: O(n^4)
 *
 * status: public api
 *
 * @param src source FDF table
 * @param scale_row row scaling factor
 * @param scale_col column scaling factor
 * @return scaled FDF table, or an empty table on failure
 */
t_fdf_table	scale_dim_fdf_table(const t_fdf_table *src,
	size_t scale_row, size_t scale_col)
{
	t_fdf_table	dst;

	if (src == NULL || src->arr == NULL
		|| mul_overflow_size_t(scale_col, scale_row) == false
		|| mul_overflow_size_t(src->row, src->col) == false
		|| mul_overflow_size_t(scale_row * scale_col, src->row * src->col) == false)
		return (create_fdf_table(0, 0, false));
	dst.col = scale_col * src->col;
	dst.row = scale_row * src->row;
	dst.arr = scale_dim_fdf_table_int(src, scale_row, scale_col);
	if (dst.arr == NULL)
		return (create_fdf_table(0, 0, false));
	dst.r = scale_dim_fdf_table_rgba(src, scale_row, scale_col, FDF_RED);
	dst.g = scale_dim_fdf_table_rgba(src, scale_row, scale_col, FDF_GREEN);
	dst.b = scale_dim_fdf_table_rgba(src, scale_row, scale_col, FDF_BLUE);
	dst.a = scale_dim_fdf_table_rgba(src, scale_row, scale_col, FDF_ALPHA);
	return (dst);
}
