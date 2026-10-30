#include"convolve.h"

int	main(void)
{
	t_fdf_table	table_a;
	t_fdf_table	table_b;
	size_t		dim;
	int			output;
	char		*dst_dir = "test/paint/convolve/fdf_k/";
	char		*src_dir = "corpus/fdf/";
	char			*arr[] = {
		"100-6.fdf",			// 0
		"20-60.fdf",			// 1
		"basictest.fdf",		// 2
		"elem.fdf",				// 3
		"pentenegpos.fdf",		// 4
		"prism_pyramid.fdf",	// 5
		"pyramide.fdf",			// 6
		"10-2.fdf",				// 7
		"42.fdf",				// 8
		"convolution_9.fdf",	// 9
		"elem2.fdf",
		"elem-fract.fdf",
		"large_plat.fdf",
		"plat.fdf",
		"pylone.fdf",
		"t1.fdf",
		"10-70.fdf",
		"50-4.fdf",
		"elem-col.fdf",
		"empty.fdf",
		"mars.fdf",
		"pnp_flat.fdf",
		"pyra.fdf",
		"t2.fdf",
	};
	size_t	  i;
	size_t	  length = 24;	// max = 24
	char	*file_name;
	t_matrix	kernel;

	dim = 7;
	kernel.col = dim;
	kernel.row = dim;
	kernel.arr = NULL;
	i = 0;
	while (i < length)
	{
		output = debug_load_file(arr[i], dst_dir, FILE_WRITE);
		file_name = concat_str(src_dir, arr[i]);
		table_a = load_fdf_table(file_name,
				FDF_FORMAT_DECIMAL_BW, false);
		free(file_name);
		table_b = convolve_fdf_table(&table_a, kernel, true);
		write_fdf_table(output, &table_b, 1, FDF_FORMAT_DECIMAL_BW);
		destroy_fdf_table(&table_a);
		destroy_fdf_table(&table_b);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/convolve/fdf_k.out

start:  15:37:40
finish: 15:43:12
*/
