#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_deep_sea()
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
	t_table_fdf		table;
	t_fdf			output;
	t_artstyle32	style;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	style.background_color = f_rgba_to_int32(255, 255, 255, 255);
	style.line_thickness = 6;
	style.artists = E_PICASSO;
	color_cells_gradient(&table, init_deep_sea(), true);
	scale_multiplication_fdf(&table, 1.0 / 20.0, HEIGHT);
	output = init_fdf(&table, projection_isometric, 1.0);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/window/indigo.out unit_test/editor/convolve/input_ascii/o_isometric2.txt
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/window/indigo.out unit_test/input/table/00_fdf_to_ascii/elem-fract.txt
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/window/indigo.out unit_test/editor/convolve/input_ascii/unix_o8.txt
*/
