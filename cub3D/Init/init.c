/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:26:31 by espinell          #+#    #+#             */
/*   Updated: 2024/09/23 10:26:31 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_images(t_img *img, void *mlx, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	if (!img->ptr)
	{
		free(img);
		return ;
	}
	img->height = height;
	img->width = width;
	img->bpp = 0;
	img->len = 0;
	img->endian = 0;
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->len, &img->endian);
}

static void	init_player(t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->move_speed = 5.0;
	player->angle = 0.0;
}

static void	init_key(t_key *key)
{
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	key->left = 0;
	key->right = 0;
	key->esc = 0;
}

static void	init_flag(t_flag *flag)
{
	flag->start = 0;
	flag->f_render = 0;
	flag->ray_flag = 0;
	flag->wall_flag = -1;
	flag->draw_flag = 0;
}

void	init_game(t_game *game)
{
	int	i;

	game->win = NULL;
	game->ceiling = 0;
	game->floor = 0;
	game->map = NULL;
	game->file = NULL;
	i = 0;
	while (i < 4)
	{
		init_images(&game->texture[i], game->mlx, WIDTH, HEIGHT);
		i++;
	}
	game->player = (t_player *)malloc(sizeof(t_player));
	init_player(game->player);
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	init_ray(game->ray);
	game->flag = (t_flag *)malloc(sizeof(t_flag));
	init_flag(game->flag);
	game->key = (t_key *)malloc(sizeof(t_key));
	init_key(game->key);
	game->wall = (t_wall *)malloc(sizeof(t_wall));
	init_wall(game->wall);
}
