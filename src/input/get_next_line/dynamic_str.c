#include "get_next_line.h"

/**
 * Allocate and create a copy of a string with a fixed length.
 * The destination is always null-terminated.
 * Missing characters are initialized with zero values.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param length number of characters to allocate for the string
 * @param src string to copy from
 *
 * @return pointer to the copied string, or NULL on failure
 */
char	*clone_string(size_t length, const char *src)
{
	size_t	i;
	char	*dst;

	if (length == 0)
		return (NULL);
	dst = (void *)malloc((length + 1) * sizeof(char));
	if (dst == NULL)
		return (dst);
	dst[length] = '\0';
	i = 0;
	while (i < length && src != NULL && src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	while (i < length)
	{
		dst[i] = 0;
		i += 1;
	}
	return (dst);
}

/**
 * Create and initialize a dynamic string with a fixed capacity.
 * The string starts empty with length set to zero.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param length initial capacity of the dynamic string
 *
 * @return initialized dynamic string structure
 */
t_dynamic_str	init_dynamic_str(size_t length)
{
	t_dynamic_str	dst;

	dst.capacity = length;
	dst.length = 0;
	dst.str = NULL;
	if (length == 0)
		return (dst);
	dst.str = clone_string(sizeof(char) * length, NULL);
	return (dst);
}

/**
 * Add a character to the end of a dynamic string.
 * Automatically doubles the capacity when the string is full.
 *
 * time/space: O(1) / O(1)
 *
 * status: public api
 *
 * @param dst dynamic string to modify
 * @param src character to append
 *
 * @return true if the character was added, otherwise false
 */
bool	push_dynamic_str(t_dynamic_str *dst, char src)
{
	char	*dst2;

	if (dst == NULL || dst->str == NULL)
		return (false);
	if (dst->length < dst->capacity)
	{
		dst->str[dst->length] = src;
		dst->length += 1;
		return (true);
	}
	dst2 = clone_string(sizeof(char) * 2 * dst->length, dst->str);
	if (dst2 == NULL)
		return (false);
	free(dst->str);
	dst->str = dst2;
	dst->capacity *= 2;
	return (push_dynamic_str(dst, src));
}

/**
 * Append a null-terminated string to a dynamic string.
 * Stops appending if the destination cannot accept more characters.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 *
 * @param dst dynamic string to modify
 * @param src string to append
 */
void	concat_dynamic_str(t_dynamic_str *dst, const char *src)
{
	size_t	i;
	bool	is_continue;

	if (dst == NULL || dst->str == NULL || src == NULL)
		return ;
	is_continue = true;
	i = 0;
	while (src[i] != '\0' && is_continue == true)
	{
		is_continue = push_dynamic_str(dst, src[i]);
		i += 1;
	}
}
