#include"evenodd.h"

// time : O(1)
// space: O(1)
t_gradient	init_deep_sea()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 200;
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

int	main(void)
{
	t_table_fdf		table_base;
	t_table_fdf		table;
	t_fdf			output;
	t_render_style	style;

	table = init_table_fdf(100, 100, true);
	table_base = init_table_fdf(100, 100, false);
	setcells_pythagorus_length(&table);
	set_cells_color(&table_base, 30, HEIGHT, is_oddlength_cube);
	table_fdf_hadamard(&table, &table_base, HEIGHT);
	scale_relu_fdf(&table, 201, 2000, 0);
	style.background_color = f_rgba_to_int32(0, 0, 0, 255);
	style.line_thickness = 2;
	style.artist = E_EULER;
	color_cells_gradient(&table, init_deep_sea(), true);
	scale_multiplication_fdf(&table, 1.0 / 120.0, HEIGHT);
	output = init_fdf(&table, projection_isometric, 0.6);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_table_fdf(&table_base);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/evenodd/cube.out
*/
