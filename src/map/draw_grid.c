/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/30 15:34:31 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	draw_wire(t_fdf *fdf)
{
	int			x;
	int			y;
	y = -1;
	while (++y < fdf->map_height)
	{
		x = -1;
		while (++x < fdf->map_width)
		{
			if (x + 1 < fdf->map_width)
			{
				draw_line(fdf, init_coord(fdf->map[y][x]), init_coord(fdf->map[y][x + 1]));
			}
			if (y + 1 < fdf->map_height)
			{
				draw_line(fdf, init_coord(fdf->map[y][x]), init_coord(fdf->map[y  + 1][x]));
			}
		}
	}
}

void	draw_line(t_fdf *fdf, t_points3d p1, t_points3d p2)
{
	t_bres		bresen;

	init_bres(&bresen, p1, p2);
	while (1)
	{
		mlx_put_pixel(fdf->image, p1.x, p1.y, WIREFRAME_COLOR);
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
	int			offset_x;
	int			offset_y;

	offset_x = WIDTH / 2;
	offset_y = HEIGHT / 2;
	if (point.x < fdf->map_width && point.y < fdf->map_height)
		mlx_put_pixel(fdf->image, point.x + offset_x, point.y + offset_y, WIREFRAME_COLOR);
}
