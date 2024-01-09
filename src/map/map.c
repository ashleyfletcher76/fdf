/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:53:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/09 15:30:40 by asfletch         ###   ########.fr       */
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

	init_map_params(&grid);
	old_size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
			check_new_line(&grid, line);
		grid.map_width = get_width(line);
		parse_line(&grid, line, old_size);
		free (line);
		grid.map_height++;
		old_size = grid.map_height * sizeof(t_points3d *);
		line = get_next_line(fd);
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

	x = -1;
	grid->map = ft_realloc(grid->map, old_size, (grid->map_height + 1)
			* sizeof(t_points3d *));
	if (!grid->map)
		exit(EXIT_FAILURE);
	grid->map[grid->map_height] = malloc(grid->map_width * sizeof(t_points3d));
	if (!grid->map[grid->map_height])
		exit(EXIT_FAILURE);
	columns = ft_split(line, ' ');
	while (++x < grid->map_width && columns[x] != NULL)
	{
		if (str_is_valid(columns[x]) == 0)
		{
			ft_freearr(columns);
			ft_printf("FAILURE!!\n");
			exit(EXIT_FAILURE);
		}
		grid->map[grid->map_height][x].x = x;
		grid->map[grid->map_height][x].y = grid->map_height;
		grid->map[grid->map_height][x].z = ft_atoi(columns[x]);
	}
	ft_freearr(columns);
}

int	str_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			return (1);
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	calculate_min_max_depth(t_fdf *fdf)
{
	int	x;
	int	y;
	int	current_z;

	fdf->max_depth = 0;
	fdf->min_depth = 0;
	y = -1;
	while (++y < fdf->map_height)
	{
		x = -1;
		while (++x < fdf->map_width)
		{
			current_z = fdf->map[y][x].z;
			if (current_z < fdf->min_depth)
				fdf->min_depth = current_z;
			if (current_z > fdf->max_depth)
				fdf->max_depth = current_z;
		}
	}
}
