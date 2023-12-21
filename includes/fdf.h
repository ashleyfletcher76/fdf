/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:16:45 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/20 14:10:02 by asfletch         ###   ########.fr       */
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
# include <math.h>

int32_t		main(void);

int32_t		pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		background(void *param);
int32_t		pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		hook(void *param);

void		set_pixels(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour);

void		init_bres(t_bresenham *params, t_coord start, t_coord end);
t_segment	vertical(int start_x, int start_y, int grid_size, int i);
t_segment	horizontal(int start_x, int start_y, int grid_size, int j);
void		grid(mlx_image_t *img, t_coord start, t_coord end, t_grid_params params);
void		draw_line(mlx_image_t *img, t_coord start, t_coord end, int32_t colour);

void		draw_horizontal(mlx_image_t *img, t_grid_params params, int y, int z);
void		draw_vertical(mlx_image_t *img, t_grid_params params, int x, int z);
void		draw_centered_grid(mlx_image_t *image, t_grid_params params);
void		isometric(int *x, int *y, int z);

#endif
