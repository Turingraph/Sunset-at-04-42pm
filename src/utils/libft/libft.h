/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:22:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:22:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "../type/type.h"

// arr.c

char			f_isspace(char s, const char *space);
size_t			f_strlen(const char *str);
void			*malloc_talk(size_t elem_size, const char *comment);
unsigned char	*get_rgba_of_table_fdf(const t_table_fdf *src,
					t_fdf_channel rgba_type);

// atoi.c

int				f_atoi(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

#endif
