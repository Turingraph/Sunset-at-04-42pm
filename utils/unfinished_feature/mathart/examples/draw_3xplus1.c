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
	generate_cells_color(&table, HEIGHT, is_collatz_coloring, gen_collatz_coloring);
	scale_multiplication_fdf(&table, 0.5, HEIGHT);
	table_2 = scale_dimension_fdf(&table, 1, 2);
	write_table_ascii_standard(output, &table_2, HEIGHT);
	free_table_fdf(&table_2);
	write_table_fdf(1, &table, 2, HEIGHT_ONLY);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all coding_examples/out/editor/paint/draw_3xplus1.out input_examples/mathart_gen/3xplus1

*/
