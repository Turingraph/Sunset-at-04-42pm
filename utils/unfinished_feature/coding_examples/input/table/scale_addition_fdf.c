#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	int			x;
	bool		is_int;

	if (len < 4)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	is_int = true;
	x = f_atoi(str[3], &is_int, "0123456789", f_strlen(str[3]));
	if (is_int == false)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	write(1, ">>> ", 4);
	ft_putnbr_fd(x, 1, "0123456789", 2);
	write(1, "\n", 1);
	scale_addition_fdf(&table, x, HEIGHT);
	write_table_ascii_cheche01(output, (const t_table_fdf *)&table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/input/table/scale_addition_fdf.out input_examples/modified/isometric2_t_null.txt input_examples/modified/isometric2_t_minus.txt -10

*/
