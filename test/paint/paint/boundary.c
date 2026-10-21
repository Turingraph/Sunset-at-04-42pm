#include"paint.h"

bool	boundary_test(const t_fdf_table *dst, size_t index)
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
	t_fdf_table	table;

	// a
	table = load_fdf_table(file_a, input_dir, parse_decimal_bw, false);
	set_cells_color(&table, 99, FDF_HEIGHT, boundary_test);
	if (table.col * table.row == length_a
		&& assert_intarr(table.arr, correct_a, length_a) == true)
		y += 1;
	destroy_fdf_table(&table);

	// b
	table = load_fdf_table(file_b, input_dir, parse_decimal_bw, false);
	set_cells_color(&table, 99, FDF_HEIGHT, boundary_test);
	if (table.col * table.row == length_b
		&& assert_intarr(table.arr, correct_b, length_b) == true)
		y += 1;
	destroy_fdf_table(&table);

	// c
	table = load_fdf_table(file_c, input_dir, parse_decimal_bw, false);
	set_cells_color(&table, 99, FDF_HEIGHT, boundary_test);
	if (table.col * table.row == length_c
		&& assert_intarr(table.arr, correct_c, length_c) == true)
		y += 1;
	destroy_fdf_table(&table);

	write_score(y, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/boundary.out

*/
