#include"paint.h"

static void	write_with_paint_aura_fdf_table(float scale, const char *file_name,
	t_fdf_table *table,
	int (*aura)(double x, double y, double z))
{
	int	output;

	output = debug_load_file(file_name,
		"corpus/aura/", FILE_WRITE);
	if (output <= -1 || file_name == NULL)
	{
		if (file_name != NULL)
			write(1, file_name, str_length(file_name));
		write(1, " isn't exists\n", 14);
		return ;
	}
	if (scale > 0)
		scale_fdf_table(table, scale, FDF_HEIGHT);
	paint_aura_fdf_table(table, 1, FDF_HEIGHT, aura);
	write_fdf_table(output, table, FDF_HEIGHT, FDF_FORMAT_ASCII_B);
	close(output);
}

int	aura_maxcos(double x, double y, double z)
{
	t_double2d	com;

	com.x = f_cos((f_abs(x) + z) / 101.0);
	com.y = f_cos((f_abs(y) + z) / 101.0);
	return (f_max(com.x, com.y) * 101);
}

int	main(void)
{
	t_fdf_table		table;

	table = create_fdf_table(101, 101, false);
	if (table.arr == NULL)
		return (0);
	write_with_paint_aura_fdf_table(0, "inequality_amgm.txt", &table, aura_inequality_amgm);
	write_with_paint_aura_fdf_table(0, "pythagorus.txt", &table, aura_pythagoras);
	write_with_paint_aura_fdf_table(0, "addsub.txt", &table, aura_addsub);
	scale_fdf_table(&table, 0, FDF_HEIGHT);
	write_with_paint_aura_fdf_table(0, "fermat.txt", &table, aura_fermat);
	write_with_paint_aura_fdf_table(0, "max.txt", &table, aura_max);
	write_with_paint_aura_fdf_table(0, "min.txt", &table, aura_min);
	write_with_paint_aura_fdf_table(0, "root2.txt", &table, aura_root2);
	write_with_paint_aura_fdf_table(0, "inequality_triangle.txt", &table, aura_inequality_triangle);
	write_with_paint_aura_fdf_table(0, "root3.txt", &table, aura_root3);
	write_with_paint_aura_fdf_table(0, "maxcos.txt", &table, aura_maxcos);
	destroy_fdf_table(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/paint_aura.out
*/