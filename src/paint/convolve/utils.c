#include "convolve.h"

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

