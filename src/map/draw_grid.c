/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/04 10:07:01 by asfletch         ###   ########.fr       */
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
					init_coord(fdf, fdf->map[y][x + 1]), fdf->map[y][x].z);
			}
			if (y + 1 < fdf->map_height)
			{
				draw_line(fdf, init_coord(fdf, fdf->map[y][x]),
					init_coord(fdf, fdf->map[y  + 1][x]), fdf->map[y][x].z);
			}
		}
	}
}

void	draw_line(t_fdf *fdf, t_points3d p1, t_points3d p2, int p3)
{
	t_bres		bresen;

	init_bres(&bresen, p1, p2);
	while (1)
	{
		draw_pixel(fdf, p1, p3);
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

void	draw_pixel(t_fdf *fdf, t_points3d point, int z)
{
	double	range;
	int		i;
	int		j;

	range = 0.5;
	i = -range;
	if (point.x < WIDTH &&point.x > 0 && point.y < HEIGHT && point.y > 0)
	{
		while (i <= range)
		{
			j = -range;
			while (j <= range)
			{
				mlx_put_pixel(fdf->image, point.x + i, point.y + j, calculate_colour(z));
				j++;
			}
			i++;
		}
	}
}

// int	calculate_colour(t_fdf *fdf, int z)
// {
// 	double		normal_value;
// 	t_colours	colours;


// 	return (colour);
// }

int	calculate_colour(int z)
{
	if (z > 0)
		return (BLUE);
	else if (z < 0)
		return (RED);
	else
		return (WHITE);
}

// void	draw_pixel(t_fdf *fdf, t_points3d point, int z)
// {
// 	if (point.x < WIDTH &&point.x > 0 && point.y < HEIGHT && point.y > 0)
// 		mlx_put_pixel(fdf->image, point.x, point.y, calculate_colour(z));
// }
