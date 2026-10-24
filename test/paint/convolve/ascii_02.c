#include"convolve.h"

int	main(void)
{
	t_fdf_table	table_a;
	t_fdf_table	table_b;
	t_fdf_table	table_c;
	size_t		half_dim;
	int			output;
	char		*dst_dir = "test/paint/convolve/input_ascii_02/";
	char		*src_dir = "corpus/ascii/";
	char		*arr[] = {
		"apartment_goofy.txt",
		"bangkok_usa_frag.txt",
		"cuneiform_peakslank.txt",
		"fast_and_ferious_speed.txt",
		"handsomeguy_nancyj.txt",
		"islamic_art.txt",
		"islamic_gauss.txt",
		"jellyfish_nvscript.txt",
		"lerem_ipsum_nvscript.txt",
		"lorem_Ipsum_script.txt",
		"mfdoom_georgi16.txt", 
		"mondrian_int.txt", 
		"o_isometric2.txt",
		"pillar.txt",
		"rain_with_cappuccino_rozzo.txt", 
		"startrack_starwars.txt",
		"the_last_of_us_poison.txt",
		"times4.txt", 
		"unix_o8.txt",
		"zutomayo_isometric2.txt"};
	size_t	  i;
	size_t	  length = 20;	// max = 24

	half_dim = 5;
	i = 0;
	while (i < length)
	{
		output = debug_load_file(arr[i], dst_dir, FILE_WRITE);
		char	*file_name = concat_str(src_dir, arr[i]);
		table_a = load_fdf_table(file_name,
				FDF_FORMAT_ASCII_A, false);
		free(file_name);
		table_b = scale_dimension_fdf(&table_a, 5, 5);
		table_c = convolve_fdf(&table_b, NULL, half_dim);
		write_fdf_table(output, &table_c, FDF_HEIGHT, FDF_FORMAT_ASCII_A);
		destroy_fdf_table(&table_a);
		destroy_fdf_table(&table_b);
		destroy_fdf_table(&table_c);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/convolve/ascii_02.out

*/
