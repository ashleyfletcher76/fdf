/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:20:09 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/08 07:24:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	free_map(t_points3d ***map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

int	check_valid_map(t_fdf *fdf)
{
	int i = 0;
	while (i < fdf->map_height)
	{
		int j = 0;
		while (j < fdf->map_width)
		{
			// if (!ft_isdigit(fdf->map[i][j].z))
			// {
			// 	printf("FAILURE!\n");
			// 	return (-1);
			// }
			printf("x = %f y = %f z = %f\n", fdf->map[i][j].x, fdf->map[i][j].y, fdf->map[i][j].z);
			j++;
		}
		i++;
	}
	return (0);
}

// int	check_valid_map(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < fdf->map_height)
// 	{
// 		x = -1;
// 		while (++x < fdf->map_width)
// 		{
// 		// ft_printf("z = %d\n", fdf->map[y][x].z);
// 			if (fdf->map[y][x].z > '0' && fdf->map[y][x].z > '9')
// 			{
// 				ft_printf("FAILURE!!\n");
// 				return (-1);
// 			}
// 			else
// 				return (0);
// 		}
// 	}
// 	return (0);
// }
