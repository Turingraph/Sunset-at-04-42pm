#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_deep_wood()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 100;
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

// static t_double2d	complex_x22(t_double2d x)
// {
// 	t_double2d	rr;

// 	rr = complex_rotate(PI314PM / 2);
// 	rr = complex_multiplication(rr,
// 		complex_multiplication(x, x));
// 	return (rr);
// }

int	main(int len, char **str)
{
	t_fdf_table		table;
	t_fdf_proj2d			output;
	t_style_render	style;

	if (len < 2)
		return (0);
	table = load_fdf_table(str[1], FDF_FORMAT_ASCII_A, true);
	if (table.col * table.row == 0)
	{
		destroy_fdf_table(&table);
		return (0);
	}
	style.thickness = 5;
	style.shape2d = SHAPE2D_CIRCLE;
	relu_fdf_table(&table, 0, 30, 0);
	paint_gradient_fdf_table(&table, init_deep_wood(), true);
	scale_fdf_table(&table, 1.0 / 15.0, FDF_HEIGHT);
	output = create_fdf_proj2d(&table, proj2d_cabinet, 1);
	// output = create_fdf_proj2d(&table, complex_x22, 0.0123);
	view_fdf_proj2d(&output, style, rgba32_from_char(255, 255, 255, 255));
	destroy_fdf_table(&table);
	destroy_fdf_proj2d(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/indigo.out test/paint/convolve/input_ascii/o_isometric2.txt
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/indigo.out test/input/table/00_fdf_to_ascii/elem-fract.txt
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/indigo.out test/paint/convolve/input_ascii/unix_o8.txt
*/
