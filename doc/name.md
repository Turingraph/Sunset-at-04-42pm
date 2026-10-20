# name (utils)

## utils name
1.	static ... *_unit = the static function that operated n times within the while loop of the another function.
2.	f_* = the basic utility function e.g. f_atoi, f_sin, etc.
3.	is_* = check something, return true or false.
4.	complex_* = complex value analytic function e.g. complex_sin, complex_exp etc.

## struct names
1.	create_* = using malloc
2.	init_* = define the value of the variable without malloc.
3.	destroy_* = free the malloc and define the struct as default.
4.	t_* = struct/enum
5.	t_fdf_* = the general FDF data.
* 	(load/) t_fdf_load = loaded FDF data. It is internal helper.
* 	(table/) t_fdf_table = the editable FDF data. It is public api.
* 	(proj2d) t_fdf_proj2d = the 2D projection of the FDF data . It is public api.
6.	is_*_valid = check if the given struct is valid or not.
7.	*_arr = the array of something.
8.	normalize_* = to scale the struct for some particular purpose e.g. normalize_fdf_proj2d(t_fdf_proj2d *src, size_t fixed_window_size);

# name (input/*)

## write function name
1.	write_* = to display the value of something using write function (from unistd.h)
2.	inspect_* = write_* but only for t_fdf_load
3.	save_* = write_* but only for t_fdf_table

## read function name
1.	parse_* = parsing function for loading t_fdf_load. (internal helper)
2.	mystruct load_*(char *file_name, e_file_mode file_mode) = Convert file name to the given struct. (public api)
3.	mystruct load_*_debug(char *file_name, char *dir, e_file_mode file_mode) = Convert file name to the given struct for debugging. (internal helper)
4.	mystruct read_*(int fd) = converting the file descriptor integer as the given struct. (internal helper)
5.	ascii = related to ASCII art text.
6.	decimal = related to string decimal representation of number.

# name (debug/*)

1.	assert_* = check if 2 arguments have same data.
2.	write_* = display the data.
3.	length_of_* = the length of the given data.
4.	*_file = to do something with int file.
5.	*_str = to do something with char *str.
6.	*_strarr = to do something with char **str.
7.	*_intarr = to do something with int *intarr.

# name (visualize/*)

1.	raster_* = to color pixel according to the particular shape (transforming a vector (curve based) image to a pixel)
2.	render_* = to draw something according to raster_* function
*	(render/) render_fdf use render_picasso use render_line use raster_line
*	(render/) render_fdf use render_kusama use render_circle use raster_circle
*	(render/) render_fdf use render_tobyfox use render_rectangle use raster_rectangle
*	(render/) render_motif use render_motif_line use render_line use raster_line
*	(render/) render_motif use render_motif_circle use render_circle use raster_circle
*	(render/) render_motif use render_motif_rectangle use render_rectangle use raster_rectangle
*	(render/) t_render_style = config for render (thickness and shape_2d, public api)
*	(raster/) t_raster_style = config for raster (thickness and int32_t color, internal helper)
3.	t_2d_* = the 2D data, including x and y axis e.g. t_2d_int, t_2d_float, t_2d_camera, t_2d_hook, and t_2d_shape etc.
4.	rgba32_from_* = convert the given arguments as int32_t that represents the rgba color.
5.	view_* = to view something e.g. view_fdf or view_motif. This is public API.
6.	proj2d_* = the projection (proj2d/proj2d.c)

# name (paint/)

...
