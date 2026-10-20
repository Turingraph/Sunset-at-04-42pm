#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 200;
	dst.rgba_start.r = 70;
	dst.rgba_start.g = 75;
	dst.rgba_start.b = 113;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 124;
	dst.rgba_end.g = 213;
	dst.rgba_end.b = 199;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(n)
// space: O(1)
bool	is_fdf_name(const char *str)
{
	size_t	len;

	len = str_length(str);
	if (len < 5
		|| str[len - 1] != 'f'
		|| str[len - 2] != 'd'
		|| str[len - 3] != 'f'
		|| str[len - 4] != '.')
		return (false);
	return (true);
}

int	main(int len, char **str)
{
	t_fdf_table		table;
	t_fdf_proj2d			output;
	t_style_render	style;

	if (len < 2 || is_fdf_name(str[1]) == false)
		return (0);
	table = load_fdf_table_file(str[1], NULL, parse_decimal_rgba, true);
	if (table.col * table.row == 0)
	{
		write(1, "File might be invalid and/or Malloc returns NULL.\n", 51);
		destroy_fdf_table(&table);
		return (0);
	}
	style.thickness = 1;
	style.shape2d = E_LINE;
	color_cells_gradient(&table, init_gradient(), true);
	output = create_fdf_proj2d(&table, proj2d_isometric, 0.5);
	view_fdf(&output, style, rgba32_from_char(255, 255, 255, 255));
	destroy_fdf_table(&table);
	destroy_fdf_proj2d(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all 

./test/out/visualize/window/fdf.out corpus/fdf/elem-fract.fdf

*/
