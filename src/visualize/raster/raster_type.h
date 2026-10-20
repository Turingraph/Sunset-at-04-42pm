#ifndef RASTER_TYPE
# define RASTER_TYPE

# include "../../utils/taylor/taylor.h"
# include "../../utils/libft/libft.h"
# include "MLX42.h"

/**
 * a pair of integer (x, y) for representing a 2D point, 2D coordinate,
 * and/or the size of row and column of t_fdf_table.
 */
typedef struct s_2d_int
{
	int	x;
	int	y;
}	t_int2d;

/**
 * Line segment between two 2D integer coordinates.
 *
 * p1 and p2 represent the two endpoints of the 2D line segment.
 */
typedef struct s_line
{
	t_int2d	p1;
	t_int2d	p2;
}	t_line;

/**
 * Describes the rendering properties of a 2D motif or FDF drawing.
 * 
 * color stores the 32-bit drawing color. shape_2d determines how the associated
 * geometry or FDF data is rendered. thickness controls the size of the
 * rendered primitive where applicable.
 * 
 * status: internal helper
 * 
 * @param color 32-bit drawing color
 * @param thickness size parameter used by the selected rendering shape_2d
 */
typedef struct t_style_raster
{
	int32_t		color;
	size_t		thickness;
}	t_style_raster;

/**
 * Supported 2D motif and rendering types.
 * 
 * The type determines how the motif geometry or FDF data is interpreted
 * by the raster layer.
 * 
 * ENUM TYPE
 * 
 * - E_RECTANGLE draws rectangular geometry.
 * 
 * - E_CIRCLE draws circular geometry.
 * 
 * - E_LINE draws polygon edges as lines.
 */
typedef enum t_shape2d
{
	E_RECTANGLE,
	E_CIRCLE,
	E_LINE,
}	t_shape2d;

#endif
