#include"paint.h"

static void	write_with_paint_aura_fdf_table(float scale, const char *file_name,
	t_fdf_table *table,
	int (*aura)(double x, double y, double z))
{
	t_fdf_table	table2;
	int	output;

	scale_fdf_table(table, 0, FDF_HEIGHT);
	output = debug_load_file(file_name,
		"corpus/aura/", FILE_WRITE);
	if (output <= -1 || file_name == NULL)
	{
		if (file_name != NULL)
			write(1, file_name, str_length(file_name));
		write(1, " isn't exists\n", 14);
		return ;
	}
	if (reset > 0)
		scale_fdf_table(table, reset, FDF_HEIGHT);
	paint_aura_fdf_table(table, scale, FDF_HEIGHT, aura);
	table2 = count_neighbors_fdf_table(table, 32);
	mix_hadamard_fdf_table(&table2, table, FDF_HEIGHT);
	write_fdf_table(output, &table2, FDF_HEIGHT, FDF_FORMAT_ASCII_B);
	close(output);
	destroy_fdf_table(&table2);
}

int	main(void)
{
	t_fdf_table		table;

	table = create_fdf_table(201, 201, false);
	if (table.arr == NULL)
		return (0);
	write_with_paint_aura_fdf_table(AURA_MEZZO , "chainsawman_no2.txt", &table, aura_chainsawman_no2);
	write_with_paint_aura_fdf_table(AURA_MEZZO , "chainsawman_no3.txt", &table, aura_chainsawman_no3);
	write_with_paint_aura_fdf_table(AURA_MEZZO , "fractal_no2.txt", &table, aura_fractal_no2);
	write_with_paint_aura_fdf_table(AURA_MEZZO , "fractal_no3.txt", &table, aura_fractal_no3);
	write_with_paint_aura_fdf_table(AURA_FORTE * 2 , "disco_no2.txt", &table, aura_disco_no2);
	write_with_paint_aura_fdf_table(AURA_MEZZO , "disco_no3.txt", &table, aura_disco_no3);
	write_with_paint_aura_fdf_table(AURA_FORTE , "hypnotize_no2.txt", &table, aura_hypnotize_no2);
	write_with_paint_aura_fdf_table(AURA_MEZZO , "hypnotize_no3.txt", &table, aura_hypnotize_no3);
	destroy_fdf_table(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/paint_spots.out

pc@pc-System-Product-Name:~/Desktop/GrASCIIfi$ valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/paint_spots.out
==164642== Memcheck, a memory error detector
==164642== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==164642== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==164642== Command: ./test/out/paint/paint/paint_spots.out
==164642== 
==164642== 
==164642== HEAP SUMMARY:
==164642==     in use at exit: 0 bytes in 0 blocks
==164642==   total heap usage: 323,241 allocs, 323,241 frees, 1,410,676,396 bytes allocated
==164642== 
==164642== All heap blocks were freed -- no leaks are possible
==164642== 
==164642== For lists of detected and suppressed errors, rerun with: -s
==164642== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/