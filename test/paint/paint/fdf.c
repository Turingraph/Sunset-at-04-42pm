#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient()
{
	t_gradient	dst;

	dst.cell_channel = GRADIENT_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 79;
	dst.rgba_start.r = 70;
	dst.rgba_start.g = 75;
	dst.rgba_start.b = 113;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 124;
	dst.rgba_end.g = 213;
	dst.rgba_end.b = 199;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(void)
{
	t_fdf_table	table_a;
	int			output;
	char		*dst = "test/paint/paint/input_fdf/";
	char		*src = "corpus/ascii/";
	char		*arr_src[] = {
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
	char		*arr_dst[] = {
		"apartment_goofy.fdf",
		"bangkok_usa_frag.fdf",
		"cuneiform_peakslank.fdf",
		"fast_and_ferious_speed.fdf",
		"handsomeguy_nancyj.fdf",
		"islamic_art.fdf",
		"islamic_gauss.fdf",
		"jellyfish_nvscript.fdf",
		"lerem_ipsum_nvscript.fdf",
		"lorem_Ipsum_script.fdf",
		"mfdoom_georgi16.fdf", 
		"mondrian_int.fdf", 
		"o_isometric2.fdf",
		"pillar.fdf",
		"rain_with_cappuccino_rozzo.fdf", 
		"startrack_starwars.fdf",
		"the_last_of_us_poison.fdf",
		"times4.fdf", 
		"unix_o8.fdf",
		"zutomayo_isometric2.fdf"};
	size_t	  i;
	size_t	  length = 20;

	i = 0;
	while (i < length)
	{
		output = debug_load_file(arr_dst[i], dst, FILE_WRITE);
		char	*file_name = concat_str(src, arr_src[i]);
		table_a = load_fdf_table(file_name,
				parse_ascii_chungaloider, true);
		free(file_name);
        color_cells_gradient(&table_a, init_gradient(), true);
		write_fdf_table(output, &table_a, 1, FDF_FORMAT_DECIMAL_RGBA);
		destroy_fdf_table(&table_a);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/paint/paint/fdf.out

*/
