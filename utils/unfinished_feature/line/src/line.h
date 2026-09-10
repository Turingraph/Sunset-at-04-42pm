#ifndef LINE_H
# define LINE_H

# include "../../utils/green_counts/green_counts.h"
# include "../../utils/libft/libft.h"
# include<unistd.h>

/*
It is recommended to refactor editor/line the same way
the graphic/raster/
*/

typedef struct t_ink t_ink;

struct t_ink
{
	e_rgba	channel;
	int		color;
	size_t	thickness;
};

typedef struct t_2d_int t_2d_int;

struct t_2d_int
{
	int	x;
	int	y;
};

typedef struct t_line t_line;

struct t_line
{
	t_2d_int	p1;
	t_2d_int	p2;
};

typedef struct t_boundary t_boundary;

struct t_boundary
{
	t_2d_int	all_area;
	t_line		sub_area;
};

typedef struct t_circle t_circle;

struct t_circle
{
	int	x;
	int	y;
	int	radius;
};

typedef struct t_2d_polygon t_2d_polygon;

struct t_2d_polygon
{
	t_complex	*arr;
	size_t		length;
	bool		is_loop;
};

// bresenham_int.c
void		bresenham_int_x(int *dst,
				t_line line, t_boundary boundary, int color);
void		bresenham_int_y(int *dst,
				t_line line, t_boundary boundary, int color);
void		bresenham_int_x_thick(int *dst,
				t_line line, t_boundary boundary, t_ink ink);
void		bresenham_int_y_thick(int *dst,
				t_line line, t_boundary boundary, t_ink ink);

// bresenham_uchar.c
void		bresenham_uchar_x(unsigned char *dst,
				t_line line, t_boundary boundary, unsigned char color);
void		bresenham_uchar_y(unsigned char *dst,
				t_line line, t_boundary boundary, unsigned char color);
void		bresenham_uchar_x_thick(unsigned char *dst,
				t_line line, t_boundary boundary, t_ink ink);
void		bresenham_uchar_y_thick(unsigned char *dst,
				t_line line, t_boundary boundary, t_ink ink);

// circle.c
t_circle	init_circle_in_boundary(t_circle point, t_boundary boundary);
void		midpoint_circle_int(int *dst,
				int color, t_circle point, t_boundary boundary);
void		midpoint_circle_uchar(unsigned char *dst,
				unsigned char color, t_circle point, t_boundary boundary);

// init.c
int			float_to_2d_int(float src, t_line boundary, char mode);
int			init_swap_bresenham_y(t_line *line, int *delta_x, int *delta_y);
int			init_swap_bresenham_x(t_line *line, int *delta_x, int *delta_y);
t_boundary	init_rectangle_boundary(t_line sub_area, size_t row, size_t col);
t_line		init_first_line(t_line src, t_boundary boundary);

// line.c
void			draw_straight_line(t_table_fdf *dst,
					t_line line, t_line rectangle_boundary, t_ink ink);

// polygon.c
t_line		init_float_line(t_complex point_1, t_complex point_2,
				t_line boundary);
void		draw_polygon(t_table_fdf *dst,
				t_2d_polygon *polygon, t_ink ink, t_line rectangle_boundary);
void		draw_square_tiling(t_table_fdf *dst,
				t_2d_polygon *polygon, t_ink ink, t_2d_int tiling_area);
void		draw_kusama_circle_int(t_table_fdf *dst,
				t_circle circle, int ink, t_2d_int tiling_area);
void		draw_kusama_circle_uchar(t_table_fdf *dst,
				t_circle circle, t_ink ink, t_2d_int tiling_area);

// rectangle.c
t_line		init_rectangle(t_line src, t_boundary boundary);
void		draw_rectangle_int(t_table_fdf *dst, t_line rectangle,
				t_line boundary, int ink);
void		draw_rectangle_uchar(t_table_fdf *dst, t_line rectangle,
				t_line boundary, t_ink ink);
void		draw_mondrian_tiling_int(t_table_fdf *dst, t_line rectangle,
				int ink, t_2d_int tiling_area);
void		draw_mondrian_tiling_uchar(t_table_fdf *dst, t_line rectangle,
				t_ink ink, t_2d_int tiling_area);

// utils.c
bool		is_in_boundary(int x, int y, t_line boundary);
t_line		define_circle_boundary(t_circle point,
				int ix, int iy, char mode);
t_line		reverse_line(t_line line);
t_line		get_tiling(t_2d_int tiling_area, size_t i, size_t j);
t_boundary	get_all_area(size_t row, size_t col);

#endif
