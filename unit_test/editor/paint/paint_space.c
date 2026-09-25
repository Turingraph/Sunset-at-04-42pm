#include"paint.h"

static void	write_with_paint_space(const char *file_name,
	t_table_fdf *table,
	int (*cell_metric)(const t_table_fdf *dst, size_t index))
{
	int	output;

	output = open_dir_file(file_name,
		"unit_test/editor/paint/input_paint_space/", E_WRITE);
	if (output <= -1 || file_name == NULL)
	{
		if (file_name != NULL)
			write(1, file_name, f_strlen(file_name));
		write(1, " isn't exists\n", 14);
		return ;
	}
	paint_space(table, HEIGHT, cell_metric);
	write_table_ascii_standard(output, table, HEIGHT);
	close(output);
}

int	main(void)
{
	t_table_fdf		table;

	table = init_table_fdf(101, 101, false);
	if (table.arr == NULL)
		return (0);
	write_with_paint_space("addsub.txt", &table, cell_metric_addsub);
	write_with_paint_space("amgm_inequality.txt", &table, cell_metric_amgm_inequality);
	write_with_paint_space("pythagorus_3d.txt", &table, cell_metric_pythagoras_3d);
	write_with_paint_space("fermat_theorem.txt", &table, cell_metric_fermat_theorem);
	write_with_paint_space("max_xyz.txt", &table, cell_metric_max_xyz);
	write_with_paint_space("min_xy.txt", &table, cell_metric_min_xy);
	write_with_paint_space("mincos.txt", &table, cell_metric_mincos);
	write_with_paint_space("minecos.txt", &table, cell_metric_minecos);
	write_with_paint_space("max_xy.txt", &table, cell_metric_max_xy);
	write_with_paint_space("root_xyz.txt", &table, cell_metric_root_xyz);
	write_with_paint_space("maxcos.txt", &table, cell_metric_maxcos);
	write_with_paint_space("amgm_inequality_3d.txt", &table, cell_metric_amgm_inequality_3d);
	write_with_paint_space("maxecos.txt", &table, cell_metric_maxecos);
	write_with_paint_space("maxesin.txt", &table, cell_metric_maxesin);
	write_with_paint_space("maxexp.txt", &table, cell_metric_maxesin);
	write_with_paint_space("minexp.txt", &table, cell_metric_minexp);
	write_with_paint_space("maxexp.txt", &table, cell_metric_maxexp);
	write_with_paint_space("maxsin.txt", &table, cell_metric_maxsin);
	write_with_paint_space("pythagorus.txt", &table, cell_metric_pythagoras);
	write_with_paint_space("triangle_inequality_3d.txt", &table, cell_metric_triangle_inequality_3d);
	write_with_paint_space("root_xy.txt", &table, cell_metric_root_xy);
	write_with_paint_space("triangle_inequality.txt", &table, cell_metric_triangle_inequality);
	write_with_paint_space("addsub_3d.txt", &table, cell_metric_addsub_3d);
	write_with_paint_space("x_plus_y_square.txt", &table, cell_metric_x_plus_y_square);
	write_with_paint_space("min_xyz.txt", &table, cell_metric_min_xyz);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/paint/paint_space.out
*/