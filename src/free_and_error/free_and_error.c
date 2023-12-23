/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:20:09 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/23 12:11:46 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	free_grid3d(t_grid3d *grid3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid3d->x)
	{
		j = 0;
		while (j < grid3d->y)
			j++;
		free(grid3d->map[i]);
		i++;
	}
	free(grid3d->map);
	free(grid3d);
}
