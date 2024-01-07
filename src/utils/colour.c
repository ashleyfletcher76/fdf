/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:26:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/07 14:46:03 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"

int	get_colour(int z, int min_z, int max_z)
{
	double	ratio;

	ratio = (double)(z - min_z) / (max_z - min_z);
	if (ratio < 0.2)
		return (RED4);
	else if (ratio < 0.4)
		return (FOREST_GREEN);
	else if (ratio < 0.6)
		return (GOLD);
	else if (ratio < 0.8)
		return (CORAL);
	else
		return (LIGHT_BLUE);
}
