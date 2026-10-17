/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_small.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:08:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/16 15:54:39 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_SMALL_H
# define API_SMALL_H

/* ************************************************************************** */
/* src/utils/taylor/ */
/* ************************************************************************** */

/**
 * compute |x|
 */
float	f_abs(float x);

/**
 * compute e^(a.x + a.y)
 */
t_2d_float	complex_exp(t_2d_float a);

/**
 * compute cos(a.x + a.y)
 */
t_2d_float	complex_cos(t_2d_float a);

/**
 * compute sin(a.x + a.y)
 */
t_2d_float	complex_sin(t_2d_float a);

/**
 * compute (a.x + a.y) * (b.x + b.y)
 */
t_2d_float	complex_multiplication(t_2d_float a, t_2d_float b);

/**
 * compute (a.x + a.y)^2
 */
t_2d_float	complex_square(t_2d_float a);

/**
 * compute (a.x + a.y)^4
 */
t_2d_float	complex_x4(t_2d_float a);

/**
 * compute (a.x + a.y)^5
 */
t_2d_float	complex_x5(t_2d_float a);

/**
 * compute (a.x + a.y)^6
 */
t_2d_float	complex_x6(t_2d_float a);

/**
 * compute (a.x + a.y)^3
 */
t_2d_float	complex_cube(t_2d_float a);

/**
 * if a.x + a.y equal to 0, return 0
 * compute 1 / (a.x + a.y)
 */
t_2d_float	complex_reciprocal(t_2d_float a);

/**
 * compute |a.x + a.im|
 */
float	complex_magnitude(t_2d_float a, char is_square);

/** 
 * convert any float number to integer by floor function.
 */
float	f_floor(float num);

/** 
 * convert any float number to integer by round the number.
 */
float	f_round(float num);

/**
 * if (num < min), return min.
 * if (num > max), return max.
 * else return num
 */
float	f_interval(float num, float min, float max);

/** 
 * if a > b, return b, else return a.
 */
float	f_max(float a, float b);

/** 
 * if a < b, return b, else return a.
 */
float	f_min(float a, float b);

/**
 * compute normal distribution bell curve function.
 * 
 * @param std standard deviation
 * @param means average score
 * @param x x value
 */
float	normal_distribution(float std, float means, float x);

/**
 * compute the standard deviation of the given dataset from the input array.
 * 
 * @param vec_v array
 * @param dim the length of the array
 */
float	f_std(const float *vec_v, size_t dim);

/**
 * compute the total sum of the given dataset from the input array.
 * 
 * @param vec_v array
 * @param dim the length of the array
 */
float	f_sum(const float *vec_v, size_t dim);

/**
 * compute x^a with a iterations.
 */
float		f_pow(float x, size_t a);

/**
 * if a == 0, then y = 0, else y = x^(1 / a) using 8 iterations newton method.
 */
float		f_root_finding(float x, size_t a);

/**
 * if -1.0 < x < 1.0, then return x
 * else return sin(x) with 8 iterations Taylor series
 */
float		f_sin(float x);

/**
 * compute cos(x) = sin(x + 3.1415 / 2.0)
 */
float		f_cos(float x);

/**
 * compute e^x with 8 iterations Taylor series
 */
float		f_exp(float x);

/**
 * Check whether a cell is located on the boundary of the table
 * or is adjacent to an empty cell.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param threshold cell that have value greater than the threshold is considered as non-empty space.
 * Cell that have value equal to or less than the threshold is considered as empty space.
 * 
 * @return true if the cell is a positive value located on the table
 * boundary or adjacent to an empty cell, false otherwise.
 */
bool	is_boundary_fdf(const t_table_fdf *dst, size_t index, int threshold);

/**
 * Counts the neighboring cells whose values exceed a given threshold.
 *
 * Examines the eight possible neighbors (horizontal, vertical, and diagonal)
 * of the cell at the specified index in a 2D grid stored as a 1D array.
 * A neighbor is counted if its value is strictly greater than the threshold.
 * Neighbors outside the grid boundaries are ignored.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table
 * @param index Index of the cell (within the FDF table) whose neighbors will be examined.
 * The index must be within the grid's valid range.
 * @param threshold Minimum value a neighboring cell must exceed to be counted.
 * 
 * @return The number of valid neighboring cells whose values exceed the
 * threshold, ranging from 0 to 8. Returns 0 if the FDF table is invalid.
 */
int	count_neighbor_fdf(const t_table_fdf *dst, size_t index, int threshold);

/**
 * Check whether a cell is considered empty
 * (the integer height of the cell less than or equal to 0).
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the cell contains a value less than or equal to 0,
 * false otherwise.
 */
