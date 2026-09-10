#include"triangle_arr.h"

int	main(int len, char **str)
{
	t_triangle_arr	output;
	t_table_fdf		table;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
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
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/triangle_arr/ascii_isometric.out input_examples/line/islamic_gauss.txt

...
(116, 238, 001),(116, 237, 001),(117, 237, 001),0x00000000
(116, 238, 001),(117, 238, 001),(117, 237, 001),0x00000000
(117, 237, 001),(117, 238, 001),(118, 238, 001),0x00000000
(117, 237, 001),(118, 237, 000),(118, 238, 001),0x00000000
(118, 238, 001),(118, 237, 000),(119, 237, 000),0x00000000
(118, 238, 001),(119, 238, 000),(119, 237, 000),0x00000000
(-119, 238, 001),(-119, 239, 001),(-118, 239, 001),0x00000000
(-119, 238, 001),(-118, 238, 001),(-118, 239, 001),0x00000000
*** meta data ***
src->length = 113766
src->capacity = 113766
src->width_x = 239
src->width_y = 239
src->width_z = 79
==1747606== 
==1747606== HEAP SUMMARY:
==1747606==     in use at exit: 0 bytes in 0 blocks
==1747606==   total heap usage: 405,140 allocs, 405,140 frees, 15,915,098 bytes allocated
==1747606== 
==1747606== All heap blocks were freed -- no leaks are possible
==1747606== 
==1747606== For lists of detected and suppressed errors, rerun with: -s
==1747606== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/