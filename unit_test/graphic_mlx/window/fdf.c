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

	len = f_strlen(str);
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
	t_table_fdf		table;
	t_fdf			output;
	t_artstyle32	style;

	if (len < 2 || is_fdf_name(str[1]) == false)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	if (table.col * table.row == 0)
	{
		write(1, "File might be invalid and/or Malloc returns NULL.\n", 51);
		free_table_fdf(&table);
		return (0);
	}
	style.background_color = f_rgba_to_int32(255, 255, 255, 255);
	style.line_thickness = 1;
	style.artists = E_PICASSO;
	color_cells_gradient(&table, init_gradient(), true);
	output = init_fdf(&table, projection_isometric, 0.5);
	view_fdf(&output, style);
	free_table_fdf(&table);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/window/fdf.out input_examples/fdf/elem-fract.fdf

*/
