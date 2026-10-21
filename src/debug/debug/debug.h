#ifndef TEST_HELPERS_H
# define TEST_HELPERS_H

# include "stdlib.h"
# include "../../input/decimal/decimal_debug.h"

typedef struct t_intarr t_intarr;

struct t_intarr
{
	size_t		length;
	const int	*arr;
};

typedef struct t_intarr_tester t_intarr_tester;

struct t_intarr_tester
{
	const t_intarr	*arr;
	const char		*file_name;
	size_t			length;
};

/*
Note
*	assert_* = check if 2 arguments have same data.
*	write_* = display the data.
*	length_of_* = the length of the given data.

Type of data
1.	file (int)
2.	str (char *)
3.	strarr (char **)
4.	intarr (int *)
*/

// ascii.c

bool	assert_file_ascii(const char *file_name_1, const char *file_name_2,
			const char *dir_name_1, const char *dir_name_2);

// file.c

size_t	file_length(int fd);
bool	assert_file(const char *file_name_1, const char *file_name_2,
			const char *dir_name_1, const char *dir_name_2);
bool	assert_file_strarr(int fd, const char **strarr,
			size_t total_lines);

// strarr.c

bool	assert_str(const char *str_1, const char *str_2,
			size_t n, bool ignore_space);
size_t	strarr_length(const char **src);
bool	assert_strarr(const char **strarr_1, const char **strarr_2,
			size_t length, bool ignore_space);
size_t	write_strarr(const char **strarr, size_t length, int fd);
char	**file_to_strarr(int fd, size_t total_lines);

// utils.c

void	write_score(size_t score, size_t max_score);
bool	assert_intarr(const int *str_1, const int *str_2, size_t n);
void	write_file_not_exists(const char *src);
void	destroy_arr2d(void **arr, size_t len);

#endif
