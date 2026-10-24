/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:46:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 17:01:06 by phsottat         ###   ########.fr       */
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
 * @param format the input format (with type t_fdf_format).
 * @param is_rgba if is_rgba == true, then the program using malloc 
 * for initializing rgba color.
 * @return return the array that contains rgba and height of the height map.
 * @see src/input/load/parse.c
 */
t_fdf_table	load_fdf_table(const char *file_name,
	t_fdf_format format, bool is_rgba)
{
	t_fdf_table		dst;
	t_fdf_load_arr	src;

	src = fetch_fdf_load(open(file_name, O_RDONLY), format);
	if (isvalid_fdf_load_arr(&src, (int)src.length - 1) == false)
	{
		destroy_fdf_load_arr(&src);
		return (create_fdf_table(0, 0, false));
	}
	dst = fdfload_to_fdftable(&src, is_rgba);
	destroy_fdf_load_arr(&src);
	return (dst);
}
