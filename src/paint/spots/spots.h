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
#include "../aura/aura.h"

// complex.c

bool	spots_andmod_custom(t_double2d x,
			t_double2d (*complex_func)(t_double2d a));
bool	spots_aura_custom(t_double2d x,
			int (*aura_custom)(int x, int y, int z),
			t_double2d (*complex_func)(t_double2d a));

// edge.c

bool	is_available_left(size_t col, size_t row, size_t index);
bool	is_available_right(size_t col, size_t row, size_t index);
bool	is_available_up(size_t col, size_t row, size_t index);
bool	is_available_down(size_t col, size_t row, size_t index);
bool	is_edge_frame(size_t col, size_t row, size_t index);

// power.c

bool	spots_oddlength_22(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x2(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x3(const t_fdf_table *dst, size_t index);
bool	spots_bugs_x2(const t_fdf_table *dst, size_t index);
bool	spots_bugs_x3(const t_fdf_table *dst, size_t index);
bool	spots_oddlength_x4(const t_fdf_table *dst, size_t index);
bool	spots_max_x2(const t_fdf_table *dst, size_t index);
bool	spots_max_x3(const t_fdf_table *dst, size_t index);
bool	spots_fermat_x2(const t_fdf_table *dst, size_t index);
bool	spots_fermat_x3(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x2(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x3(const t_fdf_table *dst, size_t index);
bool	spots_andmod_x4(const t_fdf_table *dst, size_t index);

// paint.c

void	paint_spots_fdf_table(t_fdf_table *dst, int color,
			t_fdf_channel channel, bool (*spots)(const t_fdf_table *dst, size_t index));

// space.c

size_t	count_neighbor_fdf_table(const t_fdf_table *dst, size_t index);
bool	spots_boundary(const t_fdf_table *dst, size_t index);
bool	spots_space(const t_fdf_table *dst, size_t index);
bool	spots_chess(const t_fdf_table *dst, size_t index);

#endif
