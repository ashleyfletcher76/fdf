/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:37:15 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/16 11:32:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_hook_params
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_hook_params;

// typedef struct s_grid_params
// {
// 	int		grid_size;
	// int		grid_width;
	// int		grid_height;
	// int32_t	colour;
	// int		start_x;
	// int		start_y;
// }	t_grid_params;

typedef struct s_grid_params
{
	int		grid_size;
	int		num_cols;
	int		num_rows;
	int32_t	colour;
	int		start_x;
	int		start_y;
}	t_grid_params;

#endif
