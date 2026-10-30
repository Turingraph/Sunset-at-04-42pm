#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_deep_wood()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 300;
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

	table = create_fdf_table(300, 300, true);
	table_base = create_fdf_table(300, 300, false);
	paint_aura_fdf_table(&table, 1, FDF_HEIGHT, aura_pythagoras);
	paint_aura_fdf_table(&table_base, 0.2, FDF_HEIGHT, aura_disco_no2);
	mix_hadamard_fdf_table(&table, &table_base, FDF_HEIGHT);
	paint_gradient_fdf_table(&table, init_deep_wood(), true);
	paint_gradient_fdf_table(&table, init_white_noise(), true);
	scale_fdf_table(&table, 0, FDF_HEIGHT);
	view_fdf_pixel_art_conformal(&table, rgba32_from_char(0, 0, 0, 255), 0.1, complex_x2);
	destroy_fdf_table(&table);
	destroy_fdf_table(&table_base);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./test/out/paint/paint/square.out
*/
