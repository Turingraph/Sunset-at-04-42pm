#include "debug.h"

// time : O(n)
// space: O(1)
int		compare_string_ascii(const char *str_1, const char *str_2, size_t n)
{
	size_t	i;

	i = 0;
	if (str_1 == NULL && str_2 == NULL)
		return (0);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (-1);
	while (i < n && *str_1 != '\0'
		&& mirror_tune(*str_1, true) == mirror_tune(*str_2, true))
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
		while (*str_1 == '\n')
			str_1 += 1;
		while (*str_2 == '\n')
			str_2 += 1;
	}
	return (mirror_tune(*str_1, true) - mirror_tune(*str_2, true));
}

// time : O(n)
// space: O(1)
bool	assert_strarr_ascii(const char **strarr_1,
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
				f_strlen(strarr_1[i])) != 0)
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
bool	assert_files_ascii(const char *file_name_1, const char *file_name_2,
	const char *dir_name_1, const char *dir_name_2)
{
	int		fd;
	size_t	length;
	char	**strarr_1;
	char	**strarr_2;
	bool	result;

	fd = open_dir_file(file_name_1, dir_name_1, E_READ);
	length = total_lines_of_file(fd);
	fd = open_dir_file(file_name_2, dir_name_2, E_READ);	
	if (length != total_lines_of_file(fd))
		return (false);
	fd = open_dir_file(file_name_1, dir_name_1, E_READ);
	strarr_1 = load_file_as_strarr(fd, length);
	fd = open_dir_file(file_name_2, dir_name_2, E_READ);
	strarr_2 = load_file_as_strarr(fd, length);
	result = assert_strarr_ascii((const char **)strarr_1, (const char **)strarr_2, length);
	free_2d_arr((void **)strarr_1, length);
	free_2d_arr((void **)strarr_2, length);
	return (result);
}
