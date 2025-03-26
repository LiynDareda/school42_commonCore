/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:55:55 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:55 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	draw_ray(t_game *game, t_img *img, double x1, double y1)
{
	t_ray_math	ray;
	int			i;
	int			steps;

	i = 0;
	if (game->flag->ray_flag == 0)
		init_ray_math_x(&ray, game, x1, y1);
	else
		init_ray_math_y(&ray, game, x1, y1);
	steps = find_max(find_abs(ray.delta_x), find_abs(ray.delta_y));
	while (i <= steps)
	{
		my_put_pixel(img, (int)ray.current_x - 1, (int)ray.current_y, 0xFFFF00);
		ray.current_x += ray.x_inc;
		ray.current_y += ray.y_inc;
		i++;
	}
}

static double	raycasting_horizontal(t_game *game)
{
	int	map_width;
	int	map_height;

	map_height = mat_len(game->map);
	if (game->ray->map_y >= 0 && game->ray->map_y < map_height)
		map_width = get_width(game->map, game->ray->map_y);
	else
		map_width = 0;
	game->ray->dof = 0;
	game->ray->atan = -1 / tan(game->ray->angle);
	if (game->ray->angle > PI)
	{
		game->ray->h_y = (((int)game->player->y / (TILE_SIZE / 2)) * (TILE_SIZE / 2)) - 0.0001;
		game->ray->h_x = (game->player->y - game->ray->h_y) * game->ray->atan + game->player->x;
		game->ray->h_y_off = -(TILE_SIZE / 2);
		game->ray->h_x_off = -game->ray->h_y_off * game->ray->atan;    
	}
	if (game->ray->angle < PI)
	{
		game->ray->h_y = (((int)game->player->y / (TILE_SIZE / 2)) * (TILE_SIZE / 2)) + (TILE_SIZE / 2);
		game->ray->h_x = (game->player->y - game->ray->h_y) * game->ray->atan + game->player->x;
		game->ray->h_y_off = (TILE_SIZE / 2);
		game->ray->h_x_off = -game->ray->h_y_off * game->ray->atan;    
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->h_x = game->player->x;
		game->ray->h_y = game->player->y;
		game->ray->dof = 32;
	}
	while (game->ray->dof < 32)
	{
		game->ray->map_x = (int) (game->ray->h_x) / (TILE_SIZE / 2);
		game->ray->map_y = (int) (game->ray->h_y) / (TILE_SIZE / 2);
		if (game->ray->map_y < 0)
			game->ray->map_y = 0;
		if (game->ray->map_y >= map_height)
			game->ray->map_y = map_height - 1;
		map_width = ft_strlen(game->map[game->ray->map_y]);
		if (game->ray->map_x >= 0 && game->ray->map_x < map_width && game->ray->map_y >= 0 && game->ray->map_y < map_height && game->map[game->ray->map_y][game->ray->map_x] == '1')
			game->ray->dof = 32;
		else
		{
			game->ray->h_x += game->ray->h_x_off;
			game->ray->h_y += game->ray->h_y_off;
			game->ray->dof += 1;
		}
	}
	return (dist(game->player->x, game->player->y, game->ray->h_x, game->ray->h_y));
}

