/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:46:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 14:12:14 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

/**
 * Load target file as t_fdf_table 5 rgba and height integer array data.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 * 
 * @param file_name the input file
 * @param dir the directory of the input file
 * @param one_line loading style, including parse_ascii_standard for
 * loading file as ASCII art, parse_decimal_rgba as colorful Fdf file etc.
 * @param is_rgba if is_rgba == true, then the program using malloc 
 * for initializing rgba color.
 * @return return the array that contains rgba and height of the height map.
 * @see src/input/load/parse.c
 */
t_fdf_table	load_fdf_table(const char *file_name, const char *dir,
	t_fdf_load (*one_line)(char *line), bool is_rgba)
{
	t_fdf_table		dst;
	t_fdf_load_arr	src;

	src = load_fdf_load_arr(file_name, dir, one_line);
	if (isvalid_fdf_load_arr(&src, (int)src.length - 1) == false)
	{
		destroy_fdf_load_arr(&src);
		return (create_fdf_table(0, 0, false));
	}
	dst = fdf_load_to_fdf_table(&src, is_rgba);
	destroy_fdf_load_arr(&src);
	return (dst);
}
