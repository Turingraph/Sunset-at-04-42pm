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
		|| check_multiplication_overflow_uint32_t(src->mlx->width, src->mlx->height) == false
		|| check_multiplication_overflow_uint32_t(src->img->width, src->img->height) == false
		|| is_fdf_projection2d_valid(src->fdf) == false)
		return (false);
	return (true);
}
