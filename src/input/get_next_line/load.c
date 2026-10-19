#include "get_next_line.h"

/**
 * Open a file using an optional directory and file name
 * as [directory/file_name].
 * Uses whichever path argument is provided when the other is NULL.
 * Concatenates both paths when both are provided.
 *
 * time/space: O(n) / O(n)
 *
 * status: internal helper
 *
 * @param file_name name or path of the file to open
 * @param dir directory or path prefix of the file
 * @param file_mode file access mode
 *
 * @return file descriptor on success, or -1 on failure
 */
int	load_file_debug(const char *file_name, const char *dir, t_file_mode file_mode)
{
	t_dynamic_str	file;
	int				dst;

	if (dir == NULL && file_name == NULL)
		return (-1);
	if (dir == NULL && file_name != NULL)
		return (open(file_name, file_mode));
	if (dir != NULL && file_name == NULL)
		return (open(dir, file_mode));
	file = create_dynamic_str(
			index_a_in_str(file_name, '\0', true) + index_a_in_str(dir, '\0', true));
	concat_dynamic_str(&file, dir);
	concat_dynamic_str(&file, file_name);
	if (file.str == NULL)
		return (-1);
	dst = open(file.str, file_mode);
	free(file.str);
	return (dst);
}

/**
 * Open a file
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param file_name name or path of the file to open
 * @param file_mode file access mode
 *
 * @return file descriptor on success, or -1 when file_name is NULL
 */
int	load_file(const char *file_name, t_file_mode file_mode)
{
	int	dst;

	if (file_name == NULL)
		return (-1);
	dst = open(file_name, file_mode);
	return (dst);
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
char	*concat_str(const char *str_1, const char *str_2)
{
	t_dynamic_str	dyn_str;
	char			*dst;

	dyn_str = create_dynamic_str(1);
	if (dyn_str.str == NULL)
		return (NULL);
	concat_dynamic_str(&dyn_str, str_1);
	concat_dynamic_str(&dyn_str, str_2);
	if (dyn_str.str == NULL)
		return (NULL);
	dst = clone_str(dyn_str.length, dyn_str.str);
	free(dyn_str.str);
	return (dst);
}
