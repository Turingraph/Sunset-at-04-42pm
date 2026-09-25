#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 20;
	dst.rgba_start.r = 50;
	dst.rgba_start.g = 50;
	dst.rgba_start.b = 50;
	dst.rgba_start.a = 50;
	dst.rgba_end.r = 20;
	dst.rgba_end.g = 20;
	dst.rgba_end.b = 20;
	dst.rgba_end.a = 20;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_gradient_2()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 21;
	dst.input_end = 79;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 0;
	dst.rgba_start.a = 0;
	dst.rgba_end.r = 10;
	dst.rgba_end.g = 10;
	dst.rgba_end.b = 10;
	dst.rgba_end.a = 10;
	return (dst);
}


int	main(void)
{
	t_table_fdf	table_a;
	int			output;
	char		*dst = "unit_test/editor/paint/input_ascii/";
	char		*src = "input_examples/ascii/";
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

	i = 0;
	while (i < length)
	{
		output = open_dir_file(arr[i], dst, E_WRITE);
		table_a = open_table_fdf_file(arr[i], src,
				parse_ascii_line_chungaloider, true);
        color_cells_gradient(&table_a, init_gradient(), true);
        color_cells_gradient(&table_a, init_gradient_2(), true);
		scale_multiplication_fdf(&table_a, 1.0 / 3.0, RED);
		write_table_ascii_standard(output, &table_a, RED);
		free_table_fdf(&table_a);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/paint/ascii.out

*/
