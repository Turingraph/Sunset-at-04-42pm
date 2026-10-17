/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:59:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/31 15:19:16 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_PRIVATE_H
# define LOAD_PRIVATE_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "load_type.h"

// all_files.c

t_load_fdf_arr	load_all_fdf_lines(int fd,
					t_load_fdf (*parse_line)(char *line));
t_load_fdf_arr	open_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*parse_line)(char *line));

// ascii.c

char			f_ctomirror(char a, bool is_left);
int				f_ctoi(char a, const char *dict);
void			ft_put_ascii_fd(int fd, int cell, const char *dict,
					bool is_left);
t_load_fdf		parse_ascii(char *line, const char *dict);

// atoi.c

int				f_atoi(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// decimal.c

t_load_fdf		parse_decimal(char *line, bool is_rgb);

// init.c

void			*free_load_fdf(t_load_fdf *src);
t_load_fdf		init_load_fdf(size_t line_len, bool is_rgb);
void			free_load_fdf_arr(t_load_fdf_arr *src);
t_load_fdf_arr	init_load_fdf_arr(size_t length);

// parse.c

t_load_fdf		parse_ascii_cheche01(char *line);
t_load_fdf		parse_ascii_standard(char *line);
t_load_fdf		parse_ascii_chungaloider(char *line);
t_load_fdf		parse_decimal_rgba(char *line);
t_load_fdf		parse_decimal_bw(char *line);

// rgba.c

size_t			count_hex_digits(char *line, size_t max);
void			update_rgba(char *line, t_load_fdf *dst, size_t index);

// string.c

char			f_isspace(char s, const char *space);
size_t			f_strlen(const char *str);

// write_ascii.c

void			inspect_ascii_cheche01(int fd,
					const t_load_fdf_arr *src);
void			inspect_ascii_standard(int fd,
					const t_load_fdf_arr *src);
void			inspect_ascii_chungaloider(int fd,
					const t_load_fdf_arr *src);

// write.c

void			inspect_decimal(int fd, const t_load_fdf_arr *src,
					size_t digits, t_write_style write_style);
void			inspect_ascii(int fd, const t_load_fdf_arr *src,
					const char *dict);
void			warning_load_fdf(const t_load_fdf *src, size_t i);
bool			is_load_fdf_arr_valid(t_load_fdf_arr *src, int i);

#endif
