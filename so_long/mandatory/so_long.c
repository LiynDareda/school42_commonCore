/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:43:34 by lbarlett          #+#    #+#             */
/*   Updated: 2024/03/14 14:46:43 by lbarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_basics(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[0], j * SIZE, i * SIZE);
		game->player.x = j;
		game->player.y = i;
	}
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[1], j * SIZE, i * SIZE);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[2], j * SIZE, i * SIZE);
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures[3], j * SIZE, i * SIZE);
		game->collectible++;
	}
}

static void	load_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			load_basics(game, i, j);
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures[4], j * SIZE, i * SIZE);
				game->exit.x = j;
				game->exit.y = i;
			}
		}
	}
}

static void	init_images2(t_game *game, int size)
{
	game->textures[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/anim_xpm/bolt1.xpm", &size, &size);
	if (game->textures[3] == NULL)
		img_error(game, 3, "Error: invalid texture\n", 6);
	game->textures[4] = mlx_xpm_file_to_image(game->mlx, "./textures/exitc.xpm",
			&size, &size);
	if (game->textures[4] == NULL)
		img_error(game, 4, "Error: invalid texture\n", 6);
	game->textures[5] = mlx_xpm_file_to_image(game->mlx, "./textures/exito.xpm",
			&size, &size);
	if (game->textures[5] == NULL)
		img_error(game, 5, "Error: invalid texture\n", 6);
}

static void	init_images(t_game *game)
{
	int	size;

	size = SIZE;
	game->textures[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/anim_xpm/pg1.xpm", &size, &size);
	if (game->textures[0] == NULL)
		img_error(game, 0, "Error: invalid texture\n", 6);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&size, &size);
	if (game->textures[1] == NULL)
		img_error(game, 1, "Error: invalid texture\n", 6);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&size, &size);
	if (game->textures[2] == NULL)
		img_error(game, 2, "Error: invalid texture\n", 6);
	init_images2(game, size);
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
	game->collectible = 0;
	game->moves = 0;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("Error: mlx failed\n", 5);
	game->map = get_map(argv[1], game);
	game->win = mlx_new_window(game->mlx, ft_strlenh(game->map[0]) * SIZE,
			get_height(argv[1]) * SIZE, "so_long");
	init_images(game);
	load_images(game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, get_inputs, game);
	mlx_hook(game->win, 17, 1L << 2, free_and_destroy, game);
	mlx_loop(game->mlx);
	free_and_destroy(game);
}
