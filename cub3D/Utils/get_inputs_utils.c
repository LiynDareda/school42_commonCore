/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:42:37 by espinell          #+#    #+#             */
/*   Updated: 2024/09/23 10:57:09 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_valid_position(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;
	int	prs;
	int	pbs;

	map_x = (int)x / (TILE_SIZE / 2);
	map_y = (int)y / (TILE_SIZE / 2);
	prs = (int)((x + 4) / (TILE_SIZE / 2));
	pbs = (int)((y + 4) / (TILE_SIZE / 2));
	if (game->map[map_y][map_x] == '1' || game->map[pbs][prs] == '1'
		|| game->map[map_y][prs] == '1' || game->map[pbs][map_x] == '1')
		return (0);
	return (1);
}
