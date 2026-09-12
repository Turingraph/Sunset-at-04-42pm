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

# include "../../utils/green_counts/green_counts.h"
# include "../../utils/libft/libft.h"
# include <fcntl.h>

typedef struct t_rgba
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_rgba;

typedef enum t_7cell_channels
{
	D7_RED,
	D7_GREEN,
	D7_BLUE,
	D7_ALPHA,
	D7_ROW,
	D7_COL,
	D7_HEIGHT
}	t_7cell_channels;

/**
 * Defines a color gradient over a selected cell property.
 *
 * cell_channel selects the property used to determine the gradient position.
 * input_start and input_end define the affected range.
 * rgba_start and rgba_end define the colors at the range boundaries.
 */
typedef struct t_gradient
{
	t_rgba				rgba_start;
	t_rgba				rgba_end;
	t_7cell_channels	cell_channel;
	int					input_start;
	int					input_end;
}	t_gradient;

// filter.c

bool	is_space_fdf(const t_table_fdf *dst, size_t index);
bool	is_boundary_fdf(const t_table_fdf *dst, size_t index);
bool	is_chess_fdf(const t_table_fdf *dst, size_t index);
void	set_cells_color(t_table_fdf *dst, int color, t_enum_rgba channel,
			bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index));

// gradient.c

void	color_cells_gradient(t_table_fdf *dst,
			t_gradient gradient_input, bool is_overwrite);

// length.c

void	setcells_pythagorus_length(const t_table_fdf *dst);
void	setcells_times_length(const t_table_fdf *dst);
void	setcells_addition_length(const t_table_fdf *dst);
void	setcells_maximum_length(const t_table_fdf *dst);
void	setcells_minimum_length(const t_table_fdf *dst);

// utils.c

t_complex	get_table_fdf_coordinate(const t_table_fdf *dst,
				size_t index);
int	get_rgba_input(t_enum_rgba rgba_type, t_rgba src);


#endif
