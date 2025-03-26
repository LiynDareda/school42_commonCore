/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:43:18 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 14:43:19 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_right(t_game *game)
{
	game->moves++;
	if (game->map[game->player.y][game->player.x + 1] == '1')
	{
		game->moves--;
		return ;
	}
	else if (game->map[game->player.y][game->player.x + 1] == 'C')
	{
		game->map[game->player.y][game->player.x + 1] = '0';
		game->collectible--;
	}
	else if (game->map[game->player.y][game->player.x + 1] == 'E'
		&& game->collectible == 0)
		ft_victory(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[2], game->player.x * SIZE, game->player.y * SIZE);
	game->player.x++;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y][game->player.x - 1] == 'E'
		&& game->collectible != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[4], game->exit.x * SIZE, game->exit.y * SIZE);
	ft_printmoves(game);
}

void	player_move_left(t_game *game)
{
	game->moves++;
	if (game->map[game->player.y][game->player.x - 1] == '1')
	{
		game->moves--;
		return ;
	}
	else if (game->map[game->player.y][game->player.x - 1] == 'C')
	{
		game->map[game->player.y][game->player.x - 1] = '0';
		game->collectible--;
	}
	else if (game->map[game->player.y][game->player.x - 1] == 'E'
		&& game->collectible == 0)
		ft_victory(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[2], game->player.x * SIZE, game->player.y * SIZE);
	game->player.x--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y][game->player.x + 1] == 'E'
		&& game->collectible != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[4], game->exit.x * SIZE, game->exit.y * SIZE);
	ft_printmoves(game);
}

void	player_move_down(t_game *game)
{
	game->moves++;
	if (game->map[game->player.y + 1][game->player.x] == '1')
	{
		game->moves--;
		return ;
	}
	else if (game->map[game->player.y + 1][game->player.x] == 'C')
	{
		game->map[game->player.y + 1][game->player.x] = '0';
		game->collectible--;
	}
	else if (game->map[game->player.y + 1][game->player.x] == 'E'
		&& game->collectible == 0)
		ft_victory(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[2], game->player.x * SIZE, game->player.y * SIZE);
	game->player.y++;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y - 1][game->player.x] == 'E'
		&& game->collectible != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[4], game->exit.x * SIZE, game->exit.y * SIZE);
	ft_printmoves(game);
}

void	player_move_up(t_game *game)
{
	game->moves++;
	if (game->map[game->player.y - 1][game->player.x] == '1')
	{
		game->moves--;
		return ;
	}
	else if (game->map[game->player.y - 1][game->player.x] == 'C')
	{
		game->map[game->player.y - 1][game->player.x] = '0';
		game->collectible--;
	}
	else if (game->map[game->player.y - 1][game->player.x] == 'E'
		&& game->collectible == 0)
		ft_victory(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[2], game->player.x * SIZE, game->player.y * SIZE);
	game->player.y--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y + 1][game->player.x] == 'E'
		&& game->collectible != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[4], game->exit.x * SIZE, game->exit.y * SIZE);
	ft_printmoves(game);
}
