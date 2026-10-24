#include"table.h"

int	main(void)
{
	int				fdf_dst;
	size_t			i;
	size_t			length = 36;
	t_fdf_table		table;
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
	char			*arrdst[] = {
		"0.fdf",
		"1.fdf",
		"2.fdf",
		"3.fdf",
		"4.fdf",
		"5.fdf",
		"6.fdf",
		"7.fdf",
		"8.fdf",
		"9.fdf",
		"a.fdf",
		"b.fdf",
		"c.fdf",
		"d.fdf",
		"e.fdf",
		"f.fdf",
		"g.fdf",
		"h.fdf",
		"i.fdf",
		"j.fdf",
		"k.fdf",
		"l.fdf",
		"m.fdf",
		"n.fdf",
		"o.fdf",
		"p.fdf",
		"q.fdf",
		"r.fdf",
		"s.fdf",
		"t.fdf",
		"u.fdf",
		"v.fdf",
		"w.fdf",
		"x.fdf",
		"y.fdf",
		"z.fdf"
	};
	char	*src_dir = "corpus/figlet_rozzo/";
	char	*dst_dir = "test/input/table/01_ascii_to_fdf/";

	i = 0;
	while (i < length)
	{
		char *file_name = concat_str(src_dir, arr[i]);
		table = load_fdf_table(file_name, FDF_FORMAT_ASCII_B, false);
		free(file_name);
		positive_fdf_table(&table);
		fdf_dst = debug_load_file(arrdst[i], dst_dir, FILE_WRITE);
		if(fdf_dst > -1)
		{
			write(1, "\n*** ", 5);
			write(1, arr[i], str_length(arr[i]));
			write(1, " ***\n", 5);
			write_fdf_table(1, &table, 3, FDF_FORMAT_DECIMAL_BW);
			write_fdf_table(fdf_dst, &table, 1, FDF_FORMAT_DECIMAL_BW);
		}
		else
			write_file_not_exists(arr[i]);
		destroy_fdf_table(&table);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/input/table/01_ascii_to_fdf.out

*/
