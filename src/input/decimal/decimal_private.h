#ifndef DECIMAL_PRIVATE_H
# define DECIMAL_PRIVATE_H

# include "../ascii/ascii_private.h"

// atoi.c

int		str_to_int(const char *src, bool *is_int, const char *base, size_t digits);
size_t	write_int(int n, int fd, const char *base, size_t digits);

// decimal.c

t_fdf_load	parse_decimal(char *line, bool is_rgba);

// parse.c

t_fdf_load	parse_decimal_rgba(char *line);
t_fdf_load	parse_decimal_bw(char *line);

// rgba.c

size_t	count_hex_digits(char *line, size_t max);
void	update_rgba(char *line, t_fdf_load *dst, size_t index);

// utils.c

char	is_a_in_str(char s, const char *space);
size_t	str_length(const char *str);
void	warn_fdf_load(const t_fdf_load *src, size_t i);

// write_decimal.c

void	write_load_decimal(int fd,
		const t_fdf_load_arr *src, size_t digits, t_fdf_format mode);

#endif
