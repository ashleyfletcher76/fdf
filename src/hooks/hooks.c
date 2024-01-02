/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:23 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/02 10:04:07 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		rotation_x(&fdf->camera->beta += ROTATION);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		rotation_x(&fdf->camera->beta -= ROTATION);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		rotation_y(&fdf->camera->alpha -= ROTATION);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		rotation_y(&fdf->camera->alpha += ROTATION);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		rotation_z(&fdf->camera->gamma += ROTATION);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		rotation_z(&fdf->camera->gamma -= ROTATION);
}
