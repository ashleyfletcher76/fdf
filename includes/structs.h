/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:37:15 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/19 17:52:31 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_fdf;

typedef struct s_grid_params
{
	int		grid_size;
	int		num_cols;
	int		num_rows;
	int32_t	colour;
	int		start_x;
	int		start_y;
}	t_grid_params;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_segment
{
	t_coord	start;
	t_coord	end;
}	t_segment;

#endif
