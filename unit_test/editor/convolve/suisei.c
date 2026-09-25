#include "convolve.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_table_fdf	table_c;
	size_t		ker_dim;
	int			output_fd;
	char		*input_dir = "unit_test/editor/convolve/suisei/figlet.txt";
	char		*output_dir_1 = "unit_test/editor/convolve/suisei/scale_dim.txt";
	char		*output_dir_2 = "unit_test/editor/convolve/suisei/convolve.txt";
	t_matrix	ker;

	ker_dim = 5;
	ker.arr = gaussian_kernel(ker_dim / 2, 1, 1);
	write(1, ">>> ", 4);
	ft_putnbr_fd((int)(f_sum(ker.arr, 25) * 10000), 1, "0123456789", 1);
	write(1, "\n", 1);
	table_a = open_table_fdf_file(input_dir, NULL,
			parse_ascii_line_cheche01, false);
	scale_multiplication_fdf(&table_a, 10, HEIGHT);
	table_b = scale_dimension_fdf(&table_a, 3, 3);

	output_fd = open_dir_file(output_dir_1, NULL, APPEND);
	write_table_ascii_cheche01(output_fd, &table_b, HEIGHT);
	close(output_fd);

	table_c = convolve_fdf(&table_b, ker.arr, ker_dim);
	output_fd = open_dir_file(output_dir_2, NULL, APPEND);
	write_table_ascii_cheche01(output_fd, &table_c, HEIGHT);
	close(output_fd);

	free(ker.arr);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_table_fdf(&table_c);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/convolve/suisei.out
*/
