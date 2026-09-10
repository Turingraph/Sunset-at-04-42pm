#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	float		x;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	x = 8;
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	scale_multiplication_fdf(&table, x, HEIGHT);
	write_table_ascii_cheche01(output, (const t_table_fdf *)&table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/input/table/scale_multiplication_fdf.out input_examples/modified/isometric2_a_40_40.txt input_examples/modified/isometric2_a_multiply.txt

*/