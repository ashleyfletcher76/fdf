/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/26 10:19:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	single_line(t_fdf *fdf)
{
	t_points3d	start;
	t_points3d	end;

	start.x = 100;
	start.y = 100;
	end.x = 400;
	end.y = 400;

	draw_line(fdf, start, end);
}

void	draw_lines_in_direction(t_fdf *fdf, int i, int j, int step)
{
	t_points3d	start;
	t_points3d	end;

	if (i < fdf->map_height - 1 && j < fdf->map_width - 1)
	{
		start.x = j;
		start.y = i;
		end.x = j + step;
		end.y = i;
		draw_line(fdf, start, end);
		draw_lines_in_direction(fdf, i + step, j, step);
	}
}

void	draw_wireframe(t_fdf *fdf)
{
	int	i;
	int	j;
	int	step;

	i = 0;
	j = 0;
	step = 1;
	draw_lines_in_direction(fdf, i, j, step);
	step = 1;
	draw_lines_in_direction(fdf, i, j, step);
}

void	draw_line(t_fdf *fdf, t_points3d p1, t_points3d p2)
{
	t_bres		bresen;

	init_bres(&bresen, p1, p2);
	printf("here draw\n");
	while (1)
	{
		draw_pixel(fdf, p1, WIREFRAME_COLOR);
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


void	draw_pixel(t_fdf *fdf, t_points3d point, uint32_t color)
{
	if (point.x < WIDTH && point.x > 300 && point.y < HEIGHT && point.y > 0)
		mlx_put_pixel(fdf->image, point.x, point.y, color);
}
