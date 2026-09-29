#include"motif.h"

int	main(void)
{
	t_complex	arr[] = {
		{.re = 0.5, .im = 0.5},
	};
	t_ink32			ink = {
		.color = f_rgba_to_int32(0, 0, 0, 255),
		.thickness = 20};
	t_2d_polygon	circle_arr = {.arr = arr, .is_loop = false, .length = 1};
	t_motif_arr	islamic_art = {
		.length = 1,
		.arr = (t_motif []){
			{
				.polygon = circle_arr,
				.ink = ink,
				.shape_2d = E_CIRCLE
			}
		}
	};
	view_motif(&islamic_art, f_rgba_to_int32(253, 240, 213, 255), 3);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/motif/kusama.out

*/