bool		is_space_fdf(const t_table_fdf *dst, size_t index);

/**
 * Check whether a cell belongs to the chess pattern.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the cell position belongs to the chess pattern,
 * false otherwise.
 */
bool		is_chess_fdf(const t_table_fdf *dst, size_t index);


/* ************************************************************************** */
/* *** src/paint/evenodd/ *** */
/* ************************************************************************** */

/**
 * Count the number of iterations required by a binary-search procedure
 * to locate min_input within the range [0, max_input].
 *
 * If min_input is greater than max_input, their values are exchanged
 * before performing the search.
 *
 * time/space: O(log(n)) / O(1)
 * 
 * @param min_input target value to search for
 * @param max_input upper bound of the search range
 * @return number of binary-search iterations
 */
size_t		binary_search_count(size_t min_input, size_t max_input);

/**
 * Check whether the number of iterations of a binary-search procedure
 * is odd when searching for the rounded magnitude of a cell's complex
 * coordinate within the table's diagonal-length range.
 *
 * The coordinate magnitude is used as the search target, while the
 * rounded diagonal length of the table is used as the upper bound.
 *
 * time/space: O(log(n)) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the binary-search iteration count is odd,
 * false otherwise.
 */
bool		is_binary_search_length_odd(const t_table_fdf *dst, size_t index);

/**
 * Check whether the number of iterations of a binary-search procedure
 * is odd when searching for the absolute product of a cell's rounded
 * real and imaginary coordinates within the table's cell-count range.
 *
 * The search target is:
 *
 *     |round(Re(z)) * round(Im(z))|
 *
 * and the upper bound is the total number of cells in the table.
 *
 * time/space: O(log(n)) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the binary-search iteration count is odd,
 * false otherwise.
 */
bool		is_binary_search_product_odd(const t_table_fdf *dst, size_t index);

/**
 * Check whether the number of iterations of a binary-search procedure
 * is even when searching for the absolute value of a cell's rounded
 * real or imaginary coordinates within the table's cell-count range.
 *
 * time/space: O(s, where s is less than 10000) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool		is_binary_search_andmod(const t_table_fdf *dst, size_t index);

/**
 * Find the maximum value reached by the Collatz sequence of an input.
 * The sequence is limited to 10000 iterations.
 *
 * time/space: O(s, where s is less than 10000),
 * this is an open problem! / O(1)
 *  
 */
size_t		collatz_max_point(size_t x);

/**
 * Check whether the maximum point of a cell's magnitude's Collatz sequence,
 * divided by 7, is odd.
 *
 * time/space: O(s, where s is less than 10000) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool		is_collatz_odd_length(const t_table_fdf *dst, size_t index);

/**
 * Check whether the maximum point of the Collatz sequence generated
 * from the product of a cell's coordinate components, divided by 7,
 * is odd.
 *
 * time/space: O(s, where s is less than 10000) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool		is_collatz_odd_product(const t_table_fdf *dst, size_t index);

/**
 * Check whether the maximum point of the Collatz sequence generated
 * from the absolute number of the x and y of a cell's coordinate components,
 * divided by 7, is odd.
 *
 * time/space: O(s, where s is less than 10000) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the scaled maximum Collatz point is odd,
 * false otherwise.
 */
bool		is_collatz_odd_andmod(const t_table_fdf *dst, size_t index);

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether Re(z')^2 - Im(z')^2 produces an odd integer.
 *
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating the value
 * @param zoom scaling both the real and imaginary part by a zoom factor.
 *
 * @return true if the rounded calculated value is odd,
 * false otherwise.
 */
bool		is_re2_diff_im2_odd_func(const t_table_fdf *dst, size_t index,
				t_2d_float (*complex_func)(t_2d_float a), float zoom);

/**
 * Compute z' = the complex coordinate of the cell.
 * Then check whether Re(z')^2 - Im(z')^2 produces an odd integer.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the rounded calculated value is odd,
 * false otherwise.
 */
bool		is_re2_diff_im2_odd(const t_table_fdf *dst, size_t index);

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating its magnitude
 * @param zoom scaling both the real and imaginary part by a zoom factor.
 *
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
bool		is_oddlength_func(const t_table_fdf *dst, size_t index,
				t_2d_float (*complex_func)(t_2d_float a), float zoom);

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether the magnitude of a z is odd.
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the rounded coordinate magnitude is odd,
 * false otherwise.
 */
bool		is_oddlength(const t_table_fdf *dst, size_t index);

