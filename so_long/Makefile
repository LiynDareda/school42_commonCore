# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtani <mtani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 17:37:18 by mtani             #+#    #+#              #
#    Updated: 2024/01/08 15:40:21 by mtani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./mandatory/so_long.c ./mandatory/so_long_utils.c ./mandatory/player_moves.c ./mandatory/get_next_line.c ./mandatory/get_next_line_utils.c \
	./mandatory/get_map.c ./mandatory/get_map_utils.c ./mandatory/get_map_utils2.c ./mandatory/get_inputs.c

BSRCS = ./bonus/so_long_bonus.c ./bonus/so_long_utils_bonus.c ./bonus/player_moves_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c \
	./bonus/get_map_bonus.c ./bonus/get_map_utils_bonus.c ./bonus/get_map_utils2_bonus.c ./bonus/get_inputs_bonus.c ./bonus/animations_bonus.c  \
	./bonus/init_images_bonus.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

MLX = "https://github.com/42Paris/minilibx-linux.git"

MLX_DIR = minilibx-linux

FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@git clone $(MLX)
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror $(OBJS) $(FLAGS) -o $(NAME) -g

bonus: $(MLX_DIR) $(BOBJS)
	cc -Wall -Wextra -Werror $(BOBJS) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
