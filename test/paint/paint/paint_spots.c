#include"paint.h"

static void	write_with_paint_spots_fdf_table(float scale, const char *file_name,
	t_fdf_table *table,
	int (*spots)(int x, int y, int z))
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
	scale_fdf_table(table, scale, FDF_HEIGHT);
	paint_spots_fdf_table(table, FDF_HEIGHT, aura);
	write_fdf_table(output, table, FDF_HEIGHT, FDF_FORMAT_ASCII_B);
	close(output);
}

int	spots_max_x2cos(int x, int y, int z)
{
	t_double2d	com;

	com.x = f_cos((f_abs(x) + z) / 101.0);
	com.y = f_cos((f_abs(y) + z) / 101.0);
	return (f_max_x2(com.x, com.y) * 101);
}

int	main(void)
{
	t_fdf_table		table;

	table = create_fdf_table(101, 101, false);
	if (table.arr == NULL)
		return (0);
	write_with_paint_spots_fdf_table(0, "oddlength_x2.txt", &table, spots_oddlength_x2);
	write_with_paint_spots_fdf_table(0, "oddlength_x3.txt", &table, spots_oddlength_x3);
	write_with_paint_spots_fdf_table(0, "oddlength_x4.txt", &table, spots_oddlength_x4);
	write_with_paint_spots_fdf_table(0, "fermat_x2.txt", &table, spots_fermat_x2);
	write_with_paint_spots_fdf_table(0, "max_x2.txt", &table, spots_max_x2);
	write_with_paint_spots_fdf_table(0, "max_x3.txt", &table, spots_max_x3);
	write_with_paint_spots_fdf_table(0, "fermat_x3.txt", &table, spots_fermat_x3);
	write_with_paint_spots_fdf_table(0, "andmod_x2.txt", &table, spots_andmod_x2);
	write_with_paint_spots_fdf_table(0, "andmod_x4.txt", &table, spots_andmod_x4);
	write_with_paint_spots_fdf_table(0, "andmod_x3.txt", &table, spots_andmod_x3);

	destroy_fdf_table(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/paint_spots.out
*/
