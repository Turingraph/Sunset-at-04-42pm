/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aura.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:15:35 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/27 14:54:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AURA_H
# define AURA_H

# include "../../utils/taylor/taylor.h"
# include "../../utils/libft/libft.h"
# include <fcntl.h>

// arithmetic.c

int		aura_root2(int x, int y, int z);
int		aura_root3(int x, int y, int z);
int		aura_addsub(int x, int y, int z);
int		aura_fermat(int x, int y, int z);

// inequality.c

int		aura_inequality_triangle(int x, int y, int z);
int		aura_inequality_amgm(int x, int y, int z);
int		aura_inequality_cauchy(int x, int y, int z);
int		aura_inequality_addmul(int x, int y, int z);

// metric.c

int		aura_pythagoras(int x, int y, int z);
int		aura_max(int x, int y, int z);
int		aura_min(int x, int y, int z);

// paint.c

void	paint_aura_fdf_table(t_fdf_table *dst,
			t_fdf_channel channel,
			int (*aura_custom)(int x, int y, int z));

#endif
