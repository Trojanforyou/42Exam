#include <unistd.h>
#include <stdbool.h>

void inter(int argc, char **argv)
{
	int		i = 0;
	int		j;
	char	printed[256] = {0};
	if (argc != 3)
	{
		write (1, "\n", 1);
		return ;
	}
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{
				if (printed[(unsigned char)argv[1][i]] == 0)
				{
					write (1, &argv[1][i], 1);
					printed[(unsigned char)argv[1][i]] = 1;
				}
			}
			j++;
		}
		i++;
	}
	write (1, "\n", 1);
}
int main(int argc, char **argv)
{
	inter(argc, argv);
}
int *ft_range(int start, int end)
{
    int i = 0;
    // Defining the lenght of the range
    // Since we don't have access to the abs function, we have
    // to make a manual absolute value
    int len = (end - start) < 0 ? ((end - start) * -1) + 1 : (end - start) + 1;
    // Allocating the range needed
    int *range = (int *) malloc(len * sizeof(int));

    // Fill in the range
    while (i < len)
    {
        // Next lines are for numbers going up
        if (start < end)
            range[i] = start++;
        // Next lines are for numbers going down
        else
            range[i] = start--;
        i++;
    }
    // Returning the filled range
    return (range);
}
