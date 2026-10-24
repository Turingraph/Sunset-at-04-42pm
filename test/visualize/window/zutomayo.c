#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 0;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 0;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_timeleft()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_RED;
	dst.input_start = 66 * 3 / 2;
	dst.input_end = 86 * 3 / 2;
	dst.rgba_start.r = 72;
	dst.rgba_start.g = 33;
	dst.rgba_start.b = 86;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 114;
	dst.rgba_end.g = 40;
	dst.rgba_end.b = 70;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_studyme()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 20;
	dst.rgba_start.r = 66;
	dst.rgba_start.g = 54;
	dst.rgba_start.b = 118;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 204;
	dst.rgba_end.g = 131;
	dst.rgba_end.b = 240;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_fdf_table		table;
	t_fdf_proj2d	output;
	t_style_render	style;

	if (len < 2)
		return (0);
	table = load_fdf_table(str[1], FDF_FORMAT_ASCII_A, true);
	if (table.col * table.row == 0)
	{
		destroy_fdf_table(&table);
		return (0);
	}
	style.thickness = 3;
	style.shape2d = SHAPE2D_RECTANGLE;
	color_cells_gradient(&table, init_ztmy_studyme(), true);
	color_cells_gradient(&table, init_ztmy_timeleft(), true);
	scale_fdf_table(&table, 1.0 / 3.0, FDF_HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = create_fdf_proj2d(&table, NULL, 1.0);
	view_fdf(&output, style, rgba32_from_char(0, 0, 0, 255));
	destroy_fdf_table(&table);
	destroy_fdf_proj2d(&output);
	return (0);
}

/*
valgrind --tool=callgrind 
./test/out/visualize/window/zutomayo.out test/paint/convolve/input_ascii/zutomayo_isometric2.txt
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/zutomayo.out test/paint/convolve/input_ascii/zutomayo_isometric2.txt
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/window/zutomayo.out test/paint/convolve/input_ascii_02/zutomayo_isometric2.txt

==2638489== 
==2638489== LEAK SUMMARY:
==2638489==    definitely lost: 0 bytes in 1 blocks
==2638489==    indirectly lost: 0 bytes in 0 blocks
==2638489==      possibly lost: 0 bytes in 0 blocks
==2638489==    still reachable: 317,899 bytes in 3,104 blocks
==2638489==         suppressed: 56 bytes in 2 blocks
==2638489== 
==2638489== For lists of detected and suppressed errors, rerun with: -s
==2638489== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/
