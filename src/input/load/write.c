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

#include "load_private.h"

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

// time : O(1)
// space: O(1)
void	warning_fdf_load(const t_fdf_load *src, size_t i)
{
	if (src->int_warn != ERROR_CORRECT || src->rgb_warn != ERROR_CORRECT)
	{
		write(1, "Warning: Line no. ", 19);
		write_int(i, 1, "0123456789", 1);
		write(1, " of input Fdf file is ", 23);
		if (src->int_warn == ERROR_EMPTY)
			write(1, "empty", 6);
		if (src->int_warn == ERROR_NOT_DECIMAL)
			write(1, "not a decimal number", 21);
		if (src->int_warn != ERROR_CORRECT && src->rgb_warn == 'E')
			write(1, " and ", 5);
		if (src->rgb_warn == ERROR_NOT_HEX)
			write(1, " not a valid hexadecimal rgb representation", 44);
		write(1, ".\n", 2);
	}
}

// time : O(1)
// space: O(1)
static bool	isvalid_fdf_load(t_fdf_load *src)
{
	if (src == NULL || src->arr == NULL
		|| src->int_warn == ERROR_NOT_DECIMAL
		|| src->rgb_warn == ERROR_NOT_HEX
		|| src->rgb_warn == ERROR_NOT_DECIMAL
		|| src->int_warn == ERROR_NOT_HEX)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	isvalid_fdf_load_arr(t_fdf_load_arr *src, int i)
{
	if (src == NULL || src->arr == NULL || i < 0
		|| i > (int)src->length || i > (int)src->capacity
		|| isvalid_fdf_load(&(src->arr[i])) == false)
		return (false);
	return (true);
}
