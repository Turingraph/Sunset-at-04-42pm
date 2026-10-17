/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:30:40 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 14:29:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINALG_H
# define LINALG_H

# include "stdlib.h"
# include "../taylor/taylor.h"
# include "../libft/libft.h"

typedef struct t_matrix
{
	size_t	row;
	size_t	col;
	float	*arr;
}	t_matrix;

// euclid.c

float		euclid_distance(const float *vec_v,
				const float *vec_0, size_t dim, char square);
float		cos_between_2_vectors(const float *vec_v,
				const float *vec_u, size_t dim);
void		vector_projection(float *update_v, const float *vec_u, size_t dim);
float		scale_projection(const float *vec_v,
				const float *vec_u, size_t dim);

// matrix_3d.c

t_matrix	init_inverse_3d_matrix(t_matrix src);
t_matrix	init_3d_zoom_matrix(float zoom);
void		matrix_3d_product(t_matrix src, t_matrix *dst);
float		matrix_det_3d(t_matrix src);

// rotate_3d.c

t_matrix	init_3d_rotate_matrix_x(float delta);
t_matrix	init_3d_rotate_matrix_y(float delta);
t_matrix	init_3d_rotate_matrix_z(float delta);

// matrix.c

void		*free_matrix(t_matrix *src);
t_matrix	init_matrix(size_t row, size_t col, float scale);
t_matrix	outer_product_matrix(const float *vec_v,
				const float *vec_u, size_t dim);
bool		is_matrix_valid(const t_matrix *src);
bool		is_matrix_same_dim(const t_matrix *a, const t_matrix *b);

// vector_3d.c

void		cross_product_3d(float *update_v, const float *vec_u);
void		update_3d_vector(float *dst, float x, float y, float z);
float		*init_3d_vector(float x, float y, float z);

// vector.c

float		*vector_add(float *update_v, const float *vec_u, size_t dim);
float		*hadamard_product(float *update_v, const float *vec_u, size_t dim);
void		vector_scale(float *update_v, float s, size_t dim);
float		dot_product(const float *vec_v, const float *vec_u, size_t dim);

#endif
