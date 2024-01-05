/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/05 07:28:07 by asfletch         ###   ########.fr       */
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
	background(fdf);
	while (++y < fdf->map_height)
	{
		x = -1;
		while (++x < fdf->map_width)
		{
			if (x + 1 < fdf->map_width)
			{
				draw_line(fdf, init_coord(fdf, fdf->map[y][x]),
					init_coord(fdf, fdf->map[y][x + 1]));
			}
			if (y + 1 < fdf->map_height)
			{
				draw_line(fdf, init_coord(fdf, fdf->map[y][x]),
					init_coord(fdf, fdf->map[y  + 1][x]));
			}
		}
	}
}

void	draw_line(t_fdf *fdf, t_points2d p1, t_points2d p2)
{
	t_bres	bresen;

	init_bres(&bresen, p1, p2);
	while (1)
	{
		draw_pixel(fdf, p1, calculate_gradient(p1, p2));
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

void	draw_pixel(t_fdf *fdf, t_points2d point, float gradient)
{
	int32_t	colour;
	double	range;
	int		i;
	int		j;

	range = 0.5;
	i = -range;
	if (point.x < WIDTH &&point.x > 0 && point.y < HEIGHT && point.y > 0)
	{
		// printf("p.x = %d p.y = %d\n", point.x, point.y);
		while (i++ <= range)
		{
			j = -range;
			while (j++ <= range)
			{
				colour = assign_colour(gradient);
				mlx_put_pixel(fdf->image, point.x + i, point.y + j, colour);
			}
		}
	}
}

// void	draw_pixel(t_fdf *fdf, t_points2d point, float gradient)
// {
// 	int32_t	colour;

// 	colour = assign_colour(gradient);
// 	// printf("x = %d y = %d\n\n", point.x, point.y);
// 	if (point.x < WIDTH &&point.x > 0 && point.y < HEIGHT && point.y > 0)
// 		mlx_put_pixel(fdf->image, point.x, point.y, colour);
// }
