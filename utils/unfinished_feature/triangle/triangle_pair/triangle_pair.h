#ifndef TRIANGLE_PAIR_H
# define TRIANGLE_PAIR_H

# include "../../utils/libft/libft.h"
# include "../../utils/linalg/linalg.h"

// graphic/triangle_pair/

typedef struct t_triangle t_triangle;

struct t_triangle
{
	float			*p1;
	float			*p2;
	float			*p3;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

// graphic/triangle_arr/

typedef struct t_triangle_arr t_triangle_arr;

struct t_triangle_arr
{
	t_triangle	*arr;
	size_t		length;
	size_t		capacity;
	size_t		table_row;
	size_t		table_col;
	float		width_x;
	float		width_y;
	float		width_z;
};

// graphic/prism/

typedef struct t_prism t_prism;

struct t_prism
{
	t_triangle_arr	faces;
	t_triangle_arr	edges;
};

typedef enum e_edge e_edge;

enum e_edge
{
	EDGE_X,
	EDGE_Y,
	EDGE_DIAGONAL_LEFT,
	EDGE_DIAGONAL_RIGHT,
	EDGE_INVALID
};

typedef enum e_sampling_rgba e_sampling_rgba;

enum e_sampling_rgba
{
	SAMPLE_TOP_LEFT,
	SAMPLE_AVERAGE,
	SAMPLE_EDGE_AVERAGE
};

typedef enum e_3d_shape e_3d_shape;

enum e_3d_shape
{
	ISOMETRIC,
	PRISM_MODE2,
	PRISM_CROSS,
	// PRISM_VOXEL,
	// VOXEL
};

// bool.c
bool			is_edge_x(const t_table_fdf *src, size_t index, bool is_voxel);
bool			is_edge_y(const t_table_fdf *src, size_t index, bool is_voxel);
bool			is_edge_diagonal_lr(const t_table_fdf *src,
					size_t index, bool is_left);

// color.c
void			average_tri_coloring(const t_table_fdf *src,
					size_t index, t_triangle *dst);
void			topleft_tri_coloring(const t_table_fdf *src,
					size_t index, t_triangle *dst);
void			edge_average_tri_coloring(const t_table_fdf *src,
					t_triangle_arr *dst);

// debug.c
void	write_2d_index(int max_col, int row, int col);

// edge.c
t_triangle_arr	f_fdf_edge(const t_table_fdf *src,
					size_t index, e_edge mode, bool is_voxel);

// face.c
t_triangle_arr	f_fdf_face(const t_table_fdf *src,
					size_t index, e_3d_shape shape);

// init.c
void			*free_triangle(t_triangle *src);
void			*free_triangle_arr(t_triangle_arr *src,
					size_t delete_1st_triangle);
t_triangle		init_triangle(void);
t_triangle_arr	init_triangle_arr(size_t length, size_t row, size_t col);
float			height_of_triangle(const t_triangle *src,
					size_t axis, bool is_greater);

// write.c
void			write_3d_vector(int fd, const float *vec_v);
void			write_triangle(int fd, const t_triangle *src);
void			write_triangle_arr(int fd, const t_triangle_arr *src);
void			write_triangle_arr_meta(int fd, const t_triangle_arr *src);
void			write_triangle_pair_graphic(const t_table_fdf *src,
					size_t index);

/*
To Do List
1.	check if f_fdf_edge works correctly for EDGE_DIAGONAL_LEFT and EDGE_DIAGONAL_RIGHT
2.	check if f_fdf_face works correctly
3.	display the image
4.	camera
5.	write README.md
*/

#endif
