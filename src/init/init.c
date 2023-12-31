/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/31 15:26:17 by asfletch         ###   ########.fr       */
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

static float	scale_factor(t_fdf *fdf)
{
	int	scale_1;
	int	scale_2;

	scale_1 = fdf->map_width;
	scale_2 = fdf->map_height;
	return (SCALE / (scale_1 + scale_2));
}

t_points3d	init_coord(t_fdf *fdf, t_points3d point)
{
	int		offset_x;
	int		offset_y;
	int		centre_x;
	int		centre_y;
	int		scale;

	centre_x = WIDTH / 2;
	centre_y = HEIGHT / 2;
	scale = scale_factor(fdf);
	offset_x = centre_x - (fdf->map_width * scale) / 2;
	offset_y = centre_y - (fdf->map_height * scale) / 2;
	point.x = (point.x * scale);
	point.y = (point.y * scale);
	isometric(&point.x, &point.y, point.z);
	point.x += offset_x;
	point.y += offset_y;
	return (point);
}
