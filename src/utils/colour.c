/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:26:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/05 10:12:54 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

float	calculate_gradient(t_points2d p1, t_points2d p2)
{
	float	elevation_diff;
	float	distance;

	elevation_diff = (float)p2.z - (float)p1.z;
	distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)
			+ pow(p2.z - p1.z, 2));
	if (distance == 0.0)
		return (0.0);
	else
		return (elevation_diff / distance);
}

int32_t	assign_colour(float gradient)
{
	t_colours	colour;

	if (gradient == 0.0)
		return (pixel(128, 128, 128, 255));
	colour.red = (int32_t)((gradient * 1) * 127.5);
	colour.green = (int32_t)((gradient - 1) * -127.5);
	colour.blue = (int32_t)((1 - gradient) * 255);
	colour.alpha = 255;
	return (pixel(colour.red, colour.green, colour.blue, colour.alpha));
}
