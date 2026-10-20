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
 * Defines a color input for t_gradient argument of the function `color_cells_gradient`
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

void	color_cells_gradient(t_fdf_table *dst,
			t_gradient gradient_input, bool is_overwrite);

// metric_3d.c

int		cell_metric_triangle_inequality_3d(const t_fdf_table *dst, size_t index);
int		cell_metric_pythagoras_3d(const t_fdf_table *dst, size_t index);
int		cell_metric_max_xyz(const t_fdf_table *dst, size_t index);
int		cell_metric_root_xyz(const t_fdf_table *dst, size_t index);
int		cell_metric_addsub_3d(const t_fdf_table *dst, size_t index);

// metric_inequality.c

int		cell_metric_triangle_inequality(const t_fdf_table *dst, size_t index);
int		cell_metric_amgm_inequality(const t_fdf_table *dst, size_t index);
int		cell_metric_amgm_inequality_3d(const t_fdf_table *dst, size_t index);
int		cell_metric_x_plus_y_square(const t_fdf_table *dst, size_t index);
int		cell_metric_cauchy_schwarz_inequality_3d(const t_fdf_table *dst, size_t index);

// metric_min.c

int		cell_metric_min_xy(const t_fdf_table *dst, size_t index);
int		cell_metric_min_xyz(const t_fdf_table *dst, size_t index);
int		cell_metric_mincos(const t_fdf_table *dst, size_t index);
int		cell_metric_minecos(const t_fdf_table *dst, size_t index);
int		cell_metric_minexp(const t_fdf_table *dst, size_t index);

// metric_tri.c

int		cell_metric_maxsin(const t_fdf_table *dst, size_t index);
int		cell_metric_maxesin(const t_fdf_table *dst, size_t index);
int		cell_metric_maxcos(const t_fdf_table *dst, size_t index);
int		cell_metric_maxecos(const t_fdf_table *dst, size_t index);
int		cell_metric_maxexp(const t_fdf_table *dst, size_t index);

// metric.c

int		cell_metric_pythagoras(const t_fdf_table *dst, size_t index);
int		cell_metric_max_xy(const t_fdf_table *dst, size_t index);
int		cell_metric_addsub(const t_fdf_table *dst, size_t index);
int		cell_metric_root_xy(const t_fdf_table *dst, size_t index);
int		cell_metric_fermat_theorem(const t_fdf_table *dst, size_t index);

// utils.c

void	paint_space(t_fdf_table *dst, t_fdf_channel channel,
			int (*cell_metric)(const t_fdf_table *dst, size_t index));
int		get_input_rgba(t_fdf_channel rgba_type, t_input_rgba src);

#endif
