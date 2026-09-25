/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:36:58 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/17 12:52:32 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_dynamic_str
{
	size_t	length;
	size_t	capacity;
	char	*str;
}	t_dynamic_str;

typedef enum t_file_mode
{
	E_READ = O_RDONLY,
	E_WRITE = O_WRONLY,
}	t_file_mode;

// dynamic_str.c

char			*clone_string(size_t length, const char *src);
t_dynamic_str	init_dynamic_str(size_t length);
bool			push_dynamic_str(t_dynamic_str *dst, char src);
void			concat_dynamic_str(t_dynamic_str *dst, const char *src);
size_t			index_a_in_str(const char *src, char a);

// get_next_line.c

void			fetch_text(int fd, t_dynamic_str *dst, size_t buffer_length);
char			*get_next_line(int fd, bool is_continue);

// open_dir_file.c

int				open_dir_file(const char *file_name,
					const char *dir, t_file_mode file_mode);
size_t			knight_of_coin(const char *str, char stop);

#endif
