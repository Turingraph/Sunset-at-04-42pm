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
 * @param dim the dimension of the kernel.
 * @param std standard deviation arguments.
 * @return allocated 1D kernel with 2 * dim + 1 items,
 * or NULL if allocation fails
 */
t_float_arr	kernel_gauss1d(size_t dim, float std)
{
	size_t		i;
	t_float_arr	kernel;
	float		sum;
	float		*arr;
	size_t		half_dim;

	if (dim < 3)
		dim = 3;
	if (dim % 2 == 0)
		dim += 1;
	half_dim = dim / 2;
	kernel.arr = NULL;
	kernel.length = 0;
	arr = malloc_talk(sizeof(float) * dim,
			"kernel_gauss1d\n");
	if (arr == NULL)
		return (kernel);
	i = 0;
	while (i <= half_dim)
	{
		arr[half_dim - i] = f_normal(
				std, 0, (-1.0) * (float)(i));
		arr[half_dim + i] = f_normal(std, 0, (float)(i));
		i += 1;
	}
	sum = f_sum((const float *)arr, dim);
	i = 0;
	while (i < dim && sum != 0)
	{
		arr[i] /= sum;
		i += 1;
	}
	kernel.arr = arr;
	kernel.length = dim;
	return (kernel);
}

/**
 * Create a 2D Blur Gaussian kernel from two 1D Gaussian kernels.
 *
 * time/space: O(n^2) / O(n^2)
 *
 * status: public api
 *
 * @param dim half the kernel width. If dim is less than 1,
 * then the return output will have dimension equal to 3.
 * @param std_1 standard deviation for the first dimension
 * @param std_2 standard deviation for the second dimension
 * @return generated Gaussian kernel as array of float,
 * with (2 * dim + 1) * (2 * dim + 1) items.
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 *  for more details
 */
t_matrix	kernel_gauss(size_t dim, float std_1, float std_2)
{
	t_float_arr	vec_v;
	t_float_arr	vec_u;
	t_matrix	dst;

	dst.arr = NULL;
	dst.col = 0;
	dst.row = 0;
	if (mul_overflow_size_t(dim, 2) == false)
		return (dst);
	if (dim < 3)
		dim = 3;
	if (dim % 2 == 0)
		dim += 1;
	vec_v = kernel_gauss1d(dim, std_1);
	vec_u = kernel_gauss1d(dim, std_2);
	dst = outer_product(vec_v.arr, vec_u.arr, dim);
	free(vec_v.arr);
	free(vec_u.arr);
	return (dst);
}

static void	swap_dim(size_t *inner_dim, size_t *outer_dim)
{
	size_t	temp;

	if (inner_dim != NULL && outer_dim != NULL)
	{
		if (*inner_dim < 3)
			*inner_dim = 3;
		if (*inner_dim % 2 == 0)
			*inner_dim += 1;
		if (*outer_dim < 3)
			*outer_dim = 3;
		if (*outer_dim % 2 == 0)
			*outer_dim += 1;
		if (*outer_dim < *inner_dim)
		{
			temp = *outer_dim;
			*outer_dim = *inner_dim;
			*inner_dim = temp;
		}
	}
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
t_float_arr	kernel_edge1d(size_t inner_dim, size_t outer_dim,
	float inner_num, float outer_num)
{
	size_t	i;
	float	*arr;
	t_float_arr	kernel;

	kernel.arr = NULL;
	kernel.length = 0;
	swap_dim(&inner_dim, &outer_dim);
	if (mul_overflow_size_t(outer_dim / 2, outer_dim / 2) == false)
		return (kernel);
	arr = malloc_talk(sizeof(float) * outer_dim, "kernel_edge1d\n");
	if (arr == NULL)
		return (kernel);
	i = 0;
	while (i <= inner_dim / 2 && inner_dim > 0)
	{
		arr[outer_dim / 2 - i] = inner_num;
		arr[outer_dim / 2 + i] = inner_num;
		i += 1;
	}
	while (i <= outer_dim / 2)
	{
		arr[outer_dim / 2 - i] = outer_num;
		arr[outer_dim / 2 + i] = outer_num;
		i += 1;
	}
	kernel.arr = arr;
	kernel.length = outer_dim;
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
 * status: internal helper
 * 
 * @param inner_dim dimension of the inner region.
 * @param outer_dim dimension of the outer region.
 * @param input value utilized by the inner region.
 * @param kernel_sum if kernel_sum = 1 means sharp, 0 means edge detection.
 * @return value utilized by the outer region.
 * @see Image convolution tutorial https://www.youtube.com/live/8rrHTtUzyZA?si=UZVlq0cpb2X95MZN
 * for more details.
 */
static float	init_outer_num(float inner_dim, float outer_dim, float input, float kernel_sum)
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
t_matrix	kernel_edge(size_t inner_dim, size_t outer_dim, float input, float kernel_sum)
{
	t_float_arr	vec_v;
	t_float_arr	vec_u;
	float		outer_num;
	t_matrix	dst;

	dst.arr = NULL;
	dst.col = 0;
	dst.row = 0;
	swap_dim(&inner_dim, &outer_dim);
	if (mul_overflow_size_t(outer_dim, outer_dim) == false)
		return (dst);
	outer_num = init_outer_num((float)inner_dim, (float)outer_dim, input, kernel_sum);
	vec_v = kernel_edge1d(inner_dim, outer_dim, input, outer_num);
	vec_u = kernel_edge1d(inner_dim, outer_dim, input, outer_num);
	dst = outer_product(vec_v.arr, vec_u.arr, outer_dim);
	free(vec_v.arr);
	free(vec_u.arr);
	return (dst);
}

t_matrix	kernel_cross(size_t inner_dim, size_t outer_dim)
{
	t_float_arr	vec_v;
	t_float_arr	vec_u;
	t_matrix	dst;

	dst.arr = NULL;
	dst.col = 0;
	dst.row = 0;
	swap_dim(&inner_dim, &outer_dim);
	if (mul_overflow_size_t(outer_dim, outer_dim) == false)
		return (dst);
	vec_v = kernel_edge1d(inner_dim, outer_dim, 0, 1);
	vec_u = kernel_edge1d(inner_dim, outer_dim, 0, 1);
	dst = outer_product(vec_v.arr, vec_u.arr, outer_dim);
	free(vec_v.arr);
	free(vec_u.arr);
	return (dst);
}

t_matrix	kernel_count_neighbors(size_t inner_dim, size_t outer_dim)
{
	float		*arr;
	size_t		i;
	size_t		index_left;
	size_t		index_right;
	t_matrix	dst;

	dst.arr = NULL;
	dst.col = 0;
	dst.row = 0;
	swap_dim(&inner_dim, &outer_dim);
	if (mul_overflow_size_t(outer_dim, outer_dim) == false)
		return (dst);
	arr = malloc_talk(sizeof(float) * outer_dim * outer_dim,
			"kernel_count_neighbors\n");
	if (arr == NULL)
		return (dst);
	index_left = outer_dim / 2 - inner_dim / 2;
	index_right = index_left + inner_dim;
	i = 0;
	while (i < outer_dim * outer_dim)
	{
		if (i % outer_dim <= index_left
			|| i % outer_dim >= index_right
			|| i / outer_dim <= index_left
			|| i / outer_dim >= index_right)
			arr[i] = 1;
		i += 1;
	}
	dst.arr = arr;
	dst.col = outer_dim;
	dst.row = outer_dim;
	return (dst);
}
