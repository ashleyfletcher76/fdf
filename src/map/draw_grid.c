/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/31 12:26:41 by asfletch         ###   ########.fr       */
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
				draw_line(fdf, init_coord(fdf, fdf->map[y][x]), init_coord(fdf, fdf->map[y][x + 1]));
			}
			if (y + 1 < fdf->map_height)
			{
				draw_line(fdf, init_coord(fdf, fdf->map[y][x]), init_coord(fdf, fdf->map[y  + 1][x]));
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
		//printf("Here 3\n");
		// printf("p1.x = %d p1.y = %d p2.x = %d p2.y = %d\n", p1.x, p1.y, p2.x, p2.y);
		//printf("\n");
		// mlx_put_pixel(fdf->image, p1.x, p1.y, WIRE_BLUE);
		draw_pixel(fdf, p1);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		bresen.e2 = 2 * bresen.err;
		//printf("bresen.e2 = %d bresen.err = %d bresen.dx = %d bresen.dy = %d\n", bresen.e2, bresen.err, bresen.dx, bresen.dy);
		//printf("\n");
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
	if (point.x < WIDTH &&point.x > 0 && point.y < HEIGHT && point.y > 0)
		mlx_put_pixel(fdf->image, point.x, point.y, WIREFRAME_COLOR);
}
