#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	scale_relu_fdf(&table, -1, 5, 0);
	scale_relu_fdf(&table, 10, 200, 88);
	write_table_ascii_cheche01(output, (const t_table_fdf *)&table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
./coding_examples/bin/input/table/scale_relu_fdf.out input_examples/modified/rozzo_b.txt input_examples/modified/rozzo_b_relu.txt

./coding_examples/bin/input/table/scale_relu_fdf.out input_examples/modified/isometric2_a_40_40.txt input_examples/modified/isometric2_a_relu.txt

*/
