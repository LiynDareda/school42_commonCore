/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:55:48 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:48 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_textures(char *str, t_game *game)
{
	int	i;

	i = skip_space(str);
	if (compare_elements(str + i, "NO ", "NO\t"))
		set_image(str + i + 2 + skip_space(str + 2 + i), game, NO);
	else if (compare_elements(str + i, "SO ", "SO\t"))
		set_image(str + i + 2 + skip_space(str + 2 + i), game, SO);
	else if (compare_elements(str + i, "WE ", "WE\t"))
		set_image(str + i + 2 + skip_space(str + 2 + i), game, WE);
	else if (compare_elements(str + i, "EA ", "EA\t"))
		set_image(str + i + 2 + skip_space(str + 2 + i), game, EA);
	else if (compare_elements(str + i, "F ", "F\t"))
		game->floor = valid_color(str + i + 1 + skip_space(str + 1 + i));
	else if (compare_elements(str + i, "C ", "C\t"))
		game->ceiling = valid_color(str + i + 1 + skip_space(str + 1 + i));
	else if (*(str + i) == '\n' || *(str + i) == '1' || *(str + i) == '\0')
		return (1);
	else
	{
		free_and_destroy(game);
		return (0);
	}
	return (1);
}

int	init_textures(char **file, t_game *game)
{
	int	i;

	i = 0;
	while (file[i])
	{
		get_textures(file[i], game);
		i++;
	}
	return (0);
}
