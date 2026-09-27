/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:58:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/31 16:03:53 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_TYPE_H
# define LOAD_TYPE_H

# include <stdlib.h>

/**
 * Defines the writing mode used when serializing FDF data as fdf file as text
 * file with decimal numbers.
 *
 * - HEIGHT_ONLY writes only the height value of each FDF cell.
 *
 * - HEIGHT_RGBA writes the height value together with a full RGBA color.
 *
 * - HEIGHT_RGB writes the height value together with an RGB color,
 * without an explicit alpha component.
 */
typedef enum t_write_style
{
	HEIGHT_ONLY,
	HEIGHT_RGBA,
	HEIGHT_RGB
}	t_write_style;

/**
 * Describes the parsing status of a loaded FDF value.
 *
 * - CORRECT indicates that the corresponding value was parsed successfully.
 *
 * - NOT_DECIMAL indicates that the height value is not a valid decimal integer.
 *
 * - NOT_HEX indicates that the color value is not a valid hexadecimal value.
 *
 * - EMPTY indicates that the corresponding input value is empty.
 */
typedef enum t_load_warning
{
	CORRECT,
	NOT_DECIMAL,
	NOT_HEX,
	EMPTY
}	t_load_warning;

/**
 * Temporary FDF data produced while parsing one input line.
 *
 * The arrays store the height and optional color components extracted
 * from the input line. length specifies the number of FDF cells stored
 * in the arrays.
 *
 * int_warn stores the parsing status of the height values.
 *
 * rgb_warn stores the parsing status of the color values.
 * 
 * If int_warn and/or rgb_warn are NOT_DECIMAL and/or NOT_HEX, then 
 * load_all_fdf_lines stops and open_table_fdf_file return empty output.
 *
 * status: internal data shape_2d
 *
 * @param arr array containing the parsed height values
 * @param r array containing the red color components
 * @param g array containing the green color components
 * @param b array containing the blue color components
 * @param a array containing the alpha color components
 * @param length number of FDF cells stored in the arrays
 * @param int_warn parsing status of the height values
 * @param rgb_warn parsing status of the color values
 */
typedef struct t_load_fdf
{
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
	size_t			length;
	t_load_warning	int_warn;
	t_load_warning	rgb_warn;
}	t_load_fdf;

/**
 * Dynamic array containing temporary FDF data produced while loading
 * an FDF file.
 *
 * arr points to the allocated t_load_fdf elements. length specifies
 * the number of elements currently stored, while capacity specifies
 * the total number of elements that can be stored before reallocation
 * is required.
 *
 * time/space: O(1) / O(1) for the structure itself.
 * 
 * status: internal data shape_2d
 *
 * @param arr dynamic array of loaded FDF data
 * @param length number of t_load_fdf elements currently stored
 * @param capacity number of t_load_fdf elements that can currently
 * be stored in the allocated array
 */
typedef struct t_load_fdf_arr
{
	t_load_fdf	*arr;
	size_t		length;
	size_t		capacity;
}	t_load_fdf_arr;

#endif
