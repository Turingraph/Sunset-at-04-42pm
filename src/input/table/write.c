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
void	write_rgba_fdf(int fd, const t_table_fdf *src, size_t index)
{
	if (fd > -1 && src != NULL)
	{
		write(fd, ",0x", 3);
		if (src->r != NULL)
			ft_putnbr_fd((int)src->r[index], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
		if (src->g != NULL)
			ft_putnbr_fd((int)src->g[index], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
		if (src->b != NULL)
			ft_putnbr_fd((int)src->b[index], fd, "0123456789abcdef", 2);
		else
			write(fd, "00", 2);
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
 * @param digits number of digits for height values
 * @param mode output format
 */
void	write_table_fdf(int fd, const t_table_fdf *src,
	size_t digits, t_write_style mode)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->row && fd > -1)
	{
		j = 0;
		while (j < src->col)
		{
			ft_putnbr_fd(src->arr[src->col * i + j], fd, "0123456789", digits);
			if (mode == HEIGHT_RGB || mode == HEIGHT_RGBA)
				write_rgba_fdf(fd, src, src->col * i + j);
			if (src->a != NULL && mode == HEIGHT_RGBA)
				ft_putnbr_fd((int)src->a[src->col * i + j],
					fd, "0123456789abcdef", 2);
			else if (src->a == NULL && mode == HEIGHT_RGBA)
				write(fd, "00", 2);
			write(fd, "\t", 1);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
static void	wta_rgba(unsigned char input,
	const char *dict, int fd, bool is_left)
{
	int	output;

	output = f_interval_int(input, 0, 255);
	ft_put_ascii_fd(fd, output, dict, is_left);
}

// time : O(n)
// space: O(n)
void	write_table_ascii(int fd, const t_table_fdf *src,
	t_fdf_channel channel, const char *dict)
{
	size_t			i;
	size_t			j;
	unsigned char	*arr;
	bool			left_char;

	i = 0;
	while (src != NULL && i < src->row && fd > -1)
	{
		j = 0;
		while (j < src->col)
		{
			left_char = true;
			if (j >= src->col / 2)
				left_char = false;
			arr = get_rgba_of_table_fdf(src, channel);
			if (src->arr != NULL && channel == HEIGHT)
				ft_put_ascii_fd(fd,
					(int)src->arr[i * src->col + j], dict, left_char);
			else if (arr != NULL && channel != HEIGHT)
				wta_rgba(arr[i * src->col + j], dict, fd, left_char);
			j += 1;
		}
		write(fd, "\n", 1);
		i += 1;
	}
}
