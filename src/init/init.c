/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/07 14:47:16 by asfletch         ###   ########.fr       */
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
		mlx_delete_image(fdf->mlx, fdf->image);
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

void	init_map_params(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->map_height = 0;
	fdf->map_width = 0;
}

void	init_bres(t_bres *params, t_points2d start, t_points2d end)
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
	params->err = params->dx + params->dy;
}

void	init_camera(t_fdf *fdf)
{
	fdf->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!fdf->camera)
	{
		free (fdf->camera);
		exit (EXIT_FAILURE);
	}
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	fdf->camera->centre_x = WIDTH / 2;
	fdf->camera->centre_y = HEIGHT / 2;
	fdf->camera->zoom = scale_factor(fdf);
}

t_points2d	init_coord(t_fdf *fdf, t_points3d point)
{
	int			offset_x;
	int			offset_y;
	t_points2d	points2d;
	t_points3d	temp;

	temp = point;
	offset_x = fdf->camera->centre_x - (fdf->map_width
			* fdf->camera->zoom) / 2;
	offset_y = fdf->camera->centre_y - (fdf->map_height
			* fdf->camera->zoom) / 2;
	temp.x = (temp.x * fdf->camera->zoom);
	temp.y = (temp.y * fdf->camera->zoom);
	rotate_x(&temp.y, &temp.z, fdf->camera->alpha);
	rotate_y(&temp.x, &temp.z, fdf->camera->beta);
	rotate_z(&temp.x, &temp.y, fdf->camera->gamma);
	isometric(&temp.x, &temp.y, temp.z);
	temp.x += offset_x;
	temp.y += offset_y;
	points2d.x = round(temp.x);
	points2d.y = round(temp.y);
	points2d.z = round(temp.z);
	points2d.original_z = round(point.z);
	return (points2d);
}
