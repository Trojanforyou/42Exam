#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int n;
long long ft_abs(int x){long long t = x; while (t < 0) t = -t; return (t);}
void    putnbr(int n){int c;if (n >= 10) {putnbr(n / 10);} c = n % 10 + '\0'; write (1, &c, 1);}
void    print(int *a) {for (int i = 0; i < n; i++) {if (i > 0) {write (1, " ", 1);}putnbr(a[i]);} write (1, "\n", 1);}
int     is_safe(int *range, int col, int row) {for(int i = 0; i < col; i++) if (range[i] == row || ft_abs(range[i] - row == ft_abs(i - col))) {return 0;} return(1);}
void    solve(int *range, int col) {if (col == n) {print(range); return;} for(int row = 0; row < n; row++) if (is_safe(range, col, row)) {range[col] = row; solve(range, col + 1); }}
int     main(int ac, char **av) {n = atoi(av[1]); int range[n]; solve(range, 0);}
