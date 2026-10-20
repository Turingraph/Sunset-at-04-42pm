/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 11:36:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 11:42:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_private.h"

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
void	render_fdf(t_hook2d *hook, bool is_draw)
{
	if (isvalid_hook2d(hook) == false)
		return ;
	if (hook->style_render.shape2d == SHAPE2D_LINE)
		render_picasso(hook, is_draw);
	if (hook->style_render.shape2d == SHAPE2D_CIRCLE)
		render_kusama(hook, is_draw);
	if (hook->style_render.shape2d == SHAPE2D_RECTANGLE)
		render_tobyfox(hook, is_draw);
}
