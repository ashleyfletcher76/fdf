/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/02 15:36:11 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

// void	apply_rotate_map(t_fdf *fdf)
// {
// 	int			x;
// 	int			y;
// 	y = -1;
// 	while (++y < fdf->map_height)
// 	{
// 		x = -1;
// 		while (++x < fdf->map_width)
// 		{
// 			rotation_x(&fdf->map[y][x].y, &fdf->map[y][x].z, fdf->camera->alpha);
// 			rotation_x(&fdf->map[y][x].x, &fdf->map[y][x].z, fdf->camera->beta);
// 			rotation_x(&fdf->map[y][x].x, &fdf->map[y][x].y, fdf->camera->gamma);
// 		}
// 	}
// }

void	rotate_map(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->camera->alpha += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->camera->alpha -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->camera->beta -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->camera->beta += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_U))
		fdf->camera->gamma += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		fdf->camera->gamma -= 0.1;
	fdf->camera->alpha = fmod(fdf->camera->alpha, 2 * M_PI);
	fdf->camera->beta = fmod(fdf->camera->beta, 2 * M_PI);
	fdf->camera->gamma = fmod(fdf->camera->gamma, 2 * M_PI);
	draw_wire(fdf);
}

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}
