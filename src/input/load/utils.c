#include "load_private.h"

// time : O(1)
// space: O(1)
void	warning_fdf_load(const t_fdf_load *src, size_t i)
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

// time : O(1)
// space: O(1)
static bool	isvalid_fdf_load(t_fdf_load *src)
{
	if (src == NULL || src->arr == NULL
		|| src->int_warn == ERROR_NOT_DECIMAL
		|| src->rgb_warn == ERROR_NOT_HEX
		|| src->rgb_warn == ERROR_NOT_DECIMAL
		|| src->int_warn == ERROR_NOT_HEX)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	isvalid_fdf_load_arr(t_fdf_load_arr *src, int i)
{
	if (src == NULL || src->arr == NULL || i < 0
		|| i > (int)src->length || i > (int)src->capacity
		|| isvalid_fdf_load(&(src->arr[i])) == false)
		return (false);
	return (true);
}
