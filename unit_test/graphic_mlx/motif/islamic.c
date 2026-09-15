#include"motif.h"

int	main(void)
{
	float		u_0 = 0.25;
	float		u_1 = 0.396447;
	float		u_2 = 0.08579;
	t_complex	shape_00[] = {
		{.re = 0, .im = 2 * u_0},
		{.re = u_0, .im = u_1},
		{.re = u_0, .im = u_0},
		{.re = u_1, .im = u_0},
		{.re = 2 * u_0, .im = 0},
		{.re = 0, .im = 0}
	};
	t_complex	shape_01[] = {
		{.re = 1 - 0, .im = 2 * u_0},
		{.re = 1 - u_0, .im = u_1},
		{.re = 1 - u_0, .im = u_0},
		{.re = 1 - u_1, .im = u_0},
		{.re = 1 - 2 * u_0, .im = 0},
		{.re = 1 - 0, .im = 0}
	};
	t_complex	shape_02[] = {
		{.re = 0, .im = 1 - 2 * u_0},
		{.re = u_0, .im = 1 - u_1},
		{.re = u_0, .im = 1 - u_0},
		{.re = u_1, .im = 1 - u_0},
		{.re = 2 * u_0, .im = 1 - 0},
		{.re = 0, .im = 1 - 0}
	};
	t_complex	shape_03[] = {
		{.re = 1 - 0, .im = 1 - 2 * u_0},
		{.re = 1 - u_0, .im = 1 - u_1},
		{.re = 1 - u_0, .im = 1 - u_0},
		{.re = 1 - u_1, .im = 1 - u_0},
		{.re = 1 - 2 * u_0, .im = 1 - 0},
		{.re = 1 - 0, .im = 1 - 0}
	};
	t_ink32			ink = {
		.color = (170 << 24 | 28 << 16 | 65 << 8 | 255),
		.thickness = 30};
	t_ink32			ink2 = {
		.color = (63 << 24 | 29 << 16 | 56 << 8 | 255),
		.thickness = 20};
	t_2d_polygon	polygon_00 = {.arr = shape_00, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_01 = {.arr = shape_01, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_02 = {.arr = shape_02, .is_loop = false, .length = 5};
	t_2d_polygon	polygon_03 = {.arr = shape_03, .is_loop = false, .length = 5};
	t_complex		thickline_00[] = {
		{.re = u_2, .im = 0},
		{.re = 2 * u_0, .im = 1}
	};
	t_complex		thickline_01[] = {
		{.re = 2 * u_0, .im = 1},
		{.re = 1 - u_2, .im = 0}
	};
	t_complex		thickline_02[] = {
		{.re = u_2, .im = 1},
		{.re = 2 * u_0, .im = 0}
	};
	t_complex		thickline_03[] = {
		{.re = 2 * u_0, .im = 0},
		{.re = 1 - u_2, .im = 1}
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
				.ink = ink,
				.type = E_LINE,
			},
			{
				.polygon = thickline_arr_01,
				.ink = ink,
				.type = E_LINE,
			},
			{
				.polygon = thickline_arr_02,
				.ink = ink,
				.type = E_LINE,
			},
			{
				.polygon = thickline_arr_03,
				.ink = ink,
				.type = E_LINE,
			},
			{
				.polygon = polygon_00,
				.ink = ink2,
				.type = E_LINE,
			},
			{
				.polygon = polygon_01,
				.ink = ink2,
				.type = E_LINE,
			},
			{
				.polygon = polygon_02,
				.ink = ink2,
				.type = E_LINE,
			},
			{
				.polygon = polygon_03,
				.ink = ink2,
				.type = E_LINE,
			},
		}
	};

	view_motif(&islamic_art, f_rgba_to_int32(253, 240, 213, 255), 3);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/motif/islamic.out

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