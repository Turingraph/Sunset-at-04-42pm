/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:15:06 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:26:31 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(n)
// space: O(n)
static void	inspect_ascii_unit(int fd, const t_load_fdf *src, const char *dict)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->length)
	{
		if (i < src->length / 2)
			ft_put_ascii_fd(fd, src->arr[i], dict, true);
		else
			ft_put_ascii_fd(fd, src->arr[i], dict, false);
		i += 1;
	}
	write(fd, "\n", 1);
}

// time : O(n)
// space: O(n)
void	inspect_ascii(int fd, const t_load_fdf_arr *src,
			const char *dict)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < src->length && src->arr != NULL)
	{
		inspect_ascii_unit(fd, (const t_load_fdf *)&(src->arr[i]), dict);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
void	inspect_ascii_cheche01(int fd, const t_load_fdf_arr *src)
{
	inspect_ascii(fd, src,
		" `'.,:_-;~!^\"\\|)rvcilj+xnzt>=]*?}17JTC23"
		"%Yoyhk4$5IF&XVUGZEwemqdgPKO980DQRHNB#WM@");
}

// time : O(n)
// space: O(n)
void	inspect_ascii_standard(int fd, const t_load_fdf_arr *src)
{
	inspect_ascii(fd, src,
		" .'`^\",:;Il!i>~+_-?]}1)|\\tjrxnvcz=7T23y"
		"45FXYUJCQ0OZmwqdkhoVGEegP*#MW&8%K9DRHNB@$");
}

// time : O(n)
// space: O(n)
void	inspect_ascii_chungaloider(int fd, const t_load_fdf_arr *src)
{
	inspect_ascii(fd, src,
		" `.-~'\":_,^=;>+!rc*\\z?TvJ7)|FiC}I31tlneoZ5Yxjy]"
		"2EwqkPh9d4VOGUKXHm8RD#$Bg0MNWQ%&@");
}
