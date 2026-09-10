#ifndef TRIANGLE_ARR_H
# define TRIANGLE_ARR_H

# include "../triangle_pair/triangle_pair.h"

// all_faces.c
t_triangle_arr	all_triangle_faces(const t_table_fdf *src, e_3d_shape shape);
t_triangle_arr	all_triangle_edge_x(const t_table_fdf *src, bool is_voxel);
t_triangle_arr	all_triangle_edge_y(const t_table_fdf *src, bool is_voxel);
t_triangle_arr	all_triangle_edge_lr(const t_table_fdf *src, e_edge mode);
bool			is_triangle_arr_valid(t_triangle_arr *src);

// center.c
float			update_width_of_triangle_arr(t_triangle_arr *src, size_t axis);
float			center_triangle_arr(t_triangle_arr *src, size_t axis);
float			average_triangle_arr(t_triangle_arr *src,
					size_t axis, bool is_update);
void			center_prism(t_prism *src);

// concat.c
t_triangle_arr	copy_triangle_arr(t_triangle_arr *src, size_t length);
t_triangle_arr	clone_triangle_arr(const t_triangle_arr *src, size_t length);
size_t			concat_triangle_arr(t_triangle_arr *dst, t_triangle_arr *src);

// prism.c
t_prism			table_to_prism(const t_table_fdf *src,
					float width, bool is_2faces, e_3d_shape shape);
void			free_prism(t_prism *src);

// rotation.c
void			rotate_triangle_arr(t_triangle_arr *src,
					float delta, char axis);

// scale.c
void			hadamard_triangle_arr(t_triangle_arr *src,
					float scale, size_t axis);
void			shift_triangle_arr(t_triangle_arr *src,
					float shift, size_t axis);
void			setback_triangle_arr(t_triangle_arr *src,
					float shift, size_t axis);
void			setwidth_triangle_arr(t_triangle_arr *src,
					float shift, size_t axis);
t_triangle_arr	push_back_to_triangle_arr(t_triangle_arr *src,
					float width, bool is_2faces);

#endif
