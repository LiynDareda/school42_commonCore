# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarlett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 11:51:39 by lbarlett          #+#    #+#              #
#    Updated: 2023/10/25 11:51:39 by lbarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c			\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c		\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_striteri.c		\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 		\
		ft_strtrim.c		\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c	

BSRCS = ft_lstnew.c			\
		ft_lstsize.c		\
		ft_lstmap.c		\
		ft_lstlast.c		\
		ft_lstiter.c		\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstadd_front.c	\
		ft_lstadd_back.c
NAME = libft.a

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	cc -c -Wall -Wextra -Werror $?

bonus: $(OBJS) $(BOBJS)
	ar r $(NAME) $?
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
