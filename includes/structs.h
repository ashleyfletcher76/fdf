/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:37:15 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/23 15:26:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			map_width;
	int			map_height;
}	t_fdf;

typedef struct s_grid2d
{
	int	x;
	int	y;
}	t_grid2d;

typedef struct	s_points3d
{
	int	x;
	int	y;
	int	*z_values;
}	t_points3d;

typedef struct s_grid3d
{
	int			x;
	int			y;
	t_points3d	**map;
}	t_grid3d;

typedef struct s_bres
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bres;

#endif
