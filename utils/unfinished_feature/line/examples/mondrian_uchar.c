#include"line.h"

/*
Reference
*	https://en.wikipedia.org/wiki/Composition_with_Red,_Blue_and_Yellow
*/

int	main(int len, char **str)
{
	t_table_fdf	table;
	t_table_fdf	table_2;
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
	table = init_table_fdf(144, 144, true);
	draw_mondrian_tiling_uchar(&table, square_00, (t_ink){.color = 94, .channel = BLUE, .thickness = 0}, tiling);
	draw_mondrian_tiling_uchar(&table, square_01, (t_ink){.color = 94, .channel = BLUE, .thickness = 0}, tiling);
	draw_mondrian_tiling_uchar(&table, square_02, (t_ink){.color = 10, .channel = RED, .thickness = 0}, tiling);
	draw_mondrian_tiling_uchar(&table, square_03, (t_ink){.color = 10, .channel = RED, .thickness = 0}, tiling);
	draw_mondrian_tiling_uchar(&table, square_04, (t_ink){.color = 94, .channel = BLUE, .thickness = 0}, tiling);
	draw_mondrian_tiling_uchar(&table, square_05, (t_ink){.color = 94, .channel = BLUE, .thickness = 0}, tiling);
	draw_mondrian_tiling_uchar(&table, square_06, (t_ink){.color = 10, .channel = RED, .thickness = 0}, tiling);
	table_2 = scale_dimension_fdf(&table, 1, 2);
	write_table_fdf(output, &table_2, 1, HEIGHT_RGBA);
	free_table_fdf(&table);
	free_table_fdf(&table_2);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/mondrian_uchar.out input_examples/line/mondrian_uchar.fdf

*/