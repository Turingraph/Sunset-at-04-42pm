#include "debug.h"

// time : O(n)
// space: O(n)
size_t	file_length(int fd)
{
	size_t	total_lines;
	char	*line;

	total_lines = 1;
	line = get_next_line(fd, true);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, true);
		total_lines += 1;
	}
	free(get_next_line(fd, false));
	return (total_lines);
}

// time : O(n)
// space: O(n)
bool	assert_file(const char *file_name_1, const char *file_name_2,
	const char *dir_name_1, const char *dir_name_2)
{
	int		fd;
	size_t	length;
	char	**strarr_1;
	char	**strarr_2;
	bool	result;

	fd = debug_load_file(file_name_1, dir_name_1, FILE_READ);
	length = file_length(fd);
	fd = debug_load_file(file_name_2, dir_name_2, FILE_READ);
	if (length != file_length(fd))
		return (false);
	fd = debug_load_file(file_name_1, dir_name_1, FILE_READ);
	strarr_1 = file_to_strarr(fd, length);
	fd = debug_load_file(file_name_2, dir_name_2, FILE_READ);
	strarr_2 = file_to_strarr(fd, length);
	result = assert_strarr((const char **)strarr_1, (const char **)strarr_2, length, true);
	destroy_arr2d((void **)strarr_1, length);
	destroy_arr2d((void **)strarr_2, length);
	return (result);
}

// time : O(n)
// space: O(n)
static bool	is_file_empty(int fd)
{
	char	*actual_y;

	if (fd < 0)
		return (false);
	actual_y = get_next_line(fd, true);
	if (actual_y == NULL)
		return (true);
	free(actual_y);
	free(get_next_line(fd, false));
	return (false);
}

// time : O(n)
// space: O(n)
static char	*assert_gnl_and_line(char *actual_line,
	const char *expected_line, int fd)
{
	if (assert_str(actual_line,
			expected_line, str_length(expected_line), false) == false
		|| str_length(actual_line) != str_length(expected_line))
	{
		free(actual_line);
		free(get_next_line(fd, false));
		return (NULL);
	}
	free(actual_line);
	return (get_next_line(fd, true));
}

// total_lines = 0 means to verify all lines.
// time : O(n)
// space: O(n)
bool	assert_file_strarr(int fd, const char **strarr, size_t total_lines)
{
	char	*line;
	char	*next_line;
	size_t	i;
	size_t	len;

	if (fd < 0)
		return (false);
	if (strarr == NULL || strarr[0] == NULL)
		return (is_file_empty(fd));
	line = get_next_line(fd, true);
	i = 0;
	while (line != NULL && ((i < total_lines && total_lines > 0)
			|| (total_lines == 0)))
	{
		next_line = assert_gnl_and_line(line, strarr[i], fd);
		line = next_line;
		i += 1;
	}
	len = strarr_length(strarr);
	free(line);
	free(get_next_line(fd, false));
	if (i == len)
		return (true);
	return (false);
}
