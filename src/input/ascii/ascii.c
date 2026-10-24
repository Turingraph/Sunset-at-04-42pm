/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:00:57 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:52:56 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii_private.h"

// https://paulbourke.net/dataformats/asciiart/

// time : O(1)
// space: O(1)
char	ascii_to_mirror(char a, bool is_left)
{
	size_t	i;
	char	*left_dict;
	char	*right_dict;
	size_t	half_dict_len;

	half_dict_len = 15;
	left_dict = "VZJdqznej])}>\\9";
	right_dict = "ASLbpsuaf[({</6";
	i = 0;
	while (i < half_dict_len)
	{
		if (left_dict[i] == a || right_dict[i] == a)
		{
			if (is_left == true)
				return (left_dict[i]);
			else
				return (right_dict[i]);
		}
		i += 1;
	}
	return (a);
}

// time : O(n)
// space: O(1)
int	ascii_to_int(char a, const char *dict)
{
	size_t	i;

	if (a == '\0')
		return (0);
	i = 0;
	while (dict[i] != '\0' && dict[i] != a && dict[i] != ascii_to_mirror(a, true))
		i += 1;
	return ((int)i);
}

// time : O(n)
// space: O(1)
size_t	str_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

/**
 * Write the integer as an ASCII art character in targeted file.
 *
 * time/space: O(1) / O(1)
 * 
 * status: internal helper
 *
 * @param fd target output txt file (with ASCII art)
 * @param cell the input integer
 * @param dict for define the map between integer and ASCII printable characters
 *  for example 1st char = " ", 1st char = "-", 2nd char = "0" etc.
 * @param is_left for determine if the characters are lefted or right,
 *  for examples, b = right and d = left, etc. this features make the output
 *  of this program more compatible with Figlet output.
 */
void	write_ascii(int fd, int cell, const char *dict, bool is_left)
{
	size_t	length;
	char	right_twin;
	char	left_twin;

	if (cell <= 0)
		write(fd, " ", 1);
	else
	{
		length = str_length(dict);
		if (length == 0)
			return ;
		left_twin = ascii_to_mirror(dict[cell % length], true);
		right_twin = ascii_to_mirror(dict[cell % length], false);
		if (is_left == true)
			write(fd, &left_twin, 1);
		if (is_left == false)
			write(fd, &right_twin, 1);
	}
}

// time : O(n)
// space: O(n)
static int	*line_to_ascii_arr(const char *line,
	const char *dict, int *dst, size_t length)
{
	size_t	i;

	if (dst == NULL || line == NULL || dict == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = ascii_to_int(line[i], dict);
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_fdf_load	parse_ascii(char *line, const char *dict)
{
	t_fdf_load	dst;

	dst = create_fdf_load(index_a_in_str((const char *)line, '\n', false), false);
	if (dst.int_warn == ERROR_EMPTY)
	{
		destroy_fdf_load(&dst);
		dst.a = NULL;
		dst.r = NULL;
		dst.g = NULL;
		dst.b = NULL;
		dst.arr = malloc_talk(sizeof(int) * 1, "parse_ascii\n");
		dst.length = 1;
		if (dst.arr == NULL)
			return (create_fdf_load(0, false));
		dst.arr[0] = 0;
		dst.int_warn = ERROR_CORRECT;
		dst.rgb_warn = ERROR_CORRECT;
		return (dst);
	}
	line_to_ascii_arr((const char *)line, dict, dst.arr, dst.length);
	return (dst);
}
