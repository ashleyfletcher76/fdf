/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:20:47 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/01 14:26:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

int32_t	main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc != 2)
		return (EXIT_FAILURE);
	fdf = read_map_file(argv[1]);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fdf.mlx)
		return (EXIT_FAILURE);
	fdf.image = mlx_new_image(fdf.mlx, 1920, 1080);
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
	init_camera(&fdf);
	background(&fdf);
	// single_line(&fdf);
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
