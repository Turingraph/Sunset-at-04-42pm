#include"convolve.h"

int	main(int len, char **str)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_matrix	kernel;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table_a = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	table_b = scale_dimension_fdf((const t_table_fdf *)&table_a, 1, 1);
	free_table_fdf(&table_a);
	kernel.row = 5;
	kernel.col = 5;
	kernel.arr = NULL;
	table_a = convolve_hight(&table_b, kernel);
	write_table_ascii_cheche01(output, &table_a, HEIGHT);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_matrix(&kernel);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/convolve/null_h.out input_examples/font/isometric2/t.txt input_examples/modified/isometric2_t_null.txt
*/
