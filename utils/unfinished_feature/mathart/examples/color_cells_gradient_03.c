#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient()
{
	t_gradient	dst;

	dst.cell_channel = D7_RED;
	dst.input_start = 0;
	dst.input_end = 255;
	dst.rgba_start.r = 255;
	dst.rgba_start.g = 150;
	dst.rgba_start.b = 169;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 118;
	dst.rgba_end.g = 121;
	dst.rgba_end.b = 187;
	dst.rgba_end.a = 131;
	return (dst);
}

int	main(int len, char **str)
{
	t_gradient	gradient;
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	gradient = init_gradient();
	color_cells_gradient(&table, gradient, true, is_collatz_coloring);
	write_table_fdf(output, &table, 2, HEIGHT_RGBA);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/paint/color_cells_gradient_03.out input_examples/fdf/t1.fdf input_examples/mathart_gradient/t1.fdf

~ 13:33 s
*/
