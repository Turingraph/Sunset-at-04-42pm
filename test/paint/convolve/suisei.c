#include "convolve.h"

int	main(void)
{
	t_fdf_table	table_a;
	t_fdf_table	table_b;
	t_fdf_table	table_c;
	size_t		dim;
	int			output_fd;
	char		*input_dir = "test/paint/convolve/suisei/figlet.txt";
	char		*output_dir_1 = "test/paint/convolve/suisei/scale_dim.txt";
	char		*output_dir_2 = "test/paint/convolve/suisei/convolve.txt";
	t_matrix	ker;

	dim = 5;
	ker = kernel_gauss(5, 1, 1);
	write(1, ">>> ", 4);
	write_int((int)(f_sum(ker.arr, 25) * 10000), 1, "0123456789", 1);
	write(1, "\n", 1);
	table_a = load_fdf_table(input_dir,
			FDF_FORMAT_ASCII_A, false);
	scale_fdf_table(&table_a, 10, FDF_HEIGHT);
	table_b = scale_dim_fdf_table(&table_a, 3, 3);

	output_fd = debug_load_file(output_dir_1, NULL, FILE_WRITE);
	write_fdf_table(output_fd, &table_b, FDF_HEIGHT, FDF_FORMAT_ASCII_A);
	close(output_fd);

	table_c = convolve_fdf_table(&table_b, ker.arr, dim, true);
	output_fd = debug_load_file(output_dir_2, NULL, FILE_WRITE);
	write_fdf_table(output_fd, &table_c, FDF_HEIGHT, FDF_FORMAT_ASCII_A);
	close(output_fd);

	free(ker.arr);
	destroy_fdf_table(&table_a);
	destroy_fdf_table(&table_b);
	destroy_fdf_table(&table_c);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/convolve/suisei.out
*/
