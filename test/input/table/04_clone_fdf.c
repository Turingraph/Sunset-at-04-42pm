#include"table.h"

int	main(void)
{
	int				fdf_dst;
	size_t			i;
	size_t			score;
	size_t			max_score = 16;
	t_fdf_table     table;
	char			*arr[] = {
		"100-6.fdf",
		"10-70.fdf",
		"42.fdf",
		"basictest.fdf",
		"elem2.fdf",
		"elem.fdf",
		"mars.fdf",
		"plat.fdf",
		"pyra.fdf",
		"20-60.fdf",
		"50-4.fdf",
		"convolution_9.fdf",
		"large_plat.fdf",
		"pentenegpos.fdf",
		"pnp_flat.fdf",
		"pylone.fdf",
	};
	char	*src_dir = "corpus/fdf/";
	char	*dst_dir = "test/input/table/clone_input_fdf/";

	score = 0;
	i = 0;
	while (i < max_score)
	{
		table = load_fdf_table(arr[i], src_dir, parse_decimal_bw, false);
		fdf_dst = load_file_debug(arr[i], dst_dir, FILE_WRITE);
		if (fdf_dst > -1)
		{
			write_fdf_table(fdf_dst, &table, 1, WRITE_DECIMAL_HEIGHT);
			if (assert_file(arr[i], arr[i], src_dir, dst_dir) == true)
				score += 1;
			else
			{
				write(1, "Incorrect: ", 12);
				write(1, arr[i], str_length(arr[i]));
				write(1, "\n", 1);
			}
		}
		else
			write_file_not_exists(arr[i]);
		destroy_fdf_table(&table);
		i += 1;
	}
	write_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/input/table/04_clone_fdf.out
*/
