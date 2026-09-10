#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	t_table_fdf	table_2;
	int			output;
	t_circle	circle = {.x = 12, .y = 12, .radius = 6};
	t_boundary	boundary = {
		.all_area = {.x = 49, .y = 30},
		.sub_area = {
			.p1 = {.x = 0, .y = 0},
			.p2 = {.x = 49, .y = 30}
		}
	};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(30, 49, false);
	midpoint_circle_int(table.arr, 10, circle, boundary);
	table_2 = scale_dimension_fdf(&table, 2, 1);
	table_2.row /= 2;
	table_2.col *= 2;
	write_table_ascii_cheche01(output, &table_2, HEIGHT);
	free_table_fdf(&table);
	free_table_fdf(&table_2);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/circle.out input_examples/line/circle.txt
*/
