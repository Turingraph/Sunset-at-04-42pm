#include "paint.h"

// time : O(1)
// space: O(1)
int	get_rgba_input(t_fdf_channel rgba_type, t_rgba src)
{
	if (rgba_type == RED)
		return (src.r);
	if (rgba_type == GREEN)
		return (src.g);
	if (rgba_type == BLUE)
		return (src.b);
	if (rgba_type == ALPHA)
		return (src.a);
	return (0);
}
