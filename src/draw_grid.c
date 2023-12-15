/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/15 12:58:04 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	set_pixels(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour)
{
	if (x < 0 || y < 0 || x >= img->width || y >= img->width)
		return ;
	((int *)img->pixels)[y * img->width + x] = colour;
}

// void	draw_horizon_recurs(mlx_image_t *img, t_line_params params)
// {
// 	if (params.current >= params.end)
// 		return ;
// 	set_pixels(img, params.line_len, params.current, params.colour);
// 	params.current++;
// 	draw_horizon_recurs(img, params);
// }

// void	draw_verti_recurs(mlx_image_t *img, t_line_params params)
// {
// 	if (params.current >= params.end)
// 		return ;
// 	set_pixels(img, params.current, params.line_len, params.colour);
// 	params.current++;
// 	draw_verti_recurs(img, params);
// }

// void	draw_grid_recurse(t_grid_design params)
// {
// 	t_line_params	line_params;

// 	if (params.current_x < params.image->width)
// 	{
// 		line_params.current = 0;
// 		line_params.end = params.image->height;
// 		line_params.line_len = params.current_x;
// 		line_params.colour = params.colour;
// 		draw_verti_recurs(params.image, line_params);
// 		params.current_x += params.grid_size;
// 		draw_grid_recurse(params);
// 	}
// 	if (params.current_y < params.image->height)
// 	{
// 		line_params.current = 0;
// 		line_params.end = params.image->width;
// 		line_params.line_len = params.current_y;
// 		line_params.colour = params.colour;
// 		draw_horizon_recurs(params.image, line_params);
// 		params.current_y += params.grid_size;
// 		draw_grid_recurse(params);
// 	}
// }

void	draw_horizontal(mlx_image_t *img, int y, int line_len, int32_t colour)
{
	int	x;

	x = 0;
	while (x < line_len)
	{
		set_pixels(img, x, y, colour);
		x++;
	}
}

void	draw_vertical(mlx_image_t *img, int x, int line_len, int32_t colour)
{
	int	y;

	y = 0;
	while (y < line_len)
	{
		set_pixels(img, x, y, colour);
		y++;
	}
}

void	draw_grid(mlx_image_t *image, int grd_sze, int32_t colour)
{
	u_int32_t	x;
	u_int32_t	y;

	x = 0;
	while (x < image->width)
	{
		draw_vertical(image, x, image->height, colour);
		x += grd_sze;
	}
	y = 0;
	while (y < image->height)
	{
		draw_horizontal(image, y, image->width, colour);
		y += grd_sze;
	}
}
