#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_all()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
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

	dst.cell_channel = GRADIENT_HEIGHT;
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

	dst.cell_channel = GRADIENT_HEIGHT;
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
	t_fdf_table		table_base;
	t_fdf_table		table;
	t_gradient		wood;
	size_t			i;
	size_t			dim = 300;

	wood = init_deep_wood();
	table = create_fdf_table(dim, dim, true);
	table_base = create_fdf_table(dim, dim, false);
	paint_aura_fdf_table(&table, 1, FDF_HEIGHT, aura_inequality_amgm);
	paint_aura_fdf_table(&table, 1, FDF_HEIGHT, aura_pythagoras);
	paint_aura_fdf_table(&table_base, 0.09, FDF_HEIGHT, aura_hypnotize_no2);
	mix_hadamard_fdf_table(&table, &table_base, FDF_HEIGHT);
	paint_gradient_fdf_table(&table, init_all(), true);
	i = 0;
	while (i < 24)
	{
		wood.input_start += 15;
		wood.input_end += 15;
		paint_gradient_fdf_table(&table, wood, true);
		i += 1;
	}
	paint_gradient_fdf_table(&table, init_white_noise(), true);
	scale_fdf_table(&table, 1.0 / 30.0, FDF_HEIGHT);
	view_fdf_pixel_art(&table, rgba32_from_char(0, 0, 0, 255));
	destroy_fdf_table(&table);
	destroy_fdf_table(&table_base);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 
./test/out/paint/paint/willwood.out
*/
