#include"line.h"

/*
Reference
*	https://en.wikipedia.org/wiki/Composition_with_Red,_Blue_and_Yellow
*/

int	main(int len, char **str)
{
	t_table_fdf	table;
	// t_table_fdf	table_2;
	int			output;
	t_line		square_00 = {.p1 = {.x = 1, .y = 1}, .p2 = {.x = 5, .y = 8}};
	t_line		square_01 = {.p1 = {.x = 1, .y = 11}, .p2 = {.x = 5, .y = 17}};
	t_line		square_02 = {.p1 = {.x = 1, .y = 19}, .p2 = {.x = 5, .y = 23}};
	t_line		square_03 = {.p1 = {.x = 7, .y = 1}, .p2 = {.x = 23, .y = 17}};
	t_line		square_04 = {.p1 = {.x = 7, .y = 19}, .p2 = {.x = 19, .y = 23}};
	t_line		square_05 = {.p1 = {.x = 21, .y = 19}, .p2 = {.x = 23, .y = 20}};
	t_line		square_06 = {.p1 = {.x = 21, .y = 22}, .p2 = {.x = 23, .y = 23}};
	t_2d_int	tiling = {.x = 24, .y = 24};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(48, 48, false);
	draw_mondrian_tiling_int(&table, square_00, 94, tiling);
	draw_mondrian_tiling_int(&table, square_01, 94, tiling);
	draw_mondrian_tiling_int(&table, square_02, 10, tiling);
	draw_mondrian_tiling_int(&table, square_03, 10, tiling);
	draw_mondrian_tiling_int(&table, square_04, 94, tiling);
	draw_mondrian_tiling_int(&table, square_05, 94, tiling);
	draw_mondrian_tiling_int(&table, square_06, 10, tiling);
	// table_2 = scale_dimension_fdf(&table, 1, 2);
	// write_table_ascii_cheche01(output, &table_2, HEIGHT);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	// free_table_fdf(&table_2);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/mondrian_int.out input_examples/line/mondrian_int.txt

*/