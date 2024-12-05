/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:20:35 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/04 14:10:06 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	iscolor(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) > 3 && ft_strlen(line) == 0)
		return (0);
	while (line[i])
	{
		if (ft_isdigit(line[i] == 0))
			return (0);
		i++;
	}
	if (ft_atoi(line) > 255)
		return (0);
	return (1);
}

int	ft_color(char *line)
{
	char	**element;
	int		color;

	element = ft_split(line, ',');
	if (!element)
		return (-1);
	if (count_arrays(element) != 3)
		return (free_array(element), -1);
	if (iscolor(element[0]) == 0 || iscolor(element[1]) == 0
		|| iscolor(element[2]) == 0)
		return (free_array(element), -1);
	color = ft_atoi(element[0]) * 256 * 256
		+ ft_atoi(element[1]) * 256
		+ ft_atoi(element[2]);
	return (free_array(element), color);
}
