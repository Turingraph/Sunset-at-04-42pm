#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_deep_wood()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 100;
	dst.rgba_start.r = 70;
	dst.rgba_start.g = 75;
	dst.rgba_start.b = 113;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 124;
	dst.rgba_end.g = 213;
	dst.rgba_end.b = 199;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_fdf_table		table;
	t_fdf_projection2d			output;
	t_fdf_render	style;

	if (len < 2)
		return (0);
	table = open_fdf_table_file(str[1], NULL, parse_ascii_cheche01, true);
	if (table.col * table.row == 0)
	{
		destroy_fdf_table(&table);
		return (0);
	}
	style.thickness = 1;
	style.shape_2d = E_RECTANGLE;
	scale_relu_fdf(&table, 0, 30, 0);
	color_cells_gradient(&table, init_deep_wood(), true);
	scale_multiplication_fdf(&table, 1.0, HEIGHT);
	output = create_fdf_projection2d(&table, NULL, 1.0);
	view_fdf(&output, style, rgba32_from_char(255, 255, 255, 255));
	destroy_fdf_table(&table);
	destroy_fdf_projection2d(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/indigo.out test/paint/convolve/input_ascii/o_isometric2.txt
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/indigo.out test/input/table/00_fdf_to_ascii/elem-fract.txt
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/indigo.out test/paint/convolve/input_ascii/unix_o8.txt
*/
