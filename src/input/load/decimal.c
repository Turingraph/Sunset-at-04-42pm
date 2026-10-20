/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:01:09 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:53:29 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(n)
// space: O(1)
static size_t	count_decimal_digits(const char *line, size_t max, bool *is_int)
{
	size_t	j;

	if (line == NULL)
		return (0);
	j = 0;
	if (line[j] == '-')
		j += 1;
	while (j < max && is_a_in_str(line[j], "0123456789") == 1)
		j += 1;
	if (j == 1 && is_a_in_str(line[0], "0123456789") == 0 && is_int != NULL)
		*is_int = false;
	return (j);
}

// time : O(1)
// space: O(1)
static bool	isvalid_fdf_color(const char *line)
{
	size_t	i;

	if (line == NULL || str_length(line) < 4
		|| line[1] != '0'
		|| line[2] != 'x')
		return (false);
	line += 3;
	i = 0;
	while (is_a_in_str(*line, "0123456789ABCDEFabcdef") == 1)
	{
		line += 1;
		i += 1;
	}
	if (i == 0 || i > 8
		|| (*line != '\0' && is_a_in_str(*line, " \n\t\r\f\v") == 0))
		return (false);
	return (true);
}

// time : O(n)
// space: O(1)
static size_t	count_fdf_columns(const char *line, bool *isvalid_fdf)
{
	size_t	y;

	y = 0;
	while (line != NULL && *line != '\0'
		&& isvalid_fdf != NULL && *isvalid_fdf == true)
	{
		while (is_a_in_str(*line, " \n\t\r\f\v") == 1)
			line += 1;
		if (is_a_in_str(*line, "0123456789") == 1 || *line == '-')
		{
			line += 1;
			y += 1;
		}
		while (is_a_in_str(*line, "0123456789") == 1)
			line += 1;
		if (*line == ',')
			*isvalid_fdf = isvalid_fdf_color(line);
		else if (is_a_in_str(*line, "0123456789") == 0
			&& is_a_in_str(*line, " \n\t\r\f\v") == 0 && *line != '\0')
			*isvalid_fdf = false;
		while (is_a_in_str(*line, "0123456789,xABCDEFabcdef") == 1
			&& *isvalid_fdf == true)
			line += 1;
	}
	return (y);
}

// time : O(n)
// space: O(n)
static void	parse_decimal_loop(t_fdf_load *dst, size_t length,
	bool *is_int, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < length && *line != '\0')
	{
		while (is_a_in_str(*line, " \n\t\r\f\v") == 1)
			line += 1;
		j = count_decimal_digits(line, 12, is_int);
		dst->arr[i] = str_to_int(line, is_int, "0123456789", j);
		line += j;
		if (dst->a != NULL || dst->g != NULL
			|| dst->r != NULL || dst->b != NULL)
			update_rgba(line, dst, i);
		j = count_hex_digits(line, 8);
		if (j > 0)
			line += j + 3;
		i += 1;
	}
}

// time : O(n)
// space: O(n)
t_fdf_load	parse_decimal(char *line, bool is_rgba)
{
	t_fdf_load	dst;
	size_t		length;
	bool		is_int;
	bool		isvalid_fdf;

	isvalid_fdf = true;
	length = count_fdf_columns(line, &isvalid_fdf);
	if (line == NULL || length == 0
		|| (str_length((const char *)line) == 1
			&& is_a_in_str(*line, "0123456789") == 0)
		|| isvalid_fdf == false)
		return (create_fdf_load(0, false));
	dst = create_fdf_load(length, is_rgba);
	if (dst.arr == NULL)
		return (dst);
	is_int = true;
	parse_decimal_loop(&dst, length, &is_int, line);
	if (is_int == false)
		dst.int_warn = NOT_DECIMAL;
	return (dst);
}
