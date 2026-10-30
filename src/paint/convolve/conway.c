#include "convolve.h"

t_fdf_table	convolve_bool_fdf_table(const t_fdf_table *src,
	t_matrix kernel, bool only_positive)
{
	t_fdf_table	dst;
	t_fdf_table	bi;

	if (src == NULL || src->arr == NULL
		|| mul_overflow_size_t(src->col, src->row) == false
		|| mul_overflow_size_t(kernel.col, kernel.row) == false)
		return (create_fdf_table(0, 0, false));
	bi = scale_dim_fdf_table(src, 1, 1);
	if (bi.arr == NULL)
		return (create_fdf_table(0, 0, false));
	bool_fdf_table(&bi, only_positive);
	dst = convolve_fdf_table(&bi, kernel, false);
	destroy_fdf_table(&bi);
	return (dst);
}

t_fdf_table	count_neighbors_fdf_table(const t_fdf_table *src, size_t dim)
{
	t_fdf_table	dst;
	t_matrix	kernel;

	if (src == NULL || src->arr == NULL
		|| mul_overflow_size_t(src->col, src->row) == false
		|| mul_overflow_size_t(dim, dim) == false)
		return (create_fdf_table(0, 0, false));
	if (dim % 2 == 0)
		dim += 1;
	if (dim < 3)
		dim = 3;
	kernel = create_matrix(dim, dim, 1);
	if (kernel.arr == NULL)
		return (create_fdf_table(0, 0, false));
	kernel.arr[dim * dim / 2] = 0;
	dst = convolve_bool_fdf_table(src, kernel, true);
	free(kernel.arr);
	return (dst);
}

t_fdf_table	conway_fdf_table(const t_fdf_table *src, size_t dim,
	const char *rules_birth, const char *rules_survive)
{
	t_fdf_table	dst;
	t_fdf_table	bi;
	int			i;

	if (src == NULL || src->arr == NULL
		|| mul_overflow_size_t(src->col, src->row) == false
		|| mul_overflow_size_t(dim, dim) == false)
		return (create_fdf_table(0, 0, false));
	if (dim % 2 == 0)
		dim += 1;
	if (dim < 3)
		dim = 3;
	dst = count_neighbors_fdf_table(src, dim);
	if (dst.arr == NULL)
		return (create_fdf_table(0, 0, false));
	add_fdf_table(&dst, 1, FDF_HEIGHT);
	if (rules_birth == NULL && rules_survive == NULL)
		return (dst);
	bi = scale_dim_fdf_table(src, 1, 1);
	if (bi.arr == NULL)
		return (dst);
	bool_fdf_table(&bi, false);
	mix_hadamard_fdf_table(&dst, &bi, FDF_HEIGHT);
	i = 0;
	while (rules_birth != NULL && rules_birth[i] != '\0' && (size_t)i < dim * dim)
	{
		if (rules_birth[i] % 2 == '0' % 2)
			relu_fdf_table(&dst, -i - 1, -i - 1, 0);
		i += 1;
	}
	i = 0;
	while (rules_survive != NULL && rules_survive[i] != '\0' && (size_t)i < dim * dim)
	{
		if (rules_survive[i] % 2 == '0' % 2)
			relu_fdf_table(&dst, i + 1, i + 1, 0);
		i += 1;
	}
	destroy_fdf_table(&bi);
	return (dst);
}

