/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:54:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:35:29 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_PRIVATE_H
# define TABLE_PRIVATE_H

# include <stdlib.h>
# include "../../input/load/load.h"
# include "../../utils/green_counts/green_counts.h"

// init.c

void			free_table_fdf(t_table_fdf *src);
t_table_fdf		init_table_fdf(size_t row, size_t col, bool is_rgba);
t_table_fdf		load_table_fdf(const t_load_fdf_arr *src, bool is_rgba);

// positive.c

int				get_minmax_from_table_fdf(const t_table_fdf *dst,
					bool is_max, t_enum_rgba channel);
void			scale_positive_fdf(t_table_fdf *dst);
void			scale_relu_fdf(t_table_fdf *dst, int min, int max, int expect);

// public.c

t_table_fdf		open_table_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*one_line)(char *line), bool is_rgba);

// scale_dimension.c

unsigned char	*scale_dimension_fdf_rgba(const t_table_fdf *src,
					size_t s_row, size_t s_col, t_enum_rgba rgba_type);
int				*scale_dimension_fdf_int(const t_table_fdf *src,
					size_t s_row, size_t s_col);
t_table_fdf		scale_dimension_fdf(const t_table_fdf *src,
					size_t scale_row, size_t scale_col);

// scale.c

void			scale_multiplication_fdf(t_table_fdf *dst,
					float scale, t_enum_rgba channel);
void			scale_addition_fdf(t_table_fdf *dst,
					int input, t_enum_rgba channel);
void			table_fdf_addition(t_table_fdf *dst,
					const t_table_fdf *src, t_enum_rgba channel);
void			table_fdf_hadamard(t_table_fdf *dst,
					const t_table_fdf *src, t_enum_rgba channel);
void			copy_table_fdf_channel(t_table_fdf *dst,
					const t_table_fdf *src, t_enum_rgba channel);

// shade.c

void			write_table_ascii_cheche01(int fd,
					const t_table_fdf *src, t_enum_rgba channel);
void			write_table_ascii_standard(int fd,
					const t_table_fdf *src, t_enum_rgba channel);
void			write_table_ascii_chungaloider(int fd,
					const t_table_fdf *src, t_enum_rgba channel);

// write.c

void			write_table_fdf(int fd,
					const t_table_fdf *src, size_t digits, t_write_style mode);
void			write_table_ascii(int fd, const t_table_fdf *src,
					t_enum_rgba channel, const char *dict);

#endif
