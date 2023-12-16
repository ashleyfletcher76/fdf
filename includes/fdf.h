/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:16:45 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/16 13:21:21 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include "../includes/structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_fdf;

typedef struct s_grid_design
{
	mlx_image_t	*image;
	int			grid_size;
	uint32_t	current_x;
	uint32_t	current_y;
	int32_t		colour;
}	t_grid_design;

int32_t	main(int32_t argc, const char *argv[]);

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	background(void *param);
int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	hook(void *param);


void	set_pixels(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour);

void	draw_horizontal(mlx_image_t *img, t_grid_params params, int y);
void	draw_vertical(mlx_image_t *img, t_grid_params params, int x);
void	draw_centered_grid(mlx_image_t *image, t_grid_params params);

#endif
