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
	char	*src_dir = "test/input/get_next_line/input/";
	char	*dst_dir = "test/input/get_next_line/clone_input/";

	score = 0;
	max_score = 15;
	i = 0;
	while (i < max_score)
	{
		fd = load_file_debug(arr[i],
			src_dir, E_READ);
		if (fd > -1)
		{
			total_lines = file_length(fd);
			fd = load_file_debug(arr[i], src_dir, E_READ);
			load = file_to_strarr(fd, total_lines);
			fd = load_file_debug(arr[i], dst_dir, E_WRITE);
			if (fd > -1)
			{
				write_strarr((const char **)load, strarr_length((const char **)load), fd);
				if (assert_file(arr[i], arr[i], src_dir, dst_dir) == true)
					score += 1;
				else
				{
					write(1, ">>> ", 4);
					write_int(i, 1, "0123456789", 1);
					write(1, "\n", 1);
				}
			}
			else
				write(1, ">>> Empty Set\n", 15);
			if (load != NULL)
				destroy_arr2d((void **)load, strarr_length((const char **)load));
		}
		i += 1;
	}
	write_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/input/get_next_line/test_by_files.out
*/
