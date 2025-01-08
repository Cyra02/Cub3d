/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:21:36 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/19 13:47:19 by ciestrad         ###   ########.fr       */
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
void	init_data(t_game *game)
{
	game->player.fov = 60;
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUBED", true);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	//init texturas
}


int	main(int argc, char **argv)
{
	t_game	game;
	int		error;

	if (argc != 2)
		return (ft_error(1));
	if (correct_file(argv[1]))
		return (ft_error(2));
	init_data(&game);
	ft_memset(&game, 0, sizeof(t_game));
	error = check_input(&(game.map), argv[1]);
	printf("no =%s\n", game.map.no);
	printf("so =%s\n", game.map.so);
	printf("ea =%s\n", game.map.ea);
	printf("we =%s\n", game.map.we);
	printf("f =%d\n", game.map.f);
	printf("c =%d\n", game.map.c);

	printf("height =%d\n", game.map.height);
	printf("width =%d\n", game.map.width);
	if (error)
		return (free_map(&game.map), ft_error(error));
	rayos(&game);


	mlx_loop(game.mlx);
	return (0);
}
