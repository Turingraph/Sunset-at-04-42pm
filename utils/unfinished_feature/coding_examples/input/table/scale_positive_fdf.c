#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_bw, false);
	scale_positive_fdf(&table);
	write_table_fdf(output, (const t_table_fdf *)&table, 1, HEIGHT_ONLY);
	free_table_fdf(&table);
	return (0);
}

/*
./coding_examples/bin/input/table/scale_positive_fdf.out input_examples/fdf/10-70.fdf input_examples/modified/10-70.fdf
*/