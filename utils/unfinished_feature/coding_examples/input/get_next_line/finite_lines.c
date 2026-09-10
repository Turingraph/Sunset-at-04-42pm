#include"get_next_line.h"

int	main(int len, char **str)
{
	int		fd;
	char	*line;
	size_t	max;
	int		output;

	if (len < 2)
		return (0);
	output = 1;
	max = 5;
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, true);
	if (line == NULL)
		return (0);
	while (line != NULL && max > 0)
	{
		write(output, ">>> ", 5);
		write(output, line, knight_of_coin(line, '\0'));
		free(line);
		line = get_next_line(fd, true);
		max -= 1;
	}
	get_next_line(fd, false);
	return (0);
}

// output = open_dir_file(str[2], NULL, APPEND);

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/input/get_next_line/finite_lines.out input_examples/mathart_gradient/rozzo_a_404.txt

*/
