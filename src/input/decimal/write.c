/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:15:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 13:04:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decimal_private.h"

// time : O(n)
// space: O(n)
static void	write_load_decimal_unit(int fd, const t_fdf_load *src,
		size_t digits, bool is_rgba)
{
	size_t	i;

	i = 0;
	while (i < src->length)
	{
		write_int(src->arr[i], fd, "0123456789", digits);
		if (is_rgba == true)
		{
			write(fd, ",0x", 3);
			if (src->r != NULL)
				write_int((int)src->r[i], fd, "0123456789abcdef", 2);
			if (src->g != NULL)
				write_int((int)src->g[i], fd, "0123456789abcdef", 2);
			if (src->b != NULL)
				write_int((int)src->b[i], fd, "0123456789abcdef", 2);
			if (src->a != NULL)
				write_int((int)src->a[i], fd, "0123456789abcdef", 2);
		}
		write(fd, "\t", 1);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
static void	write_load_decimal(int fd,
		const t_fdf_load_arr *src, size_t digits, bool is_rgba)
{
	size_t	i;

	i = 0;
	while (i < src->length)
	{
		write_load_decimal_unit(fd, (const t_fdf_load *)&(src->arr[i]),
			digits, is_rgba);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
static void	write_load_ascii_unit(int fd, const t_fdf_load *src, const char *dict)
{
	size_t	i;

	i = 0;
	while (i < src->length)
	{
		if (i < src->length / 2)
			write_ascii(fd, src->arr[i], dict, true);
		else
			write_ascii(fd, src->arr[i], dict, false);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
static void	write_load_ascii(int fd, const t_fdf_load_arr *src,
			const char *dict)
{
	size_t	i;

	i = 0;
	while (i < src->length)
	{
		write_load_ascii_unit(fd, (const t_fdf_load *)&(src->arr[i]), dict);
		i += 1;
	}
}

void	write_fdf_load(int fd, const t_fdf_load_arr *src, t_fdf_format format)
{
	if (src == NULL || src->arr == NULL)
		return ;
	if (format == FDF_FORMAT_ASCII_A)
		write_load_ascii(fd, src, DICT_ASCII_A);
	if (format == FDF_FORMAT_ASCII_B)
		write_load_ascii(fd, src, DICT_ASCII_B);
	if (format == FDF_FORMAT_ASCII_C)
		write_load_ascii(fd, src, DICT_ASCII_C);
	if (format == FDF_FORMAT_DECIMAL_BW)
		write_load_decimal(fd, src, 1, false);
	if (format == FDF_FORMAT_DECIMAL_RGBA)
		write_load_decimal(fd, src, 1, true);
}
