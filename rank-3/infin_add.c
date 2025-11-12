#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(const char *s)
{
	int len = 0;
	while (s[len])
		len++;
	return (len);
}

int cmp_str(const char *a, const char *b)
{
	int la = ft_strlen(a), lb = ft_strlen(b);
	if (la > lb)
		return 1;
	if (la < lb)
		return -1;
	else
	{
		int i = 0;
		while (i < la)
		{
			if (a[i] > b[i])
				return 1;
			if (a[i] < b[i])
				return -1;
			i++;
		}
		return 0;
	}
}

static void print_numbers(const char *s, int len, int sign)
{
	while (*s == '0')
	{
		s++;
		len--;
	}
	if (sign == -1)
		write(1, "-", 1);
	write(1, s, len);
	write(1, "\n", 1);
}

char *sum_abs(const char *a, const char *b, int *L)
{
	int la = ft_strlen(a), lb = ft_strlen(b);
	int len;
	if (la > lb)
		len = la + 1;
	else
		len = lb + 1;

	char *r = (char *)malloc(len);
	if (!r)
		return NULL;
	int i = la - 1, j = lb - 1, k = len - 1, carry = 0;
	while (k >= 0)
	{
		int da = 0, db = 0, d = 0;
		if (i >= 0)
			da = a[i] - '0';
		if (j >= 0)
			db = b[j] - '0';
		d = da + db + carry;
		r[k] = (char)('0' + d % 10);
		carry = d / 10;
		i--, j--, k--;
	}
	*L = len;
	return (r);
}

char *sub_abs(const char *big, const char *small, int *L)
{
	int lb = ft_strlen(big), ls = ft_strlen(small);
	int len = lb;

	char *r = (char *)malloc(len);
	if (!r)
		return NULL;
	int i = lb - 1, j = ls - 1, k = len - 1, borrow = 0;
	while (k >= 0)
	{
		int db = 0, ds = 0, d = 0;
		if (i >= 0)
			db = big[i] - '0';
		if (j >= 0)
			ds = small[j] - '0';
		d = db - borrow - ds;
		if (d < 0)
		{
			d += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		r[k] = (char)('0' + d);
		i--, j--, k--;
	}
	*L = len;
	return (r);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return 0;
	const char *a = argv[1];
	const char *b = argv[2];

	char *ret = NULL;
	int len = 0;
	int sign = 1;

	int sa = 1, sb = 1;
	if (a[0] == '-')
	{
		sa = -1;
		a++;
	}
	if (b[0] == '-')
	{
		sb = -1;
		b++;
	}

	if (sa == sb)
	{
		ret = sum_abs(a, b, &len);
		if (!ret)
			return 1;
		sign = sa;
	}
	else
	{
		int c = cmp_str(a, b);
		if (c == 0)
		{
			write(1, "0\n", 2);
			return 0;
		}
		if (c > 0)
		{
			ret = sub_abs(a, b, &len);
			sign = sa;
		}
		if (c < 0)
		{
			ret = sub_abs(b, a, &len);
			sign = sb;
		}
		if (!ret)
			return 1;
	}
	print_numbers(ret, len, sign);
	free(ret);
	return 0;
}