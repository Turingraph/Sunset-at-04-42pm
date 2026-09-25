#include"load.h"

int	main(void)
{
	int				clone_examples;
	size_t			i;
	size_t			score;
	size_t			max_score = 36;
	t_load_fdf_arr	fdf_file;
	char			*arr[] = {
		"0.txt",
		"1.txt",
		"2.txt",
		"3.txt",
		"4.txt",
		"5.txt",
		"6.txt",
		"7.txt",
		"8.txt",
		"9.txt",
		"a.txt",
		"b.txt",
		"c.txt",
		"d.txt",
		"e.txt",
		"f.txt",
		"g.txt",
		"h.txt",
		"i.txt",
		"j.txt",
		"k.txt",
		"l.txt",
		"m.txt",
		"n.txt",
		"o.txt",
		"p.txt",
		"q.txt",
		"r.txt",
		"s.txt",
		"t.txt",
		"u.txt",
		"v.txt",
		"w.txt",
		"x.txt",
		"y.txt",
		"z.txt"
	};
	char	*src_dir = "input_examples/figlet_rozzo/";
	char	*dst_dir = "unit_test/input/load/clone_input_ascii/";

	score = 0;
	i = 0;
	while (i < max_score)
	{
		fdf_file = open_fdf_file(arr[i], src_dir, parse_ascii_line_cheche01);
		clone_examples = open_dir_file(arr[i], dst_dir, E_WRITE);
		if (clone_examples > -1)
		{
			write_load_ascii_arr_cheche01(clone_examples, &fdf_file);
			if (assert_files_ascii(arr[i], arr[i], src_dir, dst_dir) == true)
				score += 1;
			else
			{
				write(1, "wrong: ", 8);
				write(1, arr[i], f_strlen(arr[i]));
				write(1, "\n", 1);
			}
		}
		free_load_fdf_arr(&fdf_file);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/load/fdf_write_ascii.out
*/
