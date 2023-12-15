/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:37:15 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/15 12:13:01 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_hook_params
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_hook_params;

typedef struct s_grid_params
{
	int		grid_size;
	int		grid_width;
	int		grid_height;
	int32_t	colour;
	int		start_x;
	int		start_y;
}	t_grid_params;

typedef struct s_line_params
{
	int		current;
	int		end;
	int		line_len;
	int32_t	colour;
}	t_line_params;

#endif
