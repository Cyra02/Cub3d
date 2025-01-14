/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:59:31 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/13 11:15:55 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	draw_north_texture(t_game *game, int x, int y)
{
	int	tx;
	int	ty;
	int	textures_width;
	
	textures_width = game->texture.north.width;

	
}

void	draw_textures(t_game *game, int x, int y)
{
	if (game->rayo[x].type == 'h' && game->rayo[x].angle < PI)
		draw_north_textures(game, x, y);
	
}