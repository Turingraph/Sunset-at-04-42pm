#include"motif.h"

/*
Reference
*	https://en.wikipedia.org/wiki/Composition_with_Red,_Blue_and_Yellow
*/

int	main(void)
{
	t_complex	square_00[] = {
		{.re = 1.0 / 24.0, .im = 1.0 / 24.0},
		{.re = 5.0 / 24.0, .im = 8.0 / 24.0},
	};
	t_complex	square_01[] = {
		{.re = 1.0 / 24.0, .im = 11.0 / 24.0},
		{.re = 5.0 / 24.0, .im = 17.0 / 24.0},
	};
	t_complex	square_02[] = {
		{.re = 1.0 / 24.0, .im = 19.0 / 24.0},
		{.re = 5.0 / 24.0, .im = 23.0 / 24.0},
	};
	t_complex	square_03[] = {
		{.re = 7.0 / 24.0, .im = 1.0 / 24.0},
		{.re = 23.0 / 24.0, .im = 17.0 / 24.0},
	};
	t_complex	square_04[] = {
		{.re = 7.0 / 24.0, .im = 19.0 / 24.0},
		{.re = 19.0 / 24.0, .im = 23.0 / 24.0},
	};
	t_complex	square_05[] = {
		{.re = 21.0 / 24.0, .im = 19.0 / 24.0},
		{.re = 23.0 / 24.0, .im = 20.0 / 24.0},
	};
	t_complex	square_06[] = {
		{.re = 21.0 / 24.0, .im = 22.0 / 24.0},
		{.re = 23.0 / 24.0, .im = 23.0 / 24.0},
	};
	t_ink32			ink_coco = {
		.color = f_rgba_to_int32(192, 192, 0, 255),
		.thickness = 30};
	t_ink32			ink_red = {
		.color = f_rgba_to_int32(255, 0, 0, 255),
		.thickness = 20};
	t_ink32			ink_white = {
		.color = f_rgba_to_int32(255, 255, 255, 255),
		.thickness = 20};
	t_ink32			ink_blue = {
		.color = f_rgba_to_int32(0, 100, 255, 255),
		.thickness = 20};
	t_2d_polygon	polygon_00 = {.arr = square_00, .is_loop = false, .length = 2};
	t_2d_polygon	polygon_01 = {.arr = square_01, .is_loop = false, .length = 2};
	t_2d_polygon	polygon_02 = {.arr = square_02, .is_loop = false, .length = 2};
	t_2d_polygon	polygon_03 = {.arr = square_03, .is_loop = false, .length = 2};
	t_2d_polygon	polygon_04 = {.arr = square_04, .is_loop = false, .length = 2};
	t_2d_polygon	polygon_05 = {.arr = square_05, .is_loop = false, .length = 2};
	t_2d_polygon	polygon_06 = {.arr = square_06, .is_loop = false, .length = 2};
	t_motif_arr	piet_mondrian = {
		.length = 7,
		.arr = (t_motif []){
			{
				.polygon = polygon_00,
				.ink = ink_white,
				.type = E_RECTANGLE
			},
			{
				.polygon = polygon_01,
				.ink = ink_coco,
				.type = E_RECTANGLE
			},
			{
				.polygon = polygon_02,
				.ink = ink_blue,
				.type = E_RECTANGLE
			},
			{
				.polygon = polygon_03,
				.ink = ink_red,
				.type = E_RECTANGLE
			},
			{
				.polygon = polygon_04,
				.ink = ink_white,
				.type = E_RECTANGLE
			},
			{
				.polygon = polygon_05,
				.ink = ink_white,
				.type = E_RECTANGLE
			},
			{
				.polygon = polygon_06,
				.ink = ink_coco,
				.type = E_RECTANGLE
			},
		}
	};

	view_motif(&piet_mondrian, f_rgba_to_int32(0, 0, 0, 255), 3);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/motif/piet_mondrian.out
*/
