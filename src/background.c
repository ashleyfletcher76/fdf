/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:20 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/16 13:21:05 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	background(void *param)
{
	uint32_t		x;
	uint32_t		y;
	t_fdf			*fdf;
	t_grid_params	grid_params;

	fdf = (t_fdf *)param;
	grid_params.grid_size = 25;
	grid_params.num_cols = 10;
	grid_params.num_rows = 10;
	grid_params.colour = pixel(255, 255, 255, 255);
	x = 0;
	while (x < fdf->image->width)
	{
		y = 0;
		while (y < fdf->image->height)
		{
			mlx_put_pixel(fdf->image, x, y, pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
	draw_centered_grid(fdf->image, grid_params);
}
