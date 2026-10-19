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

t_fdf_load_arr	open_fdf_file(const char *file_name, const char *dir,
					t_fdf_load (*parse_line)(char *line));

// ascii.c

void			ft_put_ascii_fd(int fd, int cell, const char *dict,
					bool is_left);

// atoi.c

int				f_atoi(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);


// init.c

void			destroy_load_fdf_arr(t_fdf_load_arr *src);

// parse.c

t_fdf_load		parse_ascii_cheche01(char *line);
t_fdf_load		parse_ascii_standard(char *line);
t_fdf_load		parse_ascii_chungaloider(char *line);
t_fdf_load		parse_decimal_rgba(char *line);
t_fdf_load		parse_decimal_bw(char *line);

// string.c

char			f_isspace(char s, const char *space);
size_t			f_strlen(const char *str);

// write.c

bool			is_load_fdf_arr_valid(t_fdf_load_arr *src, int i);

#endif
