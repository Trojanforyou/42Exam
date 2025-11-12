#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	char	buff;
	char	*mem = malloc(9999);
	int	i = 0;
	char	reader;

	if (fd < 0)
		return (NULL);
	while ((reader = read(fd, &buff, 1)) > 0)
	{
		mem[i] = buff;
		i++;
		if (buff == '\n')
			break;
	}
	if (i == 0 || reader < 0)
		return (free(mem), NULL);
	mem[i] = '\0';
	return (mem);
}
int		main(int argc, char **argv)
{
	int 	fd = 0;
	char	*line;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line |%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

