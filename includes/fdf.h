/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:16:45 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/11 21:37:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_fdf;

int32_t	main(int32_t argc, const char* argv[]);

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	background(void *param);
int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	hook(void *param);

#endif
