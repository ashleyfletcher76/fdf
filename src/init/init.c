/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:57:07 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/25 13:53:41 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

// t_grid3d	*init_grid(int rows, int cols)
// {
// 	t_grid3d	*grid3d;
// 	int			i;
// 	int			j;

// 	grid3d = malloc(sizeof(t_grid3d));
// 	if (!grid3d)
// 		return (NULL);
// 	grid3d->x = rows;
// 	grid3d->y = cols;
// 	grid3d->map = malloc(rows * sizeof(int **));
// 	if (!grid3d->map)
// 	{
// 		free (grid3d->map);
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (i < rows)
// 	{
// 		grid3d->map[i] = ft_calloc(cols, sizeof(int *));
// 		j = 0;
// 		while (j < cols)
// 		{
// 			grid3d->map[i][j].x = 0;
// 			grid3d->map[i][j].y = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (grid3d);
// }

// t_grid3d	init_grid3d(int x, int y)
// {
// 	t_grid3d	grid;
// 	int			i;

// 	i = 0;
// 	grid.x = x;
// 	grid.y = y;
// 	grid.map = malloc(x * sizeof(t_points3d *));
// 	return (grid);
// }

// t_bres	init_bres(t_grid2d start, t_grid2d end)
// {
// 	t_bres	params;

// 	params.dx = abs(end.x - start.x);
// 	params.dy = -abs(end.y - start.y);
// 	params.sx = start.x < end.x ? 1 : -1;
// 	params.sy = start.y < end.y ? 1 : -1;
// 	params.err = params.dx + params.dy;

// 	return (params);
// }

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
