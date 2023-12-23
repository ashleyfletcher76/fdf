/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:20:47 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/23 12:10:09 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

void	print_grid3d(t_grid3d *grid3d)
{
	for (int i = 0; i < grid3d->x; i++) {
		for (int j = 0; j < grid3d->y; j++) {
			printf("(%d, %d) ", grid3d->map[i][j].x, grid3d->map[i][j].y);
		}
		printf("\n");
	}
}


int32_t	main(int argc, char **argv)
{
	char		*file_name;
	t_fdf		fdf;
	t_grid3d	*grid3d;

	grid3d = (t_grid3d *)malloc(sizeof(t_grid3d));
	if (argc != 2)
		return (EXIT_FAILURE);
	// fdf.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	// if (!fdf.mlx)
	// 	return (EXIT_FAILURE);
	// fdf.image = mlx_new_image(fdf.mlx, 1200, 800);
	// if (!fdf.image)
	// {
	// 	mlx_close_window(fdf.mlx);
	// 	return (EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(fdf.mlx, fdf.image, 0, 0) == -1)
	// {
	// 	mlx_close_window(fdf.mlx);
	// 	return (EXIT_FAILURE);
	// }
	file_name = argv[1];
	*grid3d = read_map_file(argv[1]);
	 if (grid3d)
	 {
		print_grid3d(grid3d);
		free_grid3d(grid3d);
	} else {
		printf("Failed to allocate memory for grid3d\n");
	}
	background(&fdf);
	// draw_wireframe(grid3d, fdf.image, WIREFRAME_COLOR);
	mlx_loop_hook(fdf.mlx, hook, &fdf);
	mlx_loop(fdf.mlx);
	free_grid3d(grid3d);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
