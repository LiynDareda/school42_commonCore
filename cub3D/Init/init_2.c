/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:55:15 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:15 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_ray(t_ray *ray)
{
	ray->r = -1;
	ray->dof = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->map_p = 0;
	ray->h_x = 0.0;
	ray->h_y = 0.0;
	ray->v_x = 0.0;
	ray->v_y = 0.0;
	ray->rx = 0.0;
	ray->ry = 0.0;
	ray->atan = 0.0;
	ray->ntan = 0.0;
	ray->h_x_off = 0.0;
	ray->h_y_off = 0.0;
	ray->v_x_off = 0.0;
	ray->v_y_off = 0.0;
	ray->angle = 0.0;
}

void	init_ray_math_x(t_ray_math *ray, t_game *game, double x1, double y1)
{
	int	steps;

	ray->delta_x = game->ray->h_x - x1;
	ray->delta_y = game->ray->h_y - y1;
	steps = find_max(find_abs(ray->delta_x), find_abs(ray->delta_y));
	if (steps == 0)
		steps = 1;
	ray->x_inc = ray->delta_x / steps;
	ray->y_inc = ray->delta_y / steps;
	ray->current_x = x1;
	ray->current_y = y1;
}

void	init_ray_math_y(t_ray_math *ray, t_game *game, double x1, double y1)
{
	int	steps;

	ray->delta_x = game->ray->v_x - x1;
	ray->delta_y = game->ray->v_y - y1;
	steps = find_max(find_abs(ray->delta_x), find_abs(ray->delta_y));
	if (steps == 0)
		steps = 1;
	ray->x_inc = ray->delta_x / steps;
	ray->y_inc = ray->delta_y / steps;
	ray->current_x = x1;
	ray->current_y = y1;
}

void	init_wall(t_wall *wall)
{
	wall->f_dist = 0.0;
	wall->top = 0;
	wall->height = 0;
	wall->bottom = 0;
	wall->x_texture = 0;
	wall->y_texture = 0;
	wall->offset = 0.0;
	wall->step_texture = 0.0;
	wall->pos_texture = 0.0;
}
