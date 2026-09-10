The `unfinished_feature/` contains several directories that aren't useful for this Git repo at this stage, including

1.	`coding_examples/`
*	Purpose: The coding example as a part for user manual and integration test.
*	Why it is removed?: I remove other features e.g. `mathart/` and `line/` that are also verified by this directory. In addition, I replace `coding_examples/` with `unit_test/` (I also include the unit test of `convolve/` and `paint/` in `unit_test/` directory).
2.	`line/`
*	Purpose: For drawing line, circle, Kusama art, Islamic art, Mondrian Art, and other motif art on top of `t_table_fdf`.
*	Why it is removed?: The `raster/` can draw those artwork on top of MLX42 library. I will make the `line/` compatible with `t_table_fdf`, MLX42 library, OpenGL, etc. later in future, but I won't do it now for preventing scope creep and premature abstraction.
3.	`mathart/`
*	Purpose: For drawing artwork based on math function and `paint/` function.
*	Why it is removed?: It introduce extra complexity because originally `t_table_fdf` is this.

```
typedef struct t_table_fdf t_table_fdf;

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	size_t			origin_x;
	size_t			origin_y;
	e_sampling_rgba	color_sampling;
	float			zoom;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
};

```

where `zoom`, `origin_x`, and `origin_y` are used for describing the 2D position input in cartesian plane, such that `mathart(x, y) = new_input_value` where `new_input_value = rgba value` of the cells and/or `0/1` states for selecting which cells will be colored.

but `t_table_fdf` is simplified as this for the sake of maintainment and development ease.

```
typedef struct t_table_fdf t_table_fdf;

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
};
```

4.	`triangle/`
*	Purpose: For drawing 3D object with Z buffer algorithm and making user able to convert and export Fdf/txt/`t_table_fdf` as 3D object compatible Blender mesh file.
*	Why it is removed?: Blender compatibility and Z Buffer are outside the scope of this project in this current version. It is recommended to make good user manual before add new other features. In addition `e_sampling_rgba` add unnecessary complexity and risk making `t_table_fdf` become the God Object.

```
typedef enum e_sampling_rgba e_sampling_rgba;

enum e_sampling_rgba
{
	SAMPLE_TOP_LEFT,
	SAMPLE_AVERAGE,
	SAMPLE_EDGE_AVERAGE
};
```
