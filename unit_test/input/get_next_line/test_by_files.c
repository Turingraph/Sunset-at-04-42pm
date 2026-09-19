#include"get_next_line.h"

int	main(void)
{
	size_t	i;
	size_t	score;
	size_t	max_score = 15;
	size_t	total_lines;
	int		fd;
	char	**load;
	char	*arr[] = {
		"41_no_nl",
		"41_with_nl",
		"42_no_nl",
		"42_with_nl",
		"43_no_nl",
		"43_with_nl",
		"alternate_line_nl_no_nl",
		"alternate_line_nl_with_nl",
		"big_line_no_nl",
		"big_line_with_nl",
		"empty",
		"multiple_line_no_nl",
		"multiple_line_with_nl",
		"multiple_nlx5",
		"nl"
	};
	char	*src_dir = "unit_test/input/get_next_line/input/";
	char	*dst_dir = "unit_test/input/get_next_line/clone_input/";

	score = 0;
	max_score = 15;
	i = 0;
	while (i < max_score)
	{
		fd = open_dir_file(arr[i],
			src_dir, READ);
		if (fd > -1)
		{
			total_lines = total_lines_of_file(fd);
			fd = open_dir_file(arr[i], src_dir, READ);
			load = load_file_as_strarr(fd, total_lines);
			fd = open_dir_file(arr[i], dst_dir, APPEND);
			if (fd > -1)
			{
				write_strarr((const char **)load, length_of_strarr((const char **)load), fd);
				if (assert_files(arr[i], arr[i], src_dir, dst_dir) == true)
					score += 1;
				else
				{
					write(1, ">>> ", 4);
					ft_putnbr_fd(i, 1, "0123456789", 1);
					write(1, "\n", 1);
				}
			}
			else
				write(1, ">>> Empty Set\n", 15);
			if (load != NULL)
				free_2d_arr((void **)load, length_of_strarr((const char **)load));
		}
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/get_next_line/test_by_files.out
*/
