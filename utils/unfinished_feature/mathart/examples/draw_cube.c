#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	t_table_fdf	table_2;
	int			output;

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	table.zoom = 0.15;
	generate_cells_color(&table, HEIGHT, is_complex_cube, gen_complex_cube);
	table_2 = scale_dimension_fdf(&table, 1, 1);
	write_table_ascii_chungaloider(output, &table_2, HEIGHT);
	write_table_fdf(1, &table_2, 2, HEIGHT_ONLY);
	free_table_fdf(&table);
	free_table_fdf(&table_2);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all coding_examples/bin/editor/paint/draw_cube.out input_examples/mathart_gen/cube_1

*/