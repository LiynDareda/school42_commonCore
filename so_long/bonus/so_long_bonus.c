/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:50:38 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 11:50:41 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_error(t_game *game, int index, char *str, int num)
{
	int	i;

	i = 0;
	free_matrix(game->map);
	while (i < index)
	{
		mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	ft_error("Error: invalid texture0\n", num);
}

void	find_enemy(t_game *game, int i)
{
	int	j;
	int	k;

	j = -1;
	while (game->map[++j])
	{
		k = -1;
		while (game->map[j][++k])
		{
			if (game->map[j][k] == 'N')
			{
				if (i == 0)
					mlx_put_image_to_window(game->mlx, game->win,
						game->textures[11], k * SIZE, j * SIZE);
				else if (i == 1)
					mlx_put_image_to_window(game->mlx, game->win,
						game->textures[12], k * SIZE, j * SIZE);
				else
					mlx_put_image_to_window(game->mlx, game->win,
						game->textures[13], k * SIZE, j * SIZE);
			}
		}
	}
}

void	find_collectible(t_game *game, int i)
{
	int	j;
	int	k;

	j = -1;
	while (game->map[++j])
	{
		k = -1;
		while (game->map[j][++k])
		{
			if (game->map[j][k] == 'C')
			{
				if (i == 0)
					mlx_put_image_to_window(game->mlx, game->win,
						game->textures[9], k * SIZE, j * SIZE);
				else
					mlx_put_image_to_window(game->mlx, game->win,
						game->textures[10], k * SIZE, j * SIZE);
			}
		}
	}
}

int	check_wall(char **map, int height)
{
	int		i;
	int		length;

	length = 0;
	while (map[0][length] != '\0' && map[0][length] == '1')
		length++;
	if (length != ft_strlenh(map[0]))
		return (1);
	i = 1;
	while (i < height)
	{
		if (length != ft_strlenh(map[i])
			|| map[i][0] != '1' || map[i][length - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[height - 1][i] != '\0' && map[height - 1][i] == '1')
		i++;
	if (i != ft_strlenh(map[height - 1]))
		return (1);
	if (length == height)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Error: invalid number of arguments\n", 1);
	if (ft_check_file(argv[1]) == 0)
		ft_error("Error: invalid file\n", 2);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		ft_error("Error: invalid file extension\n", 3);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Error: malloc failed\n", 4);
	game->col = 0;
	game->moves = 0;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("Error: mlx failed\n", 5);
	game->map = get_map(argv[1], game);
	game->win = mlx_new_window(game->mlx, ft_strlenh(game->map[0]) * SIZE,
			get_height(argv[1]) * SIZE, "so_long");
	init_images(game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, get_inputs, game);
	mlx_hook(game->win, 17, 1L << 2, free_and_destroy, game);
	mlx_loop_hook(game->mlx, &animation, game);
	mlx_loop(game->mlx);
	free_and_destroy(game);
}
