/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:20:47 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/20 16:58:29 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

int32_t	main(void)
{
	t_fdf			fdf;
	t_grid_params	grid_params;
	t_coord			start;
	t_coord			end;

	grid_params.grid_size = 25;
	grid_params.num_cols = 10;
	grid_params.num_rows = 10;
	grid_params.colour = pixel(255, 255, 255, 255);
	start.x = 0;
	start.y = 0;
	end.x = start.x + grid_params.grid_size * grid_params.num_cols;
	end.y = start.y + grid_params.grid_size * grid_params.num_rows;
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fdf.mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	fdf.image = mlx_new_image(fdf.mlx, 1200, 800);
	if (!fdf.image)
	{
		mlx_close_window(fdf.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(fdf.mlx, fdf.image, 0, 0) == -1)
	{
		mlx_close_window(fdf.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	background(&fdf);
	grid(fdf.image, start, end, grid_params);
	mlx_loop_hook(fdf.mlx, hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
