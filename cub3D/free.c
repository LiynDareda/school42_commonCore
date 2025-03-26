/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:02:23 by espinell          #+#    #+#             */
/*   Updated: 2024/08/27 12:02:23 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	free_and_destroy(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i].data)
		{
			game->texture[i].data = NULL;
		}
		if (game->texture[i].ptr)
		{
			mlx_destroy_image(game->mlx, game->texture[i].ptr);
			game->texture[i].ptr = NULL;
		}
		i++;
	}
	if (game->map)
		free_matrix(game->map);
	if (game->ray)
		free(game->ray);
	if (game->flag)
		free(game->flag);
	if (game->key)
		free(game->key);
	if (game->player)
		free(game->player);
	if (game->wall)
		free(game->wall);
	if (game->file)
		free_matrix(game->file);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}

void	free_map(char **map, t_game *game)
{
	free_matrix(map);
	write(1, "Error: invalid map\n", 20);
	free_and_destroy(game);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_n_close(char *line, int fd)
{
	free(line);
	close(fd);
}
