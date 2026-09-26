#include "convolve.h"

// https://stackoverflow.com/questions/1696113/
// how-do-i-gaussian-blur-an-image-without-using-any-in-built-gaussian-functions

/**
 * Create a 1D Gaussian Blur kernel.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param half_dim the half dimension of the kernel.
 * @param std standard deviation arguments.
 * @return allocated 1D kernel with 2 * half_dim + 1 items,
 * or NULL if allocation fails
 */
float	*gaussian_kernel_1d(size_t half_dim, float std)
{
	size_t	i;
	float	*kernel;
	float	sum;

	kernel = malloc_talk(sizeof(float) * (2 * half_dim + 1),
			"gaussian_kernel_1d\n");
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

/**
 * Create a 1D kernel with an inner region and an outer region.
 *
 * The inner region is centered on the kernel and uses inner_num.
 * Remaining elements on both sides use outer_num.
 * 
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param inner_dim dimension of the inner region.
 * @param outer_dim dimension of the resulting kernel.
 * @param inner_num value utilized by the inner region.
 * @param outer_num value utilized by the outer region.
 * @return allocated 1D kernel, or NULL if allocation fails
 */
float	*edge_kernel_1d(size_t inner_dim, size_t outer_dim,
	float inner_num, float outer_num)
{
	size_t	i;
	float	*kernel;

	kernel = malloc_talk(sizeof(float) * outer_dim, "edge_kernel_1d\n");
	if (kernel == NULL)
		return (NULL);
	i = 0;
	while (i <= inner_dim / 2 && inner_dim > 0)
	{
		kernel[outer_dim / 2 - i] = inner_num;
		kernel[outer_dim / 2 + i] = inner_num;
		i += 1;
	}
	while (i <= outer_dim / 2)
	{
		kernel[outer_dim / 2 - i] = outer_num;
		kernel[outer_dim / 2 + i] = outer_num;
		i += 1;
	}
	return (kernel);
}

/*
aa ... aa ba ... ba aa ... aa
aa     aa ba     ba aa     aa
aa ... aa ba ... ba aa ... aa
ab ... ab bb ... bb ab ... ab
ab     ab bb     bb ab     ab
ab ... ab bb ... bb ab ... ab
aa ... aa ba ... ba aa ... aa
aa     aa ba     ba aa     aa
aa ... aa ba ... ba aa ... aa

|a| = m
|b| = n

0 = (bn)^2 + 4 nmab + (2am)^2
0 = (bn)^2 + 2 (nb)(2am) + (2am)^2
0 = (bn + 2am)^2
therefore b = (-2am) / n, a = (-bn) / (2m)
*/

/**
 * Define the outer number for edge-detection/sharp convolution kernel.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: public api
 * 
 * @param inner_dim dimension of the inner region.
 * @param outer_dim dimension of the outer region.
 * @param input value utilized by the inner region.
 * @param kernel_sum if kernel_sum = 1 means sharp, 0 means edge detection.
 * @return value utilized by the outer region.
 * @see Image convolution tutorial https://www.youtube.com/live/8rrHTtUzyZA?si=UZVlq0cpb2X95MZN
 * for more details.
 */
float	define_outer_num(float inner_dim, float outer_dim, float input, float kernel_sum)
{
	if (outer_dim == 0)
		return (0.0);
	return (kernel_sum - input * inner_dim / (2.0 * outer_dim));
}

/**
 * Create a square edge-detection/sharp convolution kernel.
 * The resulting kernel has odd dimensions, with a minimum dimension of 3.
 * If inner_dim is greater than outer_dim, the dimensions are swapped.
 * 
 * time/space: O(n^2) / O(n^2)
 * 
 * status: public api
 * 
 * @param inner_dim dimension of the inner region.
 * @param outer_dim dimension of the resulting square kernel.
 * @param input value utilized by the inner region.
 * @param kernel_sum if kernel_sum = 1 means sharp, 0 means edge detection.
 * @return allocated square edge kernel, or NULL if allocation fails
 * @see Image convolution tutorial https://www.youtube.com/live/8rrHTtUzyZA?si=UZVlq0cpb2X95MZN
 * for more details.
 */
float	*edge_kernel(size_t inner_dim, size_t outer_dim, float input, float kernel_sum)
{
	size_t		swap_dim;
	float		*vec_v;
	float		*vec_u;
	float		outer_num;
	t_matrix	dst;

	if (outer_dim % 2 == 0)
		outer_dim += 1;
	if (outer_dim < 3)
		outer_dim = 3;
	if (inner_dim > outer_dim)
	{
		swap_dim = inner_dim;
		inner_dim = outer_dim;
		outer_dim = swap_dim;
	}
	outer_num = define_outer_num((float)inner_dim, (float)outer_dim, input, kernel_sum);
	vec_v = edge_kernel_1d(inner_dim, outer_dim, input, outer_num);
	vec_u = edge_kernel_1d(inner_dim, outer_dim, input, outer_num);
	dst = outer_product_matrix(vec_v, vec_u, outer_dim);
	free(vec_v);
	free(vec_u);
	return (dst.arr);
}
