/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:07:13 by marvin            #+#    #+#             */
/*   Updated: 2024/06/20 11:18:53 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	flood_fill(char **tmp_map, t_coord player, t_coord mapsize)
{
	if (tmp_map[player.y][player.x] == '1' || tmp_map[player.y][player.x] == 'N'
		|| tmp_map[player.y][player.x] == 'X')
		return (0);
	tmp_map[player.y][player.x] = 'X';
	flood_fill(tmp_map, (t_coord){player.x + 1, player.y}, mapsize);
	flood_fill(tmp_map, (t_coord){player.x - 1, player.y}, mapsize);
	flood_fill(tmp_map, (t_coord){player.x, player.y + 1}, mapsize);
	flood_fill(tmp_map, (t_coord){player.x, player.y - 1}, mapsize);
	return (0);
}

static int	check_floodfill(char **tmp_map)
{
	int		i;
	int		j;

	i = 0;
	while (tmp_map[i] != NULL)
	{
		j = 0;
		while (tmp_map[i][j] != '\0')
		{
			if (tmp_map[i][j] == 'C')
				return (0);
			if (tmp_map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_matrix(char **tmp_map)
{
	int		i;

	i = 0;
	while (tmp_map[i] != NULL)
	{
		free(tmp_map[i]);
		i++;
	}
	free(tmp_map);
}

static int	check_path(char **map)
{
	char	**tmp_map;
	t_coord	player;
	t_coord	mapsize;

	player.x = get_player_coordinate(map, 1);
	player.y = get_player_coordinate(map, 0);
	tmp_map = copy_matrix(map);
	get_map_size(map, mapsize);
	flood_fill(tmp_map, player, mapsize);
	if (check_floodfill(tmp_map) == 0)
	{
		free_matrix(tmp_map);
		return (1);
	}
	free_matrix(tmp_map);
	return (0);
}

char	**get_map(char *argv, t_game *game)
{
	char	**map;
	char	*line;
	int		fd;
	int		height;
	int		i;

	i = 0;
	height = get_height(argv);
	map = (char **)ft_calloc(height + 1, sizeof(char *));
	fd = open(argv, O_RDONLY);
	if (open(, O_RDONLY) == 0)
	line = get_next_line(fd);
	while (line != 0)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	if (check_wall(map, height) || check_entities(map) || check_path(map))
		free_map(map, game);
	close(fd);
	return (map);
}
