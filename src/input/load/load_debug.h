/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_debug.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:58:24 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:41:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_DEBUG_H
# define LOAD_DEBUG_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "load_type.h"

// all_files.c

t_fdf_load_arr	open_fdf_file(const char *file_name, const char *dir,
					t_fdf_load (*parse_line)(char *line));

// ascii.c
char			f_ctomirror(char a, bool is_left);

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

// write_ascii.c

void			inspect_ascii_cheche01(int fd,
					const t_fdf_load_arr *src);
void			inspect_ascii_standard(int fd,
					const t_fdf_load_arr *src);
void			inspect_ascii_chungaloider(int fd,
					const t_fdf_load_arr *src);

// write.c

void			inspect_decimal(int fd, const t_fdf_load_arr *src,
					size_t digits, t_write_style write_style);

#endif
