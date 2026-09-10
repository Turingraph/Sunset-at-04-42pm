#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_bw, true);
	fill_cells_color(&table, 123, RED, is_complex_sin);
	write_table_ascii_standard(output, &table, RED);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/paint/fill_cells_color_01.out input_examples/fdf/100-6.fdf input_examples/mathart_gradient/100-6.txt
*/
