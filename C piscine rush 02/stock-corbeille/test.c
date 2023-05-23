
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int		fd;
	int		size_read;
	int 	size_malloc;
	char	str[100];

	size_malloc = 1;
	size_read = 2;
	fd = open("dict", O_RDONLY);
	for (int i = 0; i<9; i++)
	{	
		size_malloc += 100;
		size_read = read(fd, str, 100);
		//printf("\n%d et %d\n",size_read, size_malloc - 1);
		write(1, str, 100);
	}
}