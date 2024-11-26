#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*gnl;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	gnl = get_next_line(fd);
	printf("-------------------------------------------\n");
	while (gnl != NULL)
	{
		gnl = get_next_line(fd);
		printf("(main.c) resultat final : [%s]\n", gnl);
		printf("-------------------------------------------\n");
	}
	close(fd);
	if (fd == -1)
		return (0);
}
