#include"window.h"

/*
// time : O(1)
// space: O(1)
int	world_to_screen_xy(int offset, float world)
{
	return ((int)world + offset);
}
*/

/*
Define
1.	A = target object in world space
2.	O = offset of the camera
3.	O_a = O + width and height of screen
4.	z = zoom

Then Define
1.	C = 1 / 2 * (O + O_a), the center of the target object in screen
*	O = 2 C - O_a
2.	O_d = O_a - O
*	O = O_a - O_d
3.	A' = target object in screen space
*	A' = A + O
*	A' = A + 1 / 2 (O + O)
*	A' = A + 1 / 2 (2 C - O_a + O_a - O_d)
*	A' = A + 1 / 2 (2 C - O_d)
*	A' = A + C - 1 / 2 O_d
*	A' = A - 1 / 2 O_d + C
*	A' = zA - z / 2 O_d + C

Let's calculate A
*	A' = zA - z / 2 O_d + C
*	A' - C = zA - z / 2 O_d
*	1 / z (A' - C) = A - 1 / 2 O_d
*	A = 1 / z (A' - C) + 1 / 2 O_d

Sadly that I cannot finish the reliable zoom feature on time today, right now.

1.	Pan and Zoom by javidx9
*	https://youtu.be/ZQ8qtAizis4?si=mscCRKnmR9QVH6cy
2.	Pan and Zoom in Desmos
*	https://www.desmos.com/calculator/cstwvtxcb4
*/

// time : O(1)
// space: O(1)
int	world_to_screen_xy(int offset, float world)
{
	return ((int)world + offset);
}

// time : O(1)
// space: O(1)
t_2d_int	world_to_screen_2d(t_2d_camera camera, t_complex world)
{
	t_2d_int	dst;

	dst.x = world_to_screen_xy(camera.offset.x, world.re);
	dst.y = world_to_screen_xy(camera.offset.y, world.im);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	world_3d_to_screen_2d(t_2d_camera camera,
	float x, float y)
{
	t_2d_int	dst;

	dst.x = x + (camera.offset.x + camera.window_size.x) / 2;
	dst.y = y + (camera.offset.y + camera.window_size.y) / 2;
	return (dst);
}

// time : O(1)
// space: O(1)
bool	is_line_in_screen(t_2d_camera camera,
	t_2d_int src)
{
	if (0 <= src.x
		&& src.x <= camera.window_size.x
		&& 0 <= src.y
		&& src.y <= camera.window_size.y)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_circle_in_screen(t_2d_camera camera,
	t_2d_int src, int thickness)
{
	if (-1 * thickness <= src.x
		&& src.x <= camera.window_size.x + thickness
		&& -1 * thickness <= src.y
		&& src.y <= camera.window_size.y + thickness)
		return (true);
	return (false);
}

