/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:53:28 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/30 12:58:12 by asfletch         ###   ########.fr       */
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
	size_t		old_size;

	grid.map = NULL;
	grid.map_width = 0;
	grid.map_height = 0;
	old_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	while ((line = get_next_line(fd)) != NULL)
	{
		grid.map_width = get_width(line);
		parse_line(&grid, line, old_size);
		free (line);
		grid.map_height++;
		old_size = grid.map_height * sizeof(t_points3d *);
	}
	close (fd);
	return (grid);
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

void	parse_line(t_fdf *grid, char *line, size_t old_size)
{
	char	**columns;
	int		x;

	x = 0;
	grid->map = ft_realloc(grid->map, old_size, (grid->map_height + 1) * sizeof(t_points3d *));
	if (!grid->map)
	{
		printf("Failure\n");
		exit(EXIT_FAILURE);
	}
	grid->map[grid->map_height] = malloc(grid->map_width * sizeof(t_points3d));
	if (!grid->map[grid->map_height])
		exit(EXIT_FAILURE);
	columns = ft_split(line, ' ');
	while (x < grid->map_width && columns[x] != NULL)
	{
		grid->map[grid->map_height][x].x = x;
		grid->map[grid->map_height][x].y = grid->map_height;
		grid->map[grid->map_height][x].z = ft_atoi(columns[x]);
		x++;
	}
	ft_freearr(columns);
}
