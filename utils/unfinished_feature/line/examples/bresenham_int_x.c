#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line = {
		.p1 = {.x = 2, .y = 13},
		.p2 = {.x = 15, .y = 10}
	};
	t_boundary	boundary = {
		.all_area = {.x = 30, .y = 30},
		.sub_area = {
			.p1 = {.x = 0, .y = 0},
			.p2 = {.x = 30, .y = 30}
		}
	};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(30, 30, false);
	bresenham_int_x(table.arr, line, boundary, 42);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/bresenham_int_x.out input_examples/line/line_int_x.txt
*/
