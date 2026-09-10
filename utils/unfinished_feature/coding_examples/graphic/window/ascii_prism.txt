#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 100;
	dst.rgba_start.r = 42;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 72;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_prism		output;
	t_table_fdf	table;


	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	color_cells_gradient(&table, init_gradient(), true, NULL);
	output = table_to_prism((const t_table_fdf *)&table, 30, true, PRISM_CROSS);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&(output.faces));
	view_calligraphy(&output, f_rgba_to_int32(253, 240, 213, 255));
	write_triangle_arr_meta(1, (const t_triangle_arr *)&(output.faces));
	free_table_fdf(&table);
	free_prism(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/window/ascii_prism.out input_examples/font/42.txt

==710985== LEAK SUMMARY:
==710985==    definitely lost: 0 bytes in 1 blocks
==710985==    indirectly lost: 0 bytes in 0 blocks
==710985==      possibly lost: 6,211,024 bytes in 43,929 blocks
==710985==    still reachable: 11,818,640 bytes in 16,205 blocks
==710985==                       of which reachable via heuristic:
==710985==                         newarray           : 768,888 bytes in 9 blocks
==710985==                         multipleinheritance: 7,808 bytes in 15 blocks
==710985==         suppressed: 88 bytes in 3 blocks
==710985== 
==710985== For lists of detected and suppressed errors, rerun with: -s
==710985== ERROR SUMMARY: 970209 errors from 36336 contexts (suppressed: 1 from 1)
zsh: segmentation fault (core dumped)  valgrind --leak-check=full --show-leak-kinds=all  input_examples/font/42.txt
*/