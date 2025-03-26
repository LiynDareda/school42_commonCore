/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:10:40 by espinell          #+#    #+#             */
/*   Updated: 2024/09/03 11:10:40 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	game->player->dir_x = cos(game->player->angle) * game->player->move_speed;
	game->player->dir_y = sin(game->player->angle) * game->player->move_speed;
	game->player->dir_x = get_precision(game->player->dir_x);
	game->player->dir_y = get_precision(game->player->dir_y);
	new_x = game->player->x + game->player->dir_x;
	new_y = game->player->y + game->player->dir_y;
	if (is_valid_position(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	game->player->dir_x = cos(game->player->angle) * game->player->move_speed;
	game->player->dir_y = sin(game->player->angle) * game->player->move_speed;
	game->player->dir_x = get_precision(game->player->dir_x);
	game->player->dir_y = get_precision(game->player->dir_y);
	new_x = game->player->x - game->player->dir_x;
	new_y = game->player->y - game->player->dir_y;
	if (is_valid_position(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

static void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	game->player->dir_x = cos(game->player->angle - PI / 2)
		* game->player->move_speed;
	game->player->dir_y = sin(game->player->angle - PI / 2)
		* game->player->move_speed;
	game->player->dir_x = get_precision(game->player->dir_x);
	game->player->dir_y = get_precision(game->player->dir_y);
	new_x = game->player->x + game->player->dir_x;
	new_y = game->player->y + game->player->dir_y;
	if (is_valid_position(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

static void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	game->player->dir_x = cos(game->player->angle + PI / 2)
		* game->player->move_speed;
	game->player->dir_y = sin(game->player->angle + PI / 2)
		* game->player->move_speed;
	game->player->dir_x = get_precision(game->player->dir_x);
	game->player->dir_y = get_precision(game->player->dir_y);
	new_x = game->player->x + game->player->dir_x;
	new_y = game->player->y + game->player->dir_y;
	if (is_valid_position(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
	}
}

void	movement(t_game *game)
{
	if (game->key->w)
		move_forward(game);
	if (game->key->s)
		move_backward(game);
	if (game->key->a)
		move_left(game);
	if (game->key->d)
		move_right(game);
	if (game->key->left)
		rotate_left(game);
	if (game->key->right)
		rotate_right(game);
}
