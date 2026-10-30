/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:43:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 11:42:01 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_PRIVATE_H
# define WINDOW_PRIVATE_H

# include "../render/render.h"
# include "../../input/table/table.h"

# ifndef ZOOM_LEVEL
#  define ZOOM_LEVEL 1.1
# endif

# ifndef ZOOM_MAX
#  define ZOOM_MAX 8
# endif

# ifndef ZOOM_MIN
#  define ZOOM_MIN 0.2
# endif

// hook.c

void		hook_controller(mlx_key_data_t keydata, void *param);

// init_hook2d.c

t_camera2d	init_camera2d(size_t window_width, size_t window_height);
t_hook2d	init_hook2d(mlx_t *mlx, t_fdf_proj2d *fdf, t_style_render style_render, int32_t background_color);
void		normalize_fdf_proj2d(t_fdf_proj2d *src,
				size_t fixed_window_size);

// public.c

void		view_fdf_proj2d(t_fdf_proj2d *fdf, t_style_render style_render, int32_t background_color);
void		view_fdf_pixel_art(t_fdf_table *src, int32_t background_color);

// verify.c

bool		isvalid_key(mlx_key_data_t keydata);
bool		isvalid_pan_key(mlx_key_data_t keydata);
bool		isvalid_zoom_key_x(mlx_key_data_t keydata, float zoom);
bool		isvalid_zoom_key_y(mlx_key_data_t keydata, float zoom);
bool		isvalid_zoom_key(mlx_key_data_t keydata, float zoom_x, float zoom_y);
bool		isvalid_invert_key(mlx_key_data_t keydata);

#endif
