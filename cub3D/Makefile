# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espinell <espinell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 12:02:32 by espinell          #+#    #+#              #
#    Updated: 2024/08/27 12:02:32 by espinell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = cub3D.c error.c free.c \
		./Parsing/check_map.c ./Parsing/check_texture.c \
		./Utils/check_map_utils.c ./Utils/check_file_utils.c \
		./Utils/textures_utils.c ./Utils/get_inputs_utils.c ./Utils/player_utils.c \
		./Utils/math_utils.c ./Utils/common_utils.c \
		./Map/mini_map.c \
		./Init/init.c ./Init/init_2.c\
		./Raycasting/raycasting.c ./Raycasting/render_utils.c \
		./Raycasting/render_walls.c \
		./Get_inputs/movement.c ./Get_inputs/get_inputs.c ./Get_inputs/rotation.c\
		gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

MLX = "https://github.com/42Paris/minilibx-linux.git"

MLX_DIR = minilibx-linux

LIBFT_DIR = Libft
LIBFT = Libft/libft.a

FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext

%.o: %.c
	gcc -Wall -Wextra -Werror -g -c $< -o $@

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@git clone $(MLX)
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	gcc -Wall -Wextra -Werror -g $(OBJS) $(LIBFT) $(FLAGS) -lm -o $(NAME)

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	
re: fclean all
