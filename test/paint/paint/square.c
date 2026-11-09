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
	// dst.input_end = mmaaxx + 100;
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

// time : O(1)
// space: O(1)
t_gradient	init_popart2(void)
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_GREEN;
	dst.input_start = 120;
	dst.input_end = 200;
	dst.rgba_start.r = 255;
	dst.rgba_start.g = 123;
	dst.rgba_start.b = 31;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 229;
	dst.rgba_end.g = 11;
	dst.rgba_end.b = 112;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_timeleft()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_RED;
	dst.input_start = 90;
	dst.input_end = 129;
	dst.rgba_start.r = 72;
	dst.rgba_start.g = 33;
	dst.rgba_start.b = 86;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 114;
	dst.rgba_end.g = 40;
	dst.rgba_end.b = 70;
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
	paint_aura_fdf_table(&table, 1, FDF_HEIGHT, aura_inequality_triangle);
	paint_aura_fdf_table(&table, 1, FDF_HEIGHT, aura_pythagoras);
	paint_aura_fdf_table(&table_base, AURA_PIANISSIMO, FDF_HEIGHT, aura_fractal_no3);
	mix_hadamard_fdf_table(&table, &table_base, FDF_HEIGHT);
	paint_gradient_fdf_table(&table, init_deep_wood(), true);
	paint_gradient_fdf_table(&table, init_popart2(), true);
	paint_gradient_fdf_table(&table, init_ztmy_timeleft(), true);
	paint_gradient_fdf_table(&table, init_popart(), true);
	paint_gradient_fdf_table(&table, init_white_noise(), true);
	scale_fdf_table(&table, 0, FDF_HEIGHT);
	style.shape2d = SHAPE2D_CIRCLE;
	style.thickness = 1;
	// output = create_fdf_proj2d(&table, NULL, 1);
	output = create_fdf_proj2d(&table, complex_sin, 0.0125);
	// output = create_fdf_proj2d(&table, complex_x3, 0.00125);
	// scale_fdf_proj2d(&output, 30, 30);
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
