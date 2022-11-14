# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:51:47 by berdogan          #+#    #+#              #
#    Updated: 2022/11/15 01:03:31 by berdogan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := clang
CFLAGS := -Wall -Werror -Wextra
SRCS := ft_error_management.c so_long.c ft_check_walls.c
L_CONFG := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz



all: Libft $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) libft/libft.a $(L_CONFG)
Libft:
	make -C ./libft
clean:
	make -C ./libft fclean
	rm -rf so_long