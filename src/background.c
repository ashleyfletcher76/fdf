/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:20 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/15 12:59:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	background(void *param)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	black;
	uint32_t	grid_colour;
	uint32_t	grid_size;
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	grid_colour = pixel(255, 255, 255, 255);
	grid_size = 50;
	x = 0;
	(void)param;
	while (x < fdf->image->width)
	{
		y = 0;
		while (y < fdf->image->height)
		{
			black = pixel(0, 0, 0, 255);
			mlx_put_pixel(fdf->image, x, y, black);
			y++;
		}
		x++;
	}
	draw_grid(fdf->image, grid_size, grid_colour);
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
