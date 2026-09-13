/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 11:36:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:23:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_private.h"

/**
 * Draw or erase an FDF object on an MLX image.
 *
 * The FDF is rendered using the current 2D camera and drawing style stored
 * in the supplied hook.
 *
 * When is_draw is true, the color stored in each FDF cell is used when
 * available. When is_draw is false, the FDF is drawn using the background
 * color, allowing the previous rendering to be erased before updating
 * the object.
 *
 * The hook must contain a valid MLX image, camera, and FDF object.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param hook FDF view context containing the image, camera, and FDF object
 * @param is_draw true to draw the FDF, false to erase it
 */
void	draw_fdf_mlx(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	if (is_2dhook_valid(hook) == false)
		return ;
	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artist == E_PICASSO)
		draw_picasso_fdf(hook, is_draw, thickness);
	if (hook->master_piece.artstyle.artist == E_KUSAMA)
		draw_kusama_fdf(hook, is_draw, thickness);
	if (hook->master_piece.artstyle.artist == E_TOBY_FOX)
		draw_toby_fox_fdf(hook, is_draw);
	if (hook->master_piece.artstyle.artist == E_TUYOKI)
		draw_tuyoki_fdf(hook, is_draw);
	if (hook->master_piece.artstyle.artist == E_PIET_MONDRIAN)
		draw_piet_mondrian_fdf(hook, is_draw);
	draw_hirohiko_araki_fdf(hook, is_draw);
	draw_dijkstra_fdf(hook, is_draw);
	draw_poincare_fdf(hook, is_draw);
	draw_warhol_fdf(hook, is_draw);
	draw_euler_fdf(hook, is_draw);
}
