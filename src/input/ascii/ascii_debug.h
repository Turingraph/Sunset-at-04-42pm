/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_debug.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:58:24 by phsottat          #+#    #+#             */
/*   Updated: 2026/10/21 16:31:55 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCII_DEBUG_H
# define ASCII_DEBUG_H

# include "../get_next_line/get_next_line.h"
# include "../../utils/libft/libft.h"
# include "ascii_type.h"

// all_files.c

t_fdf_load_arr	debug_fdf_load_helper(const char *file_name, const char *dir,
					t_fdf_load (*parse_line)(char *line));

// ascii.c

size_t			str_length(const char *str);
char			ascii_to_mirror(char a, bool is_left);

// init.c

void			destroy_fdf_load_arr(t_fdf_load_arr *src);

#endif
