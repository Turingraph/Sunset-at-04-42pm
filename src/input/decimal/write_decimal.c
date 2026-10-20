/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:15:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:56:22 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decimal_private.h"


// time : O(n)
// space: O(1)
char	is_a_in_str(char s, const char *space)
{
	while (space != NULL && *space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
	}
	return (0);
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

// time : O(n)
// space: O(n)
static void	write_load_decimal_unit(int fd, const t_fdf_load *src,
		size_t digits, t_fdf_write_mode mode)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->length)
	{
		write_int(src->arr[i], fd, "0123456789", digits);
		if (mode == WRITE_HEX_RGB || mode == WRITE_HEX_RGBA)
		{
			write(fd, ",0x", 3);
			if (src->r != NULL)
				write_int((int)src->r[i], fd, "0123456789abcdef", 2);
			if (src->g != NULL)
				write_int((int)src->g[i], fd, "0123456789abcdef", 2);
			if (src->b != NULL)
				write_int((int)src->b[i], fd, "0123456789abcdef", 2);
		}
		if (mode == WRITE_HEX_RGBA && src->a != NULL)
			write_int((int)src->a[i], fd, "0123456789abcdef", 2);
		write(fd, "\t", 1);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
void	write_load_decimal(int fd,
		const t_fdf_load_arr *src, size_t digits, t_fdf_write_mode mode)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->length && src->arr != NULL)
	{
		write_load_decimal_unit(fd, (const t_fdf_load *)&(src->arr[i]),
			digits, mode);
		i += 1;
	}
}
