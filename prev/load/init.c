/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:07:25 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 14:12:14 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(1)
// space: O(1)
void	*destroy_fdf_load(t_fdf_load *src)
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
t_fdf_load	create_fdf_load(size_t line_len, bool is_rgb)
{
	t_fdf_load	dst;

	dst.arr = (int *)malloc_talk(sizeof(int) * line_len,
			"create_fdf_load\n");
	dst.r = NULL;
	dst.g = NULL;
	dst.b = NULL;
	dst.a = NULL;
	if (is_rgb == true)
	{
		dst.r = malloc_talk(sizeof(unsigned char) * line_len,
				"create_fdf_load\n");
		dst.g = malloc_talk(sizeof(unsigned char) * line_len,
				"create_fdf_load\n");
		dst.b = malloc_talk(sizeof(unsigned char) * line_len,
				"create_fdf_load\n");
		dst.a = malloc_talk(sizeof(unsigned char) * line_len,
				"create_fdf_load\n");
	}
	dst.int_warn = ERROR_CORRECT;
	if (line_len == 0)
		dst.int_warn = ERROR_EMPTY;
	dst.rgb_warn = ERROR_CORRECT;
	dst.length = line_len;
	return (dst);
}

/**
 * Free the array after it load an FDF file.
 * Intended for internal use by load_fdf_table().
 *
 * time/space: O(n) / O(1)
 * 
 * status: internal helper
 *
 * @param src the target array with t_fdf_load_arr shape2d.
 */
void	destroy_fdf_load_arr(t_fdf_load_arr *src)
{
	size_t	i;

	if (src == NULL)
		return ;
	if (src != NULL && src->arr != NULL)
	{
		i = 0;
		while (i < src->capacity)
		{
			destroy_fdf_load(&(src->arr[i]));
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
 * Intended for internal use by load_fdf_table().
 *
 * time/space: O(1) / O(n)
 * 
 * status: internal helper
 *
 * @param length the number of all row of that t_fdf_load_arr can contains.
 *  If t_fdf_load_arr do not have enough memory for load Fdf input file,
 *  the program will double its size as a dynamic array.
 * 
 * @return empty input array as t_fdf_load_arr
 * 
 */
t_fdf_load_arr	create_fdf_load_arr(size_t length)
{
	t_fdf_load_arr	dst;

	dst.capacity = length;
	dst.length = 0;
	dst.arr = malloc_talk(sizeof(t_fdf_load) * length,
			"create_fdf_load_arr\n");
	return (dst);
}
