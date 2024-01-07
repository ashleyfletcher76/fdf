/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:20 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/07 14:30:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	background(void *param)
{
	uint32_t		x;
	uint32_t		y;
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	x = 0;
	while (x < fdf->image->width)
	{
		y = 0;
		while (y < fdf->image->height)
		{
			mlx_put_pixel(fdf->image, x, y, pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
}

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
