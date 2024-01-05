/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:20:47 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/05 10:09:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

int32_t	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_bres	params;

	if (argc != 2 || ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) == NULL)
		return (EXIT_FAILURE);
	fdf = read_map_file(argv[1]);
	init_mlx(&fdf);
	init_camera(&fdf);
	init_bres_params(&params);
	draw_wire(&fdf);
	mlx_loop_hook(fdf.mlx, hook, &fdf);
	mlx_loop_hook(fdf.mlx, user_input, &fdf);
	mlx_loop(fdf.mlx);
	free_map(&fdf.map, fdf.map_height);
	system("leaks fdf");
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
