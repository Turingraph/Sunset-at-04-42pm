#include"paint.h"

bool	boundary_test(const t_table_fdf *dst, size_t index)
{
	return (is_boundary_fdf(dst, index, 0));
}

/*
0 ,  0 ,  0 ,  0 ,  99,  0 ,  99,  99,  99,  0 ,  0 ,  0 ,  0 ,  0,
0 ,  0 ,  0 ,  99,  99,  99,  0 ,  99,  99,  99,  0 ,  0 ,  0 ,  0,
0 ,  0 ,  99,  99,  69,  99,  99,  0 ,  99,  99,  99,  0 ,  0 ,  0,
0 ,  99,  99,  69,  69,  69,  99,  99,  99,  99,  99,  99,  0 ,  0,
99,  99,  99,  99,  99,  99,  99,  99,  99,  0 ,  99,  99,  99,  0,
0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0,
0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0,
*/

int	main(void)
{
	char	*file_a = "a.fdf";
	size_t	length_a = 98;
	int	correct_a[] = {
0,	0,	0,	0,	99,	0,	99,	99,	99,	0,	0,	0,	0,	0,
0,	0,	0,	99,	99,	99,	0,	99,	99,	99,	0,	0,	0,	0,
0,	0,	99,	99,	69,	99,	99,	0,	99,	99,	99,	0,	0,	0,
0,	99,	99,	69,	69,	69,	99,	99,	99,	99,	99,	99,	0,	0,
99,	99,	99,	99,	99,	99,	99,	99,	99,	0,	99,	99,	99,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,};
	char	*file_b = "b.fdf";
	size_t	length_b = 63;
	int	correct_b[] = {
99,	99,	99,	0,	99,	99,	99,	99,	0,
99,	69,	99,	0,	99,	99,	99,	99,	0,
99,	69,	99,	0,	99,	99,	0,	0,	0,
99,	69,	99,	0,	99,	99,	99,	99,	0,
99,	99,	99,	0,	99,	99,	99,	99,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,
		};
	char	*file_c = "c.fdf";
	size_t	length_c = 70;
	int	correct_c[] = {
0,	0,	99,	99,	99,	99,	99,	99,	99,	0,
0,	99,	99,	69,	99,	0,	0,	99,	99,	0,
99,	99,	69,	69,	99,	0,	0,	0,	0,	0,
0,	99,	99,	69,	99,	0,	0,	99,	99,	0,
0,	0,	99,	99,	99,	99,	99,	99,	99,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		};
	size_t	y = 0;
	size_t	max_score = 3;
	char	*input_dir = "test/input/table/01_ascii_to_fdf/";
	t_table_fdf	table;

	// a
	table = open_table_fdf_file(file_a, input_dir, parse_decimal_bw, false);
	set_cells_color(&table, 99, HEIGHT, boundary_test);
	if (table.col * table.row == length_a
		&& compare_intarr(table.arr, correct_a, length_a) == 0)
		y += 1;
	free_table_fdf(&table);

	// b
	table = open_table_fdf_file(file_b, input_dir, parse_decimal_bw, false);
	set_cells_color(&table, 99, HEIGHT, boundary_test);
	if (table.col * table.row == length_b
		&& compare_intarr(table.arr, correct_b, length_b) == 0)
		y += 1;
	free_table_fdf(&table);

	// c
	table = open_table_fdf_file(file_c, input_dir, parse_decimal_bw, false);
	set_cells_color(&table, 99, HEIGHT, boundary_test);
	if (table.col * table.row == length_c
		&& compare_intarr(table.arr, correct_c, length_c) == 0)
		y += 1;
	free_table_fdf(&table);

	write_total_score(y, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/boundary.out

*/
