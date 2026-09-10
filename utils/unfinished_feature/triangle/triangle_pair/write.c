#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	write_3d_vector(int fd, const float *vec_v)
{
	if (vec_v != NULL)
	{
		write(fd, "(", 1);
		ft_putnbr_fd(f_floor(vec_v[0]), fd, "0123456789", 3);
		write(fd, ", ", 2);
		ft_putnbr_fd(f_floor(vec_v[1]), fd, "0123456789", 3);
		write(fd, ", ", 2);
		ft_putnbr_fd(f_floor(vec_v[2]), fd, "0123456789", 3);
		write(fd, "),\t", 2);
	}
	else
		write(fd, "The Vector is NULL.\t", 21);
}

// time : O(1)
// space: O(1)
void	write_triangle(int fd, const t_triangle *src)
{
	if (src != NULL)
	{
		write_3d_vector(fd, src->p1);
		write_3d_vector(fd, src->p2);
		write_3d_vector(fd, src->p3);
		write(fd, "0x", 2);
		ft_putnbr_fd(src->r, fd, "0123456789abcdef", 2);
		ft_putnbr_fd(src->g, fd, "0123456789abcdef", 2);
		ft_putnbr_fd(src->b, fd, "0123456789abcdef", 2);
		ft_putnbr_fd(src->a, fd, "0123456789abcdef", 2);
		write(fd, "\n", 1);
	}
}

// time : O(1)
// space: O(1)
void	write_triangle_arr(int fd, const t_triangle_arr *src)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->arr != NULL && i < src->length)
	{
		write_triangle(fd, (const t_triangle *)&(src->arr[i]));
		i += 1;
	}
}

// time : O(1)
// space: O(1)
void	write_triangle_arr_meta(int fd, const t_triangle_arr *src)
{
	if (src != NULL)
	{
		write(fd, "src->length = ", 15);
		ft_putnbr_fd((int)src->length, fd, "0123456789", 1);
		write(fd, "\n", 1);
		write(fd, "src->capacity = ", 17);
		ft_putnbr_fd((int)src->capacity, fd, "0123456789", 1);
		write(fd, "\n", 1);
		write(fd, "src->width_x = ", 16);
		ft_putnbr_fd((int)src->width_x, fd, "0123456789", 1);
		write(fd, "\n", 1);
		write(fd, "src->width_y = ", 16);
		ft_putnbr_fd((int)src->width_y, fd, "0123456789", 1);
		write(fd, "\n", 1);
		write(fd, "src->width_z = ", 16);
		ft_putnbr_fd((int)src->width_z, fd, "0123456789", 1);
		write(fd, "\n", 1);
	}
}

// time : O(1)
// space: O(1)
void	write_triangle_pair_graphic(const t_table_fdf *src, size_t index)
{
	if (src != NULL && index < src->col * src->row && src->arr != NULL)
	{
		ft_putnbr_fd(src->arr[index], 1, "0123456789", 1);
		write(1, "\t", 1);
		ft_putnbr_fd(src->arr[index + 1], 1, "0123456789", 1);
		write(1, "\n", 1);
		ft_putnbr_fd(src->arr[index + src->col], 1, "0123456789", 1);
		write(1, "\t", 1);
		ft_putnbr_fd(src->arr[index + src->col + 1], 1, "0123456789", 1);
		write(1, "\n", 1);
	}
}
