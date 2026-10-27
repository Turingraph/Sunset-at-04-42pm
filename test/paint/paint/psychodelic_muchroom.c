#include "paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_RED;
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
	t_fdf_table		table;
	t_fdf_proj2d			output;
	t_style_render	style;

	table = create_fdf_table(120, 120, true);
	paint_aura_fdf_table(&table, FDF_HEIGHT, aura_inequality_amgm);
	paint_aura_fdf_table(&table, FDF_BLUE, aura_pythagoras_3d);
	paint_aura_fdf_table(&table, FDF_RED, aura_min_xy);
	paint_aura_fdf_table(&table, FDF_GREEN, aura_max);
	paint_spots_fdf_table(&table, 255, FDF_ALPHA, NULL);
	paint_gradient_fdf_table(&table, init_white_noise(), false);
	style.thickness = 2;
	style.shape2d = SHAPE2D_RECTANGLE;
	scale_fdf_table(&table, 1.0 / 120.0, FDF_HEIGHT);
	output = create_fdf_proj2d(&table, NULL, 0.6);
	view_fdf(&output, style, rgba32_from_char(0, 0, 0, 255));
	destroy_fdf_table(&table);
	destroy_fdf_proj2d(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./test/out/paint/evenodd/psychodelic_muchroom.out

*/
