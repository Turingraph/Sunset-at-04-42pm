#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line = {
		.p1 = {.x = 2, .y = 13},
		.p2 = {.x = 28, .y = 20}
	};
	t_boundary	boundary = {
		.all_area = {.x = 30, .y = 40},
		.sub_area = {
			.p1 = {.x = 0, .y = 0},
			.p2 = {.x = 30, .y = 40}
		}
	};
	t_ink		ink = {.channel = HEIGHT, .color = 10, .thickness = 4};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(40, 30, false);
	bresenham_int_x_thick(table.arr, line, boundary, ink);
	ink.color = 50;
	ink.thickness = 1;
	bresenham_int_x_thick(table.arr, line, boundary, ink);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/bresenham_int_x_thick.out input_examples/line/bresenham_int_x_thick.txt
*/
