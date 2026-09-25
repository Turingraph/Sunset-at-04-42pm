#include"load.h"

int	main(void)
{
	int				clone_examples;
	size_t			i;
	size_t			score;
	size_t			max_score = 16;
	t_load_fdf_arr	fdf_file;
	char			*arr[] = {
		"100-6.fdf",
		"10-70.fdf",
		"42.fdf",
		"basictest.fdf",
		"elem2.fdf",
		"elem.fdf",
		"mars.fdf",
		"plat.fdf",
		"pyra.fdf",
		"20-60.fdf",
		"50-4.fdf",
		"convolution_9.fdf",
		"large_plat.fdf",
		"pentenegpos.fdf",
		"pnp_flat.fdf",
		"pylone.fdf",
		// "julia.fdf"
	};
	char	*src_dir = "input_examples/fdf/";
	char	*dst_dir = "unit_test/input/load/clone_input_fdf/";

	score = 0;
	i = 0;
	while (i < max_score)
	{
		fdf_file = open_fdf_file(arr[i], src_dir, parse_fdf_line_bw);
		clone_examples = open_dir_file(arr[i], dst_dir, E_WRITE);
		if (clone_examples > -1)
		{
			write_load_fdf_arr(clone_examples, &fdf_file, 1, HEIGHT_ONLY);
			if (assert_files(arr[i], arr[i], src_dir, dst_dir) == true)
				score += 1;
			else
			{
				write(1, "Incorrect: ", 12);
				write(1, arr[i], f_strlen(arr[i]));
				write(1, "\n", 1);
			}
		}
		else
		{
			write(1, "Incorrect: ", 12);
			write(1, arr[i], f_strlen(arr[i]));
			write(1, "\n", 1);
		}
		free_load_fdf_arr(&fdf_file);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/load/fdf_write_fdf.out
*/
