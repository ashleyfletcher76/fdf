/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:53:28 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/27 16:56:30 by asfletch         ###   ########.fr       */
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
	while ((line = get_next_line(fd)) != NULL)
	{
		grid.map_width = get_width(line);
		parse_line(&grid, line);
		grid.map_width = get_width(line);
		free (line);
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

void	parse_line(t_fdf *grid, char *line)
{
	char	**columns;
	int		x;

	x = 0;
	grid->map = realloc(grid->map, (grid->map_height + 1) * sizeof(t_points3d *));
	grid->map[grid->map_height] = malloc(grid->map_width * sizeof(t_points3d));
	columns = ft_split(line, ' ');
	while (x < grid->map_width && columns[x] != NULL)
	{
		grid->map[grid->map_height][x].x = x;
		grid->map[grid->map_height][x].y = grid->map_height;
		grid->map[grid->map_height][x].z = ft_atoi(columns[x]);
		x++;
	}
	grid->map_height++;
	ft_freearr(columns);
}

// void parse_line(t_points3d ***map, char *line, int *width, int *height)
// {
//     char **columns;
//     int x;

//     x = 0;
//     *map = realloc(*map, (*height + 1) * sizeof(t_points3d *));
//     (*map)[*height] = malloc(*width * sizeof(t_points3d));

//     // Initialize the values in the first row
//     for (int i = 0; i < *width; i++)
//     {
//         (*map)[*height][i].x = 0;  // Set to a default value, you can change as needed
//         (*map)[*height][i].y = 0;  // Set to a default value
//         (*map)[*height][i].z = 0;  // Set to a default value
//     }

//     columns = ft_split(line, ' ');

//     while (x < *width && columns[x] != NULL)
//     {
//         (*map)[*height][x].x = x;
//         (*map)[*height][x].y = *height;
//         (*map)[*height][x].z = ft_atoi(columns[x]);
//         x++;
//     }

//     (*height)++;
//     ft_freearr(columns);
// }

// t_fdf	read_map_file(char *file_name)
// {
// 	int			fd;
// 	char		*line;
// 	t_fdf		grid;
// 	// char		**new_map;
// 	// int			i;

// 	grid.map = NULL;
// 	grid.map_width = 0;
// 	grid.map_height = 0;
// 	// i = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		exit (EXIT_FAILURE);
// 	// new_map = malloc(sizeof(char **) * 30);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		// grid.map = realloc(grid.map, (grid.map_height + 1) * sizeof(t_points3d *));
// 		// new_map[i] = line;
// 		// printf("%s", new_map[i]);
// 		grid.map_width = get_width(line);
// 		parse_line(&(grid.map), line, &(grid.map_width), &(grid.map_height));
// 		grid.map_width = get_width(line);
// 		free (line);
// 		// i++;
// 	}
// 	close (fd);
// 	return (grid);
// }

// void	init_rows(t_points3d ***map, int *width, int *height)
// {
// 	int	x;

// 	x = 0;
// 	if (!*map)
// 	{
// 		*map = malloc(sizeof(t_points3d *) * (*height + 1));
// 		if (!*map)
// 			exit(EXIT_FAILURE);
// 		(*map)[0] = NULL;
// 	}
// 	(*map)[*height] = realloc((*map)[*height], *width * sizeof(t_points3d));
// 	if (!(*map)[*height])
// 		exit(EXIT_FAILURE);
// 	while (x < *width)
// 	{
// 		// (*map)[*height][x].x = 0;
// 		(*map)[*height][x].y = 0;
// 		(*map)[*height][x].z = 0;
// 		++x;
// 	}
// 	printf("Debug: Initialized row %d with %d columns\n", *height, *width);
// 	printf("Debug: &map[%d] = %p, &map[%d][0] = %p\n", *height, (*map)[*height], *height, &(*map)[*height][0]);
// 	(*height)++;
// }

// void	populate_rows(t_points3d ***map, char *line, int *width, int *height)
// {
// 	char	**columns;
// 	int		x;

// 	x = 0;
// 	columns = ft_split(line, ' ');
// 	if (columns == NULL)
// 		exit(EXIT_FAILURE);
// 	printf("map height = %d, /n", *height);
// 	while (x < *width && columns[x] != NULL)
// 	{
// 		(*map)[*height][x].x = x;
// 		(*map)[*height][x].y = *height;
// 		(*map)[*height][x].z = ft_atoi(columns[x]);
// 		x++;
// 	}
// 	printf("Debug: Populated row %d\n", *height);
// 	ft_freearr(columns);
// }

// void	parse_line(t_points3d ***map, char *line, int *width, int *height)
// {
// 	*width = get_width(line);
// 	init_rows(map, width, height);
// 	populate_rows(map, line, width, height);
// }

// int	get_z_value_at_coordinate(t_fdf *grid, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (grid == NULL || grid->map == NULL)
// 		return (0);
// 	while (i < grid->map_height)
// 	{
// 		j = 0;
// 		while (j < grid->map_width)
// 		{
// 			if (grid->map[i][j].x == x && grid->map[i][j].y == y)
// 				return (grid->map[i][j].z);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

