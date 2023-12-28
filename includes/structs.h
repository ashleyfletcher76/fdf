/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:37:15 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/27 16:35:48 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_image_projection
{
	int	zoom;
	int	offset_x;
	int	offset_y;
}	t_image_projection;

typedef struct s_points3d
{
	int	x;
	int	y;
	int	z;
}	t_points3d;

typedef struct s_bres
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bres;

typedef struct s_fdf
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	t_points3d			**map;
	t_image_projection	image_projection;
	int					map_width;
	int					map_height;
}	t_fdf;

#endif
