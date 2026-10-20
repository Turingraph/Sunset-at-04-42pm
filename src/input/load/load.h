/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:00:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:41:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_H
# define LOAD_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "load_type.h"

/*
Note that
*	load_debug.h is for checking if src/input/load/ works as expected.
*/

// all_files.c

t_fdf_load_arr	load_fdf_load_arr(const char *file_name, const char *dir,
					t_fdf_load (*parse_line)(char *line));

// ascii.c

void			write_ascii(int fd, int cell, const char *dict,
					bool is_left);

// atoi.c

int				str_to_int(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			write_int(int n, int fd, const char *base, size_t digits);

// init.c

void			destroy_fdf_load_arr(t_fdf_load_arr *src);

// parse.c

t_fdf_load		parse_ascii_cheche01(char *line);
t_fdf_load		parse_ascii_standard(char *line);
t_fdf_load		parse_ascii_chungaloider(char *line);
t_fdf_load		parse_decimal_rgba(char *line);
t_fdf_load		parse_decimal_bw(char *line);

// string.c

char			is_a_in_str(char s, const char *space);
size_t			str_length(const char *str);

// write.c

bool			isvalid_fdf_load_arr(t_fdf_load_arr *src, int i);

#endif
