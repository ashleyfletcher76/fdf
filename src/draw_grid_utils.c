/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:10:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/20 12:28:59 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	init_bres(t_bresenham *params, t_coord start, t_coord end)
{
	params->dx = abs(end.x - start.x);
	if (start.x < end.x)
		params->sx = 1;
	else
		params->sx = -1;
	params->dy = -abs(start.y - end.y);
	if (start.y < end.y)
		params->sy = 1;
	else
		params->sy = -1;
	params->err = params->dx + params->dy;
}

t_segment	vertical(int start_x, int start_y, int grid_size, int i)
{
	t_segment	vertical;

	vertical.start.x = start_x + i * grid_size;
	vertical.start.y = start_y;
	vertical.end.x = vertical.start.x;
	vertical.end.y = start_y;
	return (vertical);
}

t_segment	horizontal(int start_x, int start_y, int grid_size, int j)
{
	t_segment	horizontal;

	horizontal.start.x = start_x;
	horizontal.start.y = start_y + j * grid_size;
	horizontal.end.x = start_x + grid_size;
	horizontal.end.y = horizontal.start.y;
	return (horizontal);
}
