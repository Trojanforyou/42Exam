#include <unistd.h>int matches(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}int main(int ac, char **av)
{
    char    stack[10000];
    int     stack_top = 0;
    int     error = 0;
    int i, j;    i = 1;
    if (ac == 1)
    {
        write(1, "\n", 1);
        return 0;
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == '(' || av[i][j] == '[' || av[i][j] == '{')
                stack[stack_top++] = av[i][j];
            else if (av[i][j] == ')' || av[i][j] == ']' || av[i][j] == '}')
            {
                if (stack_top == 0 || !matches(stack[stack_top - 1], av[i][j]))
                {
                    error = 1;
                    break ;
                }
                stack_top--;
            }
            j++;
        }
        if (stack_top != 0 || error)
        {
            write(1, "Error\n", 6);
            stack_top = 0;
            error = 0;
        }
        else
            write(1, "OK\n", 3);
        i++;
    }
    return 0;
}