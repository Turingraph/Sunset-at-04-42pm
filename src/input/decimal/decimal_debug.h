#ifndef DECIMAL_DEBUG_H
# define DECIMAL_DEBUG_H

#include "../ascii/ascii_debug.h"

// atoi.c

int				str_to_int(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			write_int(int n, int fd, const char *base, size_t digits);

// public.c

t_fdf_load_arr	fetch_fdf_load(int fd, t_fdf_format format);
t_fdf_load_arr	debug_fdf_load(const char *file_name,
					const char *dir, t_fdf_format format);

// utils.c

char			is_a_in_str(char s, const char *space);
size_t			str_length(const char *str);

// write.c

void	write_fdf_load(int fd, const t_fdf_load_arr *src, t_fdf_format format);

#endif
