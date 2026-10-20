#include"motif.h"

/*
Reference
*	https://en.wikipedia.org/wiki/Composition_with_Red,_Blue_and_Yellow
*/

int	main(void)
{
	t_float2d	square_00[] = {
		{.x = 1.0 / 24.0, .y = 1.0 / 24.0},
		{.x = 5.0 / 24.0, .y = 8.0 / 24.0},
	};
	t_float2d	square_01[] = {
		{.x = 1.0 / 24.0, .y = 11.0 / 24.0},
		{.x = 5.0 / 24.0, .y = 17.0 / 24.0},
	};
	t_float2d	square_02[] = {
		{.x = 1.0 / 24.0, .y = 19.0 / 24.0},
		{.x = 5.0 / 24.0, .y = 23.0 / 24.0},
	};
	t_float2d	square_03[] = {
		{.x = 7.0 / 24.0, .y = 1.0 / 24.0},
		{.x = 23.0 / 24.0, .y = 17.0 / 24.0},
	};
	t_float2d	square_04[] = {
		{.x = 7.0 / 24.0, .y = 19.0 / 24.0},
		{.x = 19.0 / 24.0, .y = 23.0 / 24.0},
	};
	t_float2d	square_05[] = {
		{.x = 21.0 / 24.0, .y = 19.0 / 24.0},
		{.x = 23.0 / 24.0, .y = 20.0 / 24.0},
	};
	t_float2d	square_06[] = {
		{.x = 21.0 / 24.0, .y = 22.0 / 24.0},
		{.x = 23.0 / 24.0, .y = 23.0 / 24.0},
	};
	t_style_raster			style_raster_coco = {
		.color = rgba32_from_char(192, 192, 0, 255),
		.thickness = 30};
	t_style_raster			style_raster_red = {
		.color = rgba32_from_char(255, 0, 0, 255),
		.thickness = 20};
	t_style_raster			style_raster_white = {
		.color = rgba32_from_char(255, 255, 255, 255),
		.thickness = 20};
	t_style_raster			style_raster_blue = {
		.color = rgba32_from_char(0, 100, 255, 255),
		.thickness = 20};
	t_polygon2d	polygon_00 = {.arr = square_00, .is_loop = false, .length = 2};
	t_polygon2d	polygon_01 = {.arr = square_01, .is_loop = false, .length = 2};
	t_polygon2d	polygon_02 = {.arr = square_02, .is_loop = false, .length = 2};
	t_polygon2d	polygon_03 = {.arr = square_03, .is_loop = false, .length = 2};
	t_polygon2d	polygon_04 = {.arr = square_04, .is_loop = false, .length = 2};
	t_polygon2d	polygon_05 = {.arr = square_05, .is_loop = false, .length = 2};
	t_polygon2d	polygon_06 = {.arr = square_06, .is_loop = false, .length = 2};
	t_motif_arr	piet_mondrian = {
		.length = 7,
		.arr = (t_motif []){
			{
				.polygon = polygon_00,
				.style_raster = style_raster_white,
				.shape2d = SHAPE2D_RECTANGLE
			},
			{
				.polygon = polygon_01,
				.style_raster = style_raster_coco,
				.shape2d = SHAPE2D_RECTANGLE
			},
			{
				.polygon = polygon_02,
				.style_raster = style_raster_blue,
				.shape2d = SHAPE2D_RECTANGLE
			},
			{
				.polygon = polygon_03,
				.style_raster = style_raster_red,
				.shape2d = SHAPE2D_RECTANGLE
			},
			{
				.polygon = polygon_04,
				.style_raster = style_raster_white,
				.shape2d = SHAPE2D_RECTANGLE
			},
			{
				.polygon = polygon_05,
				.style_raster = style_raster_white,
				.shape2d = SHAPE2D_RECTANGLE
			},
			{
				.polygon = polygon_06,
				.style_raster = style_raster_coco,
				.shape2d = SHAPE2D_RECTANGLE
			},
		}
	};

	view_motif(&piet_mondrian, rgba32_from_char(0, 0, 0, 255), 3);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/visualize/motif/piet_mondrian.out

==2639111== 
==2639111== LEAK SUMMARY:
==2639111==    definitely lost: 0 bytes in 1 blocks
==2639111==    indirectly lost: 0 bytes in 0 blocks
==2639111==      possibly lost: 0 bytes in 0 blocks
==2639111==    still reachable: 317,899 bytes in 3,104 blocks
==2639111==         suppressed: 56 bytes in 2 blocks
==2639111== 
==2639111== For lists of detected and suppressed errors, rerun with: -s
==2639111== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/
