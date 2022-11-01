CC := clang
CFLAGS := -Wall -Werror -Wextra



Linux:
	$(CC) $(CFLAGS) test1.c  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz