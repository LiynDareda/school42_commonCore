/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:49:13 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 14:45:39 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlenh(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	get_height(char *argv)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		i;
	int		n;

	n = num;
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (str);
}

int	free_and_destroy(t_game *game)
{
	int	i;

	i = 0;
	free_matrix(game->map);
	while (i < 14)
	{
		mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}

void	free_map(char **map, t_game *game)
{
	free_matrix(map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	ft_error("Error: invalid map\n", 5);
}
