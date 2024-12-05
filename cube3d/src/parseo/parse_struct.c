/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:23:35 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/05 11:57:55 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	get_element(t_map *map, char *line)
{
	char	**element;

	element = ft_split(line, ' ');
	if (!element)
		return (10);
	if (count_arrays(element) != 2)
		return (free_array(element), 3);
	if (ft_strcmp(element[0], "NO") == 0 && !map->no)
		map->no = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "SO") == 0 && !map->so)
		map->so = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "WE") == 0 && !map->we)
		map->we = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "EA") == 0 && !map->ea)
		map->ea = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "F") == 0 && map->f == -1)
		map->f = ft_color(element[1]);
	else if (ft_strcmp(element[0], "C") == 0 && map->c == 1)
		map->c = ft_color(element[1]);
	else
		return (free_array(element), 2);
	return (free_array(element), 0);
}

int	check_element(t_map *map, char *line)
{
	int	error;

	if (ft_strlen(line) == 0 || set_only(line, " "))
		return (free(line), 0);
	else
	{
		if (set_only(line, " 01NSEW"))
			return (-1);
		error = get_element(map, line);
		free(line);
		line = NULL;
		if (error)
			return (error);
	}
	return (0);
}

int	get_map(int fd, t_map *map, char *file, int size)
{
	int	i;

	i = 0;
	printf("aqui");
	map->width = ft_strlen(file);
	while (file)
	{
		map->map[i] = file;
		if (file && (int)ft_strlen(file) > map->width)
			map->width = ft_strlen(file);
		get_next_line(fd, &file, 0);
		i++;
	}
	if (i != size)
		return (free_map(map), 10);
	return (0);
}

int	read_file(t_map *map, char *file, int size)
{
	int		fd;
	int		error;
	char	*line;

	error = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (5);
	while (error == 0 && get_next_line(fd, &line, 0) != 0)
		error = check_element(map, line);
	printf("error: %d\n", error);
	if (error != -1 || line == NULL)
		return (error);
	error = get_map(fd, map, file, size);
	printf("error2: %d\n", error);
	if (error)
		return (error);
	return (0);
}
