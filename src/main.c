/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:20:47 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/26 10:14:19 by asfletch         ###   ########.fr       */
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
	single_line(&fdf);
	mlx_loop_hook(fdf.mlx, hook, &fdf);
	mlx_loop(fdf.mlx);
	// free_grid3d(&fdf);
	printf("here");
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
