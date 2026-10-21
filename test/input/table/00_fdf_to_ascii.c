#include"table.h"

int	main(void)
{
	int				fdf_dst;
	size_t			i;
	size_t			length = 23;
	t_fdf_table		table;
	char			*arr[] = {
		"100-6.fdf",
		"20-60.fdf",
		"basictest.fdf",
		"elem.fdf",
		// "julia.fdf",
		"pentenegpos.fdf",
		"prism_pyramid.fdf",
		"pyramide.fdf",
		"10-2.fdf",
		"42.fdf",
		"convolution_9.fdf",
		"elem2.fdf",
		// "elem-fract.fdf",
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
	char			*arrdst[] = {
		"100-6.txt",
		"20-60.txt",
		"basictest.txt",
		"elem.txt",
		// "julia.txt",
		"pentenegpos.txt",
		"prism_pyramid.txt",
		"pyramide.txt",
		"10-2.txt",
		"42.txt",
		"convolution_9.txt",
		"elem2.txt",
		// "elem-fract.txt",
		"large_plat.txt",
		"plat.txt",
		"pylone.txt",
		"t1.txt",
		"10-70.txt",
		"50-4.txt",
		"elem-col.txt",
		"empty.txt",
		"mars.txt",
		"pnp_flat.txt",
		"pyra.txt",
		"t2.txt",
	};
	char	*src_dir = "corpus/fdf/";
	char	*dst_dir = "test/input/table/00_fdf_to_ascii/";

	i = 0;
	while (i < length)
	{
		table = load_fdf_table(arr[i], src_dir, parse_decimal_bw, false);
		positive_fdf_table(&table);
		fdf_dst = load_file_debug(arrdst[i], dst_dir, FILE_WRITE);
		if(fdf_dst > -1)
		{
			write(1, "\n*** ", 5);
			write(1, arr[i], str_length(arr[i]));
			write(1, " ***\n", 5);
			write_fdf_table(1, &table, 3, WRITE_DECIMAL_HEIGHT);
			write_table_ascii_cheche01(fdf_dst, &table, FDF_HEIGHT);
		}
		else
			write_file_not_exists(arr[i]);
		destroy_fdf_table(&table);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/input/table/00_fdf_to_ascii.out

*/
