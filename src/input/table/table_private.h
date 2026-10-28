/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:54:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 17:01:21 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_PRIVATE_H
# define TABLE_PRIVATE_H

# include <stdlib.h>
# include "../../input/decimal/decimal.h"
# include "../../utils/taylor/taylor.h"

// create.c

void			destroy_fdf_table(t_fdf_table *src);
t_fdf_table		create_fdf_table(size_t row, size_t col, bool is_rgba);
t_fdf_table		fdfload_to_fdftable(const t_fdf_load_arr *src, bool is_rgba);

// load.c

t_fdf_table		load_fdf_table(const char *file_name,
					t_fdf_format format, bool is_rgba);

// positive.c

int				fdf_table_minmax(const t_fdf_table *dst,
					bool is_max, t_fdf_channel channel);
void			positive_fdf_table(t_fdf_table *dst);
void			relu_fdf_table(t_fdf_table *dst, int min, int max, int expect);
void			abs_fdf_table(t_fdf_table *dst);

// scale_dim.c

unsigned char	*scale_dim_fdf_table_rgba(const t_fdf_table *src,
					size_t scale_row, size_t scale_col, t_fdf_channel rgba_type);
int				*scale_dim_fdf_table_int(const t_fdf_table *src,
					size_t scale_row, size_t scale_col);
t_fdf_table		scale_dim_fdf_table(const t_fdf_table *src,
					size_t scale_row, size_t scale_col);

// scale.c

void			scale_fdf_table(t_fdf_table *dst,
					float scale, t_fdf_channel channel);
void			add_fdf_table(t_fdf_table *dst,
					int input, t_fdf_channel channel);
void			mix_add_fdf_table(t_fdf_table *dst,
					const t_fdf_table *src, t_fdf_channel channel);
void			mix_hadamard_fdf_table(t_fdf_table *dst,
					const t_fdf_table *src, t_fdf_channel channel);
void			copy_fdf_table_channel(t_fdf_table *dst,
					const t_fdf_table *src, t_fdf_channel channel);

// write.c

void			write_fdf_table_custom(int fd, const t_fdf_table *src,
					t_fdf_channel channel, const char *dict);
void			write_fdf_table(int fd, const t_fdf_table *src,
					t_fdf_channel channel, t_fdf_format format);

#endif
