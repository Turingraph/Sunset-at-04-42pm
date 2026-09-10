#ifndef SUNSET442_H
# define SUNSET442_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42.h"

/* ************************************************************************** */
/* src/utils/type/type.h */
/* ************************************************************************** */

/**
 * Identifies the data component stored in a t_table_fdf array.
 *
 * - RED selects the red color component.
 *
 * - GREEN selects the green color component.
 *
 * - BLUE selects the blue color component.
 *
 * - ALPHA selects the alpha color component.
 *
 * - HEIGHT selects the height (arr, Z) component.
 */
typedef enum t_enum_rgba
{
	RED,
	GREEN,
	BLUE,
	ALPHA,
	HEIGHT
}	t_enum_rgba;

/**
 * Stores the height and optional RGBA color components of an FDF table.
 *
 * The table contains row * col cells. arr stores the height value of
 * each cell, while r, g, b, and a store its corresponding color
 * components.
 *
 * The arrays use the same linear indexing scheme, where the cell at
 * position (row, col) is stored at index row * col_count + col.
 *
 * status: public api
 *
 * @param row number of rows in the FDF table
 * @param col number of columns in the FDF table
 * @param arr array containing the height values of each FDF cell
 * @param r array containing the red color component of each cell
 * @param g array containing the green color component of each cell
 * @param b array containing the blue color component of each cell
 * @param a array containing the alpha color component of each cell
 */
typedef struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
}	t_table_fdf;

/* ************************************************************************** */
/* src/utils/green_counts/green_counts.h */
/* ************************************************************************** */


typedef struct t_complex
{
	float	re;
	float	im;
}	t_complex;

// as_int.c

float		f_floor(float num);
float		f_round(float num);
float		f_interval(float num, float min, float max);
float		f_max(float a, float b);
float		f_min(float a, float b);

// complex_trig.c

t_complex	complex_exp(t_complex a);
t_complex	complex_sin(t_complex a);
t_complex	complex_cos(t_complex a);

// complex.c

t_complex	complex_multiplication(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
t_complex	complex_cube(t_complex a);
t_complex	complex_reciprocal(t_complex a);
float		complex_magnitude(t_complex a, char is_square);

// int.c

int			f_abs_int(int x);
int			f_max_int(int a, int b);
int			f_min_int(int a, int b);
int			f_interval_int(int num, int min, int max);

// math.c

float		f_pow(float x, size_t a);
float		f_root_finding(float x, size_t a);
float		f_sin(float x);
float		f_cos(float x);

// stats.c

float		f_exp(float x);
float		normal_distribution_function(float std, float means, float x);
float		f_std(const float *vec_v, size_t dim);
float		f_sum(const float *vec_v, size_t dim);

// utils.c

size_t		collatz_max_point(size_t x);
size_t		binary_search_count(size_t min_input, size_t max_input);
float		f_abs(float x);
float		f_max3(float a, float b, float c);

#endif
