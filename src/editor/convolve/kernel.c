/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:16:03 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 14:30:24 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convolve.h"

// https://stackoverflow.com/questions/1696113/
// how-do-i-gaussian-blur-an-image-without-using-any-in-built-gaussian-functions

// time : O(n)
// space: O(n)
float	*gaussian_kernel_1d(size_t half_dim, float std)
{
	size_t	i;
	float	*kernel;
	float	sum;

	kernel = malloc_talk(sizeof(float) * (2 * half_dim + 1),
			"editor/convolve/kernel.c/gaussian_kernel_1d\n");
	if (kernel == NULL)
		return (NULL);
	i = 0;
	while (i <= half_dim)
	{
		kernel[half_dim - i] = normal_distribution_function(
				std, 0, (-1.0) * (float)(i));
		kernel[half_dim + i] = normal_distribution_function(std, 0, (float)(i));
		i += 1;
	}
	sum = f_sum((const float *)kernel, 2 * half_dim + 1);
	i = 0;
	while (i < 2 * half_dim + 1 && sum != 0)
	{
		kernel[i] /= sum;
		i += 1;
	}
	return (kernel);
}

/**
 * Create a 2D Blur Gaussian kernel from two 1D Gaussian kernels.
 *
 * time/space: O(n^2) / O(n^2)
 *
 * status: public api
 *
 * @param half_dim half the kernel width. If half_dim is less than 1,
 * then the return output will have dimension equal to 3.
 * @param std_1 standard deviation for the first dimension
 * @param std_2 standard deviation for the second dimension
 * @return generated Gaussian kernel as array of float,
 * with (2 * half_dim + 1) * (2 * half_dim + 1) items.
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 *  for more details
 */
float	*gaussian_kernel(size_t half_dim, float std_1, float std_2)
{
	float		*vec_v;
	float		*vec_u;
	t_matrix	dst;

	if (half_dim < 1)
		half_dim = 1;
	vec_v = gaussian_kernel_1d(half_dim, std_1);
	vec_u = gaussian_kernel_1d(half_dim, std_2);
	dst = outer_product_matrix(vec_v, vec_u, 2 * half_dim + 1);
	free(vec_v);
	free(vec_u);
	return (dst.arr);
}
