#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	t_table_fdf	table_2;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_chungaloider, false);
	table_2 = scale_dimension_fdf(&table, 1, 1);
	fill_cells_height(&table_2, 50, true, is_in_prism_terrain);
	write_table_ascii_chungaloider(output, &table_2, HEIGHT);
	free_table_fdf(&table);
	free_table_fdf(&table_2);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/paint/fill_cells_height_02.out input_examples/modified/rozzo_a_40_40.txt input_examples/mathart_gradient/rozzo_a_404.txt

*/