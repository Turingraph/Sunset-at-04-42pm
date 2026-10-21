# name (utils)

## utils name

1.	static ... *_unit = the static function that operated n times within the while loop of the another function.
2.	f_* = the basic utility math function e.g. f_normal, f_sin, etc.
3.	is_* = check something, return true or false.
4.	complex_* = complex value analytic function e.g. complex_sin, complex_exp etc.
5.	is_*\_in_* = check if one data contains another data
6.	static ... *\_handle_+[0-9]+ = a part of larger function.

## struct names

1.	create_* = using malloc
2.	init_* = define the value of the variable without malloc.
3.	destroy_* = free the malloc and define the struct as default.
4.	t_* = struct/enum
5.	t_fdf_* = the general FDF data.
* 	(load/) t_fdf_load = loaded FDF data. It is internal helper.
* 	(table/) t_fdf_table = the editable FDF data. It is public api.
* 	(proj2d) t_fdf_proj2d = the 2D projection of the FDF data . It is public api.
6.	isvalid_* = check if the given struct is valid or not.
7.	*_arr = the array of something.
8.	copy_* = to copy something
9.	normalize_* = to scale the struct for some particular purpose e.g. normalize_fdf_proj2d(t_fdf_proj2d *src, size_t fixed_window_size);

general rule
*	verb_adverb_noun_adjective = doing the noun that have adjactive properties.
*	nouna_nounb = initialize the noun b of the noun a e.g. length_str, etc.
*	nounb_from_nouna = nouna_nounb (but the nounb is more common than nouna), e.g. rgba32_from_char, rgbarr_from_table etc. This make it easier for user/dev to define the color.
*	t_*_mode = the mode of something.

# name (input/*)

## write function name

*	write_* = to display the value of something using write function (from unistd.h)

## read function name

1.	parse_* = parsing function for loading t_fdf_load. (internal helper)
2.	load_*(char *file_name, e_file_mode file_mode) = Convert file name to the given output type. (public api)
3.	debug_load_*(char *file_name, char *dir, e_file_mode file_mode) = Convert file name to the given struct for debugging. (internal helper)
4.  int load_file(char *file_name,...) = to load the user's file as integer file descriptor.
5.	fetch_*(int fd) = converting the file descriptor integer as the given struct. (internal helper)
6.	ascii = related to ASCII art text.
7.	decimal = related to string decimal representation of number.

# name (debug/*)

1.	assert_* = check if 2 arguments have same data.
2.	write_* = display the data.
3.	*_length = the length of the given data.
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
*	(render/) t_style_render = config for render (thickness and shape2d, public api)
*	(raster/) t_style_raster = config for raster (thickness and int32_t color, internal helper)
3.	*2d = the 2D data, including x and y axis e.g. t_int2d, t_float2d, t_camera2d, t_hook2d, and t_shape2d etc.
4.	rgba32_from_* = convert the given arguments as int32_t that represents the rgba color.
5.	view_* = to view something e.g. view_fdf or view_motif. This is public API.
6.	proj2d_* = the projection (proj2d/proj2d.c)

# name (paint/)

...

# forbidden naming style

1.	open_* (a.k.a. load_*)
2.	2d_*
3.	define_* (a.k.a. init_*)
4.	inspect_*
5.	save_*

# To Do List

1.	Separate input/load/ as input/decimal/ and input/ascii/
2.	doing input/table
3.	doing paint/
