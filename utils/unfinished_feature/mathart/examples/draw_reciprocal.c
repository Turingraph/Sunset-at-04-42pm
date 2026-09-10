#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(23, 31, false);
	table.zoom = 0.04;
	generate_cells_color(&table, HEIGHT, NULL, gen_complex_reciprocal);
	write_table_ascii_chungaloider(output, &table, HEIGHT);
	write_table_fdf(1, &table, 2, HEIGHT_ONLY);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all coding_examples/bin/editor/paint/draw_reciprocal.out input_examples/mathart_gen/reciprocal

*/