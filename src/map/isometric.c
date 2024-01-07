/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:33:01 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/07 14:25:59 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	isometric(double *x, double *y, double z)
{
	double	before_x;
	double	before_y;

	before_x = *x;
	before_y = *y;
	*x = (before_x - before_y) * cos(0.523599);
	*y = (-z + (before_x + before_y) * sin(0.523599));
}
