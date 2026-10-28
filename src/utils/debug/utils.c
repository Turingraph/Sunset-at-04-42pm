#include "debug.h"

// time : O(1)
// space: O(1)
void	write_score(size_t score, size_t max_score)
{
	write(1, "Score: ", 8);
	write_int((int)score, 1, "0123456789", 1);
	write(1, " / ", 3);
	write_int((int)max_score, 1, "0123456789", 1);
	write(1, "\n", 1);
}

// time : O(n)
// space: O(1)
bool	assert_intarr(const int *str_1, const int *str_2, size_t n)
{
	size_t	i;

	i = 0;
	if (str_1 == NULL && str_2 == NULL)
		return (true);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (false);
	while (i < n - 1 && *str_1 == *str_2)
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
	}
	if (*str_1 - *str_2 != 0)
		return (false);
	return (true);
}

// time : O(n)
// space: O(n)
void	write_file_not_exists(const char *src)
{
	write(1, "Warning: ", 10);
	write(1, src, str_length(src));
	write(1, " is not exists.\n", 17);
}

// time : O(n)
// space: O(1)
void	destroy_arr2d(void **arr, size_t len)
{
	while (len > 0 && arr != NULL)
	{
		if (len > 0 && arr[len - 1] != NULL)
			free(arr[len - 1]);
		len -= 1;
	}
	free(arr);
}
