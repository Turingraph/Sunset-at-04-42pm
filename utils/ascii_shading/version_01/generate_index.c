#include<unistd.h>
#include<stdbool.h>

// time : O(n)
// space: O(1)
size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

// time : O(1)
// space: O(1)
size_t	display_int(int fd, long x, const char *base, bool is_write)
{
	size_t	i;
	long	d;
	char	coef;
	size_t	len;

	if (base == NULL)
		return (0);
	i = 0;
	len = f_strlen(base);
	d = 1;
	while (d < x)
		d *= len;
	if (d > x)
		d /= len;
	while (d > 0)
	{
		coef = base[x / d];
		if (is_write == true)
			write(fd, &coef, 1);
		x = x % d;
		d /= len;
		i += 1;
	}
	return (i);
}

// time : O(1)
// space: O(1)

size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits)
{
	size_t	i;
	size_t	j;

	if (base != NULL)
	{
		i = 0;
		j = 0;
		if (n > 0)
			j = display_int(fd, (long)n, base, 0);
		else if (n < 0)
		{
			n *= -1;
			j = display_int(fd, n, base, 0);
			i += (size_t)write(fd, "-", 1);
		}
		if (j > digits)
			j = digits;
		while (i < digits - j)
			i += (size_t)write(fd, base, 1);
		if (n != 0)
			i += display_int(fd, n, base, 1);
		return (i);
	}
	return (0);
}

int	main(void)
{
	size_t	i;
	size_t	j;
	size_t	max_row;
	size_t	max_col;

	max_row = 20;
	max_col = 20;
	i = 0;
	while (i < max_row)
	{
		j = 0;
		while (j < max_col)
		{
			write(1, "[", 1);
			ft_putnbr_fd(j, 1, "0123456789", 2);
			write(1, ", ", 2);
			ft_putnbr_fd(i, 1, "0123456789", 2);
			write(1, "] ", 2);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
	return (0);
}