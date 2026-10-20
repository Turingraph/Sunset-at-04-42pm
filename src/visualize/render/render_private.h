/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 19:02:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:31:07 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_PRIVATE_H
# define DISPLAY_PRIVATE_H

# include "render_type.h"

// geometry.c

bool		is_line_in_screen(t_camera2d camera,
				t_line src);
bool		is_circle_in_screen(t_camera2d camera,
				t_int2d src, int radius);
float		init_fdf_point1d(t_fdf_proj2d *fdf, t_int2d ixiy, size_t dim, char next);
t_int2d	world_to_screen2d(t_camera2d camera, float x, float y);
bool		isvalid_hook2d(const t_hook2d *src);

// render_*.c

void		render_kusama(t_hook2d *hook, bool is_draw);
void		render_picasso(t_hook2d *hook, bool is_draw);
void		render_tobyfox(t_hook2d *hook, bool is_draw);

// render.c

t_style_raster		hook_to_raster(t_hook2d *hook, bool is_draw, t_int2d ixiy);
void		render_circle(t_int2d point,
				t_style_raster ink, t_camera2d camera, mlx_image_t *img);
void		render_rectangle(t_line line, int32_t ink,
				t_camera2d camera, mlx_image_t *img);
void		render_line(t_line line, t_style_raster ink,
				t_camera2d camera, mlx_image_t *img);

// public.c

void		render_fdf(t_hook2d *hook, bool is_draw);

#endif
