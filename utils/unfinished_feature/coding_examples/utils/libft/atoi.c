#include"libft.h"

// f_atoi
int	main(int len, char **str)
{
	bool	err;
	int		min;
	int		max;

	err = true;
	if (len < 3)
		return (0);
	min = f_atoi(str[1], &err, "0123456789", f_strlen(str[1]));
	max = f_atoi(str[2], &err, "0123456789", f_strlen(str[2]));
	if (err == false)
	{
		write(1, "input is invalid.\n", 18);
		return (0);
	}
	ft_putnbr_fd((int) min, 1, "0123456789", 5);
	if (min <= max)
		write(1, " is less than or equal to ", 26);
	else
		write(1, " is greater than ", 17);
	ft_putnbr_fd((int) max, 1, "0123456789", 5);
	write(1, "\n", 1);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/utils/libft/atoi.out 100 200

*/
