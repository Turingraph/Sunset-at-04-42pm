#include"line.h"

// time : O(1)
// space: O(1)
void	write_line(t_line src, const char *comment)
{
	write(1, comment, f_strlen(comment));
	write(1, " [", 2);
	ft_putnbr_fd(src.p1.x, 1, "0123456789", 1);
	write(1, ", ", 2);
	ft_putnbr_fd(src.p1.y, 1, "0123456789", 1);
	write(1, " ] --> [ ", 9);
	ft_putnbr_fd(src.p2.x, 1, "0123456789", 1);
	write(1, ", ", 2);
	ft_putnbr_fd(src.p2.y, 1, "0123456789", 1);
	write(1, "]\n", 2);
}
