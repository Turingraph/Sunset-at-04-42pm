#include "decimal_private.h"

// time : O(n)
// space: O(1)
char	is_a_in_str(char s, const char *space)
{
	while (space != NULL && *space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
	}
	return (0);
}

// time : O(n)
// space: O(1)
size_t	str_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

// time : O(1)
// space: O(1)
void	warn_fdf_load(const t_fdf_load *src, size_t i)
{
	if (src->int_warn != ERROR_CORRECT || src->rgb_warn != ERROR_CORRECT)
	{
		write(1, "Warning: Line no. ", 19);
		write_int(i, 1, "0123456789", 1);
		write(1, " of input Fdf file is ", 23);
		if (src->int_warn == ERROR_EMPTY)
			write(1, "empty", 6);
		if (src->int_warn == ERROR_NOT_DECIMAL)
			write(1, "not a decimal number", 21);
		if (src->int_warn != ERROR_CORRECT && src->rgb_warn == 'E')
			write(1, " and ", 5);
		if (src->rgb_warn == ERROR_NOT_HEX)
			write(1, " not a valid hexadecimal rgb representation", 44);
		write(1, ".\n", 2);
	}
}
