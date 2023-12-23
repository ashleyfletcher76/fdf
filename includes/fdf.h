/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:16:45 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/23 15:38:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800
# define WIREFRAME_COLOR 0xFFFFFFFF

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include "../includes/structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

int32_t		main(int argc, char **argv);

int32_t		pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		background(void *param);
void		hook(void *param);

void		set_pixels(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour);

void		draw_wireframe(t_grid3d *grid3d, mlx_image_t *img, int32_t colour);
void		draw_line(t_grid2d start, t_grid2d end, mlx_image_t *img, int32_t colour);

t_grid3d	init_grid3d(int x, int y);
t_bres		init_bres(t_grid2d start, t_grid2d end);

t_grid3d	read_map_file(char *file_name);
int			get_width(char *line);
t_points3d	init_point3d(int x, int y, int width);
void		parse_line(t_grid3d *grid, char *line);

void		resize_z_values(t_points3d *z_value, int new_size);

void		free_grid3d(t_grid3d *grid3d);

#endif
