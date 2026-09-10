#include"load.h"

int	main(int len, char **str)
{
	t_load_fdf_arr	dst;
	int				output;

	if (len < 2)
		return (0);
	output = 1;
	// output = open_dir_file(str[2], NULL, APPEND);
	dst = open_fdf_file(str[1], NULL, parse_fdf_line_rgba);
	write_load_fdf_arr(output, (const t_load_fdf_arr *)&dst, 1, HEIGHT_RGBA);
	free_load_fdf_arr(&dst);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/input/load/fdf.out input_examples/fdf/pyramide.fdf

*/