/**
 * Compute z' = complex_func(the complex coordinate of the cell).
 * Then check whether z.x is even and z.y is even
 * 
 * If complex_func is not NULL, then complex_func is identity function.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 * @param complex_func optional complex function applied to the cell
 * coordinate before calculating its magnitude
 * @param zoom scaling both the real and imaginary part by a zoom factor.
 *
 * @return true if z.x is even and z.y is even, false otherwise.
 */
bool		is_andmod_func(const t_table_fdf *dst, size_t index,
				t_2d_float (*complex_func)(t_2d_float a), float zoom);

/**
 * Check whether constant times magnitude of the square of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_x2(const t_table_fdf *dst, size_t index);

/**
 * Check whether constant times magnitude of the cube of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_x3(const t_table_fdf *dst, size_t index);

/**
 * Check whether constant times magnitude of the 4-th power of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_x4(const t_table_fdf *dst, size_t index);

/**
 * Check whether constant times magnitude of the 5-th power of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_x5(const t_table_fdf *dst, size_t index);

/**
 * Check whether constant times magnitude of the 6-th power of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_x6(const t_table_fdf *dst, size_t index);

/**
 * Check whether the ax^2 and ay^2 of the cell is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_andmod_x2(const t_table_fdf *dst, size_t index);

/**
 * Check whether the ax^3 and ay^3 of the cell is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_andmod_x3(const t_table_fdf *dst, size_t index);

/**
 * Check whether the ax^4 and ay^4 of the cell is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_andmod_x4(const t_table_fdf *dst, size_t index);

/**
 * Check whether the ax^5 and ay^5 of the cell is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_andmod_x5(const t_table_fdf *dst, size_t index);

/**
 * Check whether the ax^6 and ay^6 of the cell is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_andmod_x6(const t_table_fdf *dst, size_t index);

/**
 * Check whether constant times magnitude of the square of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_x2shadow(const t_table_fdf *dst, size_t index);

/**
 * Check whether constant times magnitude of the cube of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_x3shadow(const t_table_fdf *dst, size_t index);

/**
 * Check whether the ax^2 and ay^2 of the cell is an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_andmod_x2shadow(const t_table_fdf *dst, size_t index);

/**
 * Check whether the ax^3 and ay^3 of the cell is an odd value.
 *
 * time/space: O(1) / O(1)
 *
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool	is_andmod_x3shadow(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the sin of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_sin(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the cos of a cell's
 * complex coordinate is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_oddlength_cos(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the sin of a cell's
 * x and y is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_andmod_sin(const t_table_fdf *dst, size_t index);

/**
 * Check whether the magnitude of the cos of a cell's
 * x and y is an odd value.
 *
 * time/space: O(1) / O(1)
 * 
 * @param dst FDF table to check
 * @param index index of the cell to check
 *
 * @return true if the calculated value is odd, false otherwise.
 */
bool		is_andmod_cos(const t_table_fdf *dst, size_t index);

/* ************************************************************************** */
/* *** src/paint/paint/ *** */
/* ************************************************************************** */


/**
 * Paint a table FDF channel using the value of each cell from
 * the origin in the complex plane, as |z.x + z.im|.
 * If cell_metric is not NULL, its output will be utilized instead
 * of the default complex-plane distance.
 * 
 * time/space: O(n) + O(cell_metric) / O(1)
 * 
 * @param dst destination FDF table to paint
 * @param channel FDF channel to paint
 * @param cell_metric optional function to calculate the value of each cell
 */
void	paint_space(t_table_fdf *dst, t_fdf_channel channel,
	int (*cell_metric)(const t_table_fdf *dst, size_t index));

/**
 * Calculate the difference between the sum of the absolute
 * components and the absolute value of their sum.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return |re| + |im| + |zd3| - |re + im + zd3|
 */
int	cell_metric_triangle_inequality_3d(const t_table_fdf *dst, size_t index);

/**
* Calculate the Euclidean distance of a cell from the origin
* in the 3d space
* 
* time/space: O(1) / O(1)
* 
* @param dst source FDF table
* @param index index of the cell
* @return Euclidean distance from the origin
*/
int	cell_metric_pythagoras_3d(const t_table_fdf *dst, size_t index);

/**
 * Calculate the maximum absolute component of a cell coordinate
 * in 3d space.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return maximum of |re|, |im|, and zd3
 */
int	cell_metric_max_xyz(const t_table_fdf *dst, size_t index);

/**
 * Calculate the square root of the absolute product of the
 * real and imaginary components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return sqrt(|re * im|)
 */
int	cell_metric_root_xyz(const t_table_fdf *dst, size_t index);

/**
 * Calculate the absolute value of the sum of x, y, and z.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return |x + y + z|
 */
int	cell_metric_addsub_3d(const t_table_fdf *dst, size_t index);

