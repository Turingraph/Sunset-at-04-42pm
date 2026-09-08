/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:01:09 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/08 16:17:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(n)
// space: O(1)
size_t	count_decimal_digits(const char *line, size_t max, bool *is_int)
{
	size_t	j;

	if (line == NULL)
		return (0);
	j = 0;
	if (line[j] == '-')
		j += 1;
	while (j < max && f_isspace(line[j], "0123456789") == 1)
		j += 1;
	if (j == 1 && f_isspace(line[0], "0123456789") == 0 && is_int != NULL)
		*is_int = false;
	return (j);
}

// time : O(1)
// space: O(1)
bool	is_valid_fdf_color(const char *line)
{
	size_t	i;

	if (line == NULL || f_strlen(line) < 4
		|| line[1] != '0'
		|| line[2] != 'x')
		return (false);
	line += 3;
	i = 0;
	while (f_isspace(*line, "0123456789ABCDEFabcdef") == 1)
	{
		line += 1;
		i += 1;
	}
	if (i == 0 || i > 8
		|| (*line != '\0' && f_isspace(*line, " \n\t\r\f\v") == 0))
		return (false);
	return (true);
}

// time : O(n)
// space: O(1)
size_t	count_fdf_columns(const char *line, bool *is_valid_fdf)
{
	size_t	y;

	y = 0;
	while (line != NULL && *line != '\0'
		&& is_valid_fdf != NULL && *is_valid_fdf == true)
	{
		while (f_isspace(*line, " \n\t\r\f\v") == 1)
			line += 1;
		if (f_isspace(*line, "0123456789") == 1 || *line == '-')
		{
			line += 1;
			y += 1;
		}
		while (f_isspace(*line, "0123456789") == 1)
			line += 1;
		if (*line == ',')
			*is_valid_fdf = is_valid_fdf_color(line);
		else if (f_isspace(*line, "0123456789") == 0
			&& f_isspace(*line, " \n\t\r\f\v") == 0 && *line != '\0')
			*is_valid_fdf = false;
		while (f_isspace(*line, "0123456789,xABCDEFabcdef") == 1
			&& *is_valid_fdf == true)
			line += 1;
	}
	return (y);
}

// time : O(n)
// space: O(n)
void	parse_fdf_line_loop(t_load_fdf *dst, size_t length,
	bool *is_int, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < length && *line != '\0')
	{
		while (f_isspace(*line, " \n\t\r\f\v") == 1)
			line += 1;
		j = count_decimal_digits(line, 12, is_int);
		dst->arr[i] = f_atoi(line, is_int, "0123456789", j);
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
t_load_fdf	parse_fdf_line(char *line, bool is_rgba)
{
	t_load_fdf	dst;
	size_t		length;
	bool		is_int;
	bool		is_valid_fdf;

	is_valid_fdf = true;
	length = count_fdf_columns(line, &is_valid_fdf);
	if (line == NULL || length == 0
		|| (f_strlen((const char *)line) == 1
			&& f_isspace(*line, "0123456789") == 0)
		|| is_valid_fdf == false)
		return (init_load_fdf(0, false));
	dst = init_load_fdf(length, is_rgba);
	if (dst.arr == NULL)
		return (dst);
	is_int = true;
	parse_fdf_line_loop(&dst, length, &is_int, line);
	if (is_int == false)
		dst.int_warn = NOT_DECIMAL;
	return (dst);
}
