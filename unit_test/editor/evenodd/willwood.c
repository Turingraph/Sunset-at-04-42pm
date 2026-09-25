#include"evenodd.h"

// time : O(1)
// space: O(1)
t_gradient	init_all()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 500;
	dst.rgba_start.r = 251;
	dst.rgba_start.g = 174;
	dst.rgba_start.b = 67;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 221;
	dst.rgba_end.g = 209;
	dst.rgba_end.b = 167;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_deep_wood()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 5;
	dst.rgba_start.r = 126;
	dst.rgba_start.g = 46;
	dst.rgba_start.b = 3;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 176;
	dst.rgba_end.g = 110;
	dst.rgba_end.b = 3;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 30;
	dst.rgba_start.g = 15;
	dst.rgba_start.b = 13;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 30;
	dst.rgba_end.g = 15;
	dst.rgba_end.b = 13;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(void)
{
	t_table_fdf		table_base;
	t_table_fdf		table;
	t_fdf			output;
	t_render_style	style;
	t_gradient		wood;
	size_t			i;

	wood = init_deep_wood();
	table = init_table_fdf(300, 300, true);
	table_base = init_table_fdf(300, 300, false);
	paint_space(&table, HEIGHT, cell_metric_amgm_inequality);
	paint_space(&table, HEIGHT, cell_metric_pythagoras_3d);
	set_cells_color(&table_base, 1, HEIGHT, is_oddlength_x2shadow);
	table_fdf_hadamard(&table, &table_base, HEIGHT);
	color_cells_gradient(&table, init_all(), true);
	style.background_color = f_rgba_to_int32(0, 0, 0, 255);
	style.line_thickness = 3;
	style.artist = E_KUSAMA;
	i = 0;
	while (i < 24)
	{
		wood.input_start += 15;
		wood.input_end += 15;
		color_cells_gradient(&table, wood, true);
		i += 1;
	}
	color_cells_gradient(&table, init_white_noise(), true);
	scale_multiplication_fdf(&table, 1.0 / 30.0, HEIGHT);
	output = init_fdf(&table, projection_cabinet, 1.3);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_table_fdf(&table_base);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/evenodd/willwood.out
*/
