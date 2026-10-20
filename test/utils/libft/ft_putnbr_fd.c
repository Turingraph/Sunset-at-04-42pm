#include"libft.h"

int	main(void)
{
	size_t					i;
	size_t					score;
	size_t					max_score;
	const t_putnbr_tester	arr[] = {
		{5890, 4, "0123456789", 4},
		{820, 3, "0123456789", 3},
		{-820, 3, "0123456789", 4},
		{-820, 5, "0123456789", 5},
		{820, 3, "01", 10},
		{820, 12, "01", 12},
		{118, 1, "0123456789abcdef", 2},
		{2147483647, 20, "0123456789", 20},
		{2147483644, 5, "01234567", 11},
		{2147483644, 5, "01233334", 11}
	};

	max_score = 10;
	i = 0;
	score = 0;
	while (i < max_score)
	{
		write(1, ">>> ", 4);
		if (arr[i].expected_length == write_int(
				arr[i].input_n, 1, arr[i].input_base, arr[i].input_digits))
		{
			write(1, "\tOK", 3);
			score += 1;
		}
		else
			write(1, "\tKO", 3);
		write(1, "\n", 1);
		i += 1;
	}
	write_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/utils/libft/write_int.out
*/
