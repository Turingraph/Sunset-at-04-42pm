#include"table.h"

int	main(void)
{
	int				fdf_dst;
	size_t			i;
	size_t			length = 25;
	t_table_fdf		table;
	char			*arr[] = {
		"100-6.fdf",
		"20-60.fdf",
		"basictest.fdf",
		"elem.fdf",
		"julia.fdf",
		"pentenegpos.fdf",
		"prism_pyramid.fdf",
		"pyramide.fdf",
		"10-2.fdf",
		"42.fdf",
		"convolution_9.fdf",
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
	char	*src_dir = "input_examples/fdf/";
	char	*dst_dir = "unit_test/input/table/02_tab/";

	i = 0;
	while (i < length)
	{
		table = open_table_fdf_file(arr[i], src_dir, parse_fdf_line_bw, false);
		scale_positive_fdf(&table);
		fdf_dst = open_dir_file(arr[i], dst_dir, E_WRITE);
		if(fdf_dst > -1)
		{
			write(1, "\n*** ", 5);
			write(1, arr[i], f_strlen(arr[i]));
			write(1, " ***\n", 5);
			write_table_fdf(1, &table, 3, HEIGHT_ONLY);
			write_table_fdf(fdf_dst, &table, 1, HEIGHT_ONLY);
		}
		else
			warning_file_not_exists(arr[i]);
		free_table_fdf(&table);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/table/02_tab.out

*/
