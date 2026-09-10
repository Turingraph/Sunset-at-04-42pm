#include"window.h"

// time : O(1)
// space: O(1)
t_ink32	get_hook_ink(t_2d_hook *hook, bool is_draw, t_2d_int ixiy)
{
	t_ink32		ink;
	t_table_fdf	*table;

	table = hook->master_piece.still_life->src;
	ink = hook->master_piece.drawing_style;
	ink.color = get_table_rgba_int32((const t_table_fdf *)table, ixiy.y * table->col + ixiy.x);
	if (is_draw == false)
		ink.color = hook->master_piece.background.color;
	return (ink);
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_unit_circle(t_2d_int point,
	t_ink32 ink, t_2d_camera camera, mlx_image_t *img)
{
	t_circle	circle;
	t_boundary	boundary;

	if (is_circle_in_screen(camera, point, ink.thickness) == true
		&& ink.type != E_RECTANGLE)
	{
		boundary = get_all_area(img->height, img->width);
		circle.radius = ink.thickness;
		circle.x = point.x;
		circle.y = point.y;
		midpoint_circle_mlx(img, ink.color, circle, boundary);
	}
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_unit(t_line line, t_ink32 ink, t_2d_camera camera, mlx_image_t *img)
{
	t_line		rectangle_boundary;

	rectangle_boundary.p1 = camera.offset;
	rectangle_boundary.p2 = camera.window_size;
	if ((is_line_in_screen(camera, line.p1) == true
		|| is_line_in_screen(camera, line.p2) == true) && ink.type == E_RECTANGLE)
		draw_rectangle_mlx(img, line, rectangle_boundary, ink.color);
	else if ((is_line_in_screen(camera, line.p1) == true
		|| is_line_in_screen(camera, line.p2) == true) && ink.type == E_LINE)
		draw_mlx_straight_line(img, line, rectangle_boundary, ink);
	else
	{
		draw_fdf_mlx_unit_circle(line.p1, ink, camera, img);
		draw_fdf_mlx_unit_circle(line.p2, ink, camera, img);
	}
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_y_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	line.p1 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->x[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x],
		hook->master_piece.still_life->y[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x]);
	line.p2 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->x[(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x],
		hook->master_piece.still_life->y[(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x]);
	draw_fdf_mlx_unit(line, ink, *(hook->camera), hook->img);
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_x_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	line.p1 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->x[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x],
		hook->master_piece.still_life->y[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x]);
	line.p2 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->x[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x + 1],
		hook->master_piece.still_life->y[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x + 1]);
	draw_fdf_mlx_unit(line, ink, *(hook->camera), hook->img);
	// write_line(line);
	// write(1, "\t", 1);
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_x(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| hook->master_piece.drawing_style.type == E_PIXEL_ART)
		return ;
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (0 < src->col && ixiy.x < (int)src->col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src->row)
		{
			draw_fdf_mlx_x_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		// write(1, "\n", 1);
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_y(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| hook->master_piece.drawing_style.type == E_PIXEL_ART)
		return ;
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (ixiy.x < (int)src->col)
	{
		ixiy.y = 0;
		while (0 < src->row && ixiy.y < (int)src->row - 1)
		{
			draw_fdf_mlx_y_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_pixel_art_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	ink.type = E_RECTANGLE;
	line.p1 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->x[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x],
		hook->master_piece.still_life->y[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x]);
	line.p2 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->x[(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x + 1],
		hook->master_piece.still_life->y[(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x + 1]);
	draw_fdf_mlx_unit(line, ink, *(hook->camera), hook->img);
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_pixel_art(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| hook->master_piece.drawing_style.type != E_PIXEL_ART)
		return ;
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (0 < src->col && ixiy.x < (int)src->col - 1)
	{
		ixiy.y = 0;
		while (0 < src->row && ixiy.y < (int)src->row - 1)
		{
			draw_fdf_mlx_pixel_art_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}



void	draw_fdf_mlx(t_2d_hook *hook, bool is_draw)
{
	draw_fdf_mlx_y(hook, is_draw);
	draw_fdf_mlx_x(hook, is_draw);
	draw_fdf_mlx_pixel_art(hook, is_draw);
}
