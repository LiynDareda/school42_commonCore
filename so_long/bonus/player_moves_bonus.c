/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:50:02 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 11:50:03 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_gameover(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[6], game->player.x * SIZE, game->player.y * SIZE);
	write(1, "GAME OVER! T'hanno gamato!\n", 28);
	free_and_destroy(game);
	exit(0);
}

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
		game->col--;
	}
	else if (game->map[game->player.y][game->player.x + 1] == 'E'
		&& game->col == 0)
		ft_victory(game);
	else if (game->map[game->player.y][game->player.x + 1] == 'N')
		ft_gameover(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[6], game->player.x * SIZE, game->player.y * SIZE);
	game->player.x++;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y][game->player.x - 1] == 'E' && game->col != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[7], game->exit.x * SIZE, game->exit.y * SIZE);
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
		game->col--;
	}
	else if (game->map[game->player.y][game->player.x - 1] == 'E'
		&& game->col == 0)
		ft_victory(game);
	else if (game->map[game->player.y][game->player.x - 1] == 'N')
		ft_gameover(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[6], game->player.x * SIZE, game->player.y * SIZE);
	game->player.x--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y][game->player.x + 1] == 'E' && game->col != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[7], game->exit.x * SIZE, game->exit.y * SIZE);
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
		game->col--;
	}
	else if (game->map[game->player.y + 1][game->player.x] == 'E'
		&& game->col == 0)
		ft_victory(game);
	else if (game->map[game->player.y + 1][game->player.x] == 'N')
		ft_gameover(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[6], game->player.x * SIZE, game->player.y * SIZE);
	game->player.y++;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y - 1][game->player.x] == 'E' && game->col != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[7], game->exit.x * SIZE, game->exit.y * SIZE);
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
		game->col--;
	}
	else if (game->map[game->player.y - 1][game->player.x] == 'E'
		&& game->col == 0)
		ft_victory(game);
	else if (game->map[game->player.y - 1][game->player.x] == 'N')
		ft_gameover(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[6], game->player.x * SIZE, game->player.y * SIZE);
	game->player.y--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures[0], game->player.x * SIZE, game->player.y * SIZE);
	if (game->map[game->player.y + 1][game->player.x] == 'E' && game->col != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[7], game->exit.x * SIZE, game->exit.y * SIZE);
	ft_printmoves(game);
}
