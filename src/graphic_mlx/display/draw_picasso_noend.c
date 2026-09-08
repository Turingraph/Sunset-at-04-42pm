#include "display_private.h"

// time : O(1)
// space: O(1)
static void	draw_picassoy_fdf_noend_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy, size_t thickness)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, thickness);
	line = init_draw_line_y(*hook->camera, hook->master_piece.fdf, ixiy);
	draw_line_fdf_noend(line, ink, *(hook->camera), hook->img);
}

// time : O(1)
// space: O(1)
static void	draw_picassox_fdf_noend_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy, size_t thickness)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, thickness);
	line = init_draw_line_x(*hook->camera, hook->master_piece.fdf, ixiy);
	draw_line_fdf(line, ink, *(hook->camera), hook->img);
}

// time : O(n)
// space: O(1)
static void	draw_picassox_fdf_noend(t_2d_hook *hook, bool is_draw, size_t thickness)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src.row && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row)
		{
			draw_picassox_fdf_noend_unit(hook, is_draw, ixiy, thickness);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
static void	draw_picassoy_fdf_noend(t_2d_hook *hook, bool is_draw, size_t thickness)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (1 < src.row && ixiy.x < (int)src.col)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			draw_picassoy_fdf_noend_unit(hook, is_draw, ixiy, thickness);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_picasso_fdf_noend(t_2d_hook *hook, bool is_draw, size_t thickness)
{
	draw_picassox_fdf_noend(hook, is_draw, thickness);
	draw_picassoy_fdf_noend(hook, is_draw, thickness);
}
