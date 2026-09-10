#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_circle	circle = {.x = 0, .y = 5, .radius = 2};
	t_2d_int	tiling = {.x = 10, .y = 10};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	draw_kusama_circle_int(&table, circle, 30, tiling);
	circle.x = 6;
	circle.y = 7;
	circle.radius = 1;
	draw_kusama_circle_int(&table, circle, 50, tiling);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/kusama_art.out input_examples/line/kusama_art_small.txt

*/