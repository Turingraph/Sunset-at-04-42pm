#include"get_next_line.h"

int	main(int len, char **str)
{
	int		fd;
	char	*line;
	int		output;

	if (len < 2)
		return (0);
	output = 1;
	fd = open_dir_file(str[1], NULL, READ);
	line = get_next_line(fd, true);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		write(output, ">>> ", 5);
		write(output, line, knight_of_coin(line, '\0'));
		free(line);
		line = get_next_line(fd, true);
	}
	return (0);
}

// output = open_dir_file(str[2], NULL, APPEND);

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/input/get_next_line/all_lines.out input_examples/mathart_gradient/rozzo_a_404.txt

*/