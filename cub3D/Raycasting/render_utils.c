/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:56:00 by espinell          #+#    #+#             */
/*   Updated: 2024/09/16 10:56:00 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_line(t_img *img, int start, int end, t_game *game)
{
	int	i;
	int	color;

	if (game->flag->draw_flag)
		color = game->floor;
	else
		color = game->ceiling;
	i = start;
	while (i < end)
	{
		my_put_pixel(img, game->ray->r, i, color);
		i++;
	}
}

void	h_stamp(t_game *game, t_wall *wall, t_img *texture, t_img *img)
{
	int		y;
	int		tex_y;
	int		color_idx;
	int		tex_color;

	y = wall->top;
	tex_y = wall->pos_texture;
	while (y < wall->bottom)
	{
		tex_y = (int)(wall->pos_texture) % texture->height;
		wall->pos_texture += wall->step_texture;
		color_idx = (tex_y * texture->width + wall->x_texture) * 4;
		if (color_idx >= 0 && color_idx < texture->width * texture->height * 4)
		{
			tex_color = (texture->data[color_idx] & 0xFF)
				| (texture->data[color_idx + 1] & 0xFF) << 8
				| (texture->data[color_idx + 2] & 0xFF) << 16;
			my_put_pixel(img, game->ray->r, y, tex_color);
		}
		y++;
	}
}

t_img	*assign_texture(t_game *game, int flag)
{
	t_img	*texture;

	if (flag == 0)
		texture = &game->texture[0];
	else if (flag == 1)
		texture = &game->texture[1];
	else if (flag == 2)
		texture = &game->texture[2];
	else if (flag == 3)
		texture = &game->texture[3];
	else
		texture = &game->texture[0];
	return (texture);
}

void	draw_walls(t_game *game, t_wall *wall, t_img *img)
{
    t_img	*texture;
	int		flag;

	if (wall->height > HEIGHT)
		wall->offset = (wall->height - HEIGHT) / 2;
	else
		wall->offset = 0;
	flag = game->flag->wall_flag;
	texture = assign_texture(game, flag);
	if (flag == 2 || flag == 3)
		wall->x_texture = ((int)game->ray->ry % TILE_SIZE);
	else
		wall->x_texture = ((int)game->ray->rx % TILE_SIZE);
	wall->x_texture = (wall->x_texture * texture->width) / TILE_SIZE;
	wall->x_texture = (int)wall->x_texture % texture->width;
	wall->step_texture = (double)texture->height / (double)wall->height;
	wall->pos_texture = (wall->offset * wall->step_texture);
	h_stamp(game, wall, texture, img);
}
