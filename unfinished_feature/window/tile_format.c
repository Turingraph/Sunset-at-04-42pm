#include"window.h"

// time : O(1)
// space: O(1)
t_2d_int	init_offset_tile(size_t width, size_t height,
	size_t resolution, size_t fixed_length)
{
	t_2d_int	output;

	output.p1.re = init_alltiles_offset(width, resolution,
			fixed_length);
	output.p1.im = init_alltiles_offset(height, resolution,
			fixed_length);
	output.p2.re = output.p1.re + init_alltiles_size(width,
			resolution, fixed_length);
	output.p2.im = output.p1.im + init_alltiles_size(height,
			resolution, fixed_length);
	return (output);
}

// time : O(1)
// space: O(1)
t_tile_format	init_tile_format(size_t width,
	size_t height, size_t resolution)
{
	t_tile_format	dst;
	size_t			fixed_side;

	fixed_side = (size_t)f_min((float)width, (float)height);
	dst.offset = init_offset_tile(width, height, resolution, fixed_side);
	dst.tile_size = (float)init_tile_size(fixed_side, resolution);
	dst.tile_counts.x = init_alltiles_count(width, resolution, fixed_side);
	dst.tile_counts.y = init_alltiles_count(height, resolution, fixed_side);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	get_first_interier_tile(t_tile_format tiles,
	t_2d_camera camera)
{
	t_2d_int	screen_xy;
	t_2d_int	output;

	output.x = 0;
	output.y = 0;
	screen_xy = world_to_screen_2d(camera, tiles.offset.p1);
	if (screen_xy.x < 0 && tiles.tile_size > 0.2)
		output.x = (int)f_abs(f_floor(screen_xy.x / tiles.tile_size));
	else if (screen_xy.x > camera.window_size.x)
		output.x = -1;
	if (screen_xy.y < 0 && tiles.tile_size > 0.2)
		output.y = (int)f_abs(f_floor(screen_xy.y / tiles.tile_size));
	else if (screen_xy.y > camera.window_size.y)
		output.y = -1;
	return (output);
}

// time : O(1)
// space: O(1)
t_2d_int	get_last_interier_tile(t_tile_format tiles,
	t_2d_camera camera)
{
	t_2d_int	screen_xy;
	t_2d_int	output;

	output = tiles.tile_counts;
	screen_xy.x = world_to_screen_xy(camera.offset.x,
			tiles.tile_counts.x * tiles.tile_size + tiles.offset.p1.re);
	screen_xy.y = world_to_screen_xy(camera.offset.y,
			tiles.tile_counts.y * tiles.tile_size + tiles.offset.p1.im);
	if (screen_xy.x < 0)
		output.x = -1;
	else if (screen_xy.x > camera.window_size.x)
		output.x += 1 - (screen_xy.x - camera.window_size.x) / tiles.tile_size;
	if (screen_xy.y < 0)
		output.y = -1;
	else if (screen_xy.y > camera.window_size.y)
		output.y += 1 - (screen_xy.y - camera.window_size.y) / tiles.tile_size;
	return (output);
}

// time : O(1)
// space: O(1)
t_2d_int	get_ith_tile_screen(t_tile_format tiles,
	t_2d_camera camera, int ix, int iy)
{
	t_2d_int	output;
	t_2d_int	screen_xy;

	screen_xy = world_to_screen_2d(camera, tiles.offset.p1);
	output.x = ix * tiles.tile_size + screen_xy.x;
	output.y = iy * tiles.tile_size + screen_xy.y;
	return (output);
}
