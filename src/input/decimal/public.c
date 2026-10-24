/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:07:35 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 14:12:14 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decimal_private.h"

static t_fdf_load	parse_decimal_rgba(char *line)
{
	return (parse_decimal(line, true));
}

static t_fdf_load	parse_decimal_bw(char *line)
{
	return (parse_decimal(line, false));
}

// me
static t_fdf_load	parse_ascii_a(char *line)
{
	return (parse_ascii(line, DICT_ASCII_A));
}

// standard
static t_fdf_load	parse_ascii_b(char *line)
{
	return (parse_ascii(line, DICT_ASCII_B));
}

// https://stackoverflow.com/questions/30097953/
static t_fdf_load	parse_ascii_c(char *line)
{
	return (parse_ascii(line, DICT_ASCII_C));
}

/**
 * Load an FDF file based on the file descriptor
 * and parse its lines into a t_fdf_load_arr.
 * This function is used with load_fdf_table from src/input/table/public.c
 * 
 * time/space: O(n) / O(n)
 * 
 * status: internal helper
 * 
 * @param fd integer file descriptor
 * @param format the fdf format (with t_fdf_format enum type).
 * @return loaded data input array as t_fdf_load_arr
 */
t_fdf_load_arr	fetch_fdf_load(int fd, t_fdf_format format)
{
	if (fd < -1)
		return (create_fdf_load_arr(0));
	if (format == FDF_FORMAT_ASCII_A)
		return (fetch_fdf_load_helper(fd, parse_ascii_a));
	if (format == FDF_FORMAT_ASCII_B)
		return (fetch_fdf_load_helper(fd, parse_ascii_b));
	if (format == FDF_FORMAT_ASCII_C)
		return (fetch_fdf_load_helper(fd, parse_ascii_c));
	if (format == FDF_FORMAT_DECIMAL_RGBA)
		return (fetch_fdf_load_helper(fd, parse_decimal_rgba));
	return (fetch_fdf_load_helper(fd, parse_decimal_bw));
}

/**
 * Load an FDF file and parse its lines into a t_fdf_load_arr.
 * This function is only used for debugging src/input/ascii/ and
 * src/input/decimal/ related coding file.
 *
 * time/space: O(n) / O(n)
 * 
 * status: internal helper
 *
 * @param file_name input file name
 * @param dir directory containing the input file
 * @param format the fdf format (with t_fdf_format enum type).
 * 
 * @return loaded data input array as t_fdf_load_arr
 * 
 * @see see: src/input/load/parse.c
 */
t_fdf_load_arr	debug_fdf_load(const char *file_name, const char *dir,
		t_fdf_format format)
{
	int		dst;

	if (dir == NULL || *dir == '\0')
		return (fetch_fdf_load(open(file_name, O_RDONLY), format));
	dst = debug_load_file(file_name, dir, FILE_READ);
	return (fetch_fdf_load(dst, format));
}
