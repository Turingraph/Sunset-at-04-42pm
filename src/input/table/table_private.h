/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:54:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 12:53:33 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_PRIVATE_H
# define TABLE_PRIVATE_H

# include <stdlib.h>
# include "../../input/decimal/decimal.h"
# include "../../utils/taylor/taylor.h"

// init.c

void			destroy_fdf_table(t_fdf_table *src);
t_fdf_table		create_fdf_table(size_t row, size_t col, bool is_rgba);
t_fdf_table		fdf_load_table(const t_fdf_load_arr *src, bool is_rgba);

// positive.c

int				fdf_table_minmax(const t_fdf_table *dst,
					bool is_max, t_fdf_channel channel);
void			scale_positive_fdf(t_fdf_table *dst);
void			scale_relu_fdf(t_fdf_table *dst, int min, int max, int expect);

// public.c

t_fdf_table		load_fdf_table_file(const char *file_name, const char *dir,
					t_fdf_load (*one_line)(char *line), bool is_rgba);

// scale_dimension.c

unsigned char	*scale_dimension_fdf_rgba(const t_fdf_table *src,
					size_t scale_row, size_t s_col, t_fdf_channel rgba_type);
int				*scale_dimension_fdf_int(const t_fdf_table *src,
					size_t scale_row, size_t s_col);
t_fdf_table		scale_dimension_fdf(const t_fdf_table *src,
					size_t scale_row, size_t scale_col);

// scale.c

void			scale_multiplication_fdf(t_fdf_table *dst,
					float scale, t_fdf_channel channel);
void			scale_addition_fdf(t_fdf_table *dst,
					int input, t_fdf_channel channel);
void			fdf_table_addition(t_fdf_table *dst,
					const t_fdf_table *src, t_fdf_channel channel);
void			fdf_table_hadamard(t_fdf_table *dst,
					const t_fdf_table *src, t_fdf_channel channel);
void			copy_fdf_table_channel(t_fdf_table *dst,
					const t_fdf_table *src, t_fdf_channel channel);

// shade.c

void			write_table_ascii_cheche01(int fd,
					const t_fdf_table *src, t_fdf_channel channel);
void			write_table_ascii_standard(int fd,
					const t_fdf_table *src, t_fdf_channel channel);
void			write_table_ascii_chungaloider(int fd,
					const t_fdf_table *src, t_fdf_channel channel);

// write.c

void			write_fdf_table(int fd,
					const t_fdf_table *src, size_t digits, t_fdf_write_mode mode);
void			write_table_ascii(int fd, const t_fdf_table *src,
					t_fdf_channel channel, const char *dict);

#endif
