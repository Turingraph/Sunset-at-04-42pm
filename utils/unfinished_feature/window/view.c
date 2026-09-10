#include"window.h"

// time : O(n)
// space: O(1)
mlx_image_t	*handle_mlx_error(mlx_t *mlx, size_t width, size_t height)
{
	mlx_image_t	*dst;

	if (mlx == NULL || width * height == 0)
		return (NULL);
	dst = mlx_new_image(mlx, width, height);
	if (dst == NULL)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_hook	init_2d_hook(mlx_t *mlx, t_motif_arr *motif,
	t_ink32 drawing_style, t_background background)
{
	t_2d_hook	dst;

	dst.mlx = mlx;
	dst.camera = NULL;
	dst.master_piece.still_life = NULL;
	dst.master_piece.motif = motif;
	dst.master_piece.background = background;
	dst.master_piece.drawing_style = drawing_style;
	if (mlx != NULL)
		dst.master_piece.tiles = init_tile_format(
			mlx->width, mlx->height,
			(size_t)f_interval(background.tiles_resolution, 0, 10));
	else
		dst.master_piece.tiles = init_tile_format(
			1, 1,
			(size_t)f_interval(background.tiles_resolution, 0, 10));
	dst.img = NULL;
	if (mlx != NULL)
		dst.img = handle_mlx_error(mlx, mlx->width, mlx->height);
	return (dst);
}



void	init_3d_fdf_object(t_fdf *src, size_t fixed_window_size,
	t_matrix *first_linear_map)
{
	t_matrix	transform;

	if (is_fdf_valid(src) == false || fixed_window_size == 0)
		return ;
	transform = init_3d_zoom_matrix(fixed_window_size / src->width);
	if (transform.arr == NULL)
		return ;
	linear_map_fdf_all(src, transform);
	if (first_linear_map != NULL && is_matrix_valid(first_linear_map) == true)
	{
		linear_map_fdf_all(src, *first_linear_map);
		matrix_3d_product(*first_linear_map, &(src->matrix));
	}
	free(transform.arr);
}

// 1920 * (3 / 4) = 1440
// 1080 * (3 / 4) = 810
// time : O(n)
// space: O(n)
void	view_master_piece(t_fdf *still_life, t_motif_arr *motif,
	t_ink32 drawing_style, t_background background)
{
	mlx_t			*mlx;
	t_2d_hook		hook;
	t_2d_camera		camera;

	mlx = mlx_init(1440, 810, "Subset at 4:42pm", true);
	hook = init_2d_hook(mlx, motif, drawing_style, background);
	if (hook.img == NULL)
	{
		if (mlx != NULL)
			mlx_terminate(mlx);
		return ;
	}
	color_background_mlx(hook.img, background.color);
	hook.master_piece.still_life = still_life;
	camera = init_2d_camera(1440, 810);
	hook.camera = &camera;
	init_3d_fdf_object(still_life, f_min(1440, 810), background.first_post);
	draw_motif_mlx(&hook, true);
	draw_fdf_mlx(&hook, true);
	if (-1 == mlx_image_to_window(mlx, hook.img,
		(mlx->width - hook.img->width) / 2,
		(mlx->height - hook.img->height) / 2))
	{
		mlx_terminate(mlx);
		return ;
	}
	mlx_key_hook(mlx, &hook_absolute_cinema, &hook);
	mlx_loop(mlx);
	mlx_delete_image(mlx, hook.img);
	mlx_terminate(mlx);
}
