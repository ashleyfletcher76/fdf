/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:20:47 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/27 16:57:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

void	print_coordinates(t_points3d **map, int height, int width, int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		printf("Coordinates at (%d, %d): x = %d, y = %d, z = %d\n",
				x, y, map[y][x].x, map[y][x].y, map[y][x].z);
	}
	else
	{
		printf("Invalid coordinates (%d, %d)\n", x, y);
	}
}

int32_t	main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc != 2)
		return (EXIT_FAILURE);
	fdf = read_map_file(argv[1]);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fdf.mlx)
		return (EXIT_FAILURE);
	fdf.image = mlx_new_image(fdf.mlx, 1200, 800);
	if (!fdf.image)
	{
		mlx_close_window(fdf.mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(fdf.mlx, fdf.image, 0, 0) == -1)
	{
		mlx_close_window(fdf.mlx);
		return (EXIT_FAILURE);
	}
	background(&fdf);
	// draw_wireframe(&fdf);
	draw_wire(&fdf);
	mlx_loop_hook(fdf.mlx, hook, &fdf);
	mlx_loop(fdf.mlx);
	// free_grid3d(&fdf);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}

// int32_t	main(int argc, char **argv)
// {
// 	t_fdf		fdf;

// 	if (argc != 2)
// 		return (EXIT_FAILURE);
// 	fdf = read_map_file(argv[1]);
// 	fdf.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!fdf.mlx)
// 		return (EXIT_FAILURE);
// 	fdf.image = mlx_new_image(fdf.mlx, 1200, 800);
// 	if (!fdf.image)
// 	{
// 		mlx_close_window(fdf.mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(fdf.mlx, fdf.image, 0, 0) == -1)
// 	{
// 		mlx_close_window(fdf.mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	background(&fdf);
// 	// print_coordinates(fdf.map, fdf.map_height,fdf.map_width,0, 1);
// 	// print_coordinates(fdf.map, fdf.map_height,fdf.map_width,1, 0);
// 	// print_coordinates(fdf.map, fdf.map_height,fdf.map_width,0, 2);
// 	// print_coordinates(fdf.map, fdf.map_height,fdf.map_width,2, 0);
// 	// print_coordinates(fdf.map, fdf.map_height,fdf.map_width,1, 1);
// 	// print_coordinates(fdf.map, fdf.map_height,fdf.map_width,1, 2);
// 	// print_coordinates(fdf.map, fdf.map_height,fdf.map_width,3, 0);
// 	int i = 0;
// 	while (i < fdf.map_height)
// 	{
// 		int j = 0;
// 		while (j < fdf.map_width)
// 		{
// 			printf("x = %d\n y = %d z = %d\n", fdf.map[i][j].x, fdf.map[i][j].y, fdf.map[i][j].z);
// 			j++;
// 		}
// 		i++;
// 	}
// 	// draw_wireframe(&fdf);
// 	// single_line(&fdf);
// 	// draw_wire(&fdf);
// 	mlx_loop_hook(fdf.mlx, hook, &fdf);
// 	mlx_loop(fdf.mlx);
// 	// free_grid3d(&fdf);
// 	// printf("here");
// 	mlx_terminate(fdf.mlx);
// 	return (EXIT_SUCCESS);
// }

// int32_t	main(int argc, char **argv)
// {
// 	t_fdf		fdf;

// 	if (argc != 2)
// 		return (EXIT_FAILURE);
// 	fdf = read_map_file(argv[1]);
// 	fdf.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!fdf.mlx)
// 		return (EXIT_FAILURE);
// 	fdf.image = mlx_new_image(fdf.mlx, 1200, 800);
// 	if (!fdf.image)
// 	{
// 		mlx_close_window(fdf.mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(fdf.mlx, fdf.image, 0, 0) == -1)
// 	{
// 		mlx_close_window(fdf.mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	background(&fdf);
// 	// printf("x = %d, y = %d\n", fdf.map[0][0].x, fdf.map[0][1].y);
// 	// printf("x = %d, y = %d\n", fdf.map[0][1].x, fdf.map[5][0].y);
// 	print_coordinates(fdf.map, fdf.map_height,fdf.map_width,0, 0);
// 	// int i = 0;
// 	// while (i < fdf.map_height)
// 	// {
// 	// 	int j = 0;
// 	// 	while (j < fdf.map_width)
// 	// 	{
// 	// 		printf("x = %d\n y = %d\n", fdf.map[i][j].x, fdf.map[i][j].y);
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// 	// draw_wireframe(&fdf);
// 	// single_line(&fdf);
// 	// draw_wire(&fdf);
// 	mlx_loop_hook(fdf.mlx, hook, &fdf);
// 	mlx_loop(fdf.mlx);
// 	// free_grid3d(&fdf);
// 	// printf("here");
// 	mlx_terminate(fdf.mlx);
// 	return (EXIT_SUCCESS);
// }
