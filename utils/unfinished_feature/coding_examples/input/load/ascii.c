#include"load.h"

int	main(int len, char **str)
{
	t_load_fdf_arr	dst;

	if (len < 2)
		return (0);
	dst = open_fdf_file(str[1], NULL, parse_ascii_line_cheche01);
	write_load_fdf_arr(1, (const t_load_fdf_arr *)&dst, 1, HEIGHT_ONLY);
	free_load_fdf_arr(&dst);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/input/load/ascii.out input_examples/modified/isometric2_q_null.txt
*/