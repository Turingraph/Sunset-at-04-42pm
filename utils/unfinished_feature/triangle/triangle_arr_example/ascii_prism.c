#include"triangle_arr.h"

int	main(int len, char **str)
{
	t_prism		output;
	t_table_fdf	table;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	output = table_to_prism((const t_table_fdf *)&table, 30, true, PRISM_CROSS);
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
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/triangle_arr/ascii_prism.out input_examples/line/islamic_gauss.txt
...
(236, 238, -31),(237, 238, -31),(237, 237, -31),0x00000000
(237, 237, -31),(238, 237, 000),(238, 238, -31),0x00000000
(000, 239, -31),(000, 238, -31),(001, 238, -31),0x00000000
(000, 239, -31),(001, 239, -31),(001, 238, -31),0x00000000
*** meta data (face) ***
src->length = 177290
src->capacity = 228484
src->width_x = 0
src->width_y = 0
src->width_z = 0
*** meta data (edge) ***
src->length = 94208
src->capacity = 131072
src->width_x = 0
src->width_y = 0
src->width_z = 0
==1812225== 
==1812225== HEAP SUMMARY:
==1812225==     in use at exit: 0 bytes in 0 blocks
==1812225==   total heap usage: 1,271,654 allocs, 1,271,654 frees, 70,029,706 bytes allocated
==1812225== 
==1812225== All heap blocks were freed -- no leaks are possible
==1812225== 
==1812225== For lists of detected and suppressed errors, rerun with: -s
==1812225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/triangle_arr/ascii_prism.out input_examples/line/mondrian_int.txt
...
(141, 143, -40),(141, 142, -40),(142, 142, -40),0x00000000
(141, 143, -40),(142, 143, -40),(142, 142, -40),0x00000000
(142, 143, -40),(142, 142, -40),(143, 142, -40),0x00000000
(142, 143, -40),(143, 143, -40),(143, 142, -40),0x00000000
*** meta data (face) ***
src->length = 113436
src->capacity = 164164
src->width_x = 0
src->width_y = 0
src->width_z = 0
*** meta data (edge) ***
src->length = 77184
src->capacity = 131072
src->width_x = 0
src->width_y = 0
src->width_z = 0
==1813430== 
==1813430== HEAP SUMMARY:
==1813430==     in use at exit: 0 bytes in 0 blocks
==1813430==   total heap usage: 895,271 allocs, 895,271 frees, 52,485,262 bytes allocated
==1813430== 
==1813430== All heap blocks were freed -- no leaks are possible
==1813430== 
==1813430== For lists of detected and suppressed errors, rerun with: -s
==1813430== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/