/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:46:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/31 17:39:14 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

/**
 * Load target file as t_table_fdf 5 rgba and height integer array data.
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
t_table_fdf	open_table_fdf_file(const char *file_name, const char *dir,
	t_load_fdf (*one_line)(char *line), bool is_rgba)
{
	t_table_fdf		dst;
	t_load_fdf_arr	src;

	src = open_fdf_file(file_name, dir, one_line);
	if (is_load_fdf_arr_valid(&src, (int)src.length - 1) == false)
	{
		destroy_load_fdf_arr(&src);
		return (init_table_fdf(0, 0, false));
	}
	dst = load_table_fdf(&src, is_rgba);
	destroy_load_fdf_arr(&src);
	return (dst);
}
