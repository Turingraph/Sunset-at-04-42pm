#include "../../include/sunset442pm.h"

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 14;
	dst.rgba_start.g = 9;
	dst.rgba_start.b = 15;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 14;
	dst.rgba_end.g = 9;
	dst.rgba_end.b = 15;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_timeleft()
{
	t_gradient	dst;

	dst.cell_channel = D7_RED;
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

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 60;
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
	t_table_fdf		table;
	t_fdf			output;
	t_fdf_render	style;
	t_gradient		text_color;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	if (table.col * table.row == 0)
	{
		free_table_fdf(&table);
		return (0);
	}
	style.thickness = 1;
	style.shape_2d = E_RECTANGLE;
	text_color = init_ztmy_studyme();
	text_color.input_end = get_minmax_from_table_fdf(&table, true, HEIGHT) * 3 / 2;
	color_cells_gradient(&table, text_color, true);
	color_cells_gradient(&table, init_ztmy_timeleft(), true);
	scale_multiplication_fdf(&table, 1.0 / 9.0, HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = init_fdf(&table, NULL, 1.0);
	view_fdf(&output, style, f_rgba_to_int32(0, 0, 0, 255));
	// view_fdf(&output, style, f_rgba_to_int32(14, 9, 15, 255));
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --tool=callgrind ./out/fanart/zutomayo/view_truth_in_lie.out fanart/zutomayo/input/convolve.txt
valgrind --leak-check=full --show-leak-kinds=all 
./out/fanart/zutomayo/view_truth_in_lie.out fanart/zutomayo/input/convolve.txt
*/