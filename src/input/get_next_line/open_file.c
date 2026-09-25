#include "get_next_line.h"

/**
 * Open a file using an optional directory and file name
 * as [directory/file_name].
 * Uses whichever path argument is provided when the other is NULL.
 * Concatenates both paths when both are provided.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param file_name name or path of the file to open
 * @param dir directory or path prefix of the file
 * @param file_mode file access mode
 *
 * @return file descriptor on success, or -1 on failure
 */
int	open_dir_file(const char *file_name, const char *dir, t_file_mode file_mode)
{
	t_dynamic_str	file;
	int				dst;

	if (dir == NULL && file_name == NULL)
		return (-1);
	if (dir == NULL && file_name != NULL)
		return (open(file_name, file_mode));
	if (dir != NULL && file_name == NULL)
		return (open(dir, file_mode));
	file = init_dynamic_str(
			index_a_in_str(file_name, '\0') + index_a_in_str(dir, '\0'));
	concat_dynamic_str(&file, dir);
	concat_dynamic_str(&file, file_name);
	if (file.str == NULL)
		return (-1);
	dst = open(file.str, file_mode);
	free(file.str);
	return (dst);
}

/**
 * Count how many characters that the string have before 
 * encounter the target characters and/or '\0'.
 * 
 * time/space: O(n) / O(1)
 * 
 * status: public api
 * 
 * @param str string
 * @param stop the target character
 * 
 * @return a number of all characters before the target character and/or '\0'
 */
size_t	knight_of_coin(const char *str, char stop)
{
	size_t	i;

	i = 0;
	while (str != NULL && str[i] != '\0' && str[i] != stop)
		i += 1;
	return (i);
}

/**
 * concatenate string str_1 and string str_2 as str_1 + str_2
 * 
 * time/space: O(n) / O(n)
 * 
 * status: public api
 * 
 * @param str_1 first string
 * @param str_2 second string
 * 
 * @return concatinated string
 */
char	*concat_string(const char *str_1, const char *str_2)
{
	t_dynamic_str	dyn_str;
	char			*dst;

	dyn_str = init_dynamic_str(1);
	if (dyn_str.str == NULL)
		return (NULL);
	concat_dynamic_str(&dyn_str, str_1);
	concat_dynamic_str(&dyn_str, str_2);
	if (dyn_str.str == NULL)
		return (NULL);
	dst = clone_string(dyn_str.length, dyn_str.str);
	free(dyn_str.str);
	return (dst);
}