static double	raycasting_vertical(t_game *game)
{
	int	map_width;
	int	map_height;

	map_height = mat_len(game->map);
	if (game->ray->map_y >= 0 && game->ray->map_y < map_height)
		map_width = get_width(game->map, game->ray->map_y);
	else 
		map_width = 0;
	game->ray->dof = 0;
	game->ray->ntan = -tan(game->ray->angle);
	if (game->ray->angle > P2 && game->ray->angle < P3)
	{
		game->ray->v_x = (((int)game->player->x / (TILE_SIZE / 2)) * (TILE_SIZE / 2)) - 0.0001;
		game->ray->v_y = (game->player->x - game->ray->v_x) * game->ray->ntan + game->player->y;
		game->ray->v_x_off = -(TILE_SIZE / 2);
		game->ray->v_y_off = -game->ray->v_x_off * game->ray->ntan;    
	}
	if (game->ray->angle < P2 || game->ray->angle > P3)
	{
		game->ray->v_x = (((int)game->player->x / (TILE_SIZE / 2)) * (TILE_SIZE / 2)) + (TILE_SIZE / 2);
		game->ray->v_y = (game->player->x - game->ray->v_x) * game->ray->ntan + game->player->y;
		game->ray->v_x_off = (TILE_SIZE / 2);
		game->ray->v_y_off = -game->ray->v_x_off * game->ray->ntan;    
	}
	if (game->ray->angle == 0 || game->ray->angle == PI)
	{
		game->ray->v_x = game->player->x;
		game->ray->v_y = game->player->y;
		game->ray->dof = 32;
	}
	while (game->ray->dof < 32)
	{
		game->ray->map_x = (int) (game->ray->v_x) / (TILE_SIZE / 2);
		game->ray->map_y = (int) (game->ray->v_y) / (TILE_SIZE / 2);
		if (game->ray->map_y < 0)
			game->ray->map_y = 0;
		if (game->ray->map_y >= map_height)
			game->ray->map_y = map_height - 1;
		map_width = ft_strlen(game->map[game->ray->map_y]);
		if (game->ray->map_x >= 0 && game->ray->map_x < map_width && game->ray->map_y >= 0 && game->ray->map_y < map_height && game->map[game->ray->map_y][game->ray->map_x] == '1')
			game->ray->dof = 32;
		else
		{
			game->ray->v_x += game->ray->v_x_off;
			game->ray->v_y += game->ray->v_y_off;
			game->ray->dof += 1;
		}
	}
	return (dist(game->player->x, game->player->y, game->ray->v_x, game->ray->v_y));
}

void raycasting_minimap(t_game *game, t_img *img)
{
    double dist_h;
    double dist_v;
    double angle_increment;
    double fov_minimap;
    int n_ray;

    n_ray = 120;
    fov_minimap = 70 * (PI / 180);
    angle_increment = fov_minimap / n_ray;
    game->ray->r = -1;
    game->ray->angle = game->player->angle - (fov_minimap / 2);
    if (game->ray->angle < 0)
        game->ray->angle += 2 * PI;
    if (game->ray->angle > 2 * PI)
        game->ray->angle -= 2 * PI;
    while (++game->ray->r < n_ray)
    {
        dist_h = raycasting_horizontal(game);
        dist_v = raycasting_vertical(game);
        if (dist_h > dist_v)
            game->flag->ray_flag = 1;
        else
            game->flag->ray_flag = 0;
        draw_ray(game, img, game->player->x, game->player->y);
        game->ray->angle += angle_increment;
        if (game->ray->angle < 0)
            game->ray->angle += 2 * PI;
        if (game->ray->angle > 2 * PI)
            game->ray->angle -= 2 * PI;
    }
}

void	raycasting_pov(t_game *game, t_img *img)
{
    double	dist_h;
	double	dist_v;
    double	angle_increment;
    double	fov;

	fov = 70 * (PI / 180);
	game->ray->r = -1;
	angle_increment = fov / WIDTH;
	game->ray->angle = game->player->angle - (fov / 2);
	if (game->ray->angle < 0)
		game->ray->angle += 2 * PI;
	if(game->ray->angle > 2 * PI)
		game->ray->angle -= 2 * PI;
	while (++game->ray->r < WIDTH)
	{
		dist_h = raycasting_horizontal(game);
		dist_v = raycasting_vertical(game);
		if (dist_h > dist_v)
			game->flag->ray_flag = 1;
		else
			game->flag->ray_flag = 0;
		wall_distance(game, dist_h, dist_v);
		render_walls(game, img);
		game->ray->angle += angle_increment;
		if (game->ray->angle < 0)
			game->ray->angle += 2 * PI;
		if (game->ray->angle > 2 * PI)
			game->ray->angle -= 2 * PI;
	}
}
