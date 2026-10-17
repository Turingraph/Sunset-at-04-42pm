/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:22:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:22:25 by phsottat         ###   ########.fr       */
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
unsigned char	*get_rgba_of_table_fdf(const t_table_fdf *src,
					t_fdf_channel rgba_type);
t_2d_float		get_table_fdf_coordinate(const t_table_fdf *dst, size_t index, float zoom);
bool			check_multiplication_overflow(size_t col, size_t row);
bool			check_multiplication_overflow_uint32_t(uint32_t col, uint32_t row);

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

#endif
