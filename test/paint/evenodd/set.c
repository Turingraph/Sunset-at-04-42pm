#include"evenodd.h"

// time : O(1)
// space: O(1)
t_gradient	init_deep_wood()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 216;
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
	t_fdf_table		table;
	t_fdf_proj2d			output;
	t_style_render	style;

	table = create_fdf_table(120, 120, true);
	paint_aura_fdf_table(&table, FDF_HEIGHT, aura_max_xy);
	style.thickness = 2;
	style.shape2d = SHAPE2D_RECTANGLE;
	paint_gradient_fdf_table(&table, init_deep_wood(), true);
	scale_fdf_table(&table, 1.0 / 120.0, FDF_HEIGHT);
	output = create_fdf_proj2d(&table, NULL, 0.6);
	view_fdf(&output, style, rgba32_from_char(0, 0, 0, 255));
	destroy_fdf_table(&table);
	destroy_fdf_proj2d(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/evenodd/set.out
*/
