/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motif.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:15:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 12:13:55 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTIF_H
# define MOTIF_H

# include "../raster/raster.h"
# include "motif_type.h"

// public.c

void	view_motif(t_motif_arr *src,
			int32_t background_color, size_t resolution);

#endif
