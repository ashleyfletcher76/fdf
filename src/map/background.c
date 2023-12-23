/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:20 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/19 13:38:20 by asfletch         ###   ########.fr       */
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
