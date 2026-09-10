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
	float		u_6 = 0.146447;
	t_complex	shape[] = {
		{.re = 2 * u_0, .im = 1},
		{.re = u_6, .im = u_6},
		{.re = 1, .im = 2 * u_0},
		{.re = u_6, .im = 1 - u_6},
		{.re = 2 * u_0, .im = 0},
		{.re = 1 - u_6, .im = 1 - u_6},
		{.re = 0, .im = 2 * u_0},
		{.re = 1 - u_6, .im = u_6}
	};
	t_2d_int		tiling = {.x = 2 * 24, .y = 2 * 12};
	t_ink			ink = {.channel = HEIGHT, .color = 100, .thickness = 1};
	t_2d_polygon	polygon = {.arr = shape, .is_loop = true, .length = 8};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(240, 240, false);
	draw_square_tiling(&table, &polygon, ink, tiling);
	write_table_ascii_standard(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/star.out input_examples/line/star.txt
*/