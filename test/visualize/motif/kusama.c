#include"motif.h"

int	main(void)
{
	t_float2d	arr[] = {
		{.x = 0.5, .y = 0.5},
	};
	t_style_raster			style_raster = {
		.color = rgba32_from_char(0, 0, 0, 255),
		.thickness = 20};
	t_polygon2d	circle_arr = {.arr = arr, .is_loop = false, .length = 1};
	t_motif_arr	islamic_art = {
		.length = 1,
		.arr = (t_motif []){
			{
				.polygon = circle_arr,
				.style_raster = style_raster,
				.shape2d = E_CIRCLE
			}
		}
	};
	view_motif(&islamic_art, rgba32_from_char(253, 240, 213, 255), 3);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/motif/kusama.out

*/