/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:18:18 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 16:23:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_H
# define PAINT_H

# include "../../utils/taylor/taylor.h"
# include "../../utils/libft/libft.h"
# include <fcntl.h>

/**
 * Defines a color input for t_gradient argument of the function `paint_gradient_fdf_table`
 * 
 * If the color channel is less than 0, then the color isn't render.
 */
typedef struct t_input_rgba
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_input_rgba;

typedef enum t_gradient_channel
{
	GRADIENT_RED,
	GRADIENT_GREEN,
	GRADIENT_BLUE,
	GRADIENT_ALPHA,
	GRADIENT_ROW,
	GRADIENT_COL,
	GRADIENT_HEIGHT
}	t_gradient_channel;

/**
 * Defines a color gradient over a selected cell property.
 *
 * cell_channel selects the property used to determine the gradient position.
 * input_start and input_end define the affected range.
 * rgba_start and rgba_end define the colors at the range boundaries.
 */
typedef struct t_gradient
{
	t_input_rgba		rgba_start;
	t_input_rgba		rgba_end;
	t_gradient_channel	cell_channel;
	int					input_start;
	int					input_end;
}	t_gradient;

// boundary.c

bool	is_boundary_fdf(const t_fdf_table *dst, size_t index, int threshold);
int		count_neighbor_fdf(const t_fdf_table *dst, size_t index, int threshold);

// filter.c

bool	is_space_fdf(const t_fdf_table *dst, size_t index);
bool	is_chess_fdf(const t_fdf_table *dst, size_t index);
void	set_cells_color(t_fdf_table *dst, int color, t_fdf_channel channel,
			bool (*is_filtered_cell)(const t_fdf_table *dst, size_t index));

// gradient.c

void	paint_gradient_fdf_table(t_fdf_table *dst,
			t_gradient gradient_input, bool is_overwrite);

#endif
