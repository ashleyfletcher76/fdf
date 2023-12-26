/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:20:09 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/24 09:37:57 by asfletch         ###   ########.fr       */
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

