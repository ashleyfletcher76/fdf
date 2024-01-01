/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:25:55 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/01 14:26:20 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

void	print_coordinates(t_points3d **map, int height, int width, int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		ft_printf("Coordinates at (%d, %d): x = %d, y = %d, z = %d\n",
			x, y, map[y][x].x, map[y][x].y, map[y][x].z);
	}
	else
	{
		ft_printf("Invalid coordinates (%d, %d)\n", x, y);
	}
}
