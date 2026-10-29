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

#include "convolve.h"

// time : O(1)
// space: O(1)
void	destroy_matrix(t_matrix *src)
{
	if (src == NULL)
		return ;
	free(src->arr);
	src->arr = NULL;
	src->row = 0;
	src->col = 0;
}

// time : O(n)
// space: O(n)
t_matrix	create_matrix(size_t row, size_t col, float scale)
{
	t_matrix	dst;
	size_t		i;

	dst.row = row;
	dst.col = col;
	dst.arr = NULL;
	if (mul_overflow_size_t(col, row) == true)
		dst.arr = (float *)malloc(sizeof(float) * row * col);
	if (dst.arr == NULL)
	{
		destroy_matrix(&dst);
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
t_matrix	outer_product(const float *vec_v,
	const float *vec_u, size_t dim)
{
	t_matrix	dst;
	size_t		i;

	dst = create_matrix(dim, dim, 1);
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
bool	isvalid_matrix(const t_matrix *src)
{
	if (src == NULL || src->arr == NULL
		|| mul_overflow_size_t(src->col, src->row) == false
		|| src->col * src->row == 0)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_matrix_same_dim(const t_matrix *a, const t_matrix *b)
{
	if (isvalid_matrix(a) == false || isvalid_matrix(b) == false
		|| a->col != b->col || a->row != b->row)
		return (false);
	return (true);
}

// time : O(n)
// space: O(1)
float	dot_product(const float *vec_v, const float *vec_u, size_t dim)
{
	float	y;
	size_t	i;

	if (vec_v == NULL || vec_u == NULL)
		return (0);
	y = 0;
	i = 0;
	while (i < dim)
	{
		y += vec_v[i] * vec_u[i];
		i += 1;
	}
	return (y);
}
