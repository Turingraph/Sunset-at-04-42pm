/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:16:58 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:16:59 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_private.h"

// time : O(n)
// space: O(1)
void	draw_euler_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_EULER)
		return ;
	draw_picasso_fdf_noend(hook, is_draw, thickness);
	draw_kusama_fdf(hook, is_draw, thickness * 3 / 2);
}

// time : O(n)
// space: O(1)
void	draw_poincare_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_POINCARE)
		return ;
	draw_kusama_fdf(hook, is_draw, thickness);
	if (is_draw == true)
		draw_kusama_fdf(hook, false, thickness * 4 / 5);
}

// time : O(n)
// space: O(1)
void	draw_dijkstra_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_DIJKSTRA)
		return ;
	draw_picasso_fdf_noend(hook, is_draw, thickness);
	draw_kusama_fdf(hook, is_draw, thickness * 3 / 2);
	if (is_draw == true)
		draw_kusama_fdf(hook, false, thickness * 4 / 5);
}

// time : O(n)
// space: O(1)
void	draw_warhol_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_WARHOL)
		return ;
	draw_toby_fox_fdf(hook, is_draw);
	draw_picasso_fdf(hook, false, thickness * 4 / 5);
}

// time : O(n)
// space: O(1)
void	draw_hirohiko_araki_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_HIROHIKO_ARAKI)
		return ;
	draw_toby_fox_fdf(hook, is_draw);
	if (is_draw == true)
	{
		draw_picasso_fdf_noend(hook, false, thickness);
		draw_kusama_fdf(hook, false, thickness * 3 / 2);
		draw_kusama_fdf(hook, true, thickness * 4 / 5);
	}
	else
		draw_kusama_fdf(hook, false, thickness * 4 / 5);
}
