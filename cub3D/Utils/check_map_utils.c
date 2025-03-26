/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:01:41 by espinell          #+#    #+#             */
/*   Updated: 2024/08/27 12:01:41 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mat_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	valid_char(char tile)
{
	if (tile == '0' || tile == '1' || tile == 'N'
		|| tile == 'S' || tile == 'E' || tile == 'W')
		return (1);
	return (0);
}

int	valid_tile(char **map, int i, int j)
{
	if (!valid_char(map[i + 1][j]) || !valid_char(map[i - 1][j])
		|| !valid_char(map[i][j - 1]) || !valid_char(map[i][j + 1])
		|| !valid_char(map[i + 1][j + 1]) || !valid_char(map[i - 1][j - 1])
		|| !valid_char(map[i + 1][j - 1]) || !valid_char(map[i - 1][j + 1]))
		return (0);
	return (1);
}

char	**copy_map(char **file, int size)
{
	char	**map;
	int		i;
	int		j;

	i = skip_space(file[size]);
	while (file[size][i] == '\n')
	{
		size++;
		i = skip_space(file[size]);
	}
	j = 0;
	i = size;
	while (file[i])
	{
		i++;
		j++;
	}
	map = (char **)ft_calloc(j + 1, sizeof(char *));
	if (!map)
		return (NULL);
	j = 0;
	while (file[size])
	{
		map[j] = my_strdup(file[size]);
		j++;
		size++;
	}
	map[j] = NULL;
	return (map);
}

int	set_map_line(char **file)
{
	int		j;
	int		i;

	i = 0;
	while (file[i])
	{
		j = skip_space(file[i]);
		if (ft_strncmp(file[i] + j, "NO", 2) != 0
			&& ft_strncmp(file[i] + j, "SO", 2) != 0
			&& ft_strncmp(file[i] + j, "WE", 2) != 0
			&& ft_strncmp(file[i] + j, "EA", 2) != 0
			&& ft_strncmp(file[i] + j, "F", 1) != 0
			&& ft_strncmp(file[i] + j, "C", 1) != 0
			&& ft_strncmp(file[i] + j, "\n", 1) != 0)
			return (i);
		i++;
	}
	return (-1);
}
