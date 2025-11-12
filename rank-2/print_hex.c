#include <unistd.h>

void	printHex(char *str)
{
	unsigned int res = 0;
	unsigned int i = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i++] - '0';
	}
	return (res);
}

void	put_hex(int nbr)
{
	char *digits = "0123456789abcdef";
	if (nbr >= 16)
		put_hex(nbr /16);
	nbr = digits[nbr % 16];
	write (1, &nbr, 1);
}
int main(int argc, char **argv)
{
	if (argc == 2)
		put_hex()
}
