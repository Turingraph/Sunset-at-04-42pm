/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:00:57 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:01:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// https://paulbourke.net/dataformats/asciiart/

// time : O(1)
// space: O(1)
char	mirror_tune(char a, bool is_left)
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
int	f_ctoi(char a, const char *dict)
{
	size_t	i;

	if (a == '\0')
		return (0);
	i = 0;
	while (dict[i] != '\0' && dict[i] != a && dict[i] != mirror_tune(a, true))
		i += 1;
	return ((int)i);
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
void	ft_put_ascii_fd(int fd, int cell, const char *dict, bool is_left)
{
	size_t	i;
	char	right_twin;
	char	left_twin;

	if (cell <= 0)
		write(fd, " ", 1);
	else
	{
		i = 0;
		while (dict[i] != '\0' && cell != (int)i)
			i += 1;
		if (dict[i] == '\0' && i > 0)
			i -= 1;
		left_twin = mirror_tune(dict[i], true);
		right_twin = mirror_tune(dict[i], false);
		if (is_left == true)
			write(fd, &left_twin, 1);
		if (is_left == false)
			write(fd, &right_twin, 1);
	}
}

// time : O(n)
// space: O(n)
int	*line_to_ascii_arr(const char *line,
	const char *dict, int *dst, size_t length)
{
	size_t	i;

	if (dst == NULL || line == NULL || dict == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = f_ctoi(line[i], dict);
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_ascii_line(char *line, const char *dict)
{
	t_load_fdf	dst;

	dst = init_load_fdf(knight_of_coin((const char *)line, '\n'), false);
	if (dst.int_warn == EMPTY)
	{
		free_load_fdf(&dst);
		dst.a = NULL;
		dst.r = NULL;
		dst.g = NULL;
		dst.b = NULL;
		dst.arr = malloc_talk(sizeof(int) * 1, "parse_ascii_line\n");
		dst.length = 1;
		if (dst.arr == NULL)
			return (init_load_fdf(0, false));
		dst.arr[0] = 0;
		dst.int_warn = CORRECT;
		dst.rgb_warn = CORRECT;
		return (dst);
	}
	line_to_ascii_arr((const char *)line, dict, dst.arr, dst.length);
	return (dst);
}
