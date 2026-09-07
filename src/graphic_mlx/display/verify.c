#include "display_private.h"

// time : O(1)
// space: O(1)
bool	is_2dhook_valid(const t_2d_hook *src)
{
	if (src == NULL
		|| src->camera == NULL
		|| src->img == NULL
		|| src->mlx == NULL
		|| is_fdf_valid(src->master_piece.fdf) == false)
		return (false);
	return (true);
}
