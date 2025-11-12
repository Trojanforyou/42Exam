#include <string.h>
#include <stdio.h>

char *ft_strcpy(char *dst, char *src)
{
	size_t i;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_strcpy(argc, argv);
	}
}
