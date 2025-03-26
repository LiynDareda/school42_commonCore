/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:52:20 by espinell          #+#    #+#             */
/*   Updated: 2024/09/23 10:54:19 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' '
			|| str[i] == '\t' || str[i] == '\r'))
		i++;
	return (i);
}

int	check_texture(char *line)
{
	int	j;

	j = skip_space(line);
	if (ft_strncmp(line + j, "NO", 2) == 0)
		return (0);
	else if (ft_strncmp(line + j, "SO", 2) == 0)
		return (0);
	else if (ft_strncmp(line + j, "WE", 2) == 0)
		return (0);
	else if (ft_strncmp(line + j, "EA", 2) == 0)
		return (0);
	else if (ft_strncmp(line + j, "F", 1) == 0)
		return (0);
	else if (ft_strncmp(line + j, "C", 1) == 0)
		return (0);
	else
		return (1);
}

int	valid_line(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = skip_space(line + i);
		i += j;
		if (!line[i])
			return (0);
		if (!valid_char(line[i]) && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	valid_file(int fd)
{
	char	*line;
	int		j;

	line = get_next_line(fd);
	while (line != NULL)
	{
		j = skip_space(line);
		if (ft_strncmp(line + j, "NO", 2) != 0
			&& ft_strncmp(line + j, "SO", 2) != 0
			&& ft_strncmp(line + j, "WE", 2) != 0
			&& ft_strncmp(line + j, "EA", 2) != 0
			&& ft_strncmp(line + j, "F", 1) != 0
			&& ft_strncmp(line + j, "C", 1) != 0
			&& ft_strncmp(line + j, "\n", 1) != 0)
		{
			if (valid_line(line))
			{
				free_n_close (line, fd);
				return (0);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
