/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:10:44 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 11:06:48 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	handle_resize(t_game *game)
{
	render_minimap(game);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->key->w = 1;
	else if (keycode == A)
		game->key->a = 1;
	else if (keycode == S)
		game->key->s = 1;
	else if (keycode == D)
		game->key->d = 1;
	else if (keycode == ESC)
		game->key->esc = 1;
	else if (keycode == LEFT)
		game->key->left = 1;
	else if (keycode == RIGHT)
		game->key->right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->key->w = 0;
	else if (keycode == A)
		game->key->a = 0;
	else if (keycode == S)
		game->key->s = 0;
	else if (keycode == D)
		game->key->d = 0;
	else if (keycode == ESC)
		game->key->esc = 0;
	else if (keycode == LEFT)
		game->key->left = 0;
	else if (keycode == RIGHT)
		game->key->right = 0;
	return (0);
}

int	key_press_handle(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		free_and_destroy(game);
		exit(0);
	}
	key_press(keycode, game);
	movement(game);
	render_minimap(game);
	return (0);
}
