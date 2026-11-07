#include"paint.h"

int	mmaaxx = 500;

// time : O(1)
// space: O(1)
t_gradient	init_deep_wood()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = mmaaxx;
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

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 0;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 0;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(void)
{
	t_fdf_table		table_base;
	t_fdf_table		table;
	t_style_render	style;
	t_fdf_proj2d	output;

	table = create_fdf_table(mmaaxx, mmaaxx, true);
	table_base = create_fdf_table(mmaaxx, mmaaxx, false);
	paint_aura_fdf_table(&table, 1, FDF_HEIGHT, aura_pythagoras);
	paint_aura_fdf_table(&table_base, AURA_PIANISSIMO, FDF_HEIGHT, aura_fractal_no3);
	mix_hadamard_fdf_table(&table, &table_base, FDF_HEIGHT);
	paint_gradient_fdf_table(&table, init_deep_wood(), true);
	paint_gradient_fdf_table(&table, init_white_noise(), true);
	scale_fdf_table(&table, 0, FDF_HEIGHT);
	style.shape2d = SHAPE2D_CIRCLE;
	style.thickness = 1;
	// output = create_fdf_proj2d(&table, NULL, 1);
	output = create_fdf_proj2d(&table, complex_cos, 0.0125);
	// scale_fdf_proj2d(&output, 100, 100);
	view_fdf_proj2d(&output, style, rgba32_from_char(0, 0, 0, 255));
	destroy_fdf_table(&table);
	destroy_fdf_table(&table_base);
	destroy_fdf_proj2d(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./test/out/paint/paint/square.out
*/
