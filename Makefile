NAME := so_long
CC := clang
CFLAGS := -Wall -Werror -Wextra
SRCS := test1.c
L_CONFG := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz



all: Libft $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) libft/libft.a $(L_CONFG)
Libft:
	make -C ./libft
clean:
	make -C ./libft fclean
	rm -rf so_long