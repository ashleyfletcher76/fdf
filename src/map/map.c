/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:53:28 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/25 12:16:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../includes/structs.h"

t_fdf	read_map_file(char *file_name)
{
	int			fd;
	char		*line;
	t_fdf		grid;

	grid.map = NULL;
	grid.map_width = 0;
	grid.map_height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	printf("Before parsing: map_width = %d, map_height = %d\n", grid.map_width, grid.map_height);
	while ((line = get_next_line(fd)) != NULL)
	{
		parse_line(&(grid.map), line, &(grid.map_width), &(grid.map_height));
		grid.map_width = get_width(line);
		free (line);
	}
	printf("After parsing: map_width = %d, map_height = %d\n", grid.map_width, grid.map_height);
	close (fd);
	return (grid);
}

void	parse_line(t_points3d ***map, char *line, int *width, int *height)
{
	char	**columns;
	int		x;

	x = 0;
	*map = realloc(*map, (*height + 1) * sizeof(t_points3d *));
	(*map)[*height] = malloc(*width * sizeof(t_points3d));
	columns = ft_split(line, ' ');
	while (x < *width && columns[x] != NULL)
	{
		(*map)[*height][x].x = x;
		(*map)[*height][x].y = *height;
		(*map)[*height][x].z = ft_atoi(columns[x]);
		// printf("x: %d, y: %d, z_values[0]: %d\n", (*map)[*height][x].x, (*map)[*height][x].y, (*map)[*height][x].z_values[0]);
		x++;
	}
	(*height)++;
	ft_freearr(columns);
}

// void	parse_line(t_points3d ***map, char *line, int *width, int *height)
// {
// 	char	**columns;
// 	int		x;

// 	x = 0;
// 	*map = realloc(*map, (*height + 1) * sizeof(t_points3d *));
// 	(*map)[*height] = malloc(*width * sizeof(t_points3d));
// 	columns = ft_split(line, ' ');
// 	while (x < *width && columns[x] != NULL)
// 	{
// 		(*map)[*height][x].x = x;
// 		(*map)[*height][x].y = *height;
// 		(*map)[*height][x].z_values = malloc(sizeof(int));
// 		(*map)[*height][x].z_values[0] = ft_atoi(columns[x]);
// 		// printf("x: %d, y: %d, z_values[0]: %d\n", (*map)[*height][x].x, (*map)[*height][x].y, (*map)[*height][x].z_values[0]);
// 		x++;
// 	}
// 	(*height)++;
// 	ft_freearr(columns);
// }

int	get_z_value_at_coordinate(t_fdf *grid, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	if (grid == NULL || grid->map == NULL)
		return (0);
	while (i < grid->map_height)
	{
		j = 0;
		while (j < grid->map_width)
		{
			if (grid->map[i][j].x == x && grid->map[i][j].y == y)
				return (grid->map[i][j].z);
			j++;
		}
		i++;
	}
	return (0);
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
