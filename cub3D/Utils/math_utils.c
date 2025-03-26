/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:56:24 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:56:24 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	find_max(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

double	find_abs(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

double	get_precision(double value)
{
	if (find_abs(value) < 0.000001)
		return (0);
	return (value);
}

int	get_width(char **map, int y)
{
	if (!map || !map[y])
		return (0);
	return (ft_strlen(map[y]));
}

double	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
