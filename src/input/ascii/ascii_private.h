/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:59:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/19 14:55:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCII_PRIVATE_H
# define ASCII_PRIVATE_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "ascii_type.h"

// ascii.c

char			ascii_to_mirror(char a, bool is_left);
int				ascii_to_int(char a, const char *dict);
void			write_ascii(int fd, int cell, const char *dict,
					bool is_left);
t_fdf_load		parse_ascii(char *line, const char *dict);

// init.c

void			*destroy_fdf_load(t_fdf_load *src);
t_fdf_load		create_fdf_load(size_t line_len, bool is_rgb);
void			destroy_fdf_load_arr(t_fdf_load_arr *src);
t_fdf_load_arr	create_fdf_load_arr(size_t length);

// parse.c

t_fdf_load		parse_ascii_cheche01(char *line);
t_fdf_load		parse_ascii_standard(char *line);
t_fdf_load		parse_ascii_chungaloider(char *line);
t_fdf_load		parse_decimal_rgba(char *line);
t_fdf_load		parse_decimal_bw(char *line);

// public.c

bool	isvalid_fdf_load_arr(t_fdf_load_arr *src, int i);
t_fdf_load_arr	fetch_fdf_load_arr(int fd,
					t_fdf_load (*parse_line)(char *line));
t_fdf_load_arr	load_fdf_load_arr(const char *file_name, const char *dir,
					t_fdf_load (*parse_line)(char *line));

// write_ascii.c

void			write_load_cheche01(int fd,
					const t_fdf_load_arr *src);
void			write_load_standard(int fd,
					const t_fdf_load_arr *src);
void			write_load_chungaloider(int fd,
					const t_fdf_load_arr *src);

#endif
