#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient(t_table_fdf *src)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	if (src != NULL)
	{
		dst.input_start = get_minmax_from_table_fdf(src, false, HEIGHT);
		dst.input_end = get_minmax_from_table_fdf(src, true, HEIGHT);
	}
	dst.rgba_start.r = 255;
	dst.rgba_start.g = 150;
	dst.rgba_start.b = 169;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 18;
	dst.rgba_end.g = 121;
	dst.rgba_end.b = 187;
	dst.rgba_end.a = 131;
	return (dst);
}

int	main(int len, char **str)
{
	t_gradient	gradient;
	t_table_fdf	table;
	t_table_fdf	table_2;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
    table_2 = scale_dimension_fdf(&table, 2, 3);
	gradient = init_gradient(&table_2);
	color_cells_gradient(&table_2, gradient, true, is_collatz_coloring);
	write_table_fdf(output, &table_2, 2, HEIGHT_RGBA);
	free_table_fdf(&table_2);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/paint/color_cells_gradient_02.out input_examples/font/rozzo/comma.txt input_examples/mathart_gradient/comma.fdf
*/