/**
 * Calculate the difference between the sum of the absolute
 * components and the absolute value of their sum.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return |re| + |im| - |re + im|
 */
int	cell_metric_triangle_inequality(const t_table_fdf *dst, size_t index);

/**
 * Calculate the different between (x + y) / 2 - (xy)^(1/2)
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return (x + y) / 2 - (xy)^(1/2)
 */
int	cell_metric_amgm_inequality(const t_table_fdf *dst, size_t index);

/**
 * Calculate the (x + y + z) / 3 - (xyz)^(1/3)
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return (x + y + z) / 3 - (xyz)^(1/3)
 */
int	cell_metric_amgm_inequality_3d(const t_table_fdf *dst, size_t index);

/**
 * Calculate the (re + im)^2
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return (re + im)^2
 */
int	cell_metric_x_plus_y_square(const t_table_fdf *dst, size_t index);

/**
 * Calculate the x^2 + y^2 + z^2 - (x + y + z)^2
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return x^2 + y^2 + z^2 - (x + y + z)^2
 */
int	cell_metric_cauchy_schwarz_inequality_3d(const t_table_fdf *dst, size_t index);

/**
 * Calculate the minimum absolute component of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return minimum of |re| and |im|
 */
int	cell_metric_min_xy(const t_table_fdf *dst, size_t index);

/**
 * Calculate the minimum absolute component of a cell coordinate
 * in 3d space.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return minimum of |re|, |im|, and zd3
 */
int	cell_metric_min_xyz(const t_table_fdf *dst, size_t index);

/**
 * Calculate the minimum cosine value of the real and imaginary
 * components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(row, col) * min(cos(re / a), cos(im / a))
 */
int	cell_metric_mincos(const t_table_fdf *dst, size_t index);

/**
 * Calculate the minimum component of the complex cosine of a
 * cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * 
 * @param index index of the cell
 * 
 * @return min(cos(z).x, cos(z).y)
 */
int	cell_metric_minecos(const t_table_fdf *dst, size_t index);

/**
 * Calculate the minimum component of the complex exponential
 * of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(re(exp(z)), im(exp(z)))
 */
int	cell_metric_minexp(const t_table_fdf *dst, size_t index);

/**
 * Calculate the maximum sine value of the real and imaginary
 * components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(row, col) * max(sin(re / a), sin(im / a))
 */
int	cell_metric_maxsin(const t_table_fdf *dst, size_t index);

/**
 * Calculate the maximum component of the complex sine of a
 * cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * 
 * @param index index of the cell
 * 
 * @return max(sin(z).x, sin(z).y)
 */
int	cell_metric_maxesin(const t_table_fdf *dst, size_t index);

/**
 * Calculate the maximum cosine value of the real and imaginary
 * components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return min(row, col) * max(cos(re / a), cos(im / a))
 */
int	cell_metric_maxcos(const t_table_fdf *dst, size_t index);

/**
 * Calculate the maximum component of the complex cosine of a
 * cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * 
 * @param index index of the cell
 * 
 * @return max(cos(z).x, cos(z).y)
 */
int	cell_metric_maxecos(const t_table_fdf *dst, size_t index);

/**
 * Calculate the maximum component of the complex exponential
 * of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return max(re(exp(z)), im(exp(z)))
 */
int	cell_metric_maxexp(const t_table_fdf *dst, size_t index);

/**
* Calculate the Euclidean distance of a cell from the origin
* in the complex plane.
* 
* time/space: O(1) / O(1)
* 
* @param dst source FDF table
* @param index index of the cell
* @return Euclidean distance from the origin
*/
int	cell_metric_pythagoras(const t_table_fdf *dst, size_t index);

/**
 * Calculate the maximum absolute component of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return maximum of |re| and |im|
 */
int	cell_metric_max_xy(const t_table_fdf *dst, size_t index);

/**
 * Calculate the absolute value of the sum of the real and
 * imaginary components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return |re + im|
 */
int	cell_metric_addsub(const t_table_fdf *dst, size_t index);

/**
 * Calculate the square root of the absolute product of the
 * real and imaginary components of a cell coordinate.
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return sqrt(|re * im|)
 */
int	cell_metric_root_xy(const t_table_fdf *dst, size_t index);

/**
 * Calculate the a^3 + b^3 - c^3 where a,b,c are integer and c is the
 * floor 3rd root of a^3 + b^3
 * 
 * time/space: O(1) / O(1)
 * 
 * @param dst source FDF table
 * @param index index of the cell
 * @return a^3 + b^3 - floor((a^3 + b^3)^(1/3))
 */
int	cell_metric_fermat_theorem(const t_table_fdf *dst, size_t index);

#endif
