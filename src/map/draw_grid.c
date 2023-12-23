/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/23 12:10:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

// void	draw_wireframe(t_fdf *fdf, int32_t colour)
// {
// 	uint32_t		x;
// 	uint32_t		y;

// 	x = 0;
// 	while (x < fdf->image->width)
// 	{
// 		y = 0;
// 		while (y < fdf->image->height)
// 		{
// 			mlx_put_pixel(fdf->image, x, y, colour);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	draw_line(t_grid2d start, t_grid2d end, mlx_image_t *img, int32_t colour)
{
	t_bres	params;
	int		err2;

	params = init_bres(start, end);
	while (1)
	{
		// set_pixels(img, start.x, start.y, colour);
		mlx_put_pixel(img, start.x, start.y, colour);
		if (start.x == end.x && start.y == end.y)
			break ;
		err2 = 2 * params.err;
		if (err2 > -params.dy)
		{
			params.err -= params.dy;
			start.x += params.sx;
		}
		if (err2 < params.dx)
		{
			params.err += params.dx;
			start.y += params.sy;
		}
	}
}

void	set_pixels(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour)
{
	if (x >= img->width || y >= img->height)
		return ;
	((int *)img->pixels)[y * img->width + x] = colour;
}

void	draw_wireframe(t_grid3d *grid3d, mlx_image_t *img, int32_t colour)
{
	int			i;
	int			j;
	t_grid2d	point_1;
	t_grid2d	point_2;
	int			offset_x;
	int			offset_y;

	i = 0;
	offset_x = WIDTH / 2;
	offset_y = HEIGHT / 2;
	while (i < grid3d->x - 1)
	{
		j = 0;
		while (j < grid3d->y - 1)
		{
			point_1.x = grid3d->map[i][j].x + offset_x;
			point_1.y = grid3d->map[i][j].y + offset_y;
			if (i + 1 < grid3d->x)
			{
				point_2.x = grid3d->map[i + 1][j].x + offset_x;
				point_2.y = grid3d->map[i + 1][j].y + offset_y;
				draw_line(point_1, point_2, img, colour);
			}
			if (j + 1 < grid3d->y)
			{
				point_2.x = grid3d->map[i][j + 1].x + offset_x;
				point_2.y = grid3d->map[i][j + 1].y + offset_y;
				draw_line(point_1, point_2, img, colour);
			}
			j++;
		}
		i++;
	}
}
