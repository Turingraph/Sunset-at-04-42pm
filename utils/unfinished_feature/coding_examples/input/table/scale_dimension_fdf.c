#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table_a = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	table_b = scale_dimension_fdf((const t_table_fdf *)&table_a, 2, 3);
	write_table_ascii_cheche01(output, (const t_table_fdf *)&table_b, HEIGHT);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/input/table/scale_dimension_fdf.out input_examples/font/isometric2/u.txt input_examples/modified/isometric2_u_23.txt

*/