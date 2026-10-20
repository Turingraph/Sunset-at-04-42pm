/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:07:35 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:41:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii_private.h"

/**
 * Parse an ASCII-art line using the Cheche01 character ramp.
 * This function is intended to be used with `load_fdf_table_file`
 *
 * time/space: O(n) / O(n)
 * 
 * status: public api
 *
 * @param line input line
 * 
 * @return loaded data input array as t_fdf_load
 * 
 * @see see: src/input/table/public.c
 */
t_fdf_load	parse_ascii_cheche01(char *line)
{
	return (parse_ascii(line,
			" `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
			"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@"));
}

/**
 * Parse an ASCII-art line using the standard character ramp.
 * This function is intended to be used with `load_fdf_table_file`
 *
 * time/space: O(n) / O(n)
 * 
 * status: public api
 *
 * @param line input line
 * 
 * @return loaded data input array as t_fdf_load
 * 
 * @see see: src/input/table/public.c
 */
t_fdf_load	parse_ascii_standard(char *line)
{
	return (parse_ascii(line,
			" .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
			"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$"));
}

/**
 * Parse an ASCII-art line using the Chungaloider brightness ramp.
 * This function is intended to be used with `load_fdf_table_file`
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 * 
 * @param line input line
 * 
 * @return loaded data input array as t_fdf_load
 * 
 * @see see: src/input/table/public.c
 * 
 * @see see: https://stackoverflow.com/questions/30097953/
 *      ascii-art-sorting-an-array-of-ascii-characters-by-brightness-levels-c-c
 */
t_fdf_load	parse_ascii_chungaloider(char *line)
{
	return (parse_ascii(line,
			" `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
			"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@"));
}
