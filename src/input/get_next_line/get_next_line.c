#include "get_next_line.h"

/**
 * Find the first occurrence of a character in a string.
 * Returns the position after the character, or the string length
 * when the character is not found.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 *
 * @param src string to search
 * @param a character to search for
 *
 * @return position after a, or string length if a is not found
 */
size_t	index_a_in_str(const char *src, char a)
{
	size_t	i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == a)
			return (i + 1);
		i += 1;
	}
	return (i);
}

/**
 * Read text from a file descriptor into a dynamic string.
 * Continues reading until the requested stop character is found
 * or a buffer cannot be allocated.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param fd file descriptor to read from
 * @param dst dynamic string to append the text to
 * @param buffer_length number of characters to read at a time
 */
void	fetch_text(int fd, t_dynamic_str *dst, size_t buffer_length)
{
	char	*buff;
	bool	continue_line;

	continue_line = true;
	while (continue_line == true && dst != NULL && dst->str != NULL)
	{
		buff = clone_string(sizeof(char) * buffer_length, NULL);
		if (buff == NULL)
			continue_line = false;
		else
		{
			read(fd, buff, buffer_length);
			concat_dynamic_str(dst, buff);
			if (index_a_in_str(buff, '\0') < buffer_length)
				continue_line = false;
		}
		free(buff);
	}
	close(fd);
}

/**
 * Read the next line from a file descriptor.
 * Preserves unread text between calls when continuation is enabled.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param fd file descriptor to read from
 * @param is_continue whether unread text should be preserved for the next call
 *
 * @return newly allocated string ending at '\n', or NULL on allocation failure
 */
char	*get_next_line(int fd, bool is_continue)
{
	char			*dst;
	static char		*prev_str = NULL;
	t_dynamic_str	dyn_str;
	size_t			length;

	dyn_str = init_dynamic_str(1);
	if (dyn_str.str == NULL)
		return (NULL);
	concat_dynamic_str(&dyn_str, prev_str);
	if (prev_str == NULL)
		fetch_text(fd, &dyn_str, BUFFER_SIZE);
	free(prev_str);
	prev_str = NULL;
	length = index_a_in_str(dyn_str.str, '\n');
	dst = clone_string(length, dyn_str.str);
	if (is_continue == true)
		prev_str = clone_string(dyn_str.length - length, dyn_str.str + length);
	free(dyn_str.str);
	return (dst);
}
