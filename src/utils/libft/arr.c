/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:27:08 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:45:39 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// time : O(n)
// space: O(1)
static size_t	sf_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}

/**
 * Allocate and initialize a memory block with zero values.
 * Print a message to stdout if allocation fails and comment is provided.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 * 
 * @param elem_size size of the memory block in bytes
 * @param comment message to print when allocation fails
 *
 * @return pointer to the initialized memory block, or NULL on failure
 */
void	*malloc_talk(size_t elem_size, const char *comment)
{
	size_t			i;
	unsigned char	*d;
	void			*dst;

	if (elem_size == 0)
		return (NULL);
	dst = (void *)malloc(elem_size);
	if (dst == NULL)
	{
		if (comment != NULL && *comment != '\0')
		{
			write(1, "Malloc Fail: ", 14);
			write(1, comment, sf_strlen(comment));
		}
	}
	d = (unsigned char *)dst;
	i = 0;
	while (i < elem_size)
	{
		*d = 0;
		d += 1;
		i += 1;
	}
	return (dst);
}

/**
 * Get the RGBA channel array corresponding to the requested channel.
 *
 * time/space: O(1) / O(1)
 * 
 * status: public api
 *
 * @param src the input t_table_fdf array
 * @param rgba_type RGBA channel to retrieve
 *
 * @return pointer to the requested channel array, or NULL if unavailable
 */
unsigned char	*get_rgba_of_table_fdf(const t_table_fdf *src,
	t_fdf_channel rgba_type)
{
	if (src == NULL)
		return (NULL);
	if (src->r != NULL && rgba_type == RED)
		return (src->r);
	if (src->g != NULL && rgba_type == GREEN)
		return (src->g);
	if (src->b != NULL && rgba_type == BLUE)
		return (src->b);
	if (src->a != NULL && rgba_type == ALPHA)
		return (src->a);
	return (NULL);
}

/**
 * Get the standard coordinate of a cell in the FDF table.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 * 
 * @param dst FDF table containing the cell
 * @param index index of the cell
 * @param zoom coordinate scaling factor
 * @return complex coordinate of the selected cell.
 */
t_complex	get_table_fdf_coordinate(const t_table_fdf *dst, size_t index, float zoom)
{
	t_complex	y;

	y.re = 0;
	y.im = 0;
	if (dst == NULL || dst->row == 0 || dst->col == 0)
		return (y);
	y.re = (float)dst->col / 2.0 - (float)index / (float)dst->col;
	y.im = (float)(index % dst->col) - (float)dst->row / 2.0;
	y.re *= zoom;
	y.im *= zoom;
	return (y);
}
