/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:56:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 19:02:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "render_type.h"

// public.c

void		render_fdf(t_hook2d *hook, bool is_draw);

// utils.c

bool		isvalid_hook2d(const t_hook2d *src);

#endif
