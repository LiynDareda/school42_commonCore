/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:02:10 by espinell          #+#    #+#             */
/*   Updated: 2024/08/27 12:02:10 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_file(char *file)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (!extension || ft_strncmp(extension, ".cub", 4) != 0)
		ft_error("Error: invalid file extension\n", 3);
	if (open(file, O_DIRECTORY, 0644) != -1)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!valid_file(fd))
		return (0);
	close(fd);
	return (1);
}

static int	get_file_height(char *argv)
{
	char	*line;
	int		fd;
	int		j;

	j = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		free(line);
		line = get_next_line(fd);
		j++;
	}
	free(line);
	close(fd);
	return (j);
}

static char	**get_file(char *argv)
{
	char	**file;
	char	*line;
	int		fd;
	int		j;

	j = get_file_height(argv);
	file = (char **)ft_calloc(j + 1, sizeof(char *));
	j = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		file[j] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		j++;
	}
	file[j] = NULL;
	close(fd);
	free(line);
	return (file);
}

t_game	*init_all(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Error: malloc failed\n", 4);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("Error: mlx failed\n", 5);
	init_game(game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Error: invalid number of arguments\n", 1);
	if (ft_check_file(argv[1]) == 0)
		ft_error("Error: invalid file\n", 2);
	game = init_all();
	game->file = get_file(argv[1]);
	init_textures(game->file, game);
	game->map = get_map(game->file, game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	render_minimap(game);
	mlx_hook(game->win, 12, 1L << 15, handle_resize, game);
	mlx_hook(game->win, 2, 1L << 0, key_press_handle, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 2, free_and_destroy, game);
	mlx_loop(game->mlx);
	free_and_destroy(game);
}
