#include <unistd.h>
void	ft_union(int argc, char **argv)
{
	int	dup[256] = {0};
	int i = 0;
	int j = 0;
	if (argc != 3)
	{
		write (1, "\n", 1);
		return ;
	}
	while (argv[1][i])
	{
		if (dup[(unsigned char)argv[1][i]] == 0)
			{
				write (1, &argv[1][i], 1);
				dup[(unsigned char)argv[1][i]] = 1;
			}
			i++;
	}
	while (argv[2][j])
	{
		if (dup[(unsigned int)argv[2][j]] == 0)
		{
			write (1, &argv[2][j], 1);
			dup[(unsigned int)argv[2][j]] = 1;
		}
		j++;
	}
	write (1, "\n", 1);
}
int main (int argc, char **argv)
{
	ft_union(argc, argv);
}
