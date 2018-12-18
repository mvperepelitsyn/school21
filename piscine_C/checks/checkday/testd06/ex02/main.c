#include <stdio.h>
#include <string.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_param(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}

int        main(int argc, char **argv)
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        ft_print_param(argv[i]);
        i++;
    }
    return (0);
}

