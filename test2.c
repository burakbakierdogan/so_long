#include "libft/libft.h"

int main()
{
	int fd = open("map.ber", O_RDONLY);


		perror("map file");
		//printf("%s\n",(strerror(errno)));
		//exit(-1);

}