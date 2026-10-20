#include"motif.h"

int	main(void)
{
	float		u_0 = 0.25;
	float		u_1 = 0.396447;
	float		u_2 = 0.08579;
	t_float2d	shape_00[] = {
		{.x = 0, .y = 2 * u_0},
		{.x = u_0, .y = u_1},
		{.x = u_0, .y = u_0},
		{.x = u_1, .y = u_0},
		{.x = 2 * u_0, .y = 0},
		{.x = 0, .y = 0}
	};
	t_float2d	shape_01[] = {
		{.x = 1 - 0, .y = 2 * u_0},
		{.x = 1 - u_0, .y = u_1},
		{.x = 1 - u_0, .y = u_0},
		{.x = 1 - u_1, .y = u_0},
		{.x = 1 - 2 * u_0, .y = 0},
		{.x = 1 - 0, .y = 0}
	};
	t_float2d	shape_02[] = {
		{.x = 0, .y = 1 - 2 * u_0},
		{.x = u_0, .y = 1 - u_1},
		{.x = u_0, .y = 1 - u_0},
		{.x = u_1, .y = 1 - u_0},
		{.x = 2 * u_0, .y = 1 - 0},
		{.x = 0, .y = 1 - 0}
	};
	t_float2d	shape_03[] = {
		{.x = 1 - 0, .y = 1 - 2 * u_0},
		{.x = 1 - u_0, .y = 1 - u_1},
		{.x = 1 - u_0, .y = 1 - u_0},
		{.x = 1 - u_1, .y = 1 - u_0},
		{.x = 1 - 2 * u_0, .y = 1 - 0},
		{.x = 1 - 0, .y = 1 - 0}
	};
	t_style_raster			style_raster = {
		.color = (170 << 24 | 28 << 16 | 65 << 8 | 255),
		.thickness = 30};
	t_style_raster			style_raster2 = {
		.color = (63 << 24 | 29 << 16 | 56 << 8 | 255),
		.thickness = 20};
	t_2d_polygon	polygon_00 = {.arr = shape_00, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_01 = {.arr = shape_01, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_02 = {.arr = shape_02, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_03 = {.arr = shape_03, .is_loop = false, .length = 5};
	t_float2d		thickline_00[] = {
		{.x = u_2, .y = 0},
		{.x = 2 * u_0, .y = 1}
	};
	t_float2d		thickline_01[] = {
		{.x = 2 * u_0, .y = 1},
		{.x = 1 - u_2, .y = 0}
	};
	t_float2d		thickline_02[] = {
		{.x = u_2, .y = 1},
		{.x = 2 * u_0, .y = 0}
	};
	t_float2d		thickline_03[] = {
		{.x = 2 * u_0, .y = 0},
		{.x = 1 - u_2, .y = 1}
	};
	t_2d_polygon	thickline_arr_00 = {.arr = thickline_00, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_01 = {.arr = thickline_01, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_02 = {.arr = thickline_02, .is_loop = false, .length = 2};
	t_2d_polygon	thickline_arr_03 = {.arr = thickline_03, .is_loop = false, .length = 2};
	t_motif_arr	islamic_art = {
		.length = 8,
		.arr = (t_motif []){
			{
				.polygon = thickline_arr_00,
				.style_raster = style_raster,
				.shape_2d = E_LINE,
			},
			{
				.polygon = thickline_arr_01,
				.style_raster = style_raster,
				.shape_2d = E_LINE,
			},
			{
				.polygon = thickline_arr_02,
				.style_raster = style_raster,
				.shape_2d = E_LINE,
			},
			{
				.polygon = thickline_arr_03,
				.style_raster = style_raster,
				.shape_2d = E_LINE,
			},
			{
				.polygon = polygon_00,
				.style_raster = style_raster2,
				.shape_2d = E_LINE,
			},
			{
				.polygon = polygon_01,
				.style_raster = style_raster2,
				.shape_2d = E_LINE,
			},
			{
				.polygon = polygon_02,
				.style_raster = style_raster2,
				.shape_2d = E_LINE,
			},
			{
				.polygon = polygon_03,
				.style_raster = style_raster2,
				.shape_2d = E_LINE,
			},
		}
	};

	view_motif(&islamic_art, rgba32_from_char(253, 240, 213, 255), 3);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/motif/islamic.out

==2639762== 
==2639762== LEAK SUMMARY:
==2639762==    definitely lost: 0 bytes in 1 blocks
==2639762==    indirectly lost: 0 bytes in 0 blocks
==2639762==      possibly lost: 0 bytes in 0 blocks
==2639762==    still reachable: 317,899 bytes in 3,104 blocks
==2639762==         suppressed: 56 bytes in 2 blocks
==2639762== 
==2639762== For lists of detected and suppressed errors, rerun with: -s
==2639762== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/