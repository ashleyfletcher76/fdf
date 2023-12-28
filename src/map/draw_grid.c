/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/28 08:42:35 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	draw_wire(t_fdf *fdf)
{
	int			x;
	int			y;
	int			offset_x;
	int			offset_y;

	x = -1;
	offset_x = WIDTH / 2;
	offset_y = HEIGHT / 2;
	while (++x < fdf->map_height)
	{
		y = -1;
		while (++y < fdf->map_width)
		{
			if (x + 1 < fdf->map_height)
			{
				draw_line(fdf, fdf->map[x][y], fdf->map[x + 1][y]);
			}
			if (y + 1 < fdf->map_width)
			{
				draw_line(fdf, fdf->map[x][y], fdf->map[x][y + 1]);
			}
		}
	}
}

void	single_line(t_fdf *fdf)
{
	t_points3d	start;
	t_points3d	end;

	start.x = 100;
	start.y = 100;
	end.x = 400;
	end.y = 400;
	start.x = 200;
	start.y = 200;
	end.x = 500;
	end.y = 500;

	draw_line(fdf, start, end);
}

void	draw_line(t_fdf *fdf, t_points3d p1, t_points3d p2)
{
	t_bres		bresen;

	init_bres(&bresen, p1, p2);
	while (1)
	{
		mlx_put_pixel(fdf->image, p1.x * 20, p2.y * 20, WIREFRAME_COLOR);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		bresen.e2 = 2 * bresen.err;
		if (bresen.e2 >= bresen.dy)
		{
			if (p1.x == p2.x)
				break ;
			bresen.err += bresen.dy;
			p1.x += bresen.sx;
		}
		if (bresen.e2 <= bresen.dx)
		{
			if (p1.y == p2.y)
				break ;
			bresen.err += bresen.dx;
			p1.y += bresen.sy;
		}
	}
}

void	set_pixls(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour)
{
	if (x >= img->width || y >= img->height)
		return ;
	((int *)img->pixels)[y * img->width + x] = colour;
}

void	draw_pixel(t_fdf *fdf, t_points3d point)
{
	if (point.x < WIDTH && point.x > 300 && point.y < HEIGHT && point.y > 0)
		mlx_put_pixel(fdf->image, point.x, point.y, pixel(0, 0, 0, 255));
}
