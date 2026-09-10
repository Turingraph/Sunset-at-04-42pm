#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	write_2d_index(int max_col, int row, int col)
{
	write(1, "row = ", 7);
	ft_putnbr_fd(row, 1, "0123456789", 1);
	write(1, "\n", 1);
	write(1, "col = ", 7);
	ft_putnbr_fd(col, 1, "0123456789", 1);
	write(1, "\n", 1);
	row = row * max_col + col;
	write(1, "index = ", 9);
	ft_putnbr_fd(row, 1, "0123456789", 1);
	write(1, "\n", 1);
	write(1, "max_col = ", 11);
	ft_putnbr_fd(max_col, 1, "0123456789", 1);
	write(1, "\n", 1);
}
