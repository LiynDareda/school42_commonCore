/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:01:51 by espinell          #+#    #+#             */
/*   Updated: 2024/08/27 12:01:51 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_nl(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j = skip_space(map[i]);
		if (map[i][j] == '\n')
		{
			i++;
			while (map[i])
			{
				j = skip_space(map[i]);
				if (map[i][j] != '\n' && map[i][j] != '\0')
					return (1);
				i++;
			}
			return (0);
		}
	}
	return (0);
}

int	check_start(char **map)
{
	t_entities	e;

	e.i = -1;
	e.player = 0;
	while (map[++e.i] != NULL)
	{
		e.j = -1;
		while (map[e.i][++e.j] != '\0' && map[e.i][e.j] != '\n')
		{
			if (map[e.i][e.j] == 'S' || map[e.i][e.j] == 'N'
				|| map[e.i][e.j] == 'W' || map[e.i][e.j] == 'E')
				e.player++;
		}
	}
	if (e.player != 1)
		return (1);
	return (0);
}

int	check_wall(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] && map[i + 1])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i] == NULL)
				return (0);
			if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'N'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				if (i == 0 || map[i] == NULL
					|| j == 0 || !valid_tile(map, i, j))
					return (1);
		}
	}
	j = -1;
	while (map[i][++j])
		if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'N'
			|| map[i][j] == 'W' || map[i][j] == 'E')
			return (1);
	return (0);
}
/*
static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
*/

char	**get_map(char **file, t_game *game)
{
	char	**map;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (file[i] && count < 6)
	{
		if (!check_texture(file[i]))
			count++;
		i++;
	}
	map = copy_map(file, i);
	if (check_wall(map) || check_start(map) || check_nl(map))
		free_map(map, game);
	return (map);
}
