#ifndef WINDOW_H
# define WINDOW_H

#include"../raster/raster.h"
#include "../../utils/linalg/linalg.h"
#include "../../input/table/table.h"

typedef struct t_fdf t_fdf;

struct t_fdf
{
	t_table_fdf	*src;
	float		*pos_x;
	float		*pos_y;
	float		*pos_z;
	t_matrix	matrix;
	float		width;
};

typedef struct t_tile_format t_tile_format;

struct t_tile_format
{
	float		tile_size;
	t_2d_int	tile_counts;
	t_2d_int	offset;
};

typedef struct t_2d_camera t_2d_camera;

struct t_2d_camera
{
	t_2d_int	offset;
	t_2d_int	window_size;
	float		zoom;
};

typedef struct t_motif t_motif;

struct t_motif
{
	t_2d_polygon	polygon;
	t_ink32			ink;
};

typedef struct t_motif_arr t_motif_arr;

struct t_motif_arr
{
	t_motif	*arr;
	size_t	length;
};

typedef struct t_background t_background;

struct t_background
{
	int32_t		color;
	t_matrix	*first_post;
	size_t		tiles_resolution;
};

typedef struct t_master_piece t_master_piece;

struct t_master_piece
{
	t_ink32			drawing_style;
	t_motif_arr		*motif;
	t_fdf			*still_life;
	t_tile_format	tiles;
	t_background	background;
};

typedef struct t_2d_hook t_2d_hook;

struct t_2d_hook
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_camera		*camera;
	t_master_piece	master_piece;
};

typedef enum e_drawing_target e_drawing_target;

enum e_drawing_target
{
	E_MINIMALISM,
	E_MOTIF,
	E_STILL_LIFE
};

// draw_fdf.c
void	draw_fdf_mlx(t_2d_hook *hook, bool is_draw);

// hook.c
void 			hook_absolute_cinema(mlx_key_data_t keydata,
	void *param);

// init_fdf.c
t_fdf		init_fdf(t_table_fdf *src);
bool		is_fdf_valid(const t_fdf *src);
void		free_fdf(t_fdf *src);

// linalg.c
float	linear_map_fdf(const t_fdf *src, t_matrix matrix, size_t i, char axis);
void	linear_map_fdf_all(t_fdf *src, t_matrix matrix);

// motif.c
void	draw_motif_mlx(t_2d_hook *hook, bool is_draw);

// tile_format.c
t_fline	init_offset_tile(size_t width, size_t height,
	size_t resolution, size_t fixed_length);
t_tile_format	init_tile_format(size_t width,
	size_t height, size_t resolution);
t_2d_int	get_first_interier_tile(t_tile_format tiles,
	t_2d_camera camera);
t_2d_int	get_last_interier_tile(t_tile_format tiles,
	t_2d_camera camera);
t_2d_int	get_ith_tile_screen(t_tile_format tiles,
	t_2d_camera camera, int ix, int iy);

// tile.c
size_t	init_tile_size(size_t side_length, size_t resolution);
size_t	init_alltiles_count(size_t side_length,
	size_t resolution, size_t fixed_length);
size_t	init_alltiles_size(size_t side_length,
	size_t resolution, size_t fixed_length);
int	init_alltiles_offset(size_t side_length,
	size_t resolution, size_t fixed_length);

// utils.c
bool			is_2dhook_valid(const t_2d_hook *src,
					e_drawing_target drawing_target);
bool			is_valid_key(mlx_key_data_t keydata);
void			write_line(t_line src);
t_2d_camera		init_2d_camera(size_t width, size_t height);
t_line		connecting_2d_point_pair(t_2d_int p1, t_2d_int p2);

// view
void	view_master_piece(t_fdf *still_life, t_motif_arr *motif,
	t_ink32 drawing_style, t_background background);

// world_to_screen.c
int	world_to_screen_xy(int offset, float world);
t_2d_int	world_to_screen_2d(t_2d_camera camera, t_complex world);
t_2d_int	world_3d_to_screen_2d(t_2d_camera camera,
	float x, float y);
bool	is_line_in_screen(t_2d_camera camera,
	t_2d_int src);
bool	is_circle_in_screen(t_2d_camera camera,
	t_2d_int src, int thickness);

#endif
