#include "libft/libft.h"

int main()
{
	int fd = open ("./maps/deneme.txt", O_RDONLY);
	char *str = malloc (100);
	read(fd, str, 7);
	printf("%s\n", str);
	close (fd);
	free(str);
	str = NULL;
	str = malloc (1000);
	fd = open ("./maps/deneme.txt", O_RDONLY);
	read(fd, str, 7);
	printf("%s\n", str);
}