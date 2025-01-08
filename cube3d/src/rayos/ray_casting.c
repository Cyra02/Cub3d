/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:43:30 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/08 12:12:14 by ciestrad         ###   ########.fr       */
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
		rayo_east(game, angle, rayo_v);
	else
		rayo_west(game, angle, rayo_v);
	if (angle > PI)
		rayo_north(game, angle, rayo_h);
	else
		rayo_south(game, angle, rayo_h);
}

void	rayos(t_game *game)
{
	double	agn;
	int		i;
	t_ray	rayo_h;
	t_ray	rayo_v;

	i = 0;
	agn = game->player.angulo - (game->player.fov / 2 * ANGLE_TO_RADIAN); //ojo de pez
	while (i < WIDTH)
	{
		init_rayo(&rayo_h, &rayo_v);
		agn = radian_circle(agn);
		which_angle(game, agn, &rayo_h, &rayo_v);
	}
	
}
