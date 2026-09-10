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
	half_dim = 2;
	table_a = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	table_b = scale_dimension_fdf((const t_table_fdf *)&table_a, 3, 2);
	free_table_fdf(&table_a);
	kernel = init_matrix(2 * half_dim + 1, 2 * half_dim + 1,
		1.0/(double)((2 * half_dim + 1) * (2 * half_dim + 1)));
	table_a = convolve_hight(&table_b, kernel);
	scale_multiplication_fdf(&table_a, 10, HEIGHT);
	write_table_fdf(output, &table_a, 2, HEIGHT_RGB);
	write_table_ascii_cheche01(1, &table_a, HEIGHT);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_matrix(&kernel);
	return (0);
}

// write_table_ascii_cheche01(output, &table_a, HEIGHT);

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/convolve/kernel_h.out input_examples/font/isometric2/f.txt input_examples/modified/isometric2_f_55.txt
*/
