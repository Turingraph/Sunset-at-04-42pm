/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:22:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 13:09:05 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "type.h"

// abs.c

float			f_abs(float x);
int				f_abs_int(int x);

// arr.c

void			*malloc_talk(size_t elem_size, const char *comment);
unsigned char	*rgbarr_from_table(const t_fdf_table *src,
					t_fdf_channel rgba_type);
t_float2d		init_table_coordinate(const t_fdf_table *dst, size_t index, float zoom);

// interval.c

float			f_floor(float num);
float			f_round(float num);
float			f_interval(float num, float min, float max);
int				f_interval_int(int num, int min, int max);

// minmax.c

float			f_max(float a, float b);
float			f_min(float a, float b);
int				f_max_int(int a, int b);
int				f_min_int(int a, int b);

// overflow.c

bool			mul_overflow_size_t(size_t col, size_t row);
bool			mul_overflow_uint32_t(uint32_t col, uint32_t row);
bool			mul_overflow_int(int a, int b);
bool			add_overflow_int(int a, int b);

#endif
