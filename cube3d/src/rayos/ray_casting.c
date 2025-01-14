/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:30 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/09 12:45:37 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3D.h"

void	init_rayo(t_ray *rayo_h, t_ray *rayo_v)
{
	rayo_h->type = 'h';
	rayo_v->type = 'v';
	rayo_h->lenght = __DBL_MAX__;
	rayo_v->lenght = __DBL_MAX__;
}

void	which_angle(t_game *game, double angle, t_ray *rayo_h, t_ray *rayo_v)
{
	if (angle < SOUTH && angle > NORTH)
		ray_east(game, angle, rayo_v);
	else
		ray_west(game, angle, rayo_v);
	if (angle > PI)
		ray_north(game, angle, rayo_h);
	else
		ray_south(game, angle, rayo_h);
}

void	rayos(t_game *game)
{
	double	agn;
	int		i;
	t_ray	rayo_h;
	t_ray	rayo_v;

	i = 0;
	agn = game->player.angulo - (game->player.fov / 2 * ANGLE_TO_RADIAN);
	while (i < WIDTH)
	{
		init_rayo(&rayo_h, &rayo_v);
		agn = radian_circle(agn);
		which_angle(game, agn, &rayo_h, &rayo_v);
		if (rayo_h.lenght < rayo_v.lenght)
			game->rayo[i] = rayo_h;
		else
			game->rayo[i] = rayo_v;
		game->rayo[i].lenght = fabs(game->rayo[i].lenght
				* cos(game->rayo[i].angle - game->player.angulo));
		agn += game->player.fov / (double)WIDTH;
		i++;
	}
}
