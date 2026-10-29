#include"convolve.h"

int	main(void)
{
	char	*file_a = "a.fdf";
	size_t	length_a = 98;
	int	correct_a[] = {
0,	0,	1,	4,	4,	6,	5,	7,	6,	4,	1,	0,	0,	0,
0,	1,	3,	5,	6,	6,	6,	6,	6,	5,	3,	1,	0,	0,
1,	3,	5,	7,	8,	7,	6,	7,	7,	7,	5,	3,	1,	0,
4,	5,	7,	8,	8,	8,	7,	7,	6,	7,	6,	5,	3,	1,
3,	4,	5,	5,	5,	5,	5,	5,	4,	5,	4,	4,	2,	1,
3,	3,	3,	3,	3,	3,	3,	3,	2,	2,	2,	3,	2,	1,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0
};

	char	*file_b = "b.fdf";
	size_t	length_b = 63;
	int	correct_b[] = {
		8,	8,	5,	6,	5,	8,	8,	5,	3,
		8,	8,	5,	6,	5,	7,	6,	3,	2,
		8,	8,	5,	6,	5,	7,	7,	4,	2,
		8,	8,	5,	6,	5,	7,	6,	3,	2,
		5,	5,	3,	4,	3,	5,	5,	3,	2,
		3,	3,	2,	2,	2,	3,	3,	2,	1,
		0,	0,	0,	0,	0,	0,	0,	0,	0,
		};

	char	*file_c = "c.fdf";
	size_t	length_c = 70;
	int	correct_c[] = {
		1,	4,	6,	8,	7,	6,	6,	7,	5,	3,
		4,	5,	7,	8,	6,	5,	4,	4,	3,	2,
		4,	6,	8,	8,	5,	3,	2,	4,	4,	2,
		4,	5,	7,	8,	6,	5,	4,	4,	3,	2,
		1,	3,	4,	5,	4,	3,	3,	4,	3,	2,
		0,	1,	2,	3,	3,	3,	3,	3,	2,	1,
		0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		};
	size_t	y = 0;
	size_t	max_score = 3;
	char	*input_dir = "test/input/table/01_ascii_to_fdf/";
	t_fdf_table	table;
	t_fdf_table	table_x;
	char	*file_name;
	
	// a
	file_name = concat_str(input_dir, file_a);
	table = load_fdf_table(file_name, FDF_FORMAT_DECIMAL_BW, false);
	free(file_name);
	table_x = count_neighbors_fdf_table(&table, 3);
	if (table_x.col * table_x.row == length_a
		&& assert_intarr(table_x.arr, correct_a, length_a) == true)
		y += 1;
	else
		write(1, "a false\n", 8);
	destroy_fdf_table(&table);
	destroy_fdf_table(&table_x);

	// b
	file_name = concat_str(input_dir, file_b);
	table = load_fdf_table(file_name, FDF_FORMAT_DECIMAL_BW, false);
	free(file_name);
	table_x = count_neighbors_fdf_table(&table, 3);
	if (table_x.col * table_x.row == length_b
		&& assert_intarr(table_x.arr, correct_b, length_b) == true)
		y += 1;
	else
		write(1, "b false\n", 8);
	destroy_fdf_table(&table);
	destroy_fdf_table(&table_x);

	// c
	file_name = concat_str(input_dir, file_c);
	table = load_fdf_table(file_name, FDF_FORMAT_DECIMAL_BW, false);
	free(file_name);
	table_x = count_neighbors_fdf_table(&table, 3);
	if (table_x.col * table_x.row == length_c
		&& assert_intarr(table_x.arr, correct_c, length_c) == true)
		y += 1;
	else
		write(1, "c false\n", 8);
	destroy_fdf_table(&table);
	destroy_fdf_table(&table_x);

	write_score(y, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/convolve/count_neighbor.out

*/
