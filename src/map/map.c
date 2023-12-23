/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:53:28 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/23 15:51:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

t_grid3d	read_map_file(char *file_name)
{
	int			fd;
	char		*line;
	t_grid3d	grid;

	grid.x = 0;
	grid.y = 0;
	grid.map = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	while ((line = get_next_line(fd)) != NULL)
	{
		parse_line(&grid, line);
		grid.y++;
		free (line);
	}
	close (fd);
	return (grid);
}

t_points3d	init_point3d(int x, int y, int width)
{
	t_points3d point;

	point.x = x;
	point.y = y;
	point.z_values = malloc(width * sizeof(int));
	if (!point.z_values)
		exit (EXIT_FAILURE);
	return (point);
}

void	parse_line(t_grid3d *grid, char *line)
{
	char	**columns;
	int		x;
	int		index;

	x = 0;
	index = 0;
	if (grid->y == 0)
		columns = get_width(line);
	columns = ft_split(line, ' ');
	grid->map = ft_realloc(grid->map, (grid->x + 1) * sizeof(t_points3d *));
	if (!grid->map)
		exit (EXIT_FAILURE);
	while (columns[x] != NULL)
	{
		grid->map[grid->x][x].x = x;
		grid->map[]
		i++;
		x++;
	}
	ft_freearr(columns);
}

int	get_width(char *line)
{
	int		width;
	char	**split_line;

	width = 0;
	split_line = ft_split(line, ' ');
	while (split_line[width] != NULL)
		width++;
	ft_freearr(split_line);
	return (width);
}

void	resize_z_values(t_points3d *z_value, int new_size)
{
	z_value->z_values = ft_realloc(z_value->z_values, new_size * sizeof(int));
	if (!z_value->z_values)
		exit (EXIT_FAILURE);
}

// void	parse_line(t_points3d *values, char *line)
// {
// 	char	**columns;
// 	int		x;
// 	int		i;

// 	x = 0;
// 	i = 0;
// 	if (grid->y == 0)
// 		grid->x = get_width(line);
// 	columns = ft_split(line, ' ');
// 	while (x < grid->x && columns[x] != NULL)
// 	{
// 		grid->map[i]->z_values = ft_atoi(columns[x]);
// 		x++;
// 	}
// 	grid->y++;
// 	ft_freearr(columns);
// }
