#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(200, 200, false);
    table.zoom = 1;
	generate_cells_color(&table, HEIGHT, ormod_collatz_coloring, gen_collatz_x_coloring);
	write_table_ascii_standard(output, &table, HEIGHT);
	write_table_fdf(1, &table, 2, HEIGHT_ONLY);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all coding_examples/out/editor/paint/draw_3xplusormod.out input_examples/mathart_gen/draw_3xplusormod.txt

*/
