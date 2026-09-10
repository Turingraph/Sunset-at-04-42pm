#include"triangle_arr.h"

int	main(int len, char **str)
{
	t_prism		output;
	t_table_fdf	table;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	output = table_to_prism((const t_table_fdf *)&table, 30, true, PRISM_MODE2);
	free_table_fdf(&table);
	write(1, "*** output.arr ***\n", 20);
	write_triangle_arr(1, (const t_triangle_arr *)&output.faces);
	write(1, "*** meta data (face) ***\n", 26);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output.faces);
	write(1, "*** meta data (edge) ***\n", 26);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output.edges);
	free_prism(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/triangle_arr/fdf_prism.out input_examples/fdf/pyramide.fdf
...
*** meta data ***
src->length = 1472
src->capacity = 1472
src->width_x = 16
src->width_y = 23
src->width_z = 78
==1752980== 
==1752980== HEAP SUMMARY:
==1752980==     in use at exit: 0 bytes in 0 blocks
==1752980==   total heap usage: 6,115 allocs, 6,115 frees, 476,070 bytes allocated
==1752980== 
==1752980== All heap blocks were freed -- no leaks are possible
==1752980== 
==1752980== For lists of detected and suppressed errors, rerun with: -s
==1752980== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/