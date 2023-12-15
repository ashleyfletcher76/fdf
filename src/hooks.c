/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:23 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/15 13:00:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->image->instances[0].y -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->image->instances[0].y += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->image->instances[0].x -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->image->instances[0].x += 5;
}

// void	background_recursive(t_fdf *fdf, uint32_t x, uint32_t y)
// {
// 	uint32_t	black;

// 	black = pixel(0, 0, 0, 255);
// 	if (y >= fdf->image->height)
// 	{
// 		y = 0;
// 		x++;
// 	}
// 	if (x >= fdf->image->width)
// 		return ;
// 	mlx_put_pixel(fdf->image, x, y, black);
// 	background_recursive(fdf, x, y + 1);
// }

// void	background(void *param)
// {
// 	t_fdf			*fdf;
// 	t_grid_design	grid_params;

// 	fdf = (t_fdf *)param;
// 	grid_params.image = fdf->image;
// 	grid_params.grid_size = 50;
// 	grid_params.colour = pixel(255, 255, 255, 255);
// 	grid_params.current_x = 0;
// 	grid_params.current_y = 0;
// 	draw_grid_recurse(grid_params);
// }
