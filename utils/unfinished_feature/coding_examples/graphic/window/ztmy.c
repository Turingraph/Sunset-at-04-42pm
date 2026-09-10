#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
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

int	main(int len, char **str)
{
	float		u_0 = 0.25;
	float		u_1 = 0.396447;
	float		u_2 = 0.08579;
	t_complex	shape_00[] = {
		{.re = 0, .im = 2 * u_0},
		{.re = u_0, .im = u_1},
		{.re = u_0, .im = u_0},
		{.re = u_1, .im = u_0},
		{.re = 2 * u_0, .im = 0},
		{.re = 0, .im = 0}
	};
	t_complex	shape_01[] = {
		{.re = 1 - 0, .im = 2 * u_0},
		{.re = 1 - u_0, .im = u_1},
		{.re = 1 - u_0, .im = u_0},
		{.re = 1 - u_1, .im = u_0},
		{.re = 1 - 2 * u_0, .im = 0},
		{.re = 1 - 0, .im = 0}
	};
	t_complex	shape_02[] = {
		{.re = 0, .im = 1 - 2 * u_0},
		{.re = u_0, .im = 1 - u_1},
		{.re = u_0, .im = 1 - u_0},
		{.re = u_1, .im = 1 - u_0},
		{.re = 2 * u_0, .im = 1 - 0},
		{.re = 0, .im = 1 - 0}
	};
	t_complex	shape_03[] = {
		{.re = 1 - 0, .im = 1 - 2 * u_0},
		{.re = 1 - u_0, .im = 1 - u_1},
		{.re = 1 - u_0, .im = 1 - u_0},
		{.re = 1 - u_1, .im = 1 - u_0},
		{.re = 1 - 2 * u_0, .im = 1 - 0},
		{.re = 1 - 0, .im = 1 - 0}
	};

	t_ink32			ink = {
		.color = (170 << 24 | 28 << 16 | 65 << 8 | 255),
		.thickness = 30, .type = E_LINE};
	t_ink32			ink2 = {
		.color = (63 << 24 | 29 << 16 | 56 << 8 | 255),
		.thickness = 20, .type = E_LINE};
	t_2d_polygon	polygon_00 = {.arr = shape_00, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_01 = {.arr = shape_01, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_02 = {.arr = shape_02, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_03 = {.arr = shape_03, .is_loop = false, .length = 5};

	t_complex		thickline_00[] = {
		{.re = u_2, .im = 0},
		{.re = 2 * u_0, .im = 1}
	};
	t_complex		thickline_01[] = {
		{.re = 2 * u_0, .im = 1},
		{.re = 1 - u_2, .im = 0}
	};
	t_complex		thickline_02[] = {
		{.re = u_2, .im = 1},
		{.re = 2 * u_0, .im = 0}
	};
	t_complex		thickline_03[] = {
		{.re = 2 * u_0, .im = 0},
		{.re = 1 - u_2, .im = 1}
	};
	t_2d_polygon	thickline_arr_00 = {.arr = thickline_00, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_01 = {.arr = thickline_01, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_02 = {.arr = thickline_02, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_03 = {.arr = thickline_03, .is_loop = false, .length = 2};
	t_motif_arr	islamic_art = {
		.length = 8,
		.arr = (t_motif []){
			{
				.polygon = thickline_arr_00,
				.ink = ink,
			},
			{
				.polygon = thickline_arr_01,
				.ink = ink,
			},
			{
				.polygon = thickline_arr_02,
				.ink = ink,
			},
			{
				.polygon = thickline_arr_03,
				.ink = ink,
			},
			{
				.polygon = polygon_00,
				.ink = ink2,
			},
			{
				.polygon = polygon_01,
				.ink = ink2,
			},
			{
				.polygon = polygon_02,
				.ink = ink2,
			},
			{
				.polygon = polygon_03,
				.ink = ink2,
			},
		}
	};
	t_table_fdf	table;
	t_fdf		output;
	t_background bc = {.color = f_rgba_to_int32(255, 255, 255, 255), .first_post = NULL, .tiles_resolution = 3};
	t_ink32	style = {.color = f_rgba_to_int32(224, 84, 84, 255), .thickness = 3, .type = E_CIRCLE};

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	scale_multiplication_fdf(&table, 10, HEIGHT);
	color_cells_gradient(&table, init_gradient(), true, NULL);
	output = init_fdf(&table);
	view_master_piece(&output, &islamic_art, style, bc);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/window/ztmy.out input_examples/view/zutomayo_isometric2.txt

*/