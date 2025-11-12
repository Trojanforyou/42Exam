#include <stdbool.h>
#include <unistd.h>
char to_low(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c + 32;
	}
	return c;
}

bool anogra(char *str,char *str1)
{
	int seen[256] = {0};

	while (*str)
	{

		seen[(unsigned char)to_low(*str)]++;
		str++;
	}

	while (*str1)
	{
		seen[(unsigned char)to_low(*str1)]--;
		str1++;
	}

	int i = 0;
	while (i < 256)
	{
		if (seen[i] != 0)
		{
			return false;
		}
		i++;
	}
	return true;

}
int main(int argc, char **argv)
{
	if (argc == 3)
		{
			if (anogra(argv[1],argv[2]))
			{
				write(1,"yes",3);
			}
			else
			{
				write(1,"no",2);
			}
		}
		write(1,"\n",1);
}
