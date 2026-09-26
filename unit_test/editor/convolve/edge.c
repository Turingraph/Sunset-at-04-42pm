#include"convolve.h"

int	main(void)
{
	t_table_fdf	table_a;
	t_table_fdf	table_c;
	int			output;
	char		*dst_dir = "unit_test/editor/convolve/input_edge_2/";
	char		*src_dir = "unit_test/editor/convolve/input_ascii/";
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
	size_t	  length = 20;
	float	*edge;

	edge = edge_kernel(3, 7, 1, 0);
	i = 0;
	while (i < length)
	{
		output = open_dir_file(arr[i], dst_dir, E_WRITE);
		table_a = open_table_fdf_file(arr[i], src_dir,
				parse_ascii_line_cheche01, false);
		scale_multiplication_fdf(&table_a, 3.0, HEIGHT);
		table_c = convolve_fdf(&table_a, edge, 5);
		// scale_positive_fdf(&table_c);
		write_table_ascii_cheche01(output, &table_c, HEIGHT);
		free_table_fdf(&table_a);
		free_table_fdf(&table_c);
		close(output);
		i += 1;
	}
	free(edge);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/convolve/edge.out

*/
