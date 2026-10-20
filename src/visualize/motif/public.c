/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:22:35 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 18:22:26 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "motif_private.h"

// This function is only used for view_fdf.
static bool	view_motif_handle_00(mlx_t *mlx, mlx_image_t *img)
{
	if (img == NULL)
	{
		if (mlx != NULL)
			mlx_terminate(mlx);
		return (false);
	}
	return (true);
}

// This function is only used for view_fdf.
static int32_t	view_motif_handle_01(mlx_t *mlx, mlx_image_t *img)
{
	return (mlx_image_to_window(mlx, img,
			(mlx->width - img->width) / 2,
			(mlx->height - img->height) / 2));
}

// This function is only used for view_fdf.
static void	view_motif_handle_02(mlx_t *mlx, mlx_image_t *img)
{
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}

/**
 * Display a motif as a tiled 2D composition in an MLX window.
 *
 * Creates a 1920x1080 static MLX window, initializes the rendering image and tile
 * format, fills the image with the requested motif, and keeps the window
 * open until the MLX loop terminates.
 *
 * The motif coordinates are interpreted by the motif rendering system and
 * repeated according to the requested tile resolution.
 *
 * The caller retains ownership of the supplied motif array.
 *
 * time/space: O(n) / O(n)
 *
 * @param src motif array to render (as Islamic Art,
 * Kusama art, Piet Mondrian inspired art etc.)
 * @param background_color background colour of the rendered composition
 * @param resolution tile subdivision resolution (equal to or less than 10).
 * If the resolution more than 10, then resolution equal to 10, given that 1920 < 2^n when 10 < n
 * If the resolution is equal to 0, then there will be only 1 tile, given that 1 = 2^0.
 */
void	view_motif(t_motif_arr *src,
	int32_t background_color, size_t resolution)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_motif_art	drawing_context;

	mlx = mlx_init(SUNSET_WINDOW_WIDTH,
		SUNSET_WINDOW_HEIGHT, "Sunset at 4:42pm", true);
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (view_motif_handle_00(mlx, img) == false)
		return ;
	raster_color_background(img, background_color);
	drawing_context.motif = src;
	drawing_context.tiles = init_tiles(SUNSET_WINDOW_WIDTH, SUNSET_WINDOW_HEIGHT,
			resolution);
	raster_motif(img, &drawing_context);
	if (-1 == view_motif_handle_01(mlx, img))
	{
		mlx_terminate(mlx);
		return ;
	}
	view_motif_handle_02(mlx, img);
}
