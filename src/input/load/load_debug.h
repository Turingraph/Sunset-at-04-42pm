/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_debug.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:58:24 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 13:59:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_DEBUG_H
# define LOAD_DEBUG_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "load_type.h"

// all_files.c

t_load_fdf_arr	open_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*parse_line)(char *line));

// ascii.c
char			mirror_tune(char a, bool is_left);

// atoi.c

int				f_atoi(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// init.c

void			free_load_fdf_arr(t_load_fdf_arr *src);

// parse.c

t_load_fdf		parse_ascii_line_cheche01(char *line);
t_load_fdf		parse_ascii_line_standard(char *line);
t_load_fdf		parse_ascii_line_chungaloider(char *line);
t_load_fdf		parse_fdf_line_rgba(char *line);
t_load_fdf		parse_fdf_line_bw(char *line);

// string.c

char			f_isspace(char s, const char *space);
size_t			f_strlen(const char *str);

// write_ascii.c

void			write_load_ascii_arr_cheche01(int fd,
					const t_load_fdf_arr *src);
void			write_load_ascii_arr_standard(int fd,
					const t_load_fdf_arr *src);
void			write_load_ascii_arr_chungaloider(int fd,
					const t_load_fdf_arr *src);

// write.c

void			write_load_fdf_arr(int fd, const t_load_fdf_arr *src,
					size_t digits, t_write_style write_style);

#endif
