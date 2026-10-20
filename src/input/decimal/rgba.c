/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:07:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:54:11 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decimal_private.h"

// time : O(1)
// space: O(1)
static unsigned char	f_rgba(const char *str, size_t len, bool *rgb_warn)
{
	int	dst;

	dst = str_to_int(str, rgb_warn, "0123456789abcdef", len);
	if (len == 1)
		dst = 16 * dst + dst;
	if (dst < 0)
		return (0);
	if (dst > 255)
		return (255);
	return ((unsigned char)dst);
}

// time : O(n)
// space: O(1)
size_t	count_hex_digits(char *line, size_t max)
{
	size_t	i;

	if (line == NULL)
		return (0);
	i = 0;
	if (str_length(line) < 4 || *line != ',' || line[1] != '0' || line[2] != 'x')
		return (0);
	while (is_a_in_str(line[i + 3], "0123456789ABCDEFabcdef") == 1 && i < max)
	{
		if (is_a_in_str(line[i + 3], "abcdef") == 1)
			line[i + 3] = line[i + 3] - 'a' + 'A';
		i += 1;
	}
	return (i);
}

// time : O(1)
// space: O(1)
static void	update_rgba_long(char *line,
	t_fdf_load *dst, size_t index, size_t length)
{
	bool	is_rgba;

	is_rgba = true;
	if (dst->r != NULL)
		dst->r[index] = f_rgba(line + 3, 1, &is_rgba);
	if (length > 2 && dst->g != NULL)
		dst->g[index] = f_rgba(line + 3 + 2, 1, &is_rgba);
	if (length > 4 && dst->b != NULL)
		dst->b[index] = f_rgba(line + 3 + 4, 1, &is_rgba);
	if (length > 6 && dst->a != NULL)
		dst->a[index] = f_rgba(line + 3 + 6, 1, &is_rgba);
}

// time : O(1)
// space: O(1)
void	update_rgba(char *line, t_fdf_load *dst, size_t index)
{
	size_t	length;
	bool	is_rgba;

	is_rgba = true;
	length = count_hex_digits(line, 8);
	dst->a[index] = 255;
	if (length > 0 && length < 5 && dst != NULL)
	{
		if (dst->r != NULL)
			dst->r[index] = f_rgba(line + 3, 1, &is_rgba);
		if (length > 1 && dst->g != NULL)
			dst->g[index] = f_rgba(line + 3 + 1, 1, &is_rgba);
		if (length > 2 && dst->b != NULL)
			dst->b[index] = f_rgba(line + 3 + 2, 1, &is_rgba);
		if (length > 3 && dst->a != NULL)
			dst->a[index] = f_rgba(line + 3 + 3, 1, &is_rgba);
	}
	if (length >= 5 && dst != NULL)
		update_rgba_long(line, dst, index, length);
	if (dst != NULL && is_rgba == false)
		dst->rgb_warn = ERROR_NOT_HEX;
}
