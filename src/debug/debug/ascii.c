#include "debug.h"

// time : O(n)
// space: O(1)
static int		compare_string_ascii(const char *str_1, const char *str_2, size_t n)
{
	size_t	i;

	i = 0;
	if (str_1 == NULL && str_2 == NULL)
		return (0);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (-1);
	while (i < n && *str_1 != '\0'
		&& ascii_to_mirror(*str_1, true) == ascii_to_mirror(*str_2, true))
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
		while (*str_1 == '\n')
			str_1 += 1;
		while (*str_2 == '\n')
			str_2 += 1;
	}
	return (ascii_to_mirror(*str_1, true) - ascii_to_mirror(*str_2, true));
}

// time : O(n)
// space: O(1)
static bool	assert_strarr_ascii(const char **strarr_1,
	const char **strarr_2, size_t length)
{
	size_t	i;

	i = 0;
	if (strarr_1 == NULL && strarr_2 == NULL)
		return (true);
	if (strarr_1 == NULL || strarr_2 == NULL)
		return (false);
	while (i < length && strarr_1[i] != NULL && strarr_2[i] != NULL)
	{
		if (compare_string_ascii(strarr_1[i], strarr_2[i],
				str_length(strarr_1[i])) != 0)
			return (false);
		i += 1;
	}
	if (strarr_1[i] == NULL && strarr_2[i] == NULL)
		return (true);
	if (strarr_1[i] != NULL || strarr_2[i] != NULL)
		return (false);
	return (true);
}

// time : O(n)
// space: O(n)
bool	assert_file_ascii(const char *file_name_1, const char *file_name_2,
	const char *dir_name_1, const char *dir_name_2)
{
	int		fd;
	size_t	length;
	char	**strarr_1;
	char	**strarr_2;
	bool	result;

	fd = load_file_debug(file_name_1, dir_name_1, E_READ);
	length = file_length(fd);
	fd = load_file_debug(file_name_2, dir_name_2, E_READ);	
	if (length != file_length(fd))
		return (false);
	fd = load_file_debug(file_name_1, dir_name_1, E_READ);
	strarr_1 = file_to_strarr(fd, length);
	fd = load_file_debug(file_name_2, dir_name_2, E_READ);
	strarr_2 = file_to_strarr(fd, length);
	result = assert_strarr_ascii((const char **)strarr_1, (const char **)strarr_2, length);
	destroy_2d_arr((void **)strarr_1, length);
	destroy_2d_arr((void **)strarr_2, length);
	return (result);
}
