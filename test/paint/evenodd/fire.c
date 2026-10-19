#include"evenodd.h"

// time : O(1)
// space: O(1)
t_gradient	init_deep_wood()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = -5;
	dst.input_end = 0;
	dst.rgba_start.r = 70;
	dst.rgba_start.g = 75;
	dst.rgba_start.b = 113;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 0;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_popart(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 15;
	dst.input_end = 30;
	dst.rgba_start.r = 34;
	dst.rgba_start.g = 79;
	dst.rgba_start.b = 112;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 163;
	dst.rgba_end.g = 196;
	dst.rgba_end.b = 202;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_feeling_blue(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 10;
	dst.rgba_start.r = 255;
	dst.rgba_start.g = 81;
	dst.rgba_start.b = 58;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255;
	dst.rgba_end.g = 189;
	dst.rgba_end.b = 13;
	dst.rgba_end.a = 255;
	return (dst);
}

bool	is_3d_pythagoras(const t_fdf_table *dst, size_t index)
{
	if (cell_metric_pythagoras_3d(dst, index) % 2 == 1)
		return (true);
	return (false);
}

int	main(void)
{
	t_fdf_table		table;
	t_fdf_table		table2;
	t_fdf_proj2d			output;
	t_render_style	style;
	size_t			i;

	table = create_fdf_table(161, 161, true);
	table2 = create_fdf_table(161, 161, true);
	paint_space(&table, HEIGHT, cell_metric_amgm_inequality);
	paint_space(&table2, HEIGHT, cell_metric_pythagoras);
	set_cells_color(&table, 0, HEIGHT, is_3d_pythagoras);
	scale_relu_fdf(&table, -10000, 0, 0);
	i = 0;
	while (i < table.row * table.col)
	{
		if (table.arr[i] == 0)
			table.arr[i] = -1 * (table2.arr[i] % 5);
		i += 1;
	}
	style.thickness = 2;
	style.shape_2d = E_CIRCLE;
	color_cells_gradient(&table, init_popart(), true);
	color_cells_gradient(&table, init_feeling_blue(), true);
	color_cells_gradient(&table, init_deep_wood(), true);
	output = create_fdf_proj2d(&table, projection_cabinet, 0.6);
	view_fdf(&output, style, rgba32_from_char(0, 0, 0, 255));
	destroy_fdf_table(&table2);
	destroy_fdf_table(&table);
	destroy_fdf_proj2d(&output);
	return (0);
}


/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/evenodd/fire.out
*/
