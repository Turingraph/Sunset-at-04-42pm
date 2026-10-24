/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape2d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:48:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/31 12:21:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

/**
 * Identifies the data component stored in a t_fdf_table array.
 *
 * - FDF_RED selects the red color component.
 *
 * - FDF_GREEN selects the green color component.
 *
 * - FDF_BLUE selects the blue color component.
 *
 * - FDF_ALPHA selects the alpha color component.
 *
 * - FDF_HEIGHT selects the height (arr, Z) component.
 */
typedef enum t_fdf_channel
{
	FDF_RED,
	FDF_GREEN,
	FDF_BLUE,
	FDF_ALPHA,
	FDF_HEIGHT
}	t_fdf_channel;

/**
 * Stores the height and optional RGBA color components of an FDF table.
 *
 * The table contains row * col cells. arr stores the height value of
 * each cell, while r, g, b, and a store its corresponding color
 * components.
 *
 * The arrays use the same linear indexing scheme, where the cell at
 * position (row, col) is stored at index row * col_count + col.
 *
 * status: public api
 *
 * @param row number of rows in the FDF table
 * @param col number of columns in the FDF table
 * @param arr array containing the height values of each FDF cell
 * @param r array containing the red color component of each cell
 * @param g array containing the green color component of each cell
 * @param b array containing the blue color component of each cell
 * @param a array containing the alpha color component of each cell
 */
typedef struct t_fdf_table
{
	size_t			row;
	size_t			col;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
}	t_fdf_table;

typedef struct t_float2d
{
	float	x;
	float	y;
}	t_float2d;

#endif
