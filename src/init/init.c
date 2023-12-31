/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/31 13:06:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	init_bres(t_bres *params, t_points3d start, t_points3d end)
{
	params->dx = abs(end.x - start.x);
	params->dy = -abs(end.y - start.y);
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

static void	isometric(int *x, int *y, int z)
{
	int	before_x;
	int	before_y;

	before_x = *x;
	before_y = *y;
	*x = (before_x - before_y) * cos(0.523599);
	*y = -z + (before_x + before_y) * sin(0.523599);
}

t_points3d	init_coord(t_fdf *fdf, t_points3d point)
{
	int	offset_x;
	int	offset_y;
	int	centre_x;
	int	centre_y;

	centre_x = WIDTH / 2;
	centre_y = HEIGHT / 2;
	offset_x = centre_x - (fdf->map_width * 20) / 2;
	offset_y = centre_y - (fdf->map_height * 20) / 2;
	point.x = (point.x * 20);
	point.y = (point.y * 20);
	//printf("Before transform p.x = %d p.y = %d\n", point.x, point.y);
	//printf("\n");
	isometric(&point.x, &point.y, point.z);
	point.x += offset_x;
	point.y += offset_y;
	//printf("After transform p.x = %d p.y = %d\n", point.x, point.y);
	//printf("\n");
	return (point);
}
