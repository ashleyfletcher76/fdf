/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:16:45 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/04 09:59:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define BLUE 0x0000FFFF
# define SCALE 1000
# define ROTATION 0.5

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include "../includes/structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

int32_t		main(int argc, char **argv);
int32_t		init_mlx(t_fdf *fdf);

int32_t		pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		background(void *param);
void		hook(void *param);

void		draw_line(t_fdf *fdf, t_points3d p1, t_points3d p2, int p3);

void		init_bres(t_bres *params, t_points3d start, t_points3d end);

t_fdf		read_map_file(char *file_name);
int			get_width(char *line);

void		parse_line(t_fdf *grid, char *line, size_t old_size);

t_points3d	init_coord(t_fdf *fdf, t_points3d point);
void		init_camera(t_fdf *fdf);
float		scale_factor(t_fdf *fdf);

void		isometric(int *x, int *y, int z);

void		draw_pixel(t_fdf *fdf, t_points3d point, int z);

void		draw_wire(t_fdf *fdf);

void		rotate_z(int *x, int *y, double gamma);
void		rotate_y(int *x, int *z, double beta);
void		rotate_x(int *y, int *z, double alpha);
void		apply_rotate_map(t_fdf *fdf);
void		rotate_map(t_fdf *fdf);

int			calculate_colour(int z);
// int			calculate_colour(t_fdf *fdf, int z);
void		calculate_min_max_depth(t_fdf *fdf);

void		user_input(void *param);

void		free_map(t_points3d ***map, int height);

void		print_coordinates(t_points3d **map, int height, int width, int x, int y);

#endif
