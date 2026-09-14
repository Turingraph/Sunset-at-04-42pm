/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:34:06 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/14 12:13:58 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

// time : O(1)
// space: O(1)
void	*free_matrix(t_matrix *src)
{
	if (src == NULL)
		return (NULL);
	free(src->arr);
	src->arr = NULL;
	src->row = 0;
	src->col = 0;
	return (NULL);
}

// time : O(n)
// space: O(n)
t_matrix	init_matrix(size_t row, size_t col, float scale)
{
	t_matrix	dst;
	size_t		i;

	dst.row = row;
	dst.col = col;
	dst.arr = (float *)malloc(sizeof(float) * row * col);
	if (dst.arr == NULL)
	{
		free_matrix(&dst);
		return (dst);
	}
	i = 0;
	while (i < row * col)
	{
		dst.arr[i] = scale;
		i += 1;
	}
	return (dst);
}

/**
 * compute the outer product of 2 vector, for image convolution.
 * 
 * time/space: O(n^2) / O(n^2)
 * 
 * status: public api
 */
t_matrix	outer_product_matrix(const float *vec_v,
	const float *vec_u, size_t dim)
{
	t_matrix	dst;
	size_t		i;

	dst = init_matrix(dim, dim, 1);
	if (dst.arr == NULL || (vec_u == NULL && vec_v == NULL))
		return (dst);
	i = 0;
	while (i < dim * dim)
	{
		if (vec_u != NULL)
			dst.arr[i] *= vec_u[i % dim];
		if (vec_v != NULL)
			dst.arr[i] *= vec_v[i / dim];
		i += 1;
	}
	return (dst);
}

// time : O(1)
// space: O(1)
bool	is_matrix_valid(const t_matrix *src)
{
	if (src == NULL || src->arr == NULL || src->col * src->row == 0)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_matrix_same_dim(const t_matrix *a, const t_matrix *b)
{
	if (is_matrix_valid(a) == false || is_matrix_valid(b) == false
		|| a->col != b->col || a->row != b->row)
		return (false);
	return (true);
}
