/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convolve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:16:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 14:30:05 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVOLVE_H
# define CONVOLVE_H

# include "../../utils/taylor/taylor.h"
# include "../../input/table/table.h"

typedef struct t_matrix
{
	size_t	row;
	size_t	col;
	float	*arr;
}	t_matrix;

// convolve_height.c

t_fdf_table	convolve_fdf_table(const t_fdf_table *src, float *kernel,
				size_t dim);

// kernel.c

float		*kernel_edge1d(size_t inner_dim, size_t outer_dim,
				float inner_num, float outer_num);
float		init_outer_num(float inner_dim, float outer_dim, float input, float kernel_sum);
float		*kernel_edge(size_t inner_dim, size_t outer_dim, float input, float kernel_sum);
float		*kernel_gauss1d(size_t half_dim, float std);
float		*kernel_gauss(size_t half_dim, float std_1, float std_2);

// matrix.c

void		*destroy_matrix(t_matrix *src);
t_matrix	create_matrix(size_t row, size_t col, float scale);
t_matrix	outer_product(const float *vec_v,
				const float *vec_u, size_t dim);
bool		isvalid_matrix(const t_matrix *src);
bool		is_matrix_same_dim(const t_matrix *a, const t_matrix *b);

// utils.c

float		dot_product(const float *vec_v, const float *vec_u, size_t dim);

#endif
