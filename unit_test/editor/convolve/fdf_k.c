#include"convolve.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	size_t		half_dim;
	int			output;
	char		*dst_dir = "unit_test/editor/convolve/fdf_k/";
	char		*src_dir = "input_examples/fdf/";
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

	half_dim = 3;
	i = 0;
	while (i < length)
	{
		output = open_dir_file(arr[i], dst_dir, E_WRITE);
		table_a = open_table_fdf_file(arr[i], src_dir,
				parse_fdf_line_bw, false);
		table_b = convolve_fdf(&table_a, NULL, half_dim);
		write_table_fdf(output, &table_b, 1, HEIGHT_ONLY);
		free_table_fdf(&table_a);
		free_table_fdf(&table_b);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/convolve/fdf_k.out

*/
