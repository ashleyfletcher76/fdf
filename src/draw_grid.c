/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/20 17:07:44 by asfletch         ###   ########.fr       */
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

void	draw_line(mlx_image_t *img, t_coord start, t_coord end, int32_t colour)
{
	t_bresenham	params;
	int			e2;

	init_bres(&params, start, end);
	while (1)
	{
		set_pixels(img, start.x, start.y, colour);
		if (start.x != end.x || start.y != end.y)
			break ;
		e2 = 2 * params.err;
		if (e2 > -params.dy)
		{
			params.err -= params.dy;
			start.x += params.sx;
		}
		if (e2 < params.dx)
		{
			params.err += params.dx;
			start.y += params.sy;
		}
	}
}

void	grid(mlx_image_t *img, t_coord start, t_coord end, t_grid_params params)
{
	t_segment	vertical_seg;
	t_segment	horizontal_seg;
	int			i;
	int			j;

	i = 0;
	(void)end;
	while (i < params.num_cols)
	{
		vertical_seg = vertical(start.x, start.y, params.grid_size, i);
		draw_line(img, vertical_seg.start, vertical_seg.end, params.colour);
		i++;
	}
	j = 0;
	while (j < params.num_rows)
	{
		horizontal_seg = horizontal(start.x, start.y, params.grid_size, j);
		draw_line(img, horizontal_seg.start, horizontal_seg.end, params.colour);
		j++;
	}
}

// void	draw_horizontal(mlx_image_t *img, t_grid_params params, int y, int z)
// {
// 	int	x;
// 	int	end_x;
// 	int	iso_x;
// 	int	iso_y;

// 	x = params.start_x;
// 	end_x = params.start_x + (params.grid_size * (params.num_cols - 1));
// 	while (x <= end_x)
// 	{
// 		iso_x = (x - y) * cos(0.523599);
// 		iso_y = (x + y) * sin(0.523599) - z;
// 		set_pixels(img, iso_x, iso_y, params.colour);
// 		x++;
// 	}
// }

// void	draw_vertical(mlx_image_t *img, t_grid_params params, int x, int z)
// {
// 	int	y;
// 	int	end_y;
// 	int	iso_x;
// 	int	iso_y;

// 	y = params.start_y;
// 	end_y = params.start_y + (params.grid_size * (params.num_rows - 1));
// 	while (y <= end_y)
// 	{
// 		iso_x = (x - y) * cos(0.523599);
// 		iso_y = (x + y) * sin(0.523599) - z;
// 		set_pixels(img, iso_x, iso_y, params.colour);
// 		y++;
// 	}
// }

// void	draw_centered_grid(mlx_image_t *image, t_grid_params params)
// {
// 	int	i;
// 	int	x;
// 	int	j;
// 	int	y;
// 	int	z;

// 	params.start_x = WIDTH / 2;
// 	params.start_y = 0;
// 	i = 0;
// 	j = 0;
// 	z = 0;
// 	while (i < params.num_cols)
// 	{
// 		x = params.start_x + i * params.grid_size;
// 		draw_vertical(image, params, x, z);
// 		i++;
// 	}
// 	while (j < params.num_rows)
// 	{
// 		y = params.start_y + j * params.grid_size;
// 		draw_horizontal(image, params, y, z);
// 		j++;
// 	}
// }

