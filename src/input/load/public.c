/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:00:47 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:52:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(1)
// space: O(1)
static t_fdf_load	copy_fdf_load(t_fdf_load src)
{
	t_fdf_load	dst;

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
static t_fdf_load_arr	copy_fdf_load_arr(const t_fdf_load_arr *src, size_t length)
{
	t_fdf_load_arr	dst;
	size_t			i;

	if (src == NULL || length == 0 || src->arr == NULL || src->length == 0)
		return (create_fdf_load_arr(0));
	dst = create_fdf_load_arr(length);
	i = 0;
	while (dst.arr != NULL && i < src->length && i < dst.capacity)
	{
		dst.arr[i] = copy_fdf_load(src->arr[i]);
		i += 1;
	}
	dst.length = i;
	return (dst);
}

// time : O(1)
// space: O(1)
static t_fdf_load_arr	push_fdf_load_arr(t_fdf_load_arr *src, t_fdf_load *item)
{
	t_fdf_load_arr	dst;

	if (src == NULL || src->arr == NULL || item == NULL)
	{
		destroy_fdf_load(item);
		destroy_fdf_load_arr(src);
		return (create_fdf_load_arr(0));
	}
	if (src->length < src->capacity)
	{
		src->arr[src->length] = *item;
		src->length += 1;
		return (*src);
	}
	dst = copy_fdf_load_arr((const t_fdf_load_arr *)src, src->length * 2);
	if (dst.arr != NULL)
	{
		free(src->arr);
		*src = dst;
		return (push_fdf_load_arr(src, item));
	}
	destroy_fdf_load(item);
	return (*src);
}

// time : O(n)
// space: O(n)
t_fdf_load_arr	fetch_fdf_load_arr(int fd,
	t_fdf_load (*parse_line)(char *line))
{
	t_fdf_load_arr	dst;
	t_fdf_load		item;
	char			*line;
	bool			isvalid;

	if (parse_line == NULL || fd < 0)
		return (create_fdf_load_arr(0));
	dst = create_fdf_load_arr(1);
	if (dst.arr == NULL)
		return (dst);
	isvalid = true;
	line = get_next_line(fd, true);
	while (line != NULL && isvalid == true)
	{
		item = parse_line(line);
		push_fdf_load_arr(&dst, &item);
		if (line[0] != '\n'
			&& isvalid_fdf_load_arr(&dst, (int)dst.length - 1) == false)
			isvalid = false;
		free(line);
		line = get_next_line(fd, true);
	}
	free(line);
	free(get_next_line(fd, false));
	close(fd);
	return (dst);
}

/**
 * Load an FDF file and parse its lines into a t_fdf_load_arr.
 *
 * time/space: O(n) / O(n)
 * 
 * status: internal helper
 *
 * @param file_name input file name
 * @param dir directory containing the input file
 * @param parse_line function used to parse each input line
 * 
 * @return loaded data input array as t_fdf_load_arr
 * 
 * @see see: src/input/load/parse.c
 */
t_fdf_load_arr	load_fdf_load_arr(const char *file_name, const char *dir,
		t_fdf_load (*parse_line)(char *line))
{
	int		dst;

	if (dir == NULL || *dir == '\0')
		return (fetch_fdf_load_arr(open(file_name, O_RDONLY), parse_line));
	dst = load_file_debug(file_name, dir, E_READ);
	return (fetch_fdf_load_arr(dst, parse_line));
}
