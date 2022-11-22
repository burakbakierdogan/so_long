# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berdogan <berdogan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 11:51:47 by berdogan          #+#    #+#              #
#    Updated: 2022/11/22 01:23:04 by berdogan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := clang
CFLAGS := -Wall -Werror -Wextra
SRCS := ft_error_management.c so_long.c ft_check_walls.c ft_check_items.c \
		ft_get_map_data.c ft_put_map.c ft_key_events.c
L_CONFG := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
M_CONFG := -L./mlx_mac -lmlx -framework OpenGL -framework AppKit -Imlx_mac

all: Libft $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) libft/libft.a $(M_CONFG)
Libft: $(SRSC)
	make -C libft
Linux: Libft $(SRCS)
	$(CC)  -o $(NAME) $(SRCS) libft/libft.a $(L_CONFG)
clean:
	make -C ./libft fclean
	rm -rf *.o
fclean: clean
	make -C ./libft fclean
	rm -rf so_long
.PHONY: Libft