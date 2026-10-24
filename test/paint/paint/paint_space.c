#include"paint.h"

static void	write_with_paint_aura_fdf_table(float scale, const char *file_name,
	t_fdf_table *table,
	int (*aura)(const t_fdf_table *dst, size_t index))
{
	int	output;

	output = debug_load_file(file_name,
		"test/paint/paint/input_paint_aura_fdf_table/", FILE_WRITE);
	if (output <= -1 || file_name == NULL)
	{
		if (file_name != NULL)
			write(1, file_name, str_length(file_name));
		write(1, " isn't exists\n", 14);
		return ;
	}
	if (scale > 0)
		scale_fdf_table(table, scale, FDF_HEIGHT);
	paint_aura_fdf_table(table, FDF_HEIGHT, aura);
	write_fdf_table(output, table, FDF_HEIGHT, FDF_FORMAT_ASCII_B);
	close(output);
}

int	main(void)
{
	t_fdf_table		table;

	table = create_fdf_table(101, 101, false);
	if (table.arr == NULL)
		return (0);
	write_with_paint_aura_fdf_table(0, "addsub.txt", &table, aura_addsub);
	write_with_paint_aura_fdf_table(0, "amgm_inequality.txt", &table, aura_amgm_inequality);
	write_with_paint_aura_fdf_table(0, "pythagorus_3d.txt", &table, aura_pythagoras_3d);
	write_with_paint_aura_fdf_table(1.0 / 20.0, "fermat_theorem.txt", &table, aura_fermat_theorem);
	write_with_paint_aura_fdf_table(0, "min_xy.txt", &table, aura_min_xy);
	write_with_paint_aura_fdf_table(0, "mincos.txt", &table, aura_mincos);
	write_with_paint_aura_fdf_table(0, "minecos.txt", &table, aura_minecos);
	write_with_paint_aura_fdf_table(0, "max_xy.txt", &table, aura_max_xy);
	write_with_paint_aura_fdf_table(0, "root_xyz.txt", &table, aura_root_xyz);
	write_with_paint_aura_fdf_table(0, "maxcos.txt", &table, aura_maxcos);
	write_with_paint_aura_fdf_table(0, "amgm_inequality_3d.txt", &table, aura_amgm_inequality_3d);
	write_with_paint_aura_fdf_table(0, "maxecos.txt", &table, aura_maxecos);
	write_with_paint_aura_fdf_table(0, "maxesin.txt", &table, aura_maxesin);
	write_with_paint_aura_fdf_table(0, "maxexp.txt", &table, aura_maxesin);
	write_with_paint_aura_fdf_table(0, "minexp.txt", &table, aura_minexp);
	write_with_paint_aura_fdf_table(0, "max_xyz.txt", &table, aura_max_xyz);
	write_with_paint_aura_fdf_table(0, "maxexp.txt", &table, aura_maxexp);
	write_with_paint_aura_fdf_table(0, "maxsin.txt", &table, aura_maxsin);
	write_with_paint_aura_fdf_table(0, "pythagorus.txt", &table, aura_pythagoras);
	write_with_paint_aura_fdf_table(0, "triangle_inequality_3d.txt", &table, aura_triangle_inequality_3d);
	write_with_paint_aura_fdf_table(0, "root_xy.txt", &table, aura_root_xy);
	write_with_paint_aura_fdf_table(0, "triangle_inequality.txt", &table, aura_triangle_inequality);
	write_with_paint_aura_fdf_table(0, "addsub_3d.txt", &table, aura_addsub_3d);
	write_with_paint_aura_fdf_table(0, "x_plus_y_square.txt", &table, aura_x_plus_y_square);
	write_with_paint_aura_fdf_table(0, "min_xyz.txt", &table, aura_min_xyz);
	destroy_fdf_table(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/paint_aura_fdf_table.out
*/