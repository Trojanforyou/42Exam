#include <unistd.h>
#include <stdio.h>

void	first_word(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);

}
int main(int argc, char **argv)
{
	first_word(argc, argv);
	return (0);
}
