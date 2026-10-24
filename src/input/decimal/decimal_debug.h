#ifndef DECIMAL_DEBUG_H
# define DECIMAL_DEBUG_H

#include "../ascii/ascii_debug.h"

// atoi.c

int				str_to_int(const char *src, bool *is_int,
					const char *base, size_t digits);
size_t			write_int(int n, int fd, const char *base, size_t digits);

// utils.c

char			is_a_in_str(char s, const char *space);
size_t			str_length(const char *str);

// write_decimal.c

void			write_load_decimal(int fd, const t_fdf_load_arr *src,
					size_t digits, t_fdf_format write_style);

#endif
