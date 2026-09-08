/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:30:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:30:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_private.h"

// time : O(1)
// space: O(1)
bool	is_2dhook_valid(const t_2d_hook *src)
{
	if (src == NULL
		|| src->camera == NULL
		|| src->img == NULL
		|| src->mlx == NULL
		|| is_fdf_valid(src->master_piece.fdf) == false)
		return (false);
	return (true);
}
