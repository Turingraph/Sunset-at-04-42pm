#include"line.h"

/*
Reference
*	https://youtu.be/pg1NpMmPv48?si=eAqEWgsZeGCyIC8K
*	https://www.desmos.com/calculator/ujafhqcj4e
*/

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
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
	t_2d_int		tiling = {.x = 24, .y = 24};
	t_ink			ink = {.channel = HEIGHT, .color = 3, .thickness = 5};
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

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(48, 48, false);
	draw_square_tiling(&table, &thickline_arr_00, ink, tiling);
	draw_square_tiling(&table, &thickline_arr_01, ink, tiling);
	draw_square_tiling(&table, &thickline_arr_02, ink, tiling);
	draw_square_tiling(&table, &thickline_arr_03, ink, tiling);
	ink.color = 100;
	ink.thickness = 1;
	draw_square_tiling(&table, &polygon_00, ink, tiling);
	draw_square_tiling(&table, &polygon_01, ink, tiling);
	draw_square_tiling(&table, &polygon_02, ink, tiling);
	draw_square_tiling(&table, &polygon_03, ink, tiling);
	write_table_ascii_standard(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/islamic_art.out input_examples/line/islamic_art.txt
*/