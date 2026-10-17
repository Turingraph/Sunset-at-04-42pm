#include"paint.h"

int	conway_test(const t_table_fdf *dst, size_t index)
{
	if (dst->arr[index] <= 0)
		return (-1 * (count_neighbor_fdf(dst, index, 0) + 1));
	return ((count_neighbor_fdf(dst, index, 0) + 1));
}

int	cell_metric_positive(const t_table_fdf *dst, size_t index)
{
	if (dst->arr[index] <= 0)
		return (-1 * dst->arr[index]);
	return (dst->arr[index]);
}

int	main(void)
{
	char	*file_a = "a.fdf";
	size_t	length_a = 98;
	int	correct_a[] = {
0,	0,	1,	3,	3,	4,	3,	4,	4,	3,	1,	0,	0,	0,
0,	1,	3,	5,	6,	6,	6,	6,	6,	5,	3,	1,	0,	0,
1,	3,	5,	7,	8,	7,	6,	7,	7,	7,	5,	3,	1,	0,
3,	5,	7,	8,	8,	8,	7,	7,	6,	7,	6,	5,	3,	1,
2,	4,	5,	5,	5,	5,	5,	5,	4,	5,	4,	4,	2,	1,
2,	3,	3,	3,	3,	3,	3,	3,	2,	2,	2,	3,	2,	1,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0
};

	char	*file_b = "b.fdf";
	size_t	length_b = 63;
	int	correct_b[] = {
		3,	5,	3,	4,	3,	5,	5,	3,	2,
		5,	8,	5,	6,	5,	7,	6,	3,	2,
		5,	8,	5,	6,	5,	7,	7,	4,	2,
		5,	8,	5,	6,	5,	7,	6,	3,	2,
		3,	5,	3,	4,	3,	5,	5,	3,	2,
		2,	3,	2,	2,	2,	3,	3,	2,	1,
		0,	0,	0,	0,	0,	0,	0,	0,	0,
		};
	char	*file_c = "c.fdf";
	size_t	length_c = 70;
	int	correct_c[] = {
		1,	3,	4,	5,	4,	3,	3,	4,	3,	2,
		3,	5,	7,	8,	6,	5,	4,	4,	3,	2,
		3,	6,	8,	8,	5,	3,	2,	4,	4,	2,
		3,	5,	7,	8,	6,	5,	4,	4,	3,	2,
		1,	3,	4,	5,	4,	3,	3,	4,	3,	2,
		0,	1,	2,	3,	3,	3,	3,	3,	2,	1,
		0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		};
	size_t	y = 0;
	size_t	max_score = 3;
	char	*input_dir = "test/input/table/01_ascii_to_fdf/";
	t_table_fdf	table;

	// a
	table = open_table_fdf_file(file_a, input_dir, parse_fdf_line_bw, false);
	paint_space(&table, HEIGHT, conway_test);
	paint_space(&table, HEIGHT, cell_metric_positive);
	scale_addition_fdf(&table, -1, HEIGHT);
	scale_relu_fdf(&table, -1, 0, 0);
	if (table.col * table.row == length_a
		&& compare_intarr(table.arr, correct_a, length_a) == 0)
		y += 1;
	else
		write(1, "a false\n", 8);
	// write_table_fdf(1, &table, 1, HEIGHT_ONLY);
	free_table_fdf(&table);

	// b
	table = open_table_fdf_file(file_b, input_dir, parse_fdf_line_bw, false);
	paint_space(&table, HEIGHT, conway_test);
	paint_space(&table, HEIGHT, cell_metric_positive);
	scale_addition_fdf(&table, -1, HEIGHT);
	scale_relu_fdf(&table, -1, 0, 0);
	if (table.col * table.row == length_b
		&& compare_intarr(table.arr, correct_b, length_b) == 0)
		y += 1;
	else
		write(1, "b false\n", 8);
	free_table_fdf(&table);

	// c
	table = open_table_fdf_file(file_c, input_dir, parse_fdf_line_bw, false);
	paint_space(&table, HEIGHT, conway_test);
	paint_space(&table, HEIGHT, cell_metric_positive);
	scale_addition_fdf(&table, -1, HEIGHT);
	scale_relu_fdf(&table, -1, 0, 0);
	if (table.col * table.row == length_c
		&& compare_intarr(table.arr, correct_c, length_c) == 0)
		y += 1;
	else
		write(1, "c false\n", 8);
	free_table_fdf(&table);

	write_total_score(y, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/count_neighbor.out

*/
