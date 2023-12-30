/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/30 12:00:34 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	init_bres(t_bres *params, t_points3d start, t_points3d end)
{
	params->dx = abs(end.x - start.x);
	params->dy = abs(end.y - start.y);
	if (start.x < end.x)
		params->sx = 1;
	else
		params->sx = -1;
	if (start.y < end.y)
		params->sy = 1;
	else
		params->sy = -1;
	params->err = params->dx - params->dy;
}

void	init_image_projection(t_fdf *fdf)
{
	fdf->image_projection.offset_x = WIDTH / 2;
	fdf->image_projection.offset_y = HEIGHT / 2;
	fdf->image_projection.zoom = 20;
}

t_points3d	init_coord(t_points3d *p1)
{
	int	offset_x;
	int	offset_y;

	offset_x = WIDTH / 2;
	offset_y = HEIGHT / 2;
	point->x = (point->x * 20) + offset_x;
	point->y = (point->y * 20) + offset_y;
	return (*point);
}
