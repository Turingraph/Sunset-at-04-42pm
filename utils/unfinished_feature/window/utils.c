#include"window.h"

// time : O(1)
// space: O(1)
bool	is_master_piece_valid(const t_master_piece *src,
	e_drawing_target drawing_target)
{
	if (src == NULL || (drawing_target != E_MOTIF
		&& drawing_target != E_MINIMALISM
		&& drawing_target != E_STILL_LIFE))
		return (false);
	if (drawing_target == E_MOTIF && (src->motif == NULL
		|| src->motif->arr == NULL || src->motif->length == 0))
		return (false);
	if (drawing_target == E_STILL_LIFE
		&& is_fdf_valid(src->still_life) == false)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_2dhook_valid(const t_2d_hook *src,
	e_drawing_target drawing_target)
{
	if (src == NULL || src->camera == NULL
		|| src->img == NULL
		|| src->mlx == NULL)
		return (false);
	return (is_master_piece_valid(&(src->master_piece),
		drawing_target));
}

// time : O(1)
// space: O(1)
bool	is_valid_key(mlx_key_data_t keydata)
{
	if ((keydata.action == MLX_PRESS
		|| keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_ESCAPE
		|| keydata.key == MLX_KEY_UP
		|| keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT
		|| keydata.key == MLX_KEY_RIGHT
		|| keydata.key == MLX_KEY_1
		|| keydata.key == MLX_KEY_2
		|| keydata.key == MLX_KEY_3
		|| keydata.key == MLX_KEY_9
		|| keydata.key == MLX_KEY_0
		|| keydata.key == MLX_KEY_Q))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
void	write_line(t_line src)
{
	ft_putnbr_fd(src.p1.x, 1, "0123456789", 3);
	write(1, ", ", 2);
	ft_putnbr_fd(src.p1.y, 1, "0123456789", 3);
	write(1, " --> ", 5);
	ft_putnbr_fd(src.p2.x, 1, "0123456789", 3);
	write(1, ", ", 2);
	ft_putnbr_fd(src.p2.y, 1, "0123456789", 3);
}



t_2d_camera	init_2d_camera(size_t width, size_t height)
{
	t_2d_camera	camera;

	camera.offset.x = 0;
	camera.offset.y = 0;
	camera.zoom = 1.0;
	camera.window_size.x = width;
	camera.window_size.y = height;
	return (camera);
}

// time : O(1)
// space: O(1)
t_line	connecting_2d_point_pair(t_2d_int p1, t_2d_int p2)
{
	t_line	dst;

	dst.p1 = p1;
	dst.p2 = p2;
	return (dst);
}
