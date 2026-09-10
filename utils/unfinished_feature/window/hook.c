#include<time.h>
#include"window.h"

// time : O(1)
// space: O(1)
void	hook_pan(mlx_key_data_t keydata, t_2d_camera *camera)
{
	if (camera == NULL || is_valid_key(keydata) == false)
		return ;
	if (keydata.key == MLX_KEY_UP)
		camera->offset.y -= 5;
	if (keydata.key == MLX_KEY_DOWN)
		camera->offset.y += 5;
	if (keydata.key == MLX_KEY_LEFT)
		camera->offset.x -= 5;
	if (keydata.key == MLX_KEY_RIGHT)
		camera->offset.x += 5;
}

// time : O(n)
// space: O(1)
void	hook_rotate(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	t_matrix	transform;
	size_t		len;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| (keydata.key != MLX_KEY_1
			&& keydata.key != MLX_KEY_2
			&& keydata.key != MLX_KEY_3))
		return ;
	if (keydata.key == MLX_KEY_1)
		transform = init_3d_rotate_matrix_x(3.1415 / 12.0);
	else if (keydata.key == MLX_KEY_2)
		transform = init_3d_rotate_matrix_y(3.1415 / 12.0);
	else
		transform = init_3d_rotate_matrix_z(3.1415 / 12.0);
	if (transform.arr == NULL)
		return ;
	len = hook->master_piece.still_life->src->col;
	len *= hook->master_piece.still_life->src->row;
	linear_map_fdf_all(hook->master_piece.still_life, transform);
	matrix_3d_product(transform, &(hook->master_piece.still_life->matrix));
	free(transform.arr);
	// if (det < 0.02)
	// 	return ;
	// vector_scale(hook->master_piece.still_life->pos_x, 1.0 / det, len);
	// vector_scale(hook->master_piece.still_life->pos_y, 1.0 / det, len);
	// vector_scale(hook->master_piece.still_life->pos_z, 1.0 / det, len);
}

// time : O(n)
// space: O(1)
void	hook_zoom(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	float		scale;
	size_t		len;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| (keydata.key != MLX_KEY_0 && keydata.key != MLX_KEY_9)
		|| (keydata.key == MLX_KEY_0 && hook->camera->zoom / 1.01 < 0.2)
		|| (keydata.key == MLX_KEY_9 && hook->camera->zoom * 1.01 > 2.0))
		return ;
	len = hook->master_piece.still_life->src->col;
	len *= hook->master_piece.still_life->src->row;
	scale = 1.01;
	if (keydata.key == MLX_KEY_0)
		scale = 1.0 / 1.01;
	hook->camera->zoom *= scale;
	vector_scale(hook->master_piece.still_life->pos_x, scale, len);
	vector_scale(hook->master_piece.still_life->pos_y, scale, len);
	vector_scale(hook->master_piece.still_life->pos_z, scale, len);
}

// time : O(n)
// space: O(1)
void	hook_home(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	t_matrix	undo;
	size_t		len;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false || hook->camera->zoom < 0.2
		|| keydata.key != MLX_KEY_Q)
		return ;
	undo = init_inverse_3d_matrix(hook->master_piece.still_life->matrix);
	if (undo.arr == NULL)
		return ;
	len = hook->master_piece.still_life->src->col;
	len *= hook->master_piece.still_life->src->row;
	hook->camera->offset.x = 0.0;
	hook->camera->offset.y = 0.0;
	vector_scale(hook->master_piece.still_life->pos_x, 1.0 / hook->camera->zoom, len);
	vector_scale(hook->master_piece.still_life->pos_y, 1.0 / hook->camera->zoom, len);
	vector_scale(hook->master_piece.still_life->pos_z, 1.0 / hook->camera->zoom, len);
	hook->camera->zoom = 1.0;
	matrix_3d_product(undo, &(hook->master_piece.still_life->matrix));
	linear_map_fdf_all(hook->master_piece.still_life, undo);
	free(undo.arr);
}

// time : O(n)
// space: O(1)
void	hook_absolute_cinema(mlx_key_data_t keydata, void *param)
{
	t_2d_hook		*hook;
	static clock_t	before = 0;
	clock_t			after;
	// float			length_v;

	hook = (t_2d_hook *)param;
	if (is_2dhook_valid((const t_2d_hook *)hook, E_STILL_LIFE) == true
		&& is_valid_key(keydata) == true)
	{
		after = clock();
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(hook->mlx);
		if (before != 0 && after - before < 1000)
			return ;
		before = after;
		draw_fdf_mlx(hook, false);
		draw_motif_mlx(hook, true);
		// hook_rotate(keydata, hook);
		// length_v = hook->master_piece.still_life->pos_x[0] * hook->master_piece.still_life->pos_x[0];
		// length_v += hook->master_piece.still_life->pos_y[0] * hook->master_piece.still_life->pos_y[0];
		// length_v += hook->master_piece.still_life->pos_z[0] * hook->master_piece.still_life->pos_z[0];
		// length_v = f_root_finding(length_v, 2);
		// write(1, "length: ", 9);
		// ft_putnbr_fd((int)f_floor(length_v), 1, "0123456789", 1);
		// write(1, "\n", 1);
		hook_zoom(keydata, hook);
		hook_pan(keydata, hook->camera);
		hook_home(keydata, hook);
		draw_fdf_mlx(hook, true);
	}
}
