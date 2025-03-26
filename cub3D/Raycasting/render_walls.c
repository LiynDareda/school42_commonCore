/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:56:10 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:56:10 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	wall_distance(t_game *game, double dist_h, double dist_v)
{
	if (dist_h < dist_v)
	{
		if (game->ray->angle > 0 && game->ray->angle < PI)
			game->flag->wall_flag = 1;
		else
			game->flag->wall_flag = 0;
		game->ray->rx = game->ray->h_x;
		game->ray->ry = game->ray->h_y;
		game->wall->f_dist = dist_h;
	}
	else
	{
		if (game->ray->angle > P2 && game->ray->angle < P3)
			game->flag->wall_flag = 3;
		else
			game->flag->wall_flag = 2;
		game->ray->rx = game->ray->v_x;
		game->ray->ry = game->ray->v_y;
		game->wall->f_dist = dist_v;
	}
	if (game->wall->f_dist < 1.0)
		game->wall->f_dist = 1.0;
}


void	render_walls(t_game *game, t_img *img)
{
	double	distance;
	double	corrected_angle;

	corrected_angle = game->ray->angle - game->player->angle;
	if (corrected_angle < -PI)
		corrected_angle += 2 * PI;
	if (corrected_angle > PI)
		corrected_angle -= 2 * PI;
	distance = game->wall->f_dist * cos(corrected_angle);
	distance = distance * 1.5;
	if (distance < 1)
		distance = 1;
	game->wall->height = (TILE_SIZE * HEIGHT) / distance;
	game->wall->top = (HEIGHT / 2) - (game->wall->height / 2);
	if (game->wall->top < 0)
		game->wall->top = 0;
	game->wall->bottom = game->wall->top + game->wall->height;
	if (game->wall->bottom > HEIGHT)
		game->wall->bottom = HEIGHT;
	game->flag->draw_flag = 0;
	draw_line(img, 0, game->wall->top, game);
	game->flag->draw_flag = 1;
	draw_line(img, game->wall->bottom, HEIGHT, game);
	draw_walls(game, game->wall, img);
}
