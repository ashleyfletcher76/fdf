/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:35:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/05 06:13:18 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

float	scale_factor(t_fdf *fdf)
{
	int	scale_1;
	int	scale_2;

	scale_1 = fdf->map_width;
	scale_2 = fdf->map_height;
	return (SCALE / (scale_1 + scale_2));
}

void	init_bres_params(t_bres *params)
{
	params->dx = 0;
	params->dy = 0;
	params->e2 = 0;
	params->err = 0;
	params->sx = 0;
	params->sy = 0;
}
