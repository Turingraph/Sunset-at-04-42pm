#include "debug.h"

// time : O(n)
// space: O(n)
size_t	length_of_file(int fd)
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

	fd = load_file_debug(file_name_1, dir_name_1, E_READ);
	length = length_of_file(fd);
	fd = load_file_debug(file_name_2, dir_name_2, E_READ);
	if (length != length_of_file(fd))
		return (false);
	fd = load_file_debug(file_name_1, dir_name_1, E_READ);
	strarr_1 = file_to_strarr(fd, length);
	fd = load_file_debug(file_name_2, dir_name_2, E_READ);
	strarr_2 = file_to_strarr(fd, length);
	result = assert_strarr((const char **)strarr_1, (const char **)strarr_2, length, true);
	destroy_2d_arr((void **)strarr_1, length);
	destroy_2d_arr((void **)strarr_2, length);
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
			expected_line, f_strlen(expected_line), false) == false
		|| f_strlen(actual_line) != f_strlen(expected_line))
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
	len = length_of_strarr(strarr);
	free(line);
	free(get_next_line(fd, false));
	if (i == len)
		return (true);
	return (false);
}
