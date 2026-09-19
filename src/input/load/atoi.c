/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:15:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/31 12:13:46 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(n)
// space: O(1)
size_t	f_atoonei(char c, const char *base, bool *is_int)
{
	size_t	i;
	char	big_c;

	big_c = c;
	if (c >= 'a' && c <= 'z')
		big_c = c - 'a' + 'A';
	if (c >= 'A' && c <= 'Z')
		big_c = c + 'a' - 'A';
	i = 0;
	while (*base != '\0' && *base != c && *base != big_c
		&& *base != '-' && *base != '+')
	{
		base += 1;
		i += 1;
	}
	if (*base == '\0' || *base == '-' || *base == '+')
	{
		if (is_int != NULL)
			*is_int = false;
		return (0);
	}
	return (i);
}

// time : O(1)
// space: O(1)
long int	f_atolongi(const char *src,
	bool *is_int, const char *base, size_t digits)
{
	long int	y;
	size_t		i;

	if (digits == 0)
		digits = f_strlen(src);
	i = 0;
	y = 0;
	while ((is_int == NULL || *is_int != false) && *src != '\0' && i < digits)
	{
		y += (long int)f_atoonei(*src, base, is_int);
		if (is_int != NULL && *is_int == false)
			return (-1);
		y *= f_strlen(base);
		src += 1;
		i += 1;
	}
	y /= f_strlen(base);
	return (y);
}

/**
 * Convert a string representing an integer in a given base.
 *
 * A leading '-' is interpreted as a negative sign.
 * The resulting value must fit within the range of an int.
 *
 * time/space: O(1) / O(1)
 * 
 * status: public api
 *
 * @param src the string to convert
 * @param is_int set to false if conversion fails
 * @param base the numeric base used for conversion
 * @param digits maximum number of characters to convert
 *
 * @return converted integer, or -1 if conversion fails or overflows
 */
int	f_atoi(const char *src, bool *is_int, const char *base, size_t digits)
{
	long int	y;
	size_t		sign;

	if (src == NULL || base == NULL)
	{
		if (is_int != NULL)
			*is_int = false;
		return (0);
	}
	if (src[0] == '0' && src[1] == '\0')
		return (0);
	sign = 0;
	if (src[sign] == '-')
		sign = 1;
	y = f_atolongi(src + sign, is_int, base, digits - sign);
	if (sign == 1)
		y *= -1;
	if (y < -2147483648 || y > 2147483647)
	{
		if (is_int != NULL)
			*is_int = false;
		return (-1);
	}
	return ((int) y);
}

// time : O(1)
// space: O(1)
size_t	display_int(int fd, long x, const char *base, bool is_write)
{
	size_t	i;
	long	d;
	char	coef;
	size_t	len;

	if (base == NULL)
		return (0);
	i = 0;
	len = f_strlen(base);
	d = 1;
	while (d < x)
		d *= len;
	if (d > x)
		d /= len;
	while (d > 0)
	{
		coef = base[x / d];
		if (is_write == true)
			write(fd, &coef, 1);
		x = x % d;
		d /= len;
		i += 1;
	}
	return (i);
}

/**
 * Write an integer to a file descriptor using the specified base.
 *
 * The output is padded with the first character of base until it
 * reaches digits characters.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param n integer to write
 * @param fd file descriptor used for output
 * @param base numeric base used for representation, return 0 if base is NULL
 * @param digits minimum number of characters to write
 *
 * @return number of characters written
 */
size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits)
{
	size_t	i;
	size_t	j;

	if (base != NULL)
	{
		i = 0;
		j = 0;
		if (n > 0)
			j = display_int(fd, (long)n, base, 0);
		else if (n < 0)
		{
			n *= -1;
			j = display_int(fd, n, base, 0);
			i += (size_t)write(fd, "-", 1);
		}
		if (j > digits)
			j = digits;
		while (i < digits - j)
			i += (size_t)write(fd, base, 1);
		if (n != 0)
			i += display_int(fd, n, base, 1);
		return (i);
	}
	return (0);
}
