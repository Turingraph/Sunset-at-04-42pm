#include"convolve.h"

int	main(int len, char **str)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_matrix	kernel;
	size_t		half_dim;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	half_dim = 3;
	table_a = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	table_b = scale_dimension_fdf((const t_table_fdf *)&table_a, 3, 3);
	free_table_fdf(&table_a);
	kernel = gaussian_kernel(half_dim, 0.7, 0.7);
	table_a = convolve_hight(&table_b, kernel);
	scale_relu_fdf(&table_a, 10, 20, 100);
	write_table_ascii_cheche01(output, &table_a, HEIGHT);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_matrix(&kernel);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/convolve/gauss_h.out input_examples/font/isometric2_a.txt input_examples/modified/isometric2_a_40_40.txt
*/
