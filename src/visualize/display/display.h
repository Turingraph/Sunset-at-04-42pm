/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:56:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 19:02:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "display_type.h"

// public.c

void		draw_fdf_mlx(t_2d_hook *hook, bool is_draw);

// utils.c

bool		is_2dhook_valid(const t_2d_hook *src);

#endif
