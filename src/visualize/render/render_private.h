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

bool		is_line_in_screen(t_2d_camera camera,
				t_line src);
bool		is_circle_in_screen(t_2d_camera camera,
				t_2d_int src, int radius);
float		get_fdf_point(t_fdf_proj2d *fdf, t_2d_int ixiy, size_t dim, char next);
t_2d_int	world_to_screen2d(t_2d_camera camera, float x, float y);
bool		is_2dhook_valid(const t_2d_hook *src);

// render_*.c

void		render_kusama(t_2d_hook *hook, bool is_draw);
void		render_picasso(t_2d_hook *hook, bool is_draw);
void		render_tobyfox(t_2d_hook *hook, bool is_draw);

// render.c

t_raster_style		hook_to_raster(t_2d_hook *hook, bool is_draw, t_2d_int ixiy);
void		render_circle(t_2d_int point,
				t_raster_style ink, t_2d_camera camera, mlx_image_t *img);
void		render_rectangle(t_line line, int32_t ink,
				t_2d_camera camera, mlx_image_t *img);
void		render_line(t_line line, t_raster_style ink,
				t_2d_camera camera, mlx_image_t *img);

// public.c

void		render_fdf(t_2d_hook *hook, bool is_draw);

#endif
