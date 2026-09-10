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
	t_background	bc = {.color = f_rgba_to_int32(253, 240, 213, 255), .first_post = NULL, .tiles_resolution = 3};
	t_ink32	style = {.color = f_rgba_to_int32(253, 240, 213, 255), .thickness = 0, .type = E_LINE};

	view_master_piece(NULL, NULL, style, bc);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/window/null.out

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