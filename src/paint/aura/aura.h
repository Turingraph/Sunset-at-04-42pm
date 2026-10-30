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

# ifndef AURA_PIANISSIMO
#  define AURA_PIANISSIMO 0.025
# endif

# ifndef AURA_PIANO
#  define AURA_PIANO 0.05
# endif

# ifndef AURA_MEZZO
#  define AURA_MEZZO 0.075
# endif

# ifndef AURA_FORTE
#  define AURA_FORTE 0.1
# endif

// arithmetic.c

int			aura_root2(double x, double y, double z);
int			aura_root3(double x, double y, double z);
int			aura_addsub(double x, double y, double z);
int			aura_fermat(double x, double y, double z);

// hypnotize_fractal.c

int			aura_hypnotize_no2(double x, double y, double z);
int			aura_hypnotize_no3(double x, double y, double z);
int			aura_fractal_no2(double x, double y, double z);
int			aura_fractal_no3(double x, double y, double z);

// inequality.c

int			aura_inequality_triangle(double x, double y, double z);
int			aura_inequality_amgm(double x, double y, double z);
int			aura_inequality_cauchy(double x, double y, double z);
int			aura_inequality_addmul(double x, double y, double z);

// math_rock.c

int			aura_disco_no2(double x, double y, double z);
int			aura_disco_no3(double x, double y, double z);
int			aura_chainsawman_no2(double x, double y, double z);
int			aura_chainsawman_no3(double x, double y, double z);

// metric.c

int			aura_pythagoras(double x, double y, double z);
int			aura_max(double x, double y, double z);
int			aura_min(double x, double y, double z);

// paint.c

t_double2d	complex_x2(t_double2d a);
t_double2d	complex_x3(t_double2d a);
void		paint_aura_fdf_table(t_fdf_table *dst,
				double zoom,
				t_fdf_channel channel,
				int (*aura_custom)(double x, double y, double z));
int			aura_custom_andmod(t_double2d x, double z,
				t_double2d (*complex_func)(t_double2d a));
int			aura_custom_bi(t_double2d x, double z,
					int (*aura_custom)(double x, double y, double z),
					t_double2d (*complex_func)(t_double2d a));

#endif
