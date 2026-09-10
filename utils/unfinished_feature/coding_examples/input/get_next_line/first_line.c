#include"get_next_line.h"

int	main(int len, char **str)
{
	int		fd;
	char	*line;
	int		output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, true);
	get_next_line(fd, false);
	write(output, ">>> ", 5);
	write(output, line, knight_of_coin(line, '\0'));
	if (line == NULL)
		return (0);
	free(line);
	return (0);
}
