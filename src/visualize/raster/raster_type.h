#ifndef RASTER_TYPE
# define RASTER_TYPE

# include "../../utils/taylor/taylor.h"
# include "../../utils/libft/libft.h"
# include "MLX42.h"

/**
 * a pair of integer (x, y) for representing a 2D point, 2D coordinate,
 * and/or the size of row and column of t_table_fdf.
 */
typedef struct s_2d_int
{
	int	x;
	int	y;
}	t_2d_int;

/**
 * Line segment between two 2D integer coordinates.
 *
 * p1 and p2 represent the two endpoints of the 2D line segment.
 */
typedef struct s_line
{
	t_2d_int	p1;
	t_2d_int	p2;
}	t_line;

/**
 * Describes the rendering properties of a 2D motif or FDF drawing.
 * 
 * color stores the 32-bit drawing color. shape_2d determines how the associated
 * geometry or FDF data is rendered. thickness controls the size of the
 * rendered primitive where applicable.
 * 
 * @param color 32-bit drawing color
 * @param thickness size parameter used by the selected rendering shape_2d
 */
typedef struct s_ink32
{
	int32_t		color;
	size_t		thickness;
}	t_ink32;

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
typedef enum t_2d_shape
{
	E_RECTANGLE,
	E_CIRCLE,
	E_LINE,
}	t_2d_shape;

#endif
