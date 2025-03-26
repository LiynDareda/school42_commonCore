/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espinell <espinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:02:43 by espinell          #+#    #+#             */
/*   Updated: 2024/08/27 12:02:43 by espinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"

# define TILE_SIZE 64
# define WIDTH 1920
# define HEIGHT 1080

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 0
# define C 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define PI 3.14159265359
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533
//0.0174533
//0.0008726

typedef struct s_wall
{
	int 	top;
	int 	height;
	int 	bottom;
	double	x_texture;
	double	y_texture;
	double	step_texture;
	double	pos_texture;
	double	f_dist;
	double 	offset;
}	t_wall;

typedef struct s_flag
{
	int f_render;
	int start;
	int ray_flag;
	int wall_flag;
	int	draw_flag;
}	t_flag;

typedef struct s_ray
{
	int		r;
	int		map_x;
	int		map_y;
	int		map_p;
	int		dof; //depth of field
	double	atan;
	double	ntan;
	double	angle;
	double	rx;
	double	ry;
	double	h_x;
	double	h_y;
	double	h_x_off;
	double	h_y_off;
	double	v_x;
	double	v_y;
	double	v_x_off;
	double	v_y_off;
}	t_ray;

typedef struct s_ray_math
{
    double delta_x; //differenza tra x e un altro punto 
    double delta_y; //differenza tra y e un altro punto
    double x_inc; //incremento x
    double y_inc; //incremento y
    double current_x; //questi si capiscono
    double current_y;
} t_ray_math;
	
typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int left;
	int right;
	int	esc;
}	t_key;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double  angle;
}	t_player;

typedef struct s_entities
{
	int	player;
	int	i;
	int	j;
}	t_entities;

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			ceiling;
	int			floor;
	char		**map;
	char		**file;
	t_img		texture[4];
	t_wall		*wall;
	t_flag		*flag;
	t_key		*key;
	t_player	*player;
	t_ray		*ray;
}	t_game;

//Init functions

t_game	*init_all(void);
void    init_ray(t_ray *ray);
void	init_wall(t_wall *wall);
void	init_game(t_game *game);
void	init_images(t_img *img, void *mlx, int width, int height);
void 	init_ray_math_x(t_ray_math *ray, t_game *game, double x1, double y1);
void	init_ray_math_y(t_ray_math *ray, t_game *game, double x1, double y1);

// Textures and color

int		set_color(char *str);
int		get_prefix(char *line);
int		valid_color(char *line);
int		check_color(char *line);
int		ft_check_file(char *file);
int		check_texture(char *file);
int		valid_tile(char **map, int i, int j);
int		create_trgb(int t, int r, int g, int b);
int		init_textures(char **file, t_game *game);
int		init_texture(char *line, char *path, t_game *game);
char	*valid_texture(char *line);
char	*get_texture_path(char *line, int i);
void	load_textures(t_game *game, char *path, int dir);
void	set_image(char *str, t_game *game, int dir);
void	my_put_pixel(t_img *img, int x, int y, int color);
t_img	assign_textures(t_game *game, int flag);

//free and error

int		free_and_destroy(t_game *game);
void	free_matrix(char **tmp_map);
void	ft_error(char *str, int num);
void	free_map(char **map, t_game *game);
void	free_n_close(char *line, int fd);

//map and file

int		valid_file(int fd);
int		mat_len(char **mat);
int		check_nl(char **map);
int 	get_color(char *line);
int		valid_char(char tile);
int		skip_space(char *str);
int		check_wall(char **map);
int		check_start(char **map);
int		set_map_line(char **file);
int		get_width(char **map, int y);
int		compare_elements(char *str, char *str1, char *str2);
char	**copy_matrix(char **map);
char	**copy_map(char **file, int i);
char	**get_map(char	**file, t_game *game);
void	render_minimap(t_game *game);
char	*my_strdup(const char *s);

//wall
void	h_stamp(t_game *game, t_wall *wall, t_img *texture, t_img *img);
void	draw_walls(t_game *game, t_wall *wall, t_img *img);
t_img	*assign_texture(t_game *game, int flag);

//raycasting & render

void    render_walls(t_game *game, t_img *img);
void	raycasting_pov(t_game *game, t_img *img);
void	raycasting_minimap(t_game *game, t_img *img);
void    draw_line(t_img *img, int start, int end, t_game *game);
void 	wall_distance(t_game *game, double dist_h, double dist_v);

//math

double  find_abs(double x);
double  get_precision(double value);
double  find_max(double x, double y);
double	dist(double ax, double ay, double bx, double by);

// Get Inputs

int		handle_resize(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		key_press_handle(int keycode, t_game *game);

// Player

int		is_valid_position(t_game *game, double x, double y);
void   	movement(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void    set_player_angle(t_game *game,int y, int x);

// GNL

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
