#include"triangle_pair.h"

int	main(int len, char **str)
{
	t_table_fdf		table;
	int				row;
	int				col;
	int				mod2;
	size_t			index;
	bool			is_int;
	bool			is_v;
	t_triangle_arr	output;

	if (len < 4)
		return (0);
	is_int = true;
	row = f_atoi(str[3], &is_int, "0123456789", f_strlen(str[3]));
	col = f_atoi(str[2], &is_int, "0123456789", f_strlen(str[2]));
	mod2 = 0;
	if (len > 4)
		mod2 = f_atoi(str[4], &is_int, "0123456789", f_strlen(str[4]));
	is_v = true;
	if (mod2 % 2 == 1)
		is_v = false;
	if (is_int == false)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, is_v);
	if (table.arr == NULL)
		return (0);
	row = (int)f_interval((float)row, 0.0, (float)(table.row - 1));
	col = (int)f_interval((float)col, 0.0, (float)(table.col - 1));
	write(1, "\nwrite_2d_index\n", 17);
	write_2d_index(table.col, row, col);
	index = row * table.col + col;
	write(1, "\nwrite_triangle_pair_graphic\n", 30);
	write_triangle_pair_graphic(&table, (size_t)index);
	output = f_fdf_edge((const t_table_fdf *)&table, index, EDGE_X, false);
	free_table_fdf(&table);
	write(1, "\nwrite_triangle_arr\n", 21);
	write_triangle_arr(1, (const t_triangle_arr *)&output);
	write(1, "\nwrite_triangle_arr_meta\n", 26);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output);
	free_triangle_arr(&output, 0);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/triangle_pair/fdf_edge_x.out input_examples/fdf/prism_pyramid.fdf 0 0
*/