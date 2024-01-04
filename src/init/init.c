/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/04 11:01:15 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

int32_t	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fdf->mlx)
		return (EXIT_FAILURE);
	fdf->image = mlx_new_image(fdf->mlx, 1920, 1080);
	if (!fdf->image)
	{
		mlx_close_window(fdf->mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) == -1)
	{
		mlx_close_window(fdf->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

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

void	init_camera(t_fdf *fdf)
{
	fdf->camera = (t_camera *)malloc(sizeof(t_camera));
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	fdf->camera->zoom = (int)scale_factor(fdf);
}

t_points3d	init_coord(t_fdf *fdf, t_points3d point)
{
	int		offset_x;
	int		offset_y;
	int		centre_x;
	int		centre_y;

	centre_x = WIDTH / 2;
	centre_y = HEIGHT / 2;
	offset_x = centre_x - (fdf->map_width * (int)fdf->camera->zoom) / 2;
	offset_y = centre_y - (fdf->map_height * (int)fdf->camera->zoom) / 2;
	point.x = (int)(point.x * fdf->camera->zoom);
	point.y = (int)(point.y * fdf->camera->zoom);
	rotate_x(&point.y, &point.z, fdf->camera->alpha);
	rotate_y(&point.x, &point.z, fdf->camera->beta);
	rotate_z(&point.x, &point.y, fdf->camera->gamma);
	isometric(&point.x, &point.y, point.z);
	point.x += offset_x;
	point.y += offset_y;
	return (point);
}
