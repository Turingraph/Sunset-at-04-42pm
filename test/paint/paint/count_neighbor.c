#include "paint.h"

static bool	test_conway(const t_fdf_table *dst, size_t index, size_t y, int sign)
{
	if (count_neighbor_fdf_table(dst, index) == y &&
		((sign > 0 &&  dst->arr[index] > 0)
		|| (sign <= 0 &&  dst->arr[index] <= 0)))
		return (true);
	return (false);
}

static bool	test_conway1p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 1, 1));
}

static bool	test_conway2p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 2, 1));
}

static bool	test_conway3p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 3, 1));
}

static bool	test_conway4p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 4, 1));
}

static bool	test_conway5p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 5, 1));
}

static bool	test_conway6p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 6, 1));
}

static bool	test_conway7p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 7, 1));
}

static bool	test_conway8p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 8, 1));
}

static bool	test_conway0p(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 0, 1));
}

static bool	test_conway1m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 1, -1));
}

static bool	test_conway2m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 2, -1));
}

static bool	test_conway3m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 3, -1));
}

static bool	test_conway4m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 4, -1));
}

static bool	test_conway5m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 5, -1));
}

static bool	test_conway6m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 6, -1));
}

static bool	test_conway7m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 7, -1));
}

static bool	test_conway8m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 8, -1));
}

static bool	test_conway0m(const t_fdf_table *dst, size_t index)
{
	return (test_conway(dst, index, 0, -1));
}

static void	conway_test(t_fdf_table *dst)
{
	paint_spots_fdf_table(dst, 1 + 1,  FDF_HEIGHT, test_conway1p);
	paint_spots_fdf_table(dst, 2 + 1,  FDF_HEIGHT, test_conway2p);
	paint_spots_fdf_table(dst, 3 + 1,  FDF_HEIGHT, test_conway3p);
	paint_spots_fdf_table(dst, 4 + 1,  FDF_HEIGHT, test_conway4p);
	paint_spots_fdf_table(dst, 5 + 1,  FDF_HEIGHT, test_conway5p);
	paint_spots_fdf_table(dst, 6 + 1,  FDF_HEIGHT, test_conway6p);
	paint_spots_fdf_table(dst, 7 + 1,  FDF_HEIGHT, test_conway7p);
	paint_spots_fdf_table(dst, 8 + 1,  FDF_HEIGHT, test_conway8p);
	paint_spots_fdf_table(dst, -1 - 1, FDF_HEIGHT, test_conway1m);
	paint_spots_fdf_table(dst, -2 - 1, FDF_HEIGHT, test_conway2m);
	paint_spots_fdf_table(dst, -3 - 1, FDF_HEIGHT, test_conway3m);
	paint_spots_fdf_table(dst, -4 - 1, FDF_HEIGHT, test_conway4m);
	paint_spots_fdf_table(dst, -5 - 1, FDF_HEIGHT, test_conway5m);
	paint_spots_fdf_table(dst, -6 - 1, FDF_HEIGHT, test_conway6m);
	paint_spots_fdf_table(dst, -7 - 1, FDF_HEIGHT, test_conway7m);
	paint_spots_fdf_table(dst, -8 - 1, FDF_HEIGHT, test_conway8m);
	paint_spots_fdf_table(dst, 0 - 1,  FDF_HEIGHT, test_conway0m);
	paint_spots_fdf_table(dst, 0 + 1,  FDF_HEIGHT, test_conway0p);

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
	t_fdf_table	table;
	char	*file_name;
	
	// a
	file_name = concat_str(input_dir, file_a);
	table = load_fdf_table(file_name, FDF_FORMAT_DECIMAL_BW, false);
	free(file_name);
	conway_test(&table);

	abs_fdf_table(&table);
	add_fdf_table(&table, -1, FDF_HEIGHT);
	relu_fdf_table(&table, -1, 0, 0);
	write_fdf_table(1, &table, FDF_HEIGHT, FDF_FORMAT_DECIMAL_BW);
	if (table.col * table.row == length_a
		&& assert_intarr(table.arr, correct_a, length_a) == true)
		y += 1;
	else
		write(1, "a false\n", 8);
	destroy_fdf_table(&table);

	// b
	file_name = concat_str(input_dir, file_b);
	table = load_fdf_table(file_name, FDF_FORMAT_DECIMAL_BW, false);
	free(file_name);
	conway_test(&table);
	abs_fdf_table(&table);
	add_fdf_table(&table, -1, FDF_HEIGHT);
	relu_fdf_table(&table, -1, 0, 0);
	write_fdf_table(1, &table, FDF_HEIGHT, FDF_FORMAT_DECIMAL_BW);
	if (table.col * table.row == length_b
		&& assert_intarr(table.arr, correct_b, length_b) == true)
		y += 1;
	else
		write(1, "b false\n", 8);
	destroy_fdf_table(&table);

	// c
	file_name = concat_str(input_dir, file_c);
	table = load_fdf_table(file_name, FDF_FORMAT_DECIMAL_BW, false);
	free(file_name);
	conway_test(&table);
	abs_fdf_table(&table);
	add_fdf_table(&table, -1, FDF_HEIGHT);
	relu_fdf_table(&table, -1, 0, 0);
	write_fdf_table(1, &table, FDF_HEIGHT, FDF_FORMAT_DECIMAL_BW);
	if (table.col * table.row == length_c
		&& assert_intarr(table.arr, correct_c, length_c) == true)
		y += 1;
	else
		write(1, "c false\n", 8);
	destroy_fdf_table(&table);

	write_score(y, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/count_neighbor.out

*/
