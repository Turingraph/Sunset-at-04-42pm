/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:15:06 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:55:13 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii_private.h"

// time : O(n)
// space: O(n)
static void	write_load_unit(int fd, const t_fdf_load *src, const char *dict)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->length)
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
static void	write_load(int fd, const t_fdf_load_arr *src,
			const char *dict)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->length && src->arr != NULL)
	{
		write_load_unit(fd, (const t_fdf_load *)&(src->arr[i]), dict);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
void	write_load_cheche01(int fd, const t_fdf_load_arr *src)
{
	write_load(fd, src,
		" `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
		"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@");
}

// time : O(n)
// space: O(n)
void	write_load_standard(int fd, const t_fdf_load_arr *src)
{
	write_load(fd, src,
		" .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
		"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$");
}

// time : O(n)
// space: O(n)
void	write_load_chungaloider(int fd, const t_fdf_load_arr *src)
{
	write_load(fd, src,
		" `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
		"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@");
}
