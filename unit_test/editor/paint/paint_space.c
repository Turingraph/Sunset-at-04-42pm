#include"paint.h"

static void	write_with_paint_space(float scale, const char *file_name,
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
	if (scale > 0)
		scale_multiplication_fdf(table, scale, HEIGHT);
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
	write_with_paint_space(0, "addsub.txt", &table, cell_metric_addsub);
	write_with_paint_space(0, "amgm_inequality.txt", &table, cell_metric_amgm_inequality);
	write_with_paint_space(0, "pythagorus_3d.txt", &table, cell_metric_pythagoras_3d);
	write_with_paint_space(1.0 / 20.0, "fermat_theorem.txt", &table, cell_metric_fermat_theorem);
	write_with_paint_space(0, "min_xy.txt", &table, cell_metric_min_xy);
	write_with_paint_space(0, "mincos.txt", &table, cell_metric_mincos);
	write_with_paint_space(0, "minecos.txt", &table, cell_metric_minecos);
	write_with_paint_space(0, "max_xy.txt", &table, cell_metric_max_xy);
	write_with_paint_space(0, "root_xyz.txt", &table, cell_metric_root_xyz);
	write_with_paint_space(0, "maxcos.txt", &table, cell_metric_maxcos);
	write_with_paint_space(0, "amgm_inequality_3d.txt", &table, cell_metric_amgm_inequality_3d);
	write_with_paint_space(0, "maxecos.txt", &table, cell_metric_maxecos);
	write_with_paint_space(0, "maxesin.txt", &table, cell_metric_maxesin);
	write_with_paint_space(0, "maxexp.txt", &table, cell_metric_maxesin);
	write_with_paint_space(0, "minexp.txt", &table, cell_metric_minexp);
	write_with_paint_space(0, "max_xyz.txt", &table, cell_metric_max_xyz);
	write_with_paint_space(0, "maxexp.txt", &table, cell_metric_maxexp);
	write_with_paint_space(0, "maxsin.txt", &table, cell_metric_maxsin);
	write_with_paint_space(0, "pythagorus.txt", &table, cell_metric_pythagoras);
	write_with_paint_space(0, "triangle_inequality_3d.txt", &table, cell_metric_triangle_inequality_3d);
	write_with_paint_space(0, "root_xy.txt", &table, cell_metric_root_xy);
	write_with_paint_space(0, "triangle_inequality.txt", &table, cell_metric_triangle_inequality);
	write_with_paint_space(0, "addsub_3d.txt", &table, cell_metric_addsub_3d);
	write_with_paint_space(0, "x_plus_y_square.txt", &table, cell_metric_x_plus_y_square);
	write_with_paint_space(0, "min_xyz.txt", &table, cell_metric_min_xyz);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/paint/paint_space.out
*/