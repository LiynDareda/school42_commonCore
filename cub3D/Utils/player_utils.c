/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:56:29 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:56:29 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_player_angle(t_game *game, int y, int x)
{
	if (game->flag->start)
		return ;
	if (!game->flag->start)
		game->flag->start = 1;
	if (game->map[y][x] == 'N')
		game->player->angle = 3 * PI / 2;
	else if (game->map[y][x] == 'S')
		game->player->angle = PI / 2;
	else if (game->map[y][x] == 'W')
		game->player->angle = PI;
	else if (game->map[y][x] == 'E')
		game->player->angle = 0;
}
