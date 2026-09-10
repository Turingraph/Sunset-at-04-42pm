#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	table.zoom = 0.5;
	generate_cells_color(&table, HEIGHT, NULL, gen_conjugate_sin);
	// scale_multiplication_fdf(&table, 0.5, HEIGHT);
	write_table_ascii_chungaloider(output, &table, HEIGHT);
	write_table_fdf(1, &table, 2, HEIGHT_ONLY);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all coding_examples/bin/editor/paint/draw_sin_x.out input_examples/mathart_gen/sin_x

*/