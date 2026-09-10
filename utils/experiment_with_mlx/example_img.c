#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "include/MLX42.h"
#define WIDTH 5120
#define HEIGHT 2880

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Create a new image
	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
	if (!img)
		error();

	// Set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/*
$ cc -Wall -Wextra -Werror example_img.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
$ valgrind --leak-check=full --show-leak-kinds=all ./a.out
...
==149601== 
==149601== LEAK SUMMARY:
==149601==    definitely lost: 56 bytes in 1 blocks
==149601==    indirectly lost: 56 bytes in 1 blocks
==149601==      possibly lost: 0 bytes in 0 blocks
==149601==    still reachable: 304,621 bytes in 3,421 blocks
==149601==         suppressed: 0 bytes in 0 blocks
==149601== 
==149601== For lists of detected and suppressed errors, rerun with: -s
==149601== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

https://github.com/codam-coding-college/MLX42/blob/master/docs/Colors.md
*/