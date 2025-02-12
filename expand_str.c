#include <unistd.h>

void	expand_str(char *str)
{
	int i = 0;

	int first_word = 1;
	while (str[i] == ' ' && str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (!first_word)
				write (1, "   ", 3);
			first_word = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				write (1, &str[i], 1);
				i++;
			}
		}
		else
			i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != '\0')
		expand_str(argv[1]);
	write (1, "\n", 1);
	return 0;
}
