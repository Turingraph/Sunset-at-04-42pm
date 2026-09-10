#include "debug_triangle.h"

// time : O(1)
// space: O(1)
bool	are_2_3dpoint_same(const float *src, float x, float y, float z)
{
	if (src == NULL)
		return (false);
	if (src[0] == x && src[1] == y && src[2] == z)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	compare_3dpoint_triangle(const t_triangle *src, t_3d_point point_1, t_3d_point point_2, t_3d_point point_3)
{
	if (src == NULL)
		return (false);
	if (src->p1 == NULL || src->p2 == NULL || src->p3 == NULL)
		return (false);
	if (are_2_3dpoint_same(src->p1, point_1.x, point_1.y, point_1.z) == true
		&& are_2_3dpoint_same(src->p2, point_2.x, point_2.y, point_2.z) == true
		&& are_2_3dpoint_same(src->p3, point_3.x, point_3.y, point_3.z) == true)
		return (true);
	return (false);
}
