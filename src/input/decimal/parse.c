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

#include "decimal_private.h"

/**
 * Parse an FDF line as colorful data.
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
 */
t_fdf_load	parse_decimal_rgba(char *line)
{
	return (parse_decimal(line, true));
}

/**
 * Parse an FDF line as black and white data.
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
 */
t_fdf_load	parse_decimal_bw(char *line)
{
	return (parse_decimal(line, false));
}
