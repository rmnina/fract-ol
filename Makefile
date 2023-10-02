# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 02:01:12 by jdufour           #+#    #+#              #
#    Updated: 2023/10/02 12:36:05 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = src/utils.c\
	src/checks.c\
	src/fractals_iterations.c\
	src/draw_fractals.c\
	src/hooks.c\
	src/main.c\

OBJS = $(SRCS:%.c=%.o)

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

INCLUDES = -I/minilibx-linux -Imlx_linux -O3

LIB = -Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft -lm

RM = rm -rfv

all: $(NAME)

%.o	:	%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -C minilibx-linux
	make -C libft
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)


clean:
	$(RM) $(OBJS)
	make -C minilibx-linux clean
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re