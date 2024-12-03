/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:21:36 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/03 10:44:12 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	correct_file(char *line)
{
	if (ft_strlen(line) >= 5
		&& ft_strncmp(line + ft_strlen(line) - 4, ".cub", 4) == 0
		&& line[ft_strlen(line) - 5] != '/')
		return (0);
	return (11);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		error;

	if (argc != 2)
		return (ft_error(1));
	if (correct_file(argv[1]))
		return (ft_error(2));
	ft_memset(&game, 0, sizeof(t_game));
	error = check_input(&(game.map), argv[1]);
	printf("no =%s\n", game.map.no);
	if (error)
		return (free_map(&game.map), ft_error(error));
	
	return (0);
	
}