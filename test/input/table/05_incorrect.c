#include"table.h"

int	main(void)
{
	size_t			i;
	size_t			score;
	size_t			max_score = 13;
	t_table_fdf     table;
	char			*arr[] = {
		"10-2.fdf",
		"10-70.fdf",
		"20-60.fdf",
		"42.fdf",
		"ufo.fdf",
		"10-2",
		"10-2.txt",
		"50-4.fdf",
		"100-6.fdf",
		"basictest.fdf",
		"convolution_9.fdf",
		"t1.fdf",
		"t2.fdf"
	};
	char	*src_dir = "test/input/table/05_incorrect/";

	score = 0;
	i = 0;
	while (i < max_score)
	{
		table = open_table_fdf_file(arr[i], src_dir, parse_decimal_bw, false);
		write_table_fdf(1, &table, 1, HEIGHT_ONLY);
		if (table.col * table.row == 0)
			score += 1;
		else
		{
			write(1, "Incorrect: ", 12);
			write(1, arr[i], f_strlen(arr[i]));
			write(1, "\n", 1);
		}
		destroy_table_fdf(&table);
		i += 1;
	}
	write_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/input/table/05_incorrect.out
*/
