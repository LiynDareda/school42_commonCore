/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:55:36 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:36 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	offset = (y * img->len) + (x * 4);
	img->data[offset] = color & 0xFF;
	img->data[offset + 1] = (color >> 8) & 0xFF;
	img->data[offset + 2] = (color >> 16) & 0xFF;
	if (img->bpp == 32)
		img->data[offset + 3] = (color >> 24);
}

static void	draw_tile(t_img *img, int x, int y, int color)
{
	int	tile_x;
	int	tile_y;

	tile_y = -1;
	while (++tile_y < TILE_SIZE / 2 - 3)
	{
		tile_x = -1;
		while (++tile_x < TILE_SIZE / 2 - 3)
		{
			my_put_pixel(img, x * (TILE_SIZE / 2) + tile_x, y
				* (TILE_SIZE / 2) + tile_y, color);
		}
	}
}

static void	set_player_pos(t_img *img, int x, int y, t_game *game)
{
	int	i;
	int	j;
	int	player_center_x;
	int	player_center_y;

	set_player_angle(game, y, x);
	if (!game->flag->f_render)
	{
		game->player->y = y * (TILE_SIZE / 2) + (TILE_SIZE / 4) - 1;
		game->player->x = x * (TILE_SIZE / 2) + (TILE_SIZE / 4) - 1;
		game->flag->f_render = 1;
	}
	i = -1;
	player_center_x = game->player->x - 3;
	player_center_y = game->player->y - 2;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			my_put_pixel(img, player_center_x + i,
				player_center_y + j, 0xFF0000);
	}
}

static void	draw_minimap(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	y = -1;
	while (game->map[++y] != NULL)
	{
		x = -1;
		while (game->map[y][++x] != '\0')
		{
			if (game->map[y][x] == '1')
				draw_tile(img, x, y, 0xFFFFFF);
			else if (game->map[y][x] == '0')
				draw_tile(img, x, y, 0x000000);
			else if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'W' || game->map[y][x] == 'E')
			{
				draw_tile(img, x, y, 0x000000);
				pos_x = x;
				pos_y = y;
			}
		}
	}
	set_player_pos(img, pos_x, pos_y, game);
}

void	render_minimap(t_game *game)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	init_images(img, game->mlx, WIDTH, HEIGHT);
	if (img == NULL)
		ft_error("Error: failed to initialize images\n", 6);
	if (game->flag->f_render == 0)
		draw_minimap(game, img);
	raycasting_pov(game, img);
	draw_minimap(game, img);
	raycasting_minimap(game, img);
	mlx_put_image_to_window(game->mlx, game->win, img->ptr, 0, 0);
	mlx_destroy_image(game->mlx, img->ptr);
	free(img);
}
