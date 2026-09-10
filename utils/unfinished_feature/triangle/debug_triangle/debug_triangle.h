#ifndef DEBUG_TRIANGLE_H
# define DEBUG_TRIANGLE_H

#include "../../utils/type/type.h"
#include "../../graphic/triangle_pair/triangle_pair.h"

typedef struct t_3d_point
{
	float	x;
	float	y;
	float	z;
}	t_3d_point;

typedef struct t_triangle_tester
{
	const char	*file_name;
	size_t		row;
	size_t		col;
	t_3d_point	*points;
	size_t		length;
}	t_triangle_tester;

// compare_edge.c
bool	compare_3dpoint_edge_tester(const t_triangle_arr *src,
			const t_triangle_tester *tester);
bool	compare_table_edge_3d_arr(const t_table_fdf *table,
			const t_triangle_arr *src, size_t index, e_edge mode);

// utils.c
bool	are_2_3dpoint_same(const float *src, float x, float y, float z);
bool	compare_3dpoint_triangle(const t_triangle *src, t_3d_point point_1,
			t_3d_point point_2, t_3d_point point_3);

#endif
