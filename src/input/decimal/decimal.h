#ifndef DECIMAL_H
# define DECIMAL_H

# include "../ascii/ascii.h"

// atoi.c

int		str_to_int(const char *src, bool *is_int, const char *base, size_t digits);
size_t	write_int(int n, int fd, const char *base, size_t digits);

// public.c

t_fdf_load_arr	fetch_fdf_load(int fd, t_fdf_format format);

// utils.c

char	is_a_in_str(char s, const char *space);
size_t	str_length(const char *str);

#endif
