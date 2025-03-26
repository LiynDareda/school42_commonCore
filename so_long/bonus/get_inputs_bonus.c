/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:47:25 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 11:47:30 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_victory(t_game *game)
{
	char	*str;
	int		len;

	str = ft_itoa(game->moves);
	len = ft_strlen(str);
	write(1, "You win!\n", 9);
	write(1, "You cleared the level in only ", 30);
	write(1, str, len);
	write(1, " moves!\n", 7);
	free(str);
	free_and_destroy(game);
	exit(0);
}

static void	make_rectangle(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 70)
	{
		j = 0;
		while (j < 20)
		{
			mlx_pixel_put(game->mlx, game->win, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	ft_printmoves(t_game *game)
{
	char	*str;
	char	*moves;

	make_rectangle(game);
	str = ft_itoa(game->moves);
	moves = ft_strjoin("Moves: ", str);
	if (game->moves > 999)
	{
		mlx_string_put(game->mlx, game->win, 4, 13, 0x00000000, "Fai schifo!");
	}
	else
		mlx_string_put(game->mlx, game->win, 6, 13, 0x00000000, moves);
	free(str);
	free(moves);
}

static void	open_door(t_game *game)
{
	if (game->col == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[8], game->exit.x * SIZE, game->exit.y * SIZE);
	}
}

int	get_inputs(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		free_and_destroy(game);
		exit(0);
	}
	else if (keycode == W)
		player_move_up(game);
	else if (keycode == A)
		player_move_left(game);
	else if (keycode == S)
		player_move_down(game);
	else if (keycode == D)
		player_move_right(game);
	open_door(game);
	return (0);
}
