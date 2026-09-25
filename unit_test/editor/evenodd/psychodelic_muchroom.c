#include "evenodd.h"

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_RED;
	dst.input_start = 0;
	dst.input_end = 255;
	dst.rgba_start.r = 255;
	dst.rgba_start.g = 255;
	dst.rgba_start.b = 255;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}


int	main(void)
{
	t_table_fdf		table;
	t_fdf			output;
	t_render_style	style;

	table = init_table_fdf(120, 120, true);
	paint_space(&table, HEIGHT, cell_metric_amgm_inequality);
	paint_space(&table, BLUE, cell_metric_pythagoras_3d);
	paint_space(&table, RED, cell_metric_min_xy);
	paint_space(&table, GREEN, cell_metric_max_xyz);
	set_cells_color(&table, 255, ALPHA, NULL);
	color_cells_gradient(&table, init_white_noise(), false);
	style.background_color = f_rgba_to_int32(0, 0, 0, 255);
	style.line_thickness = 2;
	style.artist = E_TOBY_FOX;
	scale_multiplication_fdf(&table, 1.0 / 120.0, HEIGHT);
	output = init_fdf(&table, NULL, 0.6);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./unit_test/out/editor/evenodd/psychodelic_muchroom.out

*/
