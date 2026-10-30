/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:15:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 13:14:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convolve.h"

// time : O(1)
// space: O(1)
static int	clamped(const t_fdf_table *src, int ix, int iy)
{
	if (ix < 0)
		ix = 0;
	else if (ix >= (int)src->col)
		ix = (int)src->col - 1;
	if (iy < 0)
		iy = 0;
	else if (iy >= (int)src->row)
		iy = (int)src->row - 1;
	return (src->arr[iy * src->col + ix]);
}

// time : O(1)
// space: O(1)
static size_t	get_convolve_index(size_t dim, size_t col, int i, int j)
{
	int	y;

	y = (((int)dim) / 2 + i) * ((int)col) + ((int)dim) / 2 + j;
	return (y);
}

// time : O(n^2)
// space: O(n^2)
static t_matrix	init_src_kernel_int(const t_fdf_table *src,
	size_t dim, int ix, int iy)
{
	t_matrix	dst;
	int			i;
	int			j;

	dst.col = dim;
	dst.row = dim;
	dst.arr = malloc_talk(sizeof(float) * dim * dim,
			"convolve_fdf_table\n");
	if (dst.arr == NULL)
		return (dst);
	i = 0;
	while (i <= (int)dim / 2)
	{
		j = 0;
		while (j <= (int)dim / 2)
		{
			dst.arr[get_convolve_index(dim, dst.col, i, j)] = clamped(src, ix + j, iy + i);
			dst.arr[get_convolve_index(dim, dst.col, i, -j)] = clamped(src, ix - j, iy + i);
			dst.arr[get_convolve_index(dim, dst.col, -i, j)] = clamped(src, ix + j, iy - i);
			dst.arr[get_convolve_index(dim, dst.col, -i, -j)] = clamped(src, ix - j, iy - i);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(m^2)
// space: O(m^2)
static int	convolve_unit(const t_fdf_table *src, size_t index,
	t_matrix kernel, bool is_normal)
{
	t_matrix	src_kernel;
	int			output;
	size_t		dim;

	dim = kernel.col;
	output = 0;
	src_kernel = init_src_kernel_int(src, dim,
			(int)(index % src->col), (int)(index / src->col));
	if (src_kernel.arr == NULL)
		return (output);
	if (kernel.arr != NULL)
	{
		output = dot_product(src_kernel.arr,
				kernel.arr, dim * dim);
		if ((float)f_abs(f_sum(kernel.arr, dim * dim)) > 0.2 && is_normal == true)
			output = (int)f_round(
					(float)output / (float)(f_sum(kernel.arr, dim * dim)));
	}
	else if (is_normal == true && dim > 0)
		output = (int)f_round(
				f_sum(src_kernel.arr, dim * dim) / (float)(dim * dim));
	else
		output = (int)f_round(f_sum(src_kernel.arr, dim * dim));
	free(src_kernel.arr);
	return (output);
}

/**
 * Apply a convolution kernel to FDF_HEIGHT channels.
 * 
 * The kernel must be a square matrix with odd dimensions (e.g. 3x3, 5x5).
 * For each pixel, the kernel is centered on that pixel. Samples outside
 * the source image are clamped to the nearest edge pixel.
 * 
 * If kernel is NULL, an average kernel will be utilized instead.
 *
 * time/space: O(n * m^2) / O(n)
 * 
 * status: public api (unchecked)
 *
 * @param src source FDF table
 * @param kernel square convolution kernel.
 * If the kernel.arr is NULL but kernel dimension is valid, than the kernel is averaging blur kernel.
 * If the kernel dimension is invalidL, then return NULL table
 * @param is_normal if true, then normalizing the kernel dot product output.
 * @return FDF table with the selected channels convolved
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 * for more details
 */
t_fdf_table	convolve_fdf_table(const t_fdf_table *src, t_matrix kernel, bool is_normal)
{
	t_fdf_table	dst;
	size_t		i;

	if (src == NULL || src->arr == NULL
		|| mul_overflow_size_t(src->col, src->row) == false
		|| mul_overflow_size_t(kernel.col, kernel.row) == false
		|| (kernel.arr != NULL
			&& (kernel.col != kernel.row || kernel.col % 2 == 0 || kernel.col < 3)))
		return (create_fdf_table(0, 0, false));
	dst = scale_dim_fdf_table(src, 1, 1);
	if (dst.arr == NULL)
		return (create_fdf_table(0, 0, false));
	i = 0;
	while (i < src->col * src->row)
	{
		dst.arr[i] = convolve_unit(src, i, kernel, is_normal);
		i += 1;
	}
	return (dst);
}
