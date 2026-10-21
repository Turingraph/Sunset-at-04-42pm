/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:00:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 16:57:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCII_H
# define ASCII_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "ascii_type.h"

/*
Note that
*	load_debug.h is for checking if src/input/load/ works as expected.
*/

// ascii.c

void			write_ascii(int fd, int cell, const char *dict,
					bool is_left);

// init.c

void			destroy_fdf_load_arr(t_fdf_load_arr *src);

// parse.c

t_fdf_load		parse_ascii_cheche01(char *line);
t_fdf_load		parse_ascii_standard(char *line);
t_fdf_load		parse_ascii_chungaloider(char *line);

// public.c

bool			isvalid_fdf_load_arr(t_fdf_load_arr *src, int i);
t_fdf_load_arr	fetch_fdf_load_arr(int fd,
					t_fdf_load (*parse_line)(char *line));

#endif
