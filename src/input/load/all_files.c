/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:00:47 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 16:55:43 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(1)
// space: O(1)
t_load_fdf	copy_load_fdf(t_load_fdf src)
{
	t_load_fdf	dst;

	dst.length = src.length;
	dst.arr = src.arr;
	dst.r = src.r;
	dst.g = src.g;
	dst.b = src.b;
	dst.a = src.a;
	dst.int_warn = src.int_warn;
	dst.rgb_warn = src.rgb_warn;
	return (dst);
}

// time : O(n)
// space: O(n)
t_load_fdf_arr	copy_load_fdf_arr(const t_load_fdf_arr *src, size_t length)
{
	t_load_fdf_arr	dst;
	size_t			i;

	if (src == NULL || length == 0 || src->arr == NULL || src->length == 0)
		return (init_load_fdf_arr(0));
	dst = init_load_fdf_arr(length);
	i = 0;
	while (dst.arr != NULL && i < src->length && i < dst.capacity)
	{
		dst.arr[i] = copy_load_fdf(src->arr[i]);
		i += 1;
	}
	dst.length = i;
	return (dst);
}

// time : O(1)
// space: O(1)
t_load_fdf_arr	load_fdf_arr_push(t_load_fdf_arr *src, t_load_fdf *item)
{
	t_load_fdf_arr	dst;

	if (src == NULL || src->arr == NULL || item == NULL)
	{
		free_load_fdf(item);
		free_load_fdf_arr(src);
		return (init_load_fdf_arr(0));
	}
	if (src->length < src->capacity)
	{
		src->arr[src->length] = *item;
		src->length += 1;
		return (*src);
	}
	dst = copy_load_fdf_arr((const t_load_fdf_arr *)src, src->length * 2);
	if (dst.arr != NULL)
	{
		free(src->arr);
		*src = dst;
		return (load_fdf_arr_push(src, item));
	}
	free_load_fdf(item);
	return (*src);
}

// time : O(n)
// space: O(n)
t_load_fdf_arr	load_all_fdf_lines(int fd,
	t_load_fdf (*parse_line)(char *line))
{
	t_load_fdf_arr	dst;
	t_load_fdf		item;
	char			*line;
	bool			is_valid;

	if (parse_line == NULL || fd < 0)
		return (init_load_fdf_arr(0));
	dst = init_load_fdf_arr(1);
	if (dst.arr == NULL)
		return (dst);
	is_valid = true;
	line = get_next_line(fd, true);
	while (line != NULL && is_valid == true)
	{
		item = parse_line(line);
		load_fdf_arr_push(&dst, &item);
		free(line);
		if (is_load_fdf_arr_valid(&dst, (int)dst.length - 1) == false)
			is_valid = false;
		line = get_next_line(fd, true);
	}
	free(line);
	get_next_line(fd, false);
	close(fd);
	return (dst);
}

// this 2 lines are used for debugging.
// if (dst.length > 0 && dst.arr != NULL)
// 	warning_load_fdf(&dst.arr[dst.length - 1], dst.length - 1);

/**
 * Load an FDF file and parse its lines into a t_load_fdf_arr.
 *
 * time/space: O(n) / O(n)
 * 
 * status: internal helper
 *
 * @param file_name input file name
 * @param dir directory containing the input file
 * @param parse_line function used to parse each input line
 * 
 * @return loaded data input array as t_load_fdf_arr
 * 
 * @see see: src/input/load/parse.c
 */
t_load_fdf_arr	open_fdf_file(const char *file_name, const char *dir,
		t_load_fdf (*parse_line)(char *line))
{
	int		dst;

	if (dir == NULL || *dir == '\0')
		return (load_all_fdf_lines(open(file_name, O_RDONLY), parse_line));
	dst = open_dir_file(file_name, dir, E_READ);
	return (load_all_fdf_lines(dst, parse_line));
}
