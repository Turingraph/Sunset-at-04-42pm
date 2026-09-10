// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/MLX42.h"
#include "include/table.h"
#include "include/paint.h"

// size of YouTube video screen
// the go-to standard is 1920x1080 pixels.

// -----------------------------------------------------------------------------

// time : O(1)
// space: O(1)
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}


int32_t	get_table_rgba_int32(const t_table_fdf *src, size_t index)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	if (src == NULL || index >= src->row * src->col)
		return (0);
	r = 0;
	if (src->r != NULL)
		r = (int32_t)src->r[index];
	g = 0;
	if (src->g != NULL)
		g = (int32_t)src->g[index];
	b = 0;
	if (src->b != NULL)
		b = (int32_t)src->b[index];
	a = 255;
	if (src->a != NULL)
		a = (int32_t)src->a[index];
	return (ft_pixel(r, g, b, a));
}

// time : O(n)
// space: O(1)
void	paint_table_on_image(const t_table_fdf *src, mlx_image_t *img)
{
	size_t		i;
	uint32_t	color;

	i = 0;
	while (src != NULL && img != NULL
		&& img->height == src->row
		&& img->width == src->col
		&& i < src->col * src->row)
	{
		color = get_table_rgba_int32(src, i);
		mlx_put_pixel(img, i % src->col, i / src->col, color);
		i += 1;
	}
}

// -----------------------------------------------------------------------------

// time : O(n)
// space: O(n)
t_table_fdf	scale_window_dimension_fdf(const t_table_fdf *src)
{
	size_t	window_size;

	window_size = 1080;
	if (src == NULL || src->row * src->col == 0)
	{
		write(1, "Warning: The input data is empty.\n", 35);
		return (init_table_fdf(window_size, window_size, true));
	}
	if (src->row > window_size || src->col > window_size)
	{
		write(1, "Warning: The input data contains "
			"rows and/or columns more than 1080 "
			"(window size).\nsrc->row = ", 95);
		ft_putnbr_fd(src->row, 1, "0123456789", 1);
		write(1, "\nsrc->col = ", 13);
		ft_putnbr_fd(src->col, 1, "0123456789", 1);
		write(1, "\n", 1);
		return (*src);
	}
	if (src->row >= src->col)
		return (scale_dimension_fdf(
			src, window_size / src->row, window_size / src->row));
	return (scale_dimension_fdf(
		src, window_size / src->col, window_size / src->col));
}

// // time : O(1)
// // space: O(1)
size_t	get_window_dimension_fdf(size_t row, size_t col, char axis)
{
	size_t	window_size;

	window_size = 1080;
	if (row > window_size || col > window_size || row * col == 0)
		return (0);
	if (row == col || (row < col && axis == 0) || (row > col && axis == 1))
		return (window_size);
	if (row > col && axis == 0)
		return (col * (size_t)f_floor((float)window_size / (float)row));
	if (row < col && axis == 1)
		return (row * (size_t)f_floor((float)window_size / (float)col));
	return (0);
}

// time : O(n)
// space: O(n)
int	view_table_fdf(const t_table_fdf *src)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_table_fdf	scale_src;

	scale_src = scale_window_dimension_fdf(src);
	if (scale_src.arr == NULL || scale_src.row * scale_src.col == 0)
		return (-1);
	if (src == NULL || src->row * src->col == 0)
		return (-1);
	mlx = mlx_init(1920, 1080, "Subset at 4:42pm", true);
	if (mlx == NULL)
		return(-1);
	img = mlx_new_image(mlx, scale_src.col, scale_src.row);
	if (img == NULL)
	{
		mlx_terminate(mlx);
		return(-1);
	}
	paint_table_on_image(&scale_src, img);
	if (-1 == mlx_image_to_window(mlx, img,
		1920 / 2 - get_window_dimension_fdf(src->row, src->col, 0) / 2,
		1080 / 2 - get_window_dimension_fdf(src->row, src->col, 1) / 2))
	{
		mlx_terminate(mlx);
		return(-1);
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	free_table_fdf(&scale_src);
	return (1);
}

// -----------------------------------------------------------------------------

// time : O(1)
// space: O(1)
t_gradient	init_gradient(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 100;
	dst.rgba_start.r = 42;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 72;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
bool	is_empty_space(const t_table_fdf *src, size_t index)
{
	if (src == NULL || src->arr == NULL || index >= src->row * src->col)
		return (false);
	if (src->arr[index] <= 0)
		return (true);
	return (false);
}

int	main(int len, char **str)
{
	t_table_fdf	table;
	t_gradient	gradient;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	gradient = init_gradient();
	color_cells_gradient(&table, gradient, true, NULL);
	fill_cells_color(&table, 242, RED, is_empty_space);
	fill_cells_color(&table, 230, GREEN, is_empty_space);
	fill_cells_color(&table, 216, BLUE, is_empty_space);
	fill_cells_color(&table, 255, ALPHA, is_empty_space);
	view_table_fdf(&table);
	free_table_fdf(&table);
	return (0);
}

/*
cc -Wall -Wextra -Werror main.c libmlx42.a paint.a -Iinclude -ldl -lglfw -pthread -lm
valgrind --leak-check=full --show-leak-kinds=all ./a.out input/islamic_art.txt  

I still get this leak. Why ?
==139614== LEAK SUMMARY:
==139614==    definitely lost: 56 bytes in 1 blocks
==139614==    indirectly lost: 56 bytes in 1 blocks
==139614==      possibly lost: 0 bytes in 0 blocks
==139614==    still reachable: 304,621 bytes in 3,421 blocks
==139614==         suppressed: 0 bytes in 0 blocks
==139614== 
==139614== For lists of detected and suppressed errors, rerun with: -s
==139614== ERROR SUMMARY: 9 errors from 9 contexts (suppressed: 0 from 0)

// It seem MLX42 library have its own memory leak bug. I won't fix that.
*/