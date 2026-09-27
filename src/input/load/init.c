/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:07:25 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 18:53:59 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(1)
// space: O(1)
void	*free_load_fdf(t_load_fdf *src)
{
	if (src == NULL)
		return (NULL);
	if (src->arr != NULL)
		free(src->arr);
	if (src->r != NULL)
		free(src->r);
	if (src->g != NULL)
		free(src->g);
	if (src->b != NULL)
		free(src->b);
	if (src->a != NULL)
		free(src->a);
	src->arr = NULL;
	src->r = NULL;
	src->g = NULL;
	src->b = NULL;
	src->a = NULL;
	return (NULL);
}

// time : O(n)
// space: O(n)
t_load_fdf	init_load_fdf(size_t line_len, bool is_rgb)
{
	t_load_fdf	dst;

	dst.arr = (int *)malloc_talk(sizeof(int) * line_len,
			"input/load/init.c/int_load_fdf\n");
	dst.r = NULL;
	dst.g = NULL;
	dst.b = NULL;
	dst.a = NULL;
	if (is_rgb == true)
	{
		dst.r = malloc_talk(sizeof(unsigned char) * line_len,
				"input/load/init.c/int_load_fdf\n");
		dst.g = malloc_talk(sizeof(unsigned char) * line_len,
				"input/load/init.c/int_load_fdf\n");
		dst.b = malloc_talk(sizeof(unsigned char) * line_len,
				"input/load/init.c/int_load_fdf\n");
		dst.a = malloc_talk(sizeof(unsigned char) * line_len,
				"input/load/init.c/int_load_fdf\n");
	}
	dst.int_warn = CORRECT;
	if (line_len == 0)
		dst.int_warn = EMPTY;
	dst.rgb_warn = CORRECT;
	dst.length = line_len;
	return (dst);
}

/**
 * Free the array after it load an FDF file.
 * Intended for internal use by open_table_fdf_file().
 *
 * time/space: O(n) / O(1)
 * 
 * status: internal helper
 *
 * @param src the target array with t_load_fdf_arr shape_2d.
 */
void	free_load_fdf_arr(t_load_fdf_arr *src)
{
	size_t	i;

	if (src == NULL)
		return ;
	if (src != NULL && src->arr != NULL)
	{
		i = 0;
		while (i < src->capacity)
		{
			free_load_fdf(&(src->arr[i]));
			i += 1;
		}
		free(src->arr);
	}
	src->arr = NULL;
	src->capacity = 0;
	src->length = 0;
}

/**
 * Initializing array for loading an FDF file.
 * Intended for internal use by open_table_fdf_file().
 *
 * time/space: O(1) / O(n)
 * 
 * status: internal helper
 *
 * @param length the number of all row of that t_load_fdf_arr can contains.
 *  If t_load_fdf_arr do not have enough memory for load Fdf input file,
 *  the program will double its size as a dynamic array.
 * 
 * @return empty input array as t_load_fdf_arr
 * 
 */
t_load_fdf_arr	init_load_fdf_arr(size_t length)
{
	t_load_fdf_arr	dst;

	dst.capacity = length;
	dst.length = 0;
	dst.arr = malloc_talk(sizeof(t_load_fdf) * length,
			"load/init.c/init_load_fdf_arr\n");
	return (dst);
}
