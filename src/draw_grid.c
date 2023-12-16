/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/16 13:21:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	set_pixels(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour)
{
	if (x >= img->width || y >= img->height)
		return ;
	((int *)img->pixels)[y * img->width + x] = colour;
}

void	draw_horizontal(mlx_image_t *img, t_grid_params params, int y)
{
	int	x;
	int	end_x;

	x = params.start_x;
	end_x = params.start_x + (params.grid_size * (params.num_cols - 1));
	while (x <= end_x)
	{
		set_pixels(img, x, y, params.colour);
		x++;
	}
}

void	draw_vertical(mlx_image_t *img, t_grid_params params, int x)
{
	int	y;
	int	end_y;

	y = params.start_y;
	end_y = params.start_y + (params.grid_size * (params.num_rows - 1));
	while (y <= end_y)
	{
		set_pixels(img, x, y, params.colour);
		y++;
	}
}

void	draw_centered_grid(mlx_image_t *image, t_grid_params params)
{
	int	i;
	int	x;
	int	j;
	int	y;

	params.start_x = (image->width - (params.grid_size
				* (params.num_cols - 1))) / 2;
	params.start_y = (image->height - (params.grid_size
				* (params.num_rows - 1))) / 2;
	i = 0;
	j = 0;
	while (i < params.num_cols)
	{
		x = params.start_x + i * params.grid_size;
		draw_vertical(image, params, x);
		i++;
	}
	while (j < params.num_rows)
	{
		y = params.start_y + j * params.grid_size;
		draw_horizontal(image, params, y);
		j++;
	}
}
