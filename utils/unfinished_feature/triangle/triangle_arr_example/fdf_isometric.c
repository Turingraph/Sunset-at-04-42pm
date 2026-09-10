#include"triangle_arr.h"

int	main(int len, char **str)
{
	t_triangle_arr	output;
	t_table_fdf		table;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	output = all_triangle_faces((const t_table_fdf *)&table, ISOMETRIC);
	update_width_of_triangle_arr(&output, 0);
	update_width_of_triangle_arr(&output, 1);
	update_width_of_triangle_arr(&output, 2);
	center_triangle_arr(&output, 0);
	free_table_fdf(&table);
	write(1, "*** output.arr ***\n", 20);
	write_triangle_arr(1, (const t_triangle_arr *)&output);
	write(1, "*** meta data ***\n", 19);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output);
	free_triangle_arr(&output, 0);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/triangle_arr/fdf_isometric.out input_examples/fdf/pyramide.fdf
...
*** meta data ***
src->length = 1654
src->capacity = 1654
src->width_x = 26
src->width_y = 32
src->width_z = 9
==1752684== 
==1752684== HEAP SUMMARY:
==1752684==     in use at exit: 0 bytes in 0 blocks
==1752684==   total heap usage: 6,646 allocs, 6,646 frees, 263,198 bytes allocated
==1752684== 
==1752684== All heap blocks were freed -- no leaks are possible
==1752684== 
==1752684== For lists of detected and suppressed errors, rerun with: -s
==1752684== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/