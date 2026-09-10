#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_chungaloider, true);
	generate_cells_color(&table, BLUE, is_complex_sin, gen_conjugate);
	write_table_fdf(output, &table, 2, HEIGHT_RGB);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/paint/generate_cells_color.out input_examples/modified/isometric2_a_40_40.txt input_examples/mathart_gradient/isometric2_a_404.fdf

*/