#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_white_noise(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 34;
	dst.rgba_start.g = 79;
	dst.rgba_start.b = 112;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 34;
	dst.rgba_end.g = 79;
	dst.rgba_end.b = 112;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_feeling_blue(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 100;
	dst.rgba_start.r = 255;
	dst.rgba_start.g = 81;
	dst.rgba_start.b = 58;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255;
	dst.rgba_end.g = 189;
	dst.rgba_end.b = 13;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_popart(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_GREEN;
	dst.input_start = 90;
	dst.input_end = 120;
	dst.rgba_start.r = 34;
	dst.rgba_start.g = 79;
	dst.rgba_start.b = 112;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 163;
	dst.rgba_end.g = 196;
	dst.rgba_end.b = 202;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_render_style	style;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	style.background_color = f_rgba_to_int32(34, 79, 112, 255);
	style.line_thickness = 2;
	style.artists = E_KUSAMA;
	color_cells_gradient(&table, init_feeling_blue(), true);
	color_cells_gradient(&table, init_popart(), true);
	scale_multiplication_fdf(&table, 1.0 / 20.0, HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = init_fdf(&table, projection_cabinet, 1.0);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/window/yorushika.out unit_test/editor/convolve/input_ascii/rain_with_cappuccino_rozzo.txt

*/
