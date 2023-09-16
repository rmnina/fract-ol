# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 02:01:12 by jdufour           #+#    #+#              #
#    Updated: 2023/09/08 12:39:24 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

SRCS = fract-ol.c\

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rfv

all: ${NAME}

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

minilibx-linux/libmlx.a
	make -C mlx_linux
	
clean:
	${RM} ${OBJS}
	make clean -C mlx_linux

fclean: clean
	${RM} ${NAME}
	make fclean -C mlx_linux

re: fclean all

.PHONY: all clean fclean re