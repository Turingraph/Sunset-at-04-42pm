#include "taylor.h"

int	main(void)
{
	int	y;
	size_t	score = 0;
	size_t	max_score = 7;
	
	y = f_fibonacci(1);
	if (y == 1)
		score += 1;
	y = f_fibonacci(2);
	if (y == 2)
		score += 1;
	y = f_fibonacci(3);
	if (y == 3)
		score += 1;
	y = f_fibonacci(4);
	if (y == 5)
		score += 1;
	y = f_fibonacci(5);
	if (y == 8)
		score += 1;
	y = f_fibonacci(6);
	if (y == 13)
		score += 1;
	y = f_fibonacci(7);
	if (y == 21)
		score += 1;
	y = f_fibonacci(8);
	if (y == 34)
		score += 1;
	y = f_fibonacci(9);
	if (y == 55)
		score += 1;
	y = f_fibonacci(10);
	if (y == 89)
		score += 1;
	write_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/utils/taylor/fib.out
*/

