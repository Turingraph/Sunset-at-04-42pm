#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line = {
		.p1 = {.x = 15, .y = 90},
		.p2 = {.x = 65, .y = 35}
	};
	t_line		boundary = {
		.p1 = {.x = 25, .y = 0},
		.p2 = {.x = 75, .y = 101}
	};
	t_ink		ink = {.channel = HEIGHT, .color = 10, .thickness = 12};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(101, 101, false);
	draw_straight_line(&table, line, boundary, ink);
	line.p2.x = 15;
	draw_straight_line(&table, line, boundary, ink);
	ink.thickness = 8;
	ink.color = 40;
	line.p2.x = 65;
	draw_straight_line(&table, line, boundary, ink);
	line.p2.x = 15;
	draw_straight_line(&table, line, boundary, ink);
	ink.thickness = 3;
	ink.color = 80;
	line.p2.x = 65;
	draw_straight_line(&table, line, boundary, ink);
	line.p2.x = 15;
	draw_straight_line(&table, line, boundary, ink);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/straight_line.out input_examples/line/straight_line.txt
*/
