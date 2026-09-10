#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf		table;
	int				output;
	t_line			rectangle_boundary = {
		.p1 = {.x = 0, .y = 0},
		.p2 = {.x = 101,.y = 49}
	};
	t_ink			ink = {.channel = HEIGHT, .color = 10, .thickness = 5};
	t_complex		arr[] = {
		{.re = 0, .im = 0},
		{.re = 1, .im = 0},
		{.re = 1, .im = 3.0f / 4.0f},
	};

	t_2d_polygon	polygon = {.is_loop = true, .length = 3, .arr = arr};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	draw_polygon(&table, &polygon, ink, rectangle_boundary);
	ink.color = 50;
	ink.thickness = 3;
	draw_polygon(&table, &polygon, ink, rectangle_boundary);
	ink.color = 100;
	ink.thickness = 1;
	draw_polygon(&table, &polygon, ink, rectangle_boundary);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/pythagorus_big.out input_examples/line/pythagorus_big.txt
*/
