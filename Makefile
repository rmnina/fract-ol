# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 02:01:12 by jdufour           #+#    #+#              #
#    Updated: 2023/09/27 02:17:47 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

SRCS = utils.c\
	checks.c\
	fractals.c\
	hooks.c\
	main.c\

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM = rm -rfv

all: ${NAME}

# libft:
# 	make -C libft/

# minilibx:
# 	make -C minilibx_linux/

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -L minilibx-linux -lmlx -L libft -lft -lXext -lX11 -lm -o ${NAME}

%.o: %.c
	${CC} -Wall -Wextra -Werror -I/minilibx-linux -Imlx_linux -O3 -c $< -o $@

../minilibx-linux/libmlx.a:
	make -C mlx_linux
	
clean:
	${RM} ${OBJS}
	make clean -C ../minilibx-linux
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft
	make fclean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re