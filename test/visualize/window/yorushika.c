#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_white_noise(void)
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
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

	dst.cell_channel = GRADIENT_HEIGHT;
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

	dst.cell_channel = GRADIENT_GREEN;
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
	t_fdf_table		table;
	t_fdf_proj2d			output;
	t_style_render	style;

	if (len < 2)
		return (0);
	table = load_fdf_table(str[1], NULL, parse_ascii_cheche01, true);
	if (table.col * table.row == 0)
	{
		destroy_fdf_table(&table);
		return (0);
	}
	style.thickness = 2;
	style.shape2d = SHAPE2D_CIRCLE;
	color_cells_gradient(&table, init_feeling_blue(), true);
	color_cells_gradient(&table, init_popart(), true);
	scale_fdf_table(&table, 1.0 / 20.0, FDF_HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = create_fdf_proj2d(&table, proj2d_military, 1.0);
	view_fdf(&output, style, rgba32_from_char(34, 79, 112, 255));
	destroy_fdf_table(&table);
	destroy_fdf_proj2d(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/yorushika.out test/paint/convolve/input_ascii/rain_with_cappuccino_rozzo.txt

*/
