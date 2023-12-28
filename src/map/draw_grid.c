/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/27 16:58:36 by asfletch         ###   ########.fr       */
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
	// printf("here draw\n");
	while (1)
	{
		// draw_pixel(fdf, p1);
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

// void	draw_wire(t_fdf *fdf)
// {
// 	int			x;
// 	int			y;
// 	// int			offset_x;
// 	// int			offset_y;
// 	t_points3d	start;
// 	t_points3d	end;

// 	x = 0;
// 	// offset_x = WIDTH / 2;
// 	// offset_y = HEIGHT / 2;
// 	// printf("%d\n%d\n", fdf->map[], start.y);
// 	// printf("%d\n", fdf->map[i][j].z);
// 	while (x < fdf->map_width)
// 	{
// 		y = 0;
// 		while (y < fdf->map_height)
// 		{
// 			// printf("%d\n%d\n", start.x, start.y);
// 			start.x = fdf->map[x][y].x + offset_x;
// 			start.y = fdf->map[x][y].y + offset_y;
// 			// printf("%d\n%d\n", start.x, start.y);
// 			if (x < fdf->map_width - 1)
// 			{
// 				end.x = fdf->map[x + 1][y].x + offset_x;
// 				end.y = fdf->map[x + 1][y].y + offset_y;
// 				printf("%d\n%d\n", start.x + 1, start.y);
// 				draw_line(fdf, start, end);
// 			}
// 			if (y < fdf->map_height - 1)
// 			{
// 				end.x = fdf->map[x][y + 1].x + offset_x;
// 				end.y = fdf->map[x][y + 1].y + offset_y;
// 				draw_line(fdf, start, end);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_wire(t_fdf *fdf)
// {
// 	int			x;
// 	int			y;
// 	t_points3d	start;
// 	t_points3d	end;
// 	int			offset_x;
// 	int			offset_y;

// 	x = 0;
// 	// printf("%d\n%d\n", fdf->map[], start.y);
// 	// printf("%d\n", fdf->map[i][j].z);
// 	offset_x = WIDTH / 2;
// 	offset_y = HEIGHT / 2;
// 	printf("map width = %d map height = %d x = %d y = %d\n", fdf->map_width, fdf->map_height, fdf->map[2][1].x, fdf->map[1][0].y);
// 	while (x < fdf->map_width)
// 	{
// 		y = 0;
// 		while (y < fdf->map_height)
// 		{
// 			// printf("%d\n%d\n", start.x, start.y);
// 			start.x = fdf->map[x][y].x + offset_x;
// 			start.y = fdf->map[x][y].y + offset_y;
// 			printf("x = %d y = %d\n", start.x, start.y);
// 			if (x + 1 < fdf->map_height)
// 			{
// 				end.x = fdf->map[x + 1][y].x + offset_x;
// 				end.y = fdf->map[x + 1][y].y + offset_y;
// 				// printf("%d\n%d\n", start.x + 1, start.y);
// 				draw_line(fdf, start, end);
// 			}
// 			if (y + 1 < fdf->map_width)
// 			{
// 				end.x = fdf->map[x][y + 1].x + offset_x;
// 				end.y = fdf->map[x][y + 1].y + offset_y;
// 				draw_line(fdf, start, end);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }


// void	draw_wire(t_fdf *fdf)
// {
// 	int			x;
// 	int			y;
// 	t_points3d	start;
// 	t_points3d	end;
// 	int			offset_x;
// 	int			offset_y;

// 	x = -1;
// 	offset_x = WIDTH / 2;
// 	offset_y = HEIGHT / 2;
// 	while (++x < fdf->map_height)
// 	{
// 		y = -1;
// 		while (++y < fdf->map_width)
// 		{
// 			start.x = fdf->map[x][y].x + offset_x;
// 			start.y = fdf->map[x][y].y + offset_y;
// 			printf("x = %d y = %d\n", start.y, start.x);
// 			if (x + 1 < fdf->map_height)
// 			{
// 				end.x = fdf->map[x + 1][y].x + offset_x;
// 				end.y = fdf->map[x + 1][y].y + offset_y;
// 				printf("y = %d x %d\n", end.x + 1, end.y);
// 				printf("y = %d x = %d\n", end.y + 1, end.y);
// 				draw_line(fdf, start, end);
// 			}
// 			if (y + 1 < fdf->map_width)
// 			{
// 				end.x = fdf->map[x][y + 1].x + offset_x;
// 				end.y = fdf->map[x][y + 1].y + offset_y;
// 				draw_line(fdf, start, end);
// 			}
// 		}
// 	}
// }
