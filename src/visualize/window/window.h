/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:59:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 11:38:57 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "../render/render.h"
# include "../../input/table/table.h"

// public.c

void		view_fdf_proj2d(t_fdf_proj2d *fdf, t_style_render drawing_style, int32_t background_color);
void		view_fdf_pixel_art(t_fdf_table *src, int32_t background_color);
void		view_fdf_pixel_art_conformal(t_fdf_table *src, int32_t background_color, double scale, t_double2d (*complex_map)(t_double2d a));

#endif
