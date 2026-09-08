/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:22:46 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:22:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_private.h"

// time : O(1)
// space: O(1)
t_line	init_draw_line_y(t_2d_camera camera, t_fdf *fdf, t_2d_int ixiy)
{
	t_line		line;

	line.p1 = world_3d_to_screen_2d(camera,
			get_fdf_point(fdf, ixiy, 1, 0),
			get_fdf_point(fdf, ixiy, 2, 0));
	line.p2 = world_3d_to_screen_2d(camera,
			get_fdf_point(fdf, ixiy, 1, 2),
			get_fdf_point(fdf, ixiy, 2, 2));
	return (line);
}

// time : O(1)
// space: O(1)
t_line	init_draw_line_x(t_2d_camera camera, t_fdf *fdf, t_2d_int ixiy)
{
	t_line		line;

	line.p1 = world_3d_to_screen_2d(camera,
			get_fdf_point(fdf, ixiy, 1, 0),
			get_fdf_point(fdf, ixiy, 2, 0));
	line.p2 = world_3d_to_screen_2d(camera,
			get_fdf_point(fdf, ixiy, 1, 1),
			get_fdf_point(fdf, ixiy, 2, 1));
	return (line);
}
