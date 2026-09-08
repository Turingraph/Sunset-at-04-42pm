#include "raster.h"

// time : O(n)
// space: O(1)
static void	draw_line_y_minus(mlx_image_t *dst,
	t_line line, t_line boundary, int32_t color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = -1;
	delta_x = line.p2.y - line.p1.y;
	delta_y = sign * (line.p2.x - line.p1.x);
	pivot = 2 * delta_y - delta_x;
	while (dst != NULL && line.p1.y <= line.p2.y)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary) == true)
			mlx_put_pixel(dst, line.p1.x, line.p1.y, color);
		if (0 < pivot)
		{
			pivot -= 2 * delta_x;
			line.p1.x += sign;
		}
		pivot += 2 * delta_y;
		line.p1.y += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_line_thick_y_minus(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	t_line	parallel;
	size_t	i;

	draw_line_y_minus(dst, line, boundary, ink.color);
	if (ink.thickness < 2)
		return ;
	draw_endpoint(dst, line, boundary, ink);
	parallel = line;
	i = 1;
	while (i < ink.thickness / 2)
	{
		parallel.p1.x -= 1;
		parallel.p2.x -= 1;
		draw_line_y_minus(dst, parallel, boundary, ink.color);
		line.p1.x += 1;
		line.p2.x += 1;
		draw_line_y_minus(dst, line, boundary, ink.color);
		i += 1;
	}
}


// time : O(n)
// space: O(1)
void	draw_line_thick_y_minus_noend(mlx_image_t *dst,
	t_line line, t_line boundary, t_ink32 ink)
{
	t_line	parallel;
	size_t	i;

	draw_line_y_minus(dst, line, boundary, ink.color);
	if (ink.thickness < 2)
		return ;
	parallel = line;
	i = 1;
	while (i < ink.thickness / 2)
	{
		parallel.p1.x -= 1;
		parallel.p2.x -= 1;
		draw_line_y_minus(dst, parallel, boundary, ink.color);
		line.p1.x += 1;
		line.p2.x += 1;
		draw_line_y_minus(dst, line, boundary, ink.color);
		i += 1;
	}
}
