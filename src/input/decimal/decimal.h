#ifndef DECIMAL_H
# define DECIMAL_H

# include "../ascii/ascii.h"

// atoi.c

int		str_to_int(const char *src, bool *is_int, const char *base, size_t digits);
size_t	write_int(int n, int fd, const char *base, size_t digits);

// parse.c

t_fdf_load	parse_decimal_rgba(char *line);
t_fdf_load	parse_decimal_bw(char *line);

// utils.c

char	is_a_in_str(char s, const char *space);
size_t	str_length(const char *str);

#endif
