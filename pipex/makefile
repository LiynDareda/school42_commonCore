# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarlett <lbarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 11:35:59 by lbarlett          #+#    #+#              #
#    Updated: 2024/04/10 11:25:12 by lbarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c pipex_utils.c split.c utils.c error.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
INCLUDES = .
HEADERS = pipex.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = pipex

all: $(NAME)			

$(NAME): $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo compiled $(NAME)

%.o: %.c $(HEADERS)
				@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@echo removed object files

fclean: clean
				@$(RM) $(NAME)
				@echo removed $(NAME)

re: fclean all

.PHONY: all clean fclean re
