#include "convolve.h"

int	main(void)
{
	t_fdf_table	table_x;
	t_fdf_table	table_y;
	t_fdf_table	table_z;
	char		*dir_input = "test/paint/convolve/conway_x/";
	char		*dir_expect = "test/paint/convolve/conway_y/";
	char		*arr[] = {
		"oscillators_1",
		"oscillators_2",
		"oscillators_3",
		"spaceship",
		"stilllife_1",
		"stilllife_2",
		"stilllife_3",
		"stilllife_4",
	};
	size_t	  i;
	size_t	  score = 0;
	size_t	  length = 7;	// max = 24
	char *file_name;

	i = 0;
	while (i < length)
	{
		file_name = concat_str(dir_expect, arr[i]);
		table_y = load_fdf_table(file_name,
				FDF_FORMAT_ASCII_A, false);
		bool_fdf_table(&table_y, true);
		free(file_name);
		file_name = concat_str(dir_input, arr[i]);
		table_x = load_fdf_table(file_name,
				FDF_FORMAT_ASCII_A, false);
		table_z = conway_fdf_table(&table_x, 3, "000100000", "001100000");
		// relu_fdf_table(&table_z, -10, -1, 1);
		abs_fdf_table(&table_z);
		// write_fdf_table(1, &table_z, FDF_HEIGHT, FDF_FORMAT_DECIMAL_BW);
		bool_fdf_table(&table_z, true);
		free(file_name);
		if (table_z.row == table_y.row && table_z.col == table_y.col
			&& assert_intarr(table_z.arr, table_y.arr, table_z.col * table_z.row) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			write_int(i, 1, "0123456789", 1);
			write(1, "\t", 1);
			write_int(table_z.col, 1, "0123456789", 1);
			write(1, "\t", 1);
			write_int(table_y.col, 1, "0123456789", 1);
			write(1, "\n", 1);
			// scale_fdf_table(&table_z, 30, FDF_HEIGHT);
			write_fdf_table(1, &table_z, FDF_HEIGHT, FDF_FORMAT_DECIMAL_BW);
		}
		destroy_fdf_table(&table_x);
		destroy_fdf_table(&table_y);
		destroy_fdf_table(&table_z);
		i += 1;
	}
	write_score(score, length);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/convolve/conway.out
*/