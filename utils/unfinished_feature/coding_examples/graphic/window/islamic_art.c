#include"window.h"

/*
int	main(void)
{
	t_line	src = {.p1 = {.x = 100, .y = 300}, .p2 = {.x = 500, .y = 400}};

	view_rectangle(src, 
		f_rgba_to_int32(255, 155, 100, 255),
		f_rgba_to_int32(123, 155, 244, 255));
	return (0);
}
*/

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
		.thickness = 30, .type = E_LINE};
	t_ink32			ink2 = {
		.color = (63 << 24 | 29 << 16 | 56 << 8 | 255),
		.thickness = 20, .type = E_LINE};
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
			},
			{
				.polygon = thickline_arr_01,
				.ink = ink,
			},
			{
				.polygon = thickline_arr_02,
				.ink = ink,
			},
			{
				.polygon = thickline_arr_03,
				.ink = ink,
			},
			{
				.polygon = polygon_00,
				.ink = ink2,
			},
			{
				.polygon = polygon_01,
				.ink = ink2,
			},
			{
				.polygon = polygon_02,
				.ink = ink2,
			},
			{
				.polygon = polygon_03,
				.ink = ink2,
			},
		}
	};
	t_background	bc = {.color = f_rgba_to_int32(253, 240, 213, 255), .first_post = NULL, .tiles_resolution = 3};
	t_ink32	style = {.color = f_rgba_to_int32(253, 240, 213, 255), .thickness = 0, .type = E_LINE};

	view_master_piece(NULL, &islamic_art, style, bc);
	return (0);
}


/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/window/islamic_art.out

	view_master_piece(NULL, 3, f_rgba_to_int32(123, 155, 244, 255));
==598474== 
==598474== LEAK SUMMARY:
==598474==    definitely lost: 0 bytes in 1 blocks
==598474==    indirectly lost: 0 bytes in 0 blocks
==598474==      possibly lost: 0 bytes in 0 blocks
==598474==    still reachable: 317,899 bytes in 3,104 blocks
==598474==         suppressed: 56 bytes in 2 blocks
==598474== 
==598474== For lists of detected and suppressed errors, rerun with: -s
==598474== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


	view_master_piece(islamic_art, 3, f_rgba_to_int32(123, 155, 244, 255));
==611040== 
==611040== LEAK SUMMARY:
==611040==    definitely lost: 0 bytes in 1 blocks
==611040==    indirectly lost: 0 bytes in 0 blocks
==611040==      possibly lost: 0 bytes in 0 blocks
==611040==    still reachable: 317,899 bytes in 3,104 blocks
==611040==         suppressed: 56 bytes in 2 blocks
==611040== 
==611040== For lists of detected and suppressed errors, rerun with: -s
==611040== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/