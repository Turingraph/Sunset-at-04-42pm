/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spots.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:15:42 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 11:15:58 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOTS_H
# define SPOTS_H

#include "../../utils/libft/libft.h"
#include "../../utils/taylor/taylor.h"

// binary_search.c

size_t	binary_search_count(size_t min_input, size_t max_input);
bool	spots_oddlength_bisearch(const t_fdf_table *dst, size_t index);
bool	spots_oddtime_bisearch(const t_fdf_table *dst, size_t index);
bool	spots_andmod_bisearch(const t_fdf_table *dst, size_t index);

// collatz.c

size_t	collatz_max_point(size_t x);
bool	spots_oddlength_collatz(const t_fdf_table *dst, size_t index);
bool	spots_oddtime_collatz(const t_fdf_table *dst, size_t index);
bool	spots_andmod_collatz(const t_fdf_table *dst, size_t index);

// generic.c

bool	spots_diffreim2odd_func(const t_fdf_table *dst, size_t index,
			t_float2d (*complex_func)(t_float2d a), float zoom);
bool	spots_diffreim2odd(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_func(const t_fdf_table *dst, size_t index,
			t_float2d (*complex_func)(t_float2d a), float zoom);
bool	spots_oddlength(const t_fdf_table *dst, size_t index);
bool	spots_andmod_func(const t_fdf_table *dst, size_t index,
			t_float2d (*complex_func)(t_float2d a), float zoom);

// paint.c

bool	spots_boundary(const t_fdf_table *dst, size_t index, int threshold);
bool	spots_space(const t_fdf_table *dst, size_t index);
bool	spots_chess(const t_fdf_table *dst, size_t index);
void	paint_spots_fdf_table(t_fdf_table *dst, int color,
			t_fdf_channel channel, bool (*spots)(const t_fdf_table *dst, size_t index));

// polynomial_andmod.c

bool	spots_andmod_x2(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x3(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x4(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x5(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x6(const t_fdf_table *dst, size_t index);

// polynomial_length.c

bool	spots_oddlength_x2(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x3(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x4(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x5(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x6(const t_fdf_table *dst, size_t index);

// polynomial_shadow.c

bool	spots_oddlength_x2shadow(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x3shadow(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x2shadow(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x3shadow(const t_fdf_table *dst, size_t index);

// trigonometry.c

bool	spots_oddlength_sin(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_cos(const t_fdf_table *dst, size_t index);
bool	spots_andmod_sin(const t_fdf_table *dst, size_t index);
bool	spots_andmod_cos(const t_fdf_table *dst, size_t index);

#endif
