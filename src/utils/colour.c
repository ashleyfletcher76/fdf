/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:26:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/04 15:24:17 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

float	calculate_gradient(t_points2d p1, t_points2d p2)
{
	float	elevation_diff;
	float	distance;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	z1;
	float	z2;

	x1 = (float)p1.x;
	x2 = (float)p2.x;
	y1 = (float)p1.y;
	y2 = (float)p2.y;
	z1 = (float)p1.z;
	z2 = (float)p2.z;
	// printf("p1.x = %f, p1.y = %f, p2.x = %f, p2.y = %f\n", x1, y1, x2, y2);
	elevation_diff = (float)p2.z - (float)p1.z;
	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
	// printf("elevation = %f distance = %f\n", elevation_diff, distance);
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
