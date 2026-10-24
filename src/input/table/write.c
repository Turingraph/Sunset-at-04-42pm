/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:55:57 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/11 14:29:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

// time : O(1)
// space: O(1)
void	write_rgba_fdf(int fd, const t_fdf_table *src, size_t index)
{
	write(fd, ",0x", 3);
	if (src->r != NULL)
		write_int((int)src->r[index], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (src->g != NULL)
		write_int((int)src->g[index], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (src->b != NULL)
		write_int((int)src->b[index], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
	if (src->a != NULL)
		write_int((int)src->a[index], fd, "0123456789abcdef", 2);
	else
		write(fd, "00", 2);
}

/**
 * Write an FDF table to a file descriptor.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param digits number of digits for height values
 * @param mode output format
 */
static void	write_table_decimal(int fd, const t_fdf_table *src,
	size_t digits, bool is_rgba)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < src->row)
	{
		j = 0;
		while (j < src->col)
		{
			if (src->arr != NULL)
				write_int(src->arr[src->col * i + j], fd, "0123456789", digits);
			if (is_rgba == true)
				write_rgba_fdf(fd, src, src->col * i + j);
			write(fd, "\t", 1);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
static void	write_rgba_ascii(unsigned char input,
	const char *dict, int fd, bool is_left)
{
	int	output;

	output = f_interval_int(input, 0, 255);
	write_ascii(fd, output, dict, is_left);
}

// time : O(n)
// space: O(n)
void	write_fdf_table_custom(int fd, const t_fdf_table *src,
	t_fdf_channel channel, const char *dict)
{
	size_t			i;
	size_t			j;
	unsigned char	*arr;
	bool			left_char;

	i = 0;
	arr = rgbarr_from_table(src, channel);
	if ((src->arr == NULL && channel == FDF_HEIGHT)
		|| (arr == NULL && channel != FDF_HEIGHT))
		return ;
	while (i < src->row)
	{
		j = 0;
		while (j < src->col)
		{
			left_char = true;
			if (j >= src->col / 2)
				left_char = false;
			if (channel == FDF_HEIGHT)
				write_ascii(fd,
					(int)src->arr[i * src->col + j], dict, left_char);
			else
				write_rgba_ascii(arr[i * src->col + j], dict, fd, left_char);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}

/**
 * Write an FDF table to a file descriptor.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param fd output file descriptor
 * @param src source FDF table
 * @param channel the rgba or height channel of the src table.
 * @param format output format (type t_fdf_format)
 */
void	write_fdf_table(int fd, const t_fdf_table *src,
	t_fdf_channel channel, t_fdf_format format)
{
	if (src == NULL || mul_overflow_size_t(src->col, src->row) == false || fd < -1)
		return ;
	if (format == FDF_FORMAT_ASCII_A)
		write_fdf_table_custom(fd, src, channel, DICT_ASCII_A);
	if (format == FDF_FORMAT_ASCII_B)
		write_fdf_table_custom(fd, src, channel, DICT_ASCII_B);
	if (format == FDF_FORMAT_ASCII_C)
		write_fdf_table_custom(fd, src, channel, DICT_ASCII_C);
	if (format == FDF_FORMAT_DECIMAL_RGBA)
		write_table_decimal(fd, src, 1, true);
	if (format == FDF_FORMAT_DECIMAL_BW)
		write_table_decimal(fd, src, 1, false);
}
