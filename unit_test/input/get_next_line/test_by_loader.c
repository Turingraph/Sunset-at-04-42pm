#include"get_next_line.h"

int	main(void)
{
	int							fd;
	int							fd_length;
	char						**load;
	size_t						total_lines;
	size_t						i;
	size_t						score;
	size_t						max_score = 15;
	static const t_file_tester	arr[] = {
		{(const char *)"42_no_nl", 1},
		{(const char *)"41_with_nl", 2},
		{(const char *)"42_no_nl", 1},
		{(const char *)"42_with_nl", 2},
		{(const char *)"43_no_nl", 1},
		{(const char *)"43_with_nl", 2},
		{(const char *)"alternate_line_nl_no_nl", 9},
		{(const char *)"alternate_line_nl_with_nl", 9},
		{(const char *)"big_line_no_nl", 1},
		{(const char *)"big_line_with_nl", 1},
		{(const char *)"empty", 0},
		{(const char *)"multiple_line_no_nl", 5},
		{(const char *)"multiple_line_with_nl", 5},
		{(const char *)"multiple_nlx5", 5},
		{(const char *)"nl", 1},
	};
	char	*src_dir = "unit_test/input/get_next_line/input/";

	score = 0;
	i = 0;
	while (i < max_score)
	{
		fd = open_dir_file(arr[i].file_name, src_dir, E_READ);
		fd_length = open_dir_file(arr[i].file_name, src_dir, E_READ);
		total_lines = total_lines_of_file(fd_length);
		load = load_file_as_strarr(fd, total_lines);
		fd = open_dir_file(arr[i].file_name, src_dir, E_READ);
		if (assert_file_with_strarr(fd, (const char **)load, total_lines) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			write(1, arr[i].file_name, f_strlen(arr[i].file_name));
			write(1, "\tall\n", 6);
		}
		free_2d_arr((void **)load, length_of_strarr((const char **)load));

		fd = open_dir_file(arr[i].file_name, src_dir, E_READ);
		load = load_file_as_strarr(fd, 1);
		fd = open_dir_file(arr[i].file_name, src_dir, E_READ);
		if (assert_file_with_strarr(fd, (const char **)load, 1) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			write(1, arr[i].file_name, f_strlen(arr[i].file_name));
			write(1, "\t1\n", 3);
		}
		free_2d_arr((void **)load, length_of_strarr((const char **)load));

		fd = open_dir_file(arr[i].file_name, src_dir, E_READ);
		load = load_file_as_strarr(fd, 3);
		fd = open_dir_file(arr[i].file_name, src_dir, E_READ);
		if (assert_file_with_strarr(fd, (const char **)load, 3) == true)
			score += 1;
		else
		{
			write(1, ">>> ", 4);
			write(1, arr[i].file_name, f_strlen(arr[i].file_name));
			write(1, "\t3\n", 3);
		}
		free_2d_arr((void **)load, length_of_strarr((const char **)load));
		i += 1;
	}
	write_total_score(score, max_score * 3);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/get_next_line/test_by_loader.out
*/
