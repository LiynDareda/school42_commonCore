/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:41:44 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 14:41:47 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_error(t_game *game, int index, char *str, int num)
{
	int	i;

	i = 0;
	free_matrix(game->map);
	while (i < index)
	{
		mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	ft_error("Error: invalid texture\n", num);
}

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

void	ft_printmoves(t_game *game)
{
	char	*str;
	int		len;

	str = ft_itoa(game->moves);
	len = ft_strlen(str);
	write(1, str, len);
	write(1, " move(s)\n", 9);
	free(str);
}

static void	open_door(t_game *game)
{
	if (game->collectible == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[5], game->exit.x * SIZE, game->exit.y * SIZE);
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
