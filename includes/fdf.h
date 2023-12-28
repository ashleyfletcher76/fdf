/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:16:45 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/28 09:52:12 by asfletch         ###   ########.fr       */
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

void		set_pixls(mlx_image_t *img, uint32_t x, uint32_t y, int32_t colour);

void		draw_line(t_fdf *fdf, t_points3d p1, t_points3d p2);

void		init_bres(t_bres *params, t_points3d start, t_points3d end);

t_fdf		read_map_file(char *file_name);
int			get_width(char *line);

void		parse_line(t_fdf *grid, char *line, size_t old_size);
// void		parse_line(t_fdf *grid, char *line);

void		init_image_projection(t_fdf *fdf);
// void		parse_line(t_points3d ***map, char *line, int *width, int *height);

void		draw_pixel(t_fdf *fdf, t_points3d point);

int			get_z_value_at_coordinate(t_fdf *grid, int x, int y);

void		single_line(t_fdf *fdf);

void		draw_wire(t_fdf *fdf);

void		free_map(t_points3d ***map, int height);

void		init_rows(t_fdf *grid);

void		print_coordinates(t_points3d **map, int height, int width, int x, int y);

#endif
