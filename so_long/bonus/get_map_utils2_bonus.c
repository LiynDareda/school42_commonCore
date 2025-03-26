/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:49:02 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 14:45:42 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_entities(t_entities *e, char **map)
{
	while (map[e->i][++e->j] != '\0' && map[e->i][e->j] != '\n')
	{
		if (map[e->i][e->j] == 'P')
			e->player++;
		else if (map[e->i][e->j] == 'E')
			e->exit++;
		else if (map[e->i][e->j] == 'C')
			e->collectible++;
		else if (map[e->i][e->j] == 'N')
			e->enemy++;
		else if (map[e->i][e->j] != '0' && map[e->i][e->j] != '1')
			return (1);
	}
	return (0);
}

int	check_entities(char **map)
{
	t_entities	*e;

	e = (t_entities *)malloc(sizeof(t_entities));
	e->i = -1;
	e->player = 0;
	e->exit = 0;
	e->collectible = 0;
	e->enemy = 0;
	while (map[++e->i] != NULL)
	{
		e->j = -1;
		if (count_entities(e, map) == 1)
		{
			free(e);
			return (1);
		}
	}
	if (e->player != 1 || e->exit != 1 || e->collectible == 0)
	{
		free(e);
		return (1);
	}
	free(e);
	return (0);
}

char	**copy_matrix(char **map)
{
	char	**tmp_map;
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
		i++;
	tmp_map = (char **)ft_calloc(i + 1, sizeof(char *));
	j = 0;
	while (j < i)
	{
		tmp_map[j] = ft_strdup(map[j]);
		j++;
	}
	return (tmp_map);
}

int	get_player_coordinate(char **map, int flag)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				if (flag == 0)
					return (i);
				else
					return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	get_map_size(char **map, t_coord mapsize)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
		i++;
	mapsize.y = i;
	mapsize.x = ft_strlenh(map[0]);
}